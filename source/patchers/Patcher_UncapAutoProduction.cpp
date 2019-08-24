#include "Patcher_UncapAutoProduction.h"
#include "../Addr.h"
#include "../FileSystem.h"

//-----------------------------------------------------------------------------
// Static variable initialization

//-----------------------------------------------------------------------------
// Constructor

CPatcher_UncapAutoProduction::CPatcher_UncapAutoProduction(void)
{
	patchname = "Uncap Auto Production";

	vector<WORD> patch;
	vector<WORD> backup;

	backup +=
		0x66, 0x39, 0x86, 0xDC, 0x01, 0x00, 0x00, 0x76, 0x07, 0x66, 0x89, 0x86, 0xDC, 0x01, 0x00, 0x00;

	patch +=
		-1, -1, -1, -1, -1, -1, -1, 0xEB, 0x07, -1, -1, -1, -1, -1, -1, -1;

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

bool CPatcher_UncapAutoProduction::ReadINI(void)
{
	if (ReadINI_Bool(L"UncapAutoProduction"))
		return Install();
	return true;
}

bool CPatcher_UncapAutoProduction::WriteINI(void)
{
	WriteINI_Bool(L"UncapAutoProduction", IsInstalled());
	return true;
}