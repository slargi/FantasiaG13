#include "Patcher_EnableNakedMode.h"
#include "../Addr.h"
#include "../FileSystem.h"

//-----------------------------------------------------------------------------
// Static variable initialization

//-----------------------------------------------------------------------------
// Constructor

CPatcher_EnableNakedMode::CPatcher_EnableNakedMode(void)
{
	patchname = "Enable Naked Mode";

	vector<WORD> patch;
	vector<WORD> backup;

	backup +=
		0x74, 0x11;

	patch +=
		0xEB, -1;

	MemoryPatch mp((LPBYTE)0x638E57D1, patch, backup);

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

bool CPatcher_EnableNakedMode::ReadINI(void)
{
	if (ReadINI_Bool(L"EnableNakedMode"))
		return Install();
	return true;
}

bool CPatcher_EnableNakedMode::WriteINI(void)
{
	WriteINI_Bool(L"EnableNakedMode", IsInstalled());
	return true;
}