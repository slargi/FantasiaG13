#include "MasterPatcher.h"

vector<IGenericPatcher *> CMasterPatcher::PatchList;


bool CMasterPatcher::WaitForUnpack(void) {
	LPBYTE addr = (LPBYTE)PatchFromINI;
	SngPatcher_DetectUnpack::Instance()->StartDetection(addr);
	return true;
}

int CMasterPatcher::GetSkillSwapID(void) {
	return SngPatcher_CombatMasterySwap::Instance()->GetSkillID();
}

bool CMasterPatcher::InjectUserCommands(void) {
	SngPatcher_UserCommands::Instance()->addMasterFunctions(ReloadINI, GetSkillSwapID);
	return true;
}

bool CMasterPatcher::PatchFromINI( void )
{
	DebugLog("Reading settings from INI...\n");
	GetPatchList();
	vector<IGenericPatcher *>::iterator it;
	for (it = PatchList.begin(); it != PatchList.end(); it++) {
		(*it)->ReadINI();
	}
	DebugLog("Settings loaded!\n");
	WriteLog("Fantasia Patch successfully completed.\n");
	SngPatcher_DetectUnpack::Instance()->Uninstall();
	return true;
}

bool CMasterPatcher::ReloadINI(void)
{
	DebugLog("Rereading the settings in the INI file...\n");
	GetPatchList();
	vector<IGenericPatcher *>::iterator it;
	for (it = PatchList.begin(); it != PatchList.end(); it++) {
		(*it)->ReadINI();
	}
	DebugLog("Settings have been read again.\n");
	return true;
}

bool CMasterPatcher::SaveToINI( void )
{
	DebugLog("Saving settings to INI...\n");
	GetPatchList();
	vector<IGenericPatcher *>::iterator it;
	for (it = PatchList.begin(); it != PatchList.end(); it++) {
		(*it)->WriteINI();
	}
	DebugLog("Settings saved!\n");
	return true;
}

bool CMasterPatcher::GetPatchList( void )
{
	PatchList.clear();
	PatchList +=
		SngPatcher_HackShield::Instance(),
		SngPatcher_BlockEndingAds::Instance(),
		SngPatcher_ClearDungeonFog::Instance(),
		SngPatcher_DisableNighttime::Instance(),
		// SngPatcher_EnableFSAA::Instance(),
		SngPatcher_EnableNameColoring::Instance(),
		SngPatcher_EnableSelfRightClick::Instance(),
		SngPatcher_EnterRemoteShop::Instance(),
		SngPatcher_LargeClockText::Instance(),
		SngPatcher_ModifyZoomLimit::Instance(),
		// SngPatcher_MoveToSameChannel::Instance(),
		SngPatcher_MoveWhileTalking::Instance(),
		SngPatcher_RemoveLoginDelay::Instance(),
		SngPatcher_ScreenshotQuality::Instance(),
		SngPatcher_ShowCombatPower::Instance(),
		SngPatcher_ShowExplorationPercent::Instance(),
		SngPatcher_ShowItemPrice::Instance(),
		SngPatcher_ShowTrueDurability::Instance(),
		SngPatcher_ShowTrueFoodQuality::Instance(),
		SngPatcher_TalkToUnequippedEgo::Instance(),
		SngPatcher_TargetProps::Instance(),
		SngPatcher_ElfLagFix::Instance(),
		SngPatcher_UseBitmapFonts::Instance(),
		SngPatcher_UseDataFolder::Instance(),
		SngPatcher_ExtraThreads::Instance(),
		SngPatcher_ShowNegativeHP::Instance(),
		SngPatcher_ShowNegativeStats::Instance(),
		SngPatcher_ShowClockMinutes::Instance(),
		SngPatcher_NoMountTimeout::Instance(),
		SngPatcher_NoChannelPenaltyMsg::Instance(),
		SngPatcher_NoChannelMoveDenial::Instance(),
		SngPatcher_EnableCutsceneSkip::Instance(),
		SngPatcher_TargetRestingEnemies::Instance(),
		SngPatcher_DisplayNamesFar::Instance(),
		SngPatcher_DisableSunlightGlare::Instance(),
		SngPatcher_DisableGrayFog::Instance(),
		SngPatcher_PartyBoardToHousing::Instance(),
		SngPatcher_ShowDetailedFPS::Instance(),
		SngPatcher_ShowSimpleFPS::Instance(),
		SngPatcher_ItemSplitQuantity::Instance(),
		SngPatcher_DefaultRangedSwap::Instance(),
		SngPatcher_UncapAutoProduction::Instance(),
		SngPatcher_ModifyRenderDistance::Instance(),
		SngPatcher_StayAsAlchemyGolem::Instance(),
		SngPatcher_DisableScreenShake::Instance(),
		SngPatcher_EnableNakedMode::Instance(),
		SngPatcher_DisableCloudRender::Instance(),
		SngPatcher_ShowPoisonDurability::Instance(),
		SngPatcher_ShowTrueHP::Instance(),
		SngPatcher_ShowItemID::Instance(),
		SngPatcher_TimeAlarm::Instance(),
		SngPatcher_DisableFlashyDyes::Instance(),
		SngPatcher_EnableNPCEquipView::Instance(),
		SngPatcher_EnableMinimapZoom::Instance(),
		SngPatcher_CombatMasterySwap::Instance(),
		SngPatcher_UserCommands::Instance(),
		// SngPatcher_MeditationPatch::Instance(),
		SngPatcher_EnableTTF::Instance(),
		SngPatcher_ModifyFontSize::Instance(),
		SngPatcher_FasterInterfaceWindows::Instance();
		// SngPatcher_WindowPosition::Instance();
	return true;	
}