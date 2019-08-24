#include "Patcher_DisableGrayFog.h"
#include "../Addr.h"
#include "../FileSystem.h"

//-----------------------------------------------------------------------------
// Static variable initialization

//-----------------------------------------------------------------------------
// Constructor

CPatcher_DisableGrayFog::CPatcher_DisableGrayFog(void)
{
	patchname = "Disable Gray Fog";

	// Disable Fog Begin
	vector<WORD> patch1;
	vector<WORD> backup1;
	backup1 +=
		0xE8, 0x7F, 0xFB, 0xFF, 0xFF, 0x0F, 0xB6, 0x40, 0x02, 0x89,
		0x45, 0x14, 0xDB, 0x45, 0x14, 0xDC, 0x35, -1, -1, -1, -1,
		0xD9, 0x5D, 0x14, 0xD9, 0x45, 0x14;

	patch1 +=
		-1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
		-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
		-1, -1, -1, -1, 0xEB, 0x90;

	MemoryPatch mp1( NULL, patch1, backup1);
	mp1.Search(L"Renderer2.dll");

	// Disable Fog End
	vector<WORD> patch2;
	vector<WORD> backup2;
	backup2 +=
		0xE8, 0x34, 0xFB, 0xFF, 0xFF, 0x0F, 0xB6, 0x40, 0x02, 0x89,
		0x45, 0x14, 0xDB, 0x45, 0x14, 0xDC, 0x35, -1, -1, -1, -1,
		0xD9, 0x5D, 0x14, 0xD9, 0x45, 0x14;

	patch2 +=
		-1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
		-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
		-1, -1, -1, -1, 0xEB, 0x90;

	MemoryPatch mp2(NULL, patch2, backup2);
	mp2.Search(L"Renderer2.dll");

	patches += mp1;
	patches += mp2;
	if (CheckPatches())
		WriteLog("Patch initialization successful: %s.\n", patchname.c_str());
	else
		WriteLog("Patch initialization failed: %s.\n", patchname.c_str());
}

//-----------------------------------------------------------------------------
// Hook functions

//-----------------------------------------------------------------------------
// INI Functions

bool CPatcher_DisableGrayFog::ReadINI(void)
{
	if (ReadINI_Bool(L"DisableGrayFog"))
		return Install();
	return true;
}

bool CPatcher_DisableGrayFog::WriteINI(void)
{
	WriteINI_Bool(L"DisableGrayFog", IsInstalled());
	return true;
}