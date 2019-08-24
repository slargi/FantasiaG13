#include <chrono>
#include <thread>
#include "ModifyWindow.h"
#include "FileSystem.h"
#include "MSSHook.h"
#include "ThreadWatch.h"
#include "patchers/MasterPatcher.h"

//-------------------------------------------------------------------
// Local variables

static HWND mabiHWnd = NULL;
static HANDLE mabiThread = NULL;
static WNDPROC wpPrevWndProc = NULL;
static HICON hIcon = NULL;
static HMENU fantasiaSubMenu = NULL;
static bool isMinimized = false;
static bool diceStarted = false;
static int thread_priority = 0;
static int sleep_time = 0;
//-------------------------------------------------------------------
// Functions

bool CModifyWindow::SpawnModifier( int priority, int milliseconds )
{
	SECURITY_ATTRIBUTES ThreadAttributes;
	ThreadAttributes.bInheritHandle = false;
	ThreadAttributes.lpSecurityDescriptor = NULL;
	ThreadAttributes.nLength = sizeof( SECURITY_ATTRIBUTES );
	HANDLE hThr = CreateThread( &ThreadAttributes, 0, ModifierThreadMain, NULL, 0, NULL );
	sleep_time = milliseconds;

	if (hThr == NULL) {
		DebugLog("ERROR: CreateThread for watcher thread failed.\n");
		return false;
	}

	return true;
}

DWORD WINAPI CModifyWindow::ModifierThreadMain( LPVOID lpParam )
{
	DWORD processID;
	DWORD mabiProcessID;
	while(mabiHWnd == NULL) {
		mabiHWnd = FindMabiHWnd();
		std::this_thread::sleep_for(std::chrono::milliseconds(sleep_time));
	}
	mabiProcessID = GetWindowThreadProcessId(mabiHWnd, &processID);
	mabiThread = OpenThread(THREAD_SET_INFORMATION | THREAD_QUERY_INFORMATION, 0, mabiProcessID);
	if (!mabiThread) {
		DebugLog("Thread not found\n");
	}
	if (!SetThreadPriority(mabiThread, thread_priority)) {
		DebugLog("Failed to set thread priority: %d\n", thread_priority);
	}
	else {
		DebugLog("Thread set to base priority: %d\n", GetThreadPriority(mabiThread));
	}
	DebugLog("Mabi window found.  HWND=0x%08lX\n", mabiHWnd);
	ModifyMenu();
	return 0;
}

HWND CModifyWindow::FindMabiHWnd()
{
	HWND hwnd = NULL;

	set<DWORD> threadList = CThreadWatch::GetList();
	set<DWORD>::iterator it;
	for (it = threadList.begin(); it != threadList.end(); it++ )
	{
		if (!EnumThreadWindows( *it, (WNDENUMPROC)EnumThreadWindows_fn, (LPARAM)&hwnd ))
			break;
	}

	return hwnd;
}

BOOL CModifyWindow::EnumThreadWindows_fn(HWND hwnd, LPARAM lparam)
{
	wchar_t buf[255];
	GetClassName(hwnd, (LPTSTR)&buf, 255);

	if (wcscmp(buf, L"Mabinogi") == 0) {
		*((HWND *)lparam) = hwnd;
		return false; // Do not continue enumeration
	}
	return true; // Continue enumeration
}

bool CModifyWindow::ModifyMenu()
{
	HMENU systemMenu = GetSystemMenu( mabiHWnd, false );
	HMENU fantasiaMenu = LoadMenu( g_hInstance, MAKEINTRESOURCE(IDR_FANTASIA_MENU) );
	if (fantasiaMenu == NULL) {
		DebugLog("ERROR: Load Fantasia menu failed.\n");
		return false;
	}

	fantasiaSubMenu = GetSubMenu( fantasiaMenu, 0 );
	if (fantasiaSubMenu == NULL) {
		DebugLog("ERROR: Loading Fantasia submenu failed.\n");
		return false;
	}

	BOOL result = true;
	result &= InsertMenu( systemMenu, -1, MF_SEPARATOR, 0, 0 );
	result &= InsertMenu( systemMenu, -1, MF_BYPOSITION | MF_POPUP, (UINT_PTR)fantasiaSubMenu, L"Fantasia Patch" );
	if (!result) {
		DebugLog("ERROR: Inserting Fantasia submenu failed.\n");
		return false;
	}

	wpPrevWndProc = (WNDPROC)SetWindowLong( mabiHWnd, GWLP_WNDPROC, (LONG)FantasiaWndFunc );
	if (wpPrevWndProc == 0) {
		DebugLog("ERROR: Overwriting system window function failed.\n");
		return false;
	}

	DebugLog("Menu modification successful.\n");
	return true;
}

