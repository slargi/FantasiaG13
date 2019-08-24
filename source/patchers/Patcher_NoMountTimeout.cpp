#include "Patcher_NoMountTimeout.h"
#include "../Addr.h"
#include "../FileSystem.h"

//-----------------------------------------------------------------------------
// Static variable initialization

//-----------------------------------------------------------------------------
// Constructor

CPatcher_NoMountTimeout::CPatcher_NoMountTimeout(void)
{
	patchname = "No Mount Timeout";

	vector<WORD> patch;
	vector<WORD> backup;

	backup +=
		0x89, 0x81, 0x54, 0x02, 0x00, 0x00;

	patch +=
		0x90, 0x90, 0x90, 0x90, 0x90, 0x90;	// NOP => NOP

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

bool CPatcher_NoMountTimeout::ReadINI(void)
{
	if (ReadINI_Bool(L"NoMountTimeout"))
		return Install();
	return true;
}

bool CPatcher_NoMountTimeout::WriteINI(void)
{
	WriteINI_Bool(L"NoMountTimeout", IsInstalled());
	return true;
}