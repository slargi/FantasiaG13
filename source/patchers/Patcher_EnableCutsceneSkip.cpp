#include "Patcher_EnableCutsceneSkip.h"
#include "../Addr.h"
#include "../FileSystem.h"

//-----------------------------------------------------------------------------
// Static variable initialization

//-----------------------------------------------------------------------------
// Constructor

CPatcher_EnableCutsceneSkip::CPatcher_EnableCutsceneSkip(void)
{
	patchname = "Enable Cutscene Skip";

	vector<WORD> patch;
	vector<WORD> backup;

	backup +=
		0x39, 0x4D, 0xDC, 0x75, 0x05, 0x39, 0x45, 0xE0;

	patch +=
		-1, -1, -1, 0xEB, -1, -1, -1, -1;	// NOP => NOP

	MemoryPatch mp( NULL, patch, backup);
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

bool CPatcher_EnableCutsceneSkip::ReadINI(void)
{
	if (ReadINI_Bool(L"EnableCutsceneSkip"))
		return Install();
	return true;
}

bool CPatcher_EnableCutsceneSkip::WriteINI(void)
{
	WriteINI_Bool(L"EnableCutsceneSkip", IsInstalled());
	return true;
}