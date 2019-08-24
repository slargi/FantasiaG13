#pragma once

#include "../Main.h"
#include "Patcher_BlockEndingAds.h"
#include "Patcher_ClearDungeonFog.h"
#include "Patcher_DisableNighttime.h"
#include "Patcher_EnableFSAA.h"
#include "Patcher_EnableNameColoring.h"
#include "Patcher_EnableSelfRightClick.h"
#include "Patcher_EnterRemoteShop.h"
#include "Patcher_ExtraThreads.h"
#include "Patcher_HackShield.h"
#include "Patcher_LargeClockText.h"
#include "Patcher_ModifyZoomLimit.h"
#include "Patcher_MoveToSameChannel.h"
#include "Patcher_MoveWhileTalking.h"
#include "Patcher_RemoveLoginDelay.h"
#include "Patcher_ScreenshotQuality.h"
#include "Patcher_ShowCombatPower.h"
#include "Patcher_ShowExplorationPercent.h"
#include "Patcher_ShowItemPrice.h"
#include "Patcher_ShowTrueDurability.h"
#include "Patcher_ShowTrueFoodQuality.h"
#include "Patcher_TalkToUnequippedEgo.h"
#include "Patcher_TargetProps.h"
#include "Patcher_UseBitmapFonts.h"
#include "Patcher_UseDataFolder.h"
#include "Patcher_DetectUnpack.h"
#include "Patcher_ElfLagFix.h"
#include "Patcher_WindowPosition.h"
#include "Patcher_ShowNegativeHP.h"
#include "Patcher_ShowNegativeStats.h"
#include "Patcher_ShowClockMinutes.h"
#include "Patcher_NoMountTimeout.h"
#include "Patcher_NoChannelPenaltyMsg.h"
#include "Patcher_NoChannelMoveDenial.h"
#include "Patcher_EnableCutsceneSkip.h"
#include "Patcher_TargetRestingEnemies.h"
#include "Patcher_DisplayNamesFar.h"
#include "Patcher_DisableSunlightGlare.h"
#include "Patcher_DisableGrayFog.h"
#include "Patcher_PartyBoardToHousing.h"
#include "Patcher_ShowDetailedFPS.h"
#include "Patcher_ShowSimpleFPS.h"
#include "Patcher_ItemSplitQuantity.h"
#include "Patcher_DefaultRangedSwap.h"
#include "Patcher_UncapAutoProduction.h"
#include "Patcher_ModifyRenderDistance.h"
#include "Patcher_FarDiceThrow.h"
#include "Patcher_StayAsAlchemyGolem.h"
#include "Patcher_DisableScreenShake.h"
#include "Patcher_EnableNakedMode.h"
#include "Patcher_DisableCloudRender.h"
#include "Patcher_ShowPoisonDurability.h"
#include "Patcher_ShowTrueHP.h"
#include "Patcher_ShowItemID.h"
#include "Patcher_TimeAlarm.h"
#include "Patcher_DisableFlashyDyes.h"
#include "Patcher_EnableNPCEquipView.h"
#include "Patcher_EnableMinimapZoom.h"
#include "Patcher_CombatMasterySwap.h"
#include "Patcher_UserCommands.h"
#include "Patcher_MeditationPatch.h"
#include "Patcher_EnableTTF.h"
#include "Patcher_ModifyFontSize.h"
#include "Patcher_FasterInterfaceWindows.h"

class CMasterPatcher {
public:
	static bool WaitForUnpack();
	static int GetSkillSwapID();
	static bool InjectUserCommands(void);
	static bool PatchFromINI( void );
	static bool ReloadINI(void);
	static bool SaveToINI( void );
private:
	static vector<IGenericPatcher *> PatchList;
	static bool GetPatchList( void );
};