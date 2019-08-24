#include "Patcher_DisableSunlightGlare.h"
#include "../Addr.h"
#include "../FileSystem.h"

//-----------------------------------------------------------------------------
// Static variable initialization

//-----------------------------------------------------------------------------
// Constructor

CPatcher_DisableSunlightGlare::CPatcher_DisableSunlightGlare(void)
{
	patchname = "Disable Sunlight Glare";

	vector<WORD> patch;
	vector<WORD> backup;

	backup +=
		0xE8, 0x13, 0x0A, 0x00, 0x00;

	patch +=
		0x90, 0x90, 0x90, 0x90, 0x90;	// NOP => NOP

	MemoryPatch mp(NULL, patch, backup);
	mp.Search(L"Renderer2.dll");

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

bool CPatcher_DisableSunlightGlare::ReadINI(void)
{
	if (ReadINI_Bool(L"DisableSunlightGlare"))
		return Install();
	return true;
}

bool CPatcher_DisableSunlightGlare::WriteINI(void)
{
	WriteINI_Bool(L"DisableSunlightGlare", IsInstalled());
	return true;
}