LRESULT APIENTRY CModifyWindow::FantasiaWndFunc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam )
{
	switch (uMsg)
	{
	case WM_ACTIVATE:
		if (HIWORD(wParam) != 0)
			isMinimized = true;
		else
			isMinimized = false;
		UpdateIcon();
		break;
	case WM_SYSCOMMAND:
		// Menu item selected
		switch (wParam)
		{
		case ID_RELOADSETTINGS:
			CMasterPatcher::ReloadINI();
			break;
		case ID_SAVESETTINGS:
			CMasterPatcher::SaveToINI();
			break;
		case ID_CPUMENU_WHILEMINIMIZED:
			if (CThreadWatch::GetOptionOnlyMinimized())
				CThreadWatch::SetOptionOnlyMinimized(false);
			else
				CThreadWatch::SetOptionOnlyMinimized(true);
			UpdateIcon();
			break;
		case ID_CPUMENU_90:
			CThreadWatch::SetReductionPercentage( 90 );
			UpdateIcon();
			break;
		case ID_CPUMENU_80:
			CThreadWatch::SetReductionPercentage( 80 );
			UpdateIcon();
			break;
		case ID_CPUMENU_70:
			CThreadWatch::SetReductionPercentage( 70 );
			UpdateIcon();
			break;
		case ID_CPUMENU_60:
			CThreadWatch::SetReductionPercentage( 60 );
			UpdateIcon();
			break;
		case ID_CPUMENU_50:
			CThreadWatch::SetReductionPercentage( 50 );
			UpdateIcon();
			break;
		case ID_CPUMENU_40:
			CThreadWatch::SetReductionPercentage( 40 );
			UpdateIcon();
			break;
		case ID_CPUMENU_30:
			CThreadWatch::SetReductionPercentage( 30 );
			UpdateIcon();
			break;
		case ID_CPUMENU_20:
			CThreadWatch::SetReductionPercentage( 20 );
			UpdateIcon();
			break;
		case ID_CPUMENU_10:
			CThreadWatch::SetReductionPercentage( 10 );
			UpdateIcon();
			break;
		case ID_CPUMENU_OFF:
			CThreadWatch::SetReductionPercentage( 0 );
			UpdateIcon();
			break;
		case ID_TOGGLE_CLEARDUNGEONFOG:
			SngPatcher_ClearDungeonFog::Instance()->Toggle();
			break;
		case ID_TOGGLE_DISABLENIGHTTIME:
			SngPatcher_DisableNighttime::Instance()->Toggle();
			break;
		case ID_TOGGLE_ENABLENAMECOLORING:
			SngPatcher_EnableNameColoring::Instance()->Toggle();
			break;
		case ID_TOGGLE_ENABLESELFRIGHTCLICK:
			SngPatcher_EnableSelfRightClick::Instance()->Toggle();
			break;
		case ID_TOGGLE_ENTERREMOTESHOP:
			SngPatcher_EnterRemoteShop::Instance()->Toggle();
			break;
		case ID_TOGGLE_LARGECLOCKTEXT:
			SngPatcher_LargeClockText::Instance()->Toggle();
			break;
		/*case ID_ZOOMLIMIT_15000:
			SngPatcher_ModifyZoomLimit::Instance()->SetLimit(15000);
			SngPatcher_ModifyZoomLimit::Instance()->Install();
			break;
		case ID_ZOOMLIMIT_10000:
			SngPatcher_ModifyZoomLimit::Instance()->SetLimit(10000);
			SngPatcher_ModifyZoomLimit::Instance()->Install();
			break;
		case ID_ZOOMLIMIT_5000:
			SngPatcher_ModifyZoomLimit::Instance()->SetLimit( 5000 );
			SngPatcher_ModifyZoomLimit::Instance()->Install();
			break;
		case ID_ZOOMLIMIT_3500:
			SngPatcher_ModifyZoomLimit::Instance()->SetLimit( 3500 );
			SngPatcher_ModifyZoomLimit::Instance()->Install();
			break;
		case ID_ZOOMLIMIT_1500:
			SngPatcher_ModifyZoomLimit::Instance()->SetLimit( 1500 );
			SngPatcher_ModifyZoomLimit::Instance()->Install();
			break;*/
		case ID_TOGGLE_MOVEWHILETALKING:
			SngPatcher_MoveWhileTalking::Instance()->Toggle();
			break;
		case ID_TOGGLE_REMOVELOGINDELAY:
			SngPatcher_RemoveLoginDelay::Instance()->Toggle();
			break;
		case ID_SSQUALITY_100:
			SngMSSHook::Instance()->SetSSQuality(100);
			break;
		case ID_SSQUALITY_90:
			SngMSSHook::Instance()->SetSSQuality(90);
			break;
		case ID_SSQUALITY_75:
			SngMSSHook::Instance()->SetSSQuality(75);
			break;
		case ID_SSQUALITY_50:
			SngMSSHook::Instance()->SetSSQuality(50);
			break;
		case ID_TOGGLE_SHOWCOMBATPOWER:
			SngPatcher_ShowCombatPower::Instance()->Toggle(0);
			break;
		case ID_TOGGLE_SHOWMAXHP:
			SngPatcher_ShowCombatPower::Instance()->Toggle(1);
			break;
		case ID_TOGGLE_SHOWEXPLORATIONPERCENT:
			SngPatcher_ShowExplorationPercent::Instance()->Toggle();
			break;
		case ID_TOGGLE_SHOWITEMPRICE:
			SngPatcher_ShowItemPrice::Instance()->Toggle();
			break;
		case ID_TOGGLE_SHOWTRUEDURABILITY:
			SngPatcher_ShowTrueDurability::Instance()->Toggle();
			break;
		case ID_TOGGLE_SHOWITEMCOLOR:
			SngPatcher_ShowTrueDurability::Instance()->ToggleColor();
			break;
		case ID_TOGGLE_SHOWTRUEFOODQUALITY:
			SngPatcher_ShowTrueFoodQuality::Instance()->Toggle();
			break;
		case ID_TOGGLE_TALKTOUNEQUIPPEDEGO:
			SngPatcher_TalkToUnequippedEgo::Instance()->Toggle();
			break;
		case ID_TOGGLE_TARGETPROPS:
			SngPatcher_TargetProps::Instance()->Toggle();
			break;
		case ID_TOGGLE_USEBITMAPFONTS:
			SngPatcher_UseBitmapFonts::Instance()->Toggle();
			break;
		case ID_TOGGLE_USEDATAFOLDER:
			SngPatcher_UseDataFolder::Instance()->Toggle();
			break;
		case ID_TOGGLE_ELFLAGFIX:
			SngPatcher_ElfLagFix::Instance()->Toggle();
			break;
		case ID_TOGGLE_SHOWNEGATIVEHP:
			SngPatcher_ShowNegativeHP::Instance()->Toggle();
			break;
		case ID_TOGGLE_SHOWNEGATIVESTATS:
			SngPatcher_ShowNegativeStats::Instance()->Toggle();
			break;
		case ID_TOGGLE_SHOWCLOCKMINUTES:
			SngPatcher_ShowClockMinutes::Instance()->Toggle();
			break;
		case ID_TOGGLE_NOMOUNTTIMEOUT:
			SngPatcher_NoMountTimeout::Instance()->Toggle();
			break;
		case ID_TOGGLE_NOCHANNELPENALTYMSG:
			SngPatcher_NoChannelPenaltyMsg::Instance()->Toggle();
			break;
		case ID_TOGGLE_NOCHANNELMOVEDENIAL:
			SngPatcher_NoChannelMoveDenial::Instance()->Toggle();
			break;
		case ID_TOGGLE_ENABLECUTSCENESKIP:
			SngPatcher_EnableCutsceneSkip::Instance()->Toggle();
			break;
		case ID_TOGGLE_TARGETRESTINGENEMIES:
			SngPatcher_TargetRestingEnemies::Instance()->Toggle();
			break;
		case ID_TOGGLE_DISPLAYNAMESFAR:
			SngPatcher_DisplayNamesFar::Instance()->Toggle();
			break;
		case ID_TOGGLE_DISABLESUNLIGHTGLARE:
			SngPatcher_DisableSunlightGlare::Instance()->Toggle();
			break;
		case ID_TOGGLE_DISABLEGRAYFOG:
			SngPatcher_DisableGrayFog::Instance()->Toggle();
			break;
		case ID_TOGGLE_PARTYBOARDTOHOUSING:
			SngPatcher_PartyBoardToHousing::Instance()->Toggle();
			break;
		case ID_TOGGLE_SHOWDETAILEDFPS:
			SngPatcher_ShowDetailedFPS::Instance()->Toggle();
			break;
		case ID_TOGGLE_SHOWSIMPLEFPS:
			SngPatcher_ShowSimpleFPS::Instance()->Toggle();
			break;
		case ID_ITEMQUANTITY_1:
			SngPatcher_ItemSplitQuantity::Instance()->SetQuantity(1);
			SngPatcher_ItemSplitQuantity::Instance()->Install();
			break;
		case ID_ITEMQUANTITY_5:
			SngPatcher_ItemSplitQuantity::Instance()->SetQuantity(5);
			SngPatcher_ItemSplitQuantity::Instance()->Install();
			break;
		case ID_ITEMQUANTITY_10:
			SngPatcher_ItemSplitQuantity::Instance()->SetQuantity(10);
			SngPatcher_ItemSplitQuantity::Instance()->Install();
			break;
		case ID_RANGEDSWAP_MAGNUM:
			SngPatcher_DefaultRangedSwap::Instance()->SetSwap(1);
			SngPatcher_DefaultRangedSwap::Instance()->Install();
			break;
		case ID_RANGEDSWAP_MARIAR:
			SngPatcher_DefaultRangedSwap::Instance()->SetSwap(2);
			SngPatcher_DefaultRangedSwap::Instance()->Install();
			break;
		case ID_RANGEDSWAP_AR:
			SngPatcher_DefaultRangedSwap::Instance()->SetSwap(3);
			SngPatcher_DefaultRangedSwap::Instance()->Install();
			break;
		case ID_RANGEDSWAP_SUPPORT:
			SngPatcher_DefaultRangedSwap::Instance()->SetSwap(4);
			SngPatcher_DefaultRangedSwap::Instance()->Install();
			break;
		case ID_RANGEDSWAP_MIRAGE:
			SngPatcher_DefaultRangedSwap::Instance()->SetSwap(5);
			SngPatcher_DefaultRangedSwap::Instance()->Install();
			break;
		case ID_RANGEDSWAP_CRASH:
			SngPatcher_DefaultRangedSwap::Instance()->SetSwap(6);
			SngPatcher_DefaultRangedSwap::Instance()->Install();
			break;
		case ID_RANGEDSWAP_DEFAULT:
			SngPatcher_DefaultRangedSwap::Instance()->SetSwap(0);
			SngPatcher_DefaultRangedSwap::Instance()->Uninstall();
			break;
		case ID_TOGGLE_UNCAPAUTOPRODUCTION:
			SngPatcher_UncapAutoProduction::Instance()->Toggle();
			break;
		case ID_RENDERDISTANCE_100000:
			if (!SngPatcher_ModifyRenderDistance::Instance()->IsInstalled()) {
				SngPatcher_ModifyRenderDistance::Instance()->Install();
			}
			SngPatcher_ModifyRenderDistance::Instance()->SetDistance(100000);
			break;
		case ID_RENDERDISTANCE_75000:
			if (!SngPatcher_ModifyRenderDistance::Instance()->IsInstalled()) {
				SngPatcher_ModifyRenderDistance::Instance()->Install();
			}
			SngPatcher_ModifyRenderDistance::Instance()->SetDistance(75000);
			break;
		case ID_RENDERDISTANCE_50000:
			if (!SngPatcher_ModifyRenderDistance::Instance()->IsInstalled()) {
				SngPatcher_ModifyRenderDistance::Instance()->Install();
			}
			SngPatcher_ModifyRenderDistance::Instance()->SetDistance(50000);
			break;
		case ID_RENDERDISTANCE_25000:
			if (!SngPatcher_ModifyRenderDistance::Instance()->IsInstalled()) {
				SngPatcher_ModifyRenderDistance::Instance()->Install();
			}
			SngPatcher_ModifyRenderDistance::Instance()->SetDistance(25000);
			break;
		case ID_RENDERDISTANCE_10000:
			if (!SngPatcher_ModifyRenderDistance::Instance()->IsInstalled()) {
				SngPatcher_ModifyRenderDistance::Instance()->Install();
			}
			SngPatcher_ModifyRenderDistance::Instance()->SetDistance(10000);
			break;
		case ID_RENDERDISTANCE_5000:
			if (!SngPatcher_ModifyRenderDistance::Instance()->IsInstalled()) {
				SngPatcher_ModifyRenderDistance::Instance()->Install();
			}
			SngPatcher_ModifyRenderDistance::Instance()->SetDistance(5000);
			break;
		case ID_RENDERDISTANCE_DEFAULT:
			if (SngPatcher_ModifyRenderDistance::Instance()->IsInstalled()) {
				SngPatcher_ModifyRenderDistance::Instance()->Uninstall();
				SngPatcher_ModifyRenderDistance::Instance()->SetDistance(0);
			}
			break;
		case ID_TOGGLE_FARDICETHROW:
			if (!diceStarted) {
				SngPatcher_FarDiceThrow::Instance();
				diceStarted = true;
			}
			SngPatcher_FarDiceThrow::Instance()->Toggle();
			break;
		case ID_TOGGLE_STAYASALCHEMYGOLEM:
			SngPatcher_StayAsAlchemyGolem::Instance()->Toggle();
			break;
		case ID_TOGGLE_DISABLESCREENSHAKE:
			SngPatcher_DisableScreenShake::Instance()->Toggle();
			break;
		case ID_TOGGLE_ENABLENAKEDMODE:
			SngPatcher_EnableNakedMode::Instance()->Toggle();
			break;
		case ID_TOGGLE_DISABLECLOUDRENDER:
			SngPatcher_DisableCloudRender::Instance()->Toggle();
			break;
		case ID_PRIORITY_REALTIME:
			if (!SetThreadPriority(mabiThread, THREAD_PRIORITY_TIME_CRITICAL)) {
				DebugLog("Failed to set thread priority: %d\n", THREAD_PRIORITY_TIME_CRITICAL);
				break;
			}
			thread_priority = THREAD_PRIORITY_TIME_CRITICAL;
			DebugLog("Thread set to base priority: %d\n", GetThreadPriority(mabiThread));
			break;
		case ID_PRIORITY_HIGH:
			if (!SetThreadPriority(mabiThread, THREAD_PRIORITY_HIGHEST)) {
				DebugLog("Failed to set thread priority: %d\n", THREAD_PRIORITY_HIGHEST);
				break;
			}
			thread_priority = THREAD_PRIORITY_HIGHEST;
			DebugLog("Thread set to base priority: %d\n", GetThreadPriority(mabiThread));
			break;
		case ID_PRIORITY_ABOVE_NORMAL:
			if (!SetThreadPriority(mabiThread, THREAD_PRIORITY_ABOVE_NORMAL)) {
				DebugLog("Failed to set thread priority: %d\n", THREAD_PRIORITY_ABOVE_NORMAL);
				break;
			}
			thread_priority = THREAD_PRIORITY_ABOVE_NORMAL;
			DebugLog("Thread set to base priority: %d\n", GetThreadPriority(mabiThread));
			break;
		case ID_PRIORITY_NORMAL:
			if (!SetThreadPriority(mabiThread, THREAD_PRIORITY_NORMAL)) {
				DebugLog("Failed to set thread priority: %d\n", THREAD_PRIORITY_NORMAL);
				break;
			}
			thread_priority = THREAD_PRIORITY_NORMAL;
			DebugLog("Thread set to base priority: %d\n", GetThreadPriority(mabiThread));
			break;
		case ID_PRIORITY_BELOW_NORMAL:
			if (!SetThreadPriority(mabiThread, THREAD_PRIORITY_BELOW_NORMAL)) {
				DebugLog("Failed to set thread priority: %d\n", THREAD_PRIORITY_BELOW_NORMAL);
				break;
			}
			thread_priority = THREAD_PRIORITY_BELOW_NORMAL;
			DebugLog("Thread set to base priority: %d\n", GetThreadPriority(mabiThread));
			break;
		case ID_PRIORITY_LOW:
			if (!SetThreadPriority(mabiThread, THREAD_PRIORITY_LOWEST)) {
				DebugLog("Failed to set thread priority: %d\n", THREAD_PRIORITY_LOWEST);
				break;
			}
			thread_priority = THREAD_PRIORITY_LOWEST;
			DebugLog("Thread set to base priority: %d\n", GetThreadPriority(mabiThread));
			break;
		case ID_PRIORITY_IDLE:
			if (!SetThreadPriority(mabiThread, THREAD_PRIORITY_IDLE)) {
				DebugLog("Failed to set thread priority: %d\n", THREAD_PRIORITY_IDLE);
				break;
			}
			thread_priority = THREAD_PRIORITY_IDLE;
			DebugLog("Thread set to base priority: %d\n", GetThreadPriority(mabiThread));
			break;
		case ID_TOGGLE_SHOWPOISONDURABILITY:
			SngPatcher_ShowPoisonDurability::Instance()->Toggle();
			break;
		case ID_TOGGLE_SHOWTRUEHP:
			SngPatcher_ShowTrueHP::Instance()->Toggle();
			break;
		case ID_TOGGLE_SHOWITEMID:
			SngPatcher_ShowItemID::Instance()->Toggle();
			break;
		case ID_TOGGLE_TIMEALARM:
			SngPatcher_TimeAlarm::Instance()->Toggle();
			break;
		case ID_TOGGLE_DISABLEFLASHYDYES:
			SngPatcher_DisableFlashyDyes::Instance()->Toggle();
			break;
		case ID_TOGGLE_ENABLEMINIMAPZOOM:
			SngPatcher_EnableMinimapZoom::Instance()->Toggle();
			break;
		case ID_TOGGLE_COMBATMASTERYSWAP:
			SngPatcher_CombatMasterySwap::Instance()->Toggle();
			break;
		case ID_TOGGLE_ENABLEUSERCOMMANDS:
			SngPatcher_UserCommands::Instance()->Toggle();
			break;
		/*case ID_TOGGLE_MEDITATIONPATCH:
			SngPatcher_MeditationPatch::Instance()->Toggle();
			break;*/
		case ID_TOGGLE_ENABLETTF:
			SngPatcher_EnableTTF::Instance()->Toggle();
			break;
		case ID_FONTSIZE_10:
			SngPatcher_ModifyFontSize::Instance()->SetFontSize(10);
			SngPatcher_ModifyFontSize::Instance()->Install();
			break;
		case ID_FONTSIZE_12:
			SngPatcher_ModifyFontSize::Instance()->SetFontSize(12);
			SngPatcher_ModifyFontSize::Instance()->Install();
			break;
		case ID_FONTSIZE_14:
			SngPatcher_ModifyFontSize::Instance()->SetFontSize(14);
			SngPatcher_ModifyFontSize::Instance()->Install();
			break;
		case ID_FONTSIZE_16:
			SngPatcher_ModifyFontSize::Instance()->SetFontSize(16);
			SngPatcher_ModifyFontSize::Instance()->Install();
			break;
		case ID_FONTSIZE_18:
			SngPatcher_ModifyFontSize::Instance()->SetFontSize(18);
			SngPatcher_ModifyFontSize::Instance()->Install();
			break;
		case ID_FONTSIZE_20:
			SngPatcher_ModifyFontSize::Instance()->SetFontSize(20);
			SngPatcher_ModifyFontSize::Instance()->Install();
			break;
		case ID_TOGGLE_FASTERINTERFACEWINDOWS:
			SngPatcher_FasterInterfaceWindows::Instance()->Toggle();
			break;

		//case ID_TOGGLE_NAMEOFMOD:
		//	SngPatcher_NameOfMod::Instance()->Toggle();
		//	break;
		}
		break;
	case WM_INITMENU:
		// Update display of menu
		UpdateMenu();
		break;
	}

	return CallWindowProc( wpPrevWndProc, hwnd, uMsg, wParam, lParam );
}

