#include "Patcher_EnableTTF.h"
#include "../Addr.h"
#include "../FileSystem.h"

//-----------------------------------------------------------------------------
// Static variable initialization

//-----------------------------------------------------------------------------
// Constructor

CPatcher_EnableTTF::CPatcher_EnableTTF(void)
{
	patchname = "EnableTTF";

	vector<WORD> patch;
	vector<WORD> backup;

	backup +=
		0x75, 0x43, 0x8B, 0x44, 0x24, 0x04;

	patch +=
		0x90, 0x90, -1, -1, -1, -1;

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

bool CPatcher_EnableTTF::ReadINI(void)
{
	if (ReadINI_Bool(L"EnableTTF"))
		return Install();
	return true;
}

bool CPatcher_EnableTTF::WriteINI(void)
{
	WriteINI_Bool(L"EnableTTF", IsInstalled());
	return true;
}