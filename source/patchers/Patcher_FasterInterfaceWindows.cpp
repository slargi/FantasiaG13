#include "Patcher_FasterInterfaceWindows.h"
#include "../Addr.h"
#include "../FileSystem.h"

//-----------------------------------------------------------------------------
// Static variable initialization

//-----------------------------------------------------------------------------
// Constructor

CPatcher_FasterInterfaceWindows::CPatcher_FasterInterfaceWindows(void)
{
	patchname = "FasterInterfaceWindows";

	// FadeIn
	vector<WORD> patch;
	vector<WORD> backup;

	backup +=
		0x74, 0x6F, 0xE8, 0xD4, 0x8F, 0xFD, 0xFF, 0x85, 0xC0, 0x74, 0x10;

	patch +=
		0xEB, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1;

	MemoryPatch mp(NULL, patch, backup);
	mp.Search(L"Pleione.dll");

	// BeginAnimation
	vector<WORD> patch1;
	vector<WORD> backup1;

	backup1 +=
		0x8B, 0x8E, 0x9C, 0x00, 0x00, 0x00, 0x6A, 0x00, 0xFF, 0x75, 0x18;

	patch1 +=
		-1, -1, -1, -1, -1, -1, -1, -1, 0x6A, 0x00, 0x90;

	MemoryPatch mp1(NULL, patch1, backup1);
	mp1.Search(L"Pleione.dll");

	patches += mp;
	patches += mp1;
	if (CheckPatches())
		WriteLog("Patch initialization successful: %s.\n", patchname.c_str());
	else
		WriteLog("Patch initialization failed: %s.\n", patchname.c_str());
}

//-----------------------------------------------------------------------------
// Hook functions

//-----------------------------------------------------------------------------
// INI Functions

bool CPatcher_FasterInterfaceWindows::ReadINI(void)
{
	if (ReadINI_Bool(L"FasterInterfaceWindows"))
		return Install();
	return true;
}

bool CPatcher_FasterInterfaceWindows::WriteINI(void)
{
	WriteINI_Bool(L"FasterInterfaceWindows", IsInstalled());
	return true;
}