bool CModifyWindow::UpdateMenu()
{
	bool result = true;
	MENUITEMINFO info;
	info.cbSize = sizeof(MENUITEMINFO);
	info.fMask = MIIM_STATE;

	// CPU Mod: Only when minimized
	info.fState = (CThreadWatch::GetOptionOnlyMinimized()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &= 0 != SetMenuItemInfo( fantasiaSubMenu, ID_CPUMENU_WHILEMINIMIZED, false, &info );

	// CPU Mod: Reduction percentage
	switch (CThreadWatch::GetReductionPercentage()) {
	case 90:	result &= 0 != CheckMenuRadioItem( fantasiaSubMenu, ID_CPUMENU_90, ID_CPUMENU_OFF, ID_CPUMENU_90, 0 );	break;
	case 80:	result &= 0 != CheckMenuRadioItem( fantasiaSubMenu, ID_CPUMENU_90, ID_CPUMENU_OFF, ID_CPUMENU_80, 0 );	break;
	case 70:	result &= 0 != CheckMenuRadioItem( fantasiaSubMenu, ID_CPUMENU_90, ID_CPUMENU_OFF, ID_CPUMENU_70, 0 );	break;
	case 60:	result &= 0 != CheckMenuRadioItem( fantasiaSubMenu, ID_CPUMENU_90, ID_CPUMENU_OFF, ID_CPUMENU_60, 0 );	break;
	case 50:	result &= 0 != CheckMenuRadioItem( fantasiaSubMenu, ID_CPUMENU_90, ID_CPUMENU_OFF, ID_CPUMENU_50, 0 );	break;
	case 40:	result &= 0 != CheckMenuRadioItem( fantasiaSubMenu, ID_CPUMENU_90, ID_CPUMENU_OFF, ID_CPUMENU_40, 0 );	break;
	case 30:	result &= 0 != CheckMenuRadioItem( fantasiaSubMenu, ID_CPUMENU_90, ID_CPUMENU_OFF, ID_CPUMENU_30, 0 );	break;
	case 20:	result &= 0 != CheckMenuRadioItem( fantasiaSubMenu, ID_CPUMENU_90, ID_CPUMENU_OFF, ID_CPUMENU_20, 0 );	break;
	case 10:	result &= 0 != CheckMenuRadioItem( fantasiaSubMenu, ID_CPUMENU_90, ID_CPUMENU_OFF, ID_CPUMENU_10, 0 );	break;
	case 0:		result &= 0 != CheckMenuRadioItem( fantasiaSubMenu, ID_CPUMENU_90, ID_CPUMENU_OFF, ID_CPUMENU_OFF, 0 );	break;
	}
	// Screenshot quality
	switch (SngMSSHook::Instance()->GetSSQuality()) {
	case 100:	result &= 0 != CheckMenuRadioItem( fantasiaSubMenu, ID_SSQUALITY_100, ID_SSQUALITY_50, ID_SSQUALITY_100, 0 );	break;
	case 90:	result &= 0 != CheckMenuRadioItem( fantasiaSubMenu, ID_SSQUALITY_100, ID_SSQUALITY_50, ID_SSQUALITY_90, 0 );	break;
	case 75:	result &= 0 != CheckMenuRadioItem( fantasiaSubMenu, ID_SSQUALITY_100, ID_SSQUALITY_50, ID_SSQUALITY_75, 0 );	break;
	case 50:	result &= 0 != CheckMenuRadioItem( fantasiaSubMenu, ID_SSQUALITY_100, ID_SSQUALITY_50, ID_SSQUALITY_50, 0 );	break;
	}
	//// Zoom limit
	//switch (SngPatcher_ModifyZoomLimit::Instance()->GetLimit()) {
	//case 15000:	result &= 0 != CheckMenuRadioItem(fantasiaSubMenu, ID_ZOOMLIMIT_5000, ID_ZOOMLIMIT_15000, ID_ZOOMLIMIT_15000, 0);	break;
	//case 10000:	result &= 0 != CheckMenuRadioItem(fantasiaSubMenu, ID_ZOOMLIMIT_5000, ID_ZOOMLIMIT_15000, ID_ZOOMLIMIT_10000, 0);	break;
	//case 5000:	result &= 0 != CheckMenuRadioItem( fantasiaSubMenu, ID_ZOOMLIMIT_5000, ID_ZOOMLIMIT_15000, ID_ZOOMLIMIT_5000, 0 );	break;
	//case 3500:	result &= 0 != CheckMenuRadioItem( fantasiaSubMenu, ID_ZOOMLIMIT_5000, ID_ZOOMLIMIT_15000, ID_ZOOMLIMIT_3500, 0 );	break;
	//case 1500:	result &= 0 != CheckMenuRadioItem( fantasiaSubMenu, ID_ZOOMLIMIT_5000, ID_ZOOMLIMIT_15000, ID_ZOOMLIMIT_1500, 0 );	break;
	//}
	// Item Quantity
	switch (SngPatcher_ItemSplitQuantity::Instance()->GetQuantity()) {
	case 10:	result &= 0 != CheckMenuRadioItem( fantasiaSubMenu, ID_ITEMQUANTITY_1, ID_ITEMQUANTITY_10, ID_ITEMQUANTITY_10, 0);	break;
	case 5:		result &= 0 != CheckMenuRadioItem( fantasiaSubMenu, ID_ITEMQUANTITY_1, ID_ITEMQUANTITY_10, ID_ITEMQUANTITY_5, 0);	break;
	case 1:		result &= 0 != CheckMenuRadioItem( fantasiaSubMenu, ID_ITEMQUANTITY_1, ID_ITEMQUANTITY_10, ID_ITEMQUANTITY_1, 0);	break;
	}
	switch (SngPatcher_ModifyFontSize::Instance()->GetFontSize()) {
	case 20:	result &= 0 != CheckMenuRadioItem(fantasiaSubMenu, ID_FONTSIZE_10, ID_FONTSIZE_20, ID_FONTSIZE_20, 0);	break;
	case 18:	result &= 0 != CheckMenuRadioItem(fantasiaSubMenu, ID_FONTSIZE_10, ID_FONTSIZE_20, ID_FONTSIZE_18, 0);	break;
	case 16:	result &= 0 != CheckMenuRadioItem(fantasiaSubMenu, ID_FONTSIZE_10, ID_FONTSIZE_20, ID_FONTSIZE_16, 0);	break;
	case 14:	result &= 0 != CheckMenuRadioItem(fantasiaSubMenu, ID_FONTSIZE_10, ID_FONTSIZE_20, ID_FONTSIZE_14, 0);	break;
	case 12:	result &= 0 != CheckMenuRadioItem(fantasiaSubMenu, ID_FONTSIZE_10, ID_FONTSIZE_20, ID_FONTSIZE_12, 0);	break;
	case 10:	result &= 0 != CheckMenuRadioItem(fantasiaSubMenu, ID_FONTSIZE_10, ID_FONTSIZE_20, ID_FONTSIZE_10, 0);	break;
	}
	// Ranged Swap
	switch (SngPatcher_DefaultRangedSwap::Instance()->GetSwap()) {
	case 0:	result &= 0 != CheckMenuRadioItem(fantasiaSubMenu, ID_RANGEDSWAP_MAGNUM, ID_RANGEDSWAP_DEFAULT, ID_RANGEDSWAP_DEFAULT, 0);	break;
	case 1:	result &= 0 != CheckMenuRadioItem(fantasiaSubMenu, ID_RANGEDSWAP_MAGNUM, ID_RANGEDSWAP_DEFAULT, ID_RANGEDSWAP_MAGNUM, 0);	break;
	case 2:	result &= 0 != CheckMenuRadioItem(fantasiaSubMenu, ID_RANGEDSWAP_MAGNUM, ID_RANGEDSWAP_DEFAULT, ID_RANGEDSWAP_MARIAR, 0);	break;
	case 3:	result &= 0 != CheckMenuRadioItem(fantasiaSubMenu, ID_RANGEDSWAP_MAGNUM, ID_RANGEDSWAP_DEFAULT, ID_RANGEDSWAP_AR, 0);		break;
	case 4:	result &= 0 != CheckMenuRadioItem(fantasiaSubMenu, ID_RANGEDSWAP_MAGNUM, ID_RANGEDSWAP_DEFAULT, ID_RANGEDSWAP_SUPPORT, 0);	break;
	case 5:	result &= 0 != CheckMenuRadioItem(fantasiaSubMenu, ID_RANGEDSWAP_MAGNUM, ID_RANGEDSWAP_DEFAULT, ID_RANGEDSWAP_MIRAGE, 0);	break;
	case 6:	result &= 0 != CheckMenuRadioItem(fantasiaSubMenu, ID_RANGEDSWAP_MAGNUM, ID_RANGEDSWAP_DEFAULT, ID_RANGEDSWAP_CRASH, 0);	break;
	}
	// Modify Render Distance
	switch ((int)SngPatcher_ModifyRenderDistance::Instance()->GetRenderDistance()) {
	case 100000:	result &= 0 != CheckMenuRadioItem(fantasiaSubMenu, ID_RENDERDISTANCE_5000, ID_RENDERDISTANCE_DEFAULT, ID_RENDERDISTANCE_100000, 0);		break;
	case 75000:		result &= 0 != CheckMenuRadioItem(fantasiaSubMenu, ID_RENDERDISTANCE_5000, ID_RENDERDISTANCE_DEFAULT, ID_RENDERDISTANCE_75000, 0);		break;
	case 50000:		result &= 0 != CheckMenuRadioItem( fantasiaSubMenu, ID_RENDERDISTANCE_5000, ID_RENDERDISTANCE_DEFAULT, ID_RENDERDISTANCE_50000, 0 );	break;
	case 25000:		result &= 0 != CheckMenuRadioItem( fantasiaSubMenu, ID_RENDERDISTANCE_5000, ID_RENDERDISTANCE_DEFAULT, ID_RENDERDISTANCE_25000, 0 );	break;
	case 10000:		result &= 0 != CheckMenuRadioItem( fantasiaSubMenu, ID_RENDERDISTANCE_5000, ID_RENDERDISTANCE_DEFAULT, ID_RENDERDISTANCE_10000, 0 );	break;
	case 5000:		result &= 0 != CheckMenuRadioItem(fantasiaSubMenu, ID_RENDERDISTANCE_5000, ID_RENDERDISTANCE_DEFAULT, ID_RENDERDISTANCE_5000, 0);		break;
	case 0:			result &= 0 != CheckMenuRadioItem(fantasiaSubMenu, ID_RENDERDISTANCE_5000, ID_RENDERDISTANCE_DEFAULT, ID_RENDERDISTANCE_DEFAULT, 0);	break;
	}
	// Set Thread Priority
	switch (thread_priority) {
	case THREAD_PRIORITY_TIME_CRITICAL:	result &= 0 != CheckMenuRadioItem(fantasiaSubMenu, ID_PRIORITY_REALTIME, ID_PRIORITY_IDLE, ID_PRIORITY_REALTIME, 0);		break;
	case THREAD_PRIORITY_HIGHEST:		result &= 0 != CheckMenuRadioItem(fantasiaSubMenu, ID_PRIORITY_REALTIME, ID_PRIORITY_IDLE, ID_PRIORITY_HIGH, 0);			break;
	case THREAD_PRIORITY_ABOVE_NORMAL:	result &= 0 != CheckMenuRadioItem(fantasiaSubMenu, ID_PRIORITY_REALTIME, ID_PRIORITY_IDLE, ID_PRIORITY_ABOVE_NORMAL, 0);	break;
	case THREAD_PRIORITY_NORMAL:		result &= 0 != CheckMenuRadioItem(fantasiaSubMenu, ID_PRIORITY_REALTIME, ID_PRIORITY_IDLE, ID_PRIORITY_NORMAL, 0);			break;
	case THREAD_PRIORITY_BELOW_NORMAL:	result &= 0 != CheckMenuRadioItem(fantasiaSubMenu, ID_PRIORITY_REALTIME, ID_PRIORITY_IDLE, ID_PRIORITY_BELOW_NORMAL, 0);	break;
	case THREAD_PRIORITY_LOWEST:		result &= 0 != CheckMenuRadioItem(fantasiaSubMenu, ID_PRIORITY_REALTIME, ID_PRIORITY_IDLE, ID_PRIORITY_LOW, 0);				break;
	case THREAD_PRIORITY_IDLE:			result &= 0 != CheckMenuRadioItem(fantasiaSubMenu, ID_PRIORITY_REALTIME, ID_PRIORITY_IDLE, ID_PRIORITY_IDLE, 0);			break;
	}
	// Block ending ads
	info.fState = (SngPatcher_BlockEndingAds::Instance()->IsInstalled()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &= 0 != SetMenuItemInfo( fantasiaSubMenu, ID_TOGGLE_BLOCKENDINGADS, false, &info );
	// Clear dungeon fog
	info.fState = (SngPatcher_ClearDungeonFog::Instance()->IsInstalled()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &= 0 != SetMenuItemInfo( fantasiaSubMenu, ID_TOGGLE_CLEARDUNGEONFOG, false, &info );
	// Disable nighttime
	info.fState = (SngPatcher_DisableNighttime::Instance()->IsInstalled()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &= 0 != SetMenuItemInfo( fantasiaSubMenu, ID_TOGGLE_DISABLENIGHTTIME, false, &info );
	// Enable name coloring
	info.fState = (SngPatcher_EnableNameColoring::Instance()->IsInstalled()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &= 0 != SetMenuItemInfo( fantasiaSubMenu, ID_TOGGLE_ENABLENAMECOLORING, false, &info );
	// Enable self right-click
	info.fState = (SngPatcher_EnableSelfRightClick::Instance()->IsInstalled()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &= 0 != SetMenuItemInfo( fantasiaSubMenu, ID_TOGGLE_ENABLESELFRIGHTCLICK, false, &info );
	// Enter remote shop
	info.fState = (SngPatcher_EnterRemoteShop::Instance()->IsInstalled()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &= 0 != SetMenuItemInfo( fantasiaSubMenu, ID_TOGGLE_ENTERREMOTESHOP, false, &info );
	// Large clock text
	info.fState = (SngPatcher_LargeClockText::Instance()->IsInstalled()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &= 0 != SetMenuItemInfo( fantasiaSubMenu, ID_TOGGLE_LARGECLOCKTEXT, false, &info );
	// Move while talking
	info.fState = (SngPatcher_MoveWhileTalking::Instance()->IsInstalled()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &= 0 != SetMenuItemInfo( fantasiaSubMenu, ID_TOGGLE_MOVEWHILETALKING, false, &info );
	// Remove login delay
	info.fState = (SngPatcher_RemoveLoginDelay::Instance()->IsInstalled()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &= 0 != SetMenuItemInfo( fantasiaSubMenu, ID_TOGGLE_REMOVELOGINDELAY, false, &info );
	// Show combat power
	info.fState = (SngPatcher_ShowCombatPower::Instance()->IsInstalled(0)) ? MFS_CHECKED : MFS_UNCHECKED;
	result &= 0 != SetMenuItemInfo( fantasiaSubMenu, ID_TOGGLE_SHOWCOMBATPOWER, false, &info );
	// Show Max HP
	info.fState = (SngPatcher_ShowCombatPower::Instance()->IsInstalled(1)) ? MFS_CHECKED : MFS_UNCHECKED;
	result &= 0 != SetMenuItemInfo(fantasiaSubMenu, ID_TOGGLE_SHOWMAXHP, false, &info);
	// Show exploration percent
	info.fState = (SngPatcher_ShowExplorationPercent::Instance()->IsInstalled()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &= 0 != SetMenuItemInfo( fantasiaSubMenu, ID_TOGGLE_SHOWEXPLORATIONPERCENT, false, &info );
	// Show item price
	info.fState = (SngPatcher_ShowItemPrice::Instance()->IsInstalled()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &= 0 != SetMenuItemInfo( fantasiaSubMenu, ID_TOGGLE_SHOWITEMPRICE, false, &info );
	// Show true durability
	info.fState = (SngPatcher_ShowTrueDurability::Instance()->IsInstalled()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &= 0 != SetMenuItemInfo( fantasiaSubMenu, ID_TOGGLE_SHOWTRUEDURABILITY, false, &info );
	// Show item color
	info.fState = (SngPatcher_ShowTrueDurability::Instance()->IsInstalled()) ? MFS_ENABLED : MFS_DISABLED;
	info.fState |= (SngPatcher_ShowTrueDurability::Instance()->IsColorEnabled()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &= 0 != SetMenuItemInfo( fantasiaSubMenu, ID_TOGGLE_SHOWITEMCOLOR, false, &info );
	// Show true food quality
	info.fState = (SngPatcher_ShowTrueFoodQuality::Instance()->IsInstalled()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &= 0 != SetMenuItemInfo( fantasiaSubMenu, ID_TOGGLE_SHOWTRUEFOODQUALITY, false, &info );
	// Talk to unequipped ego
	info.fState = (SngPatcher_TalkToUnequippedEgo::Instance()->IsInstalled()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &= 0 != SetMenuItemInfo( fantasiaSubMenu, ID_TOGGLE_TALKTOUNEQUIPPEDEGO, false, &info );
	// Target props
	info.fState = (SngPatcher_TargetProps::Instance()->IsInstalled()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &= 0 != SetMenuItemInfo( fantasiaSubMenu, ID_TOGGLE_TARGETPROPS, false, &info );
	// Use bitmap fonts
	info.fState = (SngPatcher_UseBitmapFonts::Instance()->IsInstalled()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &= 0 != SetMenuItemInfo( fantasiaSubMenu, ID_TOGGLE_USEBITMAPFONTS, false, &info );
	// Use data folder
	info.fState = (SngPatcher_UseDataFolder::Instance()->IsInstalled()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &= 0 != SetMenuItemInfo( fantasiaSubMenu, ID_TOGGLE_USEDATAFOLDER, false, &info );
	// Use Elf Lag Fix
	info.fState = (SngPatcher_ElfLagFix::Instance()->IsInstalled()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &= 0 != SetMenuItemInfo(fantasiaSubMenu, ID_TOGGLE_ELFLAGFIX, false, &info);
	// Show Negative HP
	info.fState = (SngPatcher_ShowNegativeHP::Instance()->IsInstalled()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &= 0 != SetMenuItemInfo(fantasiaSubMenu, ID_TOGGLE_SHOWNEGATIVEHP, false, &info);
	// Show Negative Stats
	info.fState = (SngPatcher_ShowNegativeStats::Instance()->IsInstalled()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &= 0 != SetMenuItemInfo(fantasiaSubMenu, ID_TOGGLE_SHOWNEGATIVESTATS, false, &info);
	// Show Clock Minutes
	info.fState = (SngPatcher_ShowClockMinutes::Instance()->IsInstalled()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &= 0 != SetMenuItemInfo(fantasiaSubMenu, ID_TOGGLE_SHOWCLOCKMINUTES, false, &info);
	// No Mount Timeout
	info.fState = (SngPatcher_NoMountTimeout::Instance()->IsInstalled()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &= 0 != SetMenuItemInfo(fantasiaSubMenu, ID_TOGGLE_NOMOUNTTIMEOUT, false, &info);
	// No Channel Penalty Msg
	info.fState = (SngPatcher_NoChannelPenaltyMsg::Instance()->IsInstalled()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &= 0 != SetMenuItemInfo(fantasiaSubMenu, ID_TOGGLE_NOCHANNELPENALTYMSG, false, &info);
	// No Channel Move Denial
	info.fState = (SngPatcher_NoChannelMoveDenial::Instance()->IsInstalled()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &= 0 != SetMenuItemInfo(fantasiaSubMenu, ID_TOGGLE_NOCHANNELMOVEDENIAL, false, &info);
	// Enable Cutscene Skip
	info.fState = (SngPatcher_EnableCutsceneSkip::Instance()->IsInstalled()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &= 0 != SetMenuItemInfo(fantasiaSubMenu, ID_TOGGLE_ENABLECUTSCENESKIP, false, &info);
	// Target Resting Enemies
	info.fState = (SngPatcher_TargetRestingEnemies::Instance()->IsInstalled()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &= 0 != SetMenuItemInfo(fantasiaSubMenu, ID_TOGGLE_TARGETRESTINGENEMIES, false, &info);
	// Display Names Far
	info.fState = (SngPatcher_DisplayNamesFar::Instance()->IsInstalled()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &= 0 != SetMenuItemInfo(fantasiaSubMenu, ID_TOGGLE_DISPLAYNAMESFAR, false, &info);
	// Disable Sunlight Glare
	info.fState = (SngPatcher_DisableSunlightGlare::Instance()->IsInstalled()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &= 0 != SetMenuItemInfo(fantasiaSubMenu, ID_TOGGLE_DISABLESUNLIGHTGLARE, false, &info);
	// Disable Gray Fog
	info.fState = (SngPatcher_DisableGrayFog::Instance()->IsInstalled()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &= 0 != SetMenuItemInfo(fantasiaSubMenu, ID_TOGGLE_DISABLEGRAYFOG, false, &info);
	// Party Board to Housing
	info.fState = (SngPatcher_PartyBoardToHousing::Instance()->IsInstalled()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &= 0 != SetMenuItemInfo(fantasiaSubMenu, ID_TOGGLE_PARTYBOARDTOHOUSING, false, &info);
	// Show Detailed FPS
	info.fState = (SngPatcher_ShowDetailedFPS::Instance()->IsInstalled()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &= 0 != SetMenuItemInfo(fantasiaSubMenu, ID_TOGGLE_SHOWDETAILEDFPS, false, &info);
	// Show Simple FPS
	info.fState = (SngPatcher_ShowSimpleFPS::Instance()->IsInstalled()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &= 0 != SetMenuItemInfo(fantasiaSubMenu, ID_TOGGLE_SHOWSIMPLEFPS, false, &info);
	// Uncap Auto-Production
	info.fState = (SngPatcher_UncapAutoProduction::Instance()->IsInstalled()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &= 0 != SetMenuItemInfo(fantasiaSubMenu, ID_TOGGLE_UNCAPAUTOPRODUCTION, false, &info);
	// Far Dice Throw
	info.fState = (SngPatcher_FarDiceThrow::Instance()->IsInstalled()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &= 0 != SetMenuItemInfo(fantasiaSubMenu, ID_TOGGLE_FARDICETHROW, false, &info);
	// Stay as Alchemy Golem
	info.fState = (SngPatcher_StayAsAlchemyGolem::Instance()->IsInstalled()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &= 0 != SetMenuItemInfo(fantasiaSubMenu, ID_TOGGLE_STAYASALCHEMYGOLEM, false, &info);
	// Disable Screen Shake
	info.fState = (SngPatcher_DisableScreenShake::Instance()->IsInstalled()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &= 0 != SetMenuItemInfo(fantasiaSubMenu, ID_TOGGLE_DISABLESCREENSHAKE, false, &info);
	// Enable Naked Mode
	info.fState = (SngPatcher_EnableNakedMode::Instance()->IsInstalled()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &= 0 != SetMenuItemInfo(fantasiaSubMenu, ID_TOGGLE_ENABLENAKEDMODE, false, &info);
	// Disable Cloud Render
	info.fState = (SngPatcher_DisableCloudRender::Instance()->IsInstalled()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &= 0 != SetMenuItemInfo(fantasiaSubMenu, ID_TOGGLE_DISABLECLOUDRENDER, false, &info);
	// Show Poison Durability
	info.fState = (SngPatcher_ShowPoisonDurability::Instance()->IsInstalled()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &= 0 != SetMenuItemInfo(fantasiaSubMenu, ID_TOGGLE_SHOWPOISONDURABILITY, false, &info);
	// Show True HP
	info.fState = (SngPatcher_ShowTrueHP::Instance()->IsInstalled()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &= 0 != SetMenuItemInfo(fantasiaSubMenu, ID_TOGGLE_SHOWTRUEHP, false, &info);
	// Show Item ID
	info.fState = (SngPatcher_ShowItemID::Instance()->IsInstalled()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &= 0 != SetMenuItemInfo(fantasiaSubMenu, ID_TOGGLE_SHOWITEMID, false, &info);
	// Time Alarm
	info.fState = (SngPatcher_TimeAlarm::Instance()->IsInstalled()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &= 0 != SetMenuItemInfo(fantasiaSubMenu, ID_TOGGLE_TIMEALARM, false, &info);
	// Disable Flashy Dyes
	info.fState = (SngPatcher_DisableFlashyDyes::Instance()->IsInstalled()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &= 0 != SetMenuItemInfo(fantasiaSubMenu, ID_TOGGLE_DISABLEFLASHYDYES, false, &info);
	// Enable NPC Equip View
	info.fState = (SngPatcher_EnableNPCEquipView::Instance()->IsInstalled()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &= 0 != SetMenuItemInfo(fantasiaSubMenu, ID_TOGGLE_ENABLENPCEQUIPVIEW, false, &info);
	// Enable Minimap Zoom
	info.fState = (SngPatcher_EnableMinimapZoom::Instance()->IsInstalled()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &= 0 != SetMenuItemInfo(fantasiaSubMenu, ID_TOGGLE_ENABLEMINIMAPZOOM, false, &info);
	// Combat Mastery Swap
	info.fState = (SngPatcher_CombatMasterySwap::Instance()->IsInstalled()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &= 0 != SetMenuItemInfo(fantasiaSubMenu, ID_TOGGLE_COMBATMASTERYSWAP, false, &info);
	// Enable User Commands
	info.fState = (SngPatcher_UserCommands::Instance()->IsInstalled()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &= 0 != SetMenuItemInfo(fantasiaSubMenu, ID_TOGGLE_ENABLEUSERCOMMANDS, false, &info);
	// Enable Meditation Patch
	/*info.fState = (SngPatcher_MeditationPatch::Instance()->IsInstalled()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &= 0 != SetMenuItemInfo(fantasiaSubMenu, ID_TOGGLE_MEDITATIONPATCH, false, &info);*/
	// Enable TTF
	info.fState = (SngPatcher_EnableTTF::Instance()->IsInstalled()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &= 0 != SetMenuItemInfo(fantasiaSubMenu, ID_TOGGLE_ENABLETTF, false, &info);
	// Faster Interface Windows
	info.fState = (SngPatcher_FasterInterfaceWindows::Instance()->IsInstalled()) ? MFS_CHECKED : MFS_UNCHECKED;
	result &= 0 != SetMenuItemInfo(fantasiaSubMenu, ID_TOGGLE_FASTERINTERFACEWINDOWS, false, &info);
	// // NameOfMod
	// info.fState = (SngPatcher_NameOfMod::Instance()->IsInstalled()) ? MFS_CHECKED : MFS_UNCHECKED;
	// result &= 0 != SetMenuItemInfo( fantasiaSubMenu, ID_TOGGLE_NAMEOFMOD, false, &info );

	if (result)
		DebugLog("System menu updated.\n");
	return result;
}

bool CModifyWindow::UpdateIcon( void )
{
	LPWSTR iconResource;
	if ((CThreadWatch::GetReductionPercentage() > 0) &&
		(!CThreadWatch::GetOptionOnlyMinimized() || isMinimized))
		iconResource = MAKEINTRESOURCE( IDI_ICON_BLUE );
	else iconResource = MAKEINTRESOURCE( IDI_ICON_ORANGE );

	if (hIcon)
		DeleteObject( hIcon );
	HICON icon = LoadIcon( g_hInstance, iconResource );
	if (icon == NULL) {
		DebugLog("ERROR: Loading icon resource 0x%08lX failed.\n", iconResource);
		return false;
	}
	SendMessage( mabiHWnd, WM_SETICON, ICON_SMALL, (LPARAM)icon );
	return true;	
}

bool CModifyWindow::IsMinimized( void )
{
	return isMinimized;
}