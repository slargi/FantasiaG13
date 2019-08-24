#include "Patcher_NoChannelPenaltyMsg.h"
#include "../Addr.h"
#include "../FileSystem.h"

//-----------------------------------------------------------------------------
// Static variable initialization

//-----------------------------------------------------------------------------
// Constructor

CPatcher_NoChannelPenaltyMsg::CPatcher_NoChannelPenaltyMsg(void)
{
	patchname = "NoChannelPenaltyMsg";

	vector<WORD> patch;
	vector<WORD> backup;

	backup +=
		0x33, 0xC9, 0x51, 0x51, 0x6A, 0x01, 0x51, 0x8B, 0x0D,
		0x38, 0xDF, 0xFB, 0x63, 0x6A, 0x01, 0x57, 0x50, 0x8D,
		0x45, 0xE0, 0x50, 0xC6, 0x45, 0xFC, 0x06, 0xE8, 0xEC,
		0x13, 0xFE, 0xFF;

	patch +=
		0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
		0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
		0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
		0x90, 0x90, 0x90;

	MemoryPatch mp(NULL, patch, backup);
	mp.Search(L"Pleione.dll");

	patches += mp;
	if (CheckPatches())
		WriteLog("Patch initialization successful: %s.\n", patchname.c_str());
	else
		WriteLog("Patch initialization failed: %s.\n", patchname.c_str());
}

//-----------------------------------------------------------------------------
// Hook functions

//-----------------------------------------------------------------------------
// INI Functions

bool CPatcher_NoChannelPenaltyMsg::ReadINI(void)
{
	if (ReadINI_Bool(L"NoChannelPenaltyMsg"))
		return Install();
	return true;
}

bool CPatcher_NoChannelPenaltyMsg::WriteINI(void)
{
	WriteINI_Bool(L"NoChannelPenaltyMsg", IsInstalled());
	return true;
}