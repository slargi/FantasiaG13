#include "Patcher_WindowPosition.h"
#include "../Addr.h"
#include "../FileSystem.h"

//-----------------------------------------------------------------------------
// Static variable initialization

//-----------------------------------------------------------------------------
// Constructor

CPatcher_WindowPosition::CPatcher_WindowPosition(void)
{
	patchname = "Window Position";

	LPBYTE addrCreateWindowExW = CAddr::Addr(win32_CreateWindowExW);
	if (!addrCreateWindowExW) {
		WriteLog("Patch initialization failed: %s.\n", patchname.c_str());
		WriteLog("   Missing dependency.\n");
		return;
	}

	vector<WORD> patch;
	vector<WORD> backup;

	backup +=
		0xFF, 0x75, 0x34, 0xFF, 0x75, 0x30, 0xFF,
		0x75, 0x2C, 0xFF, 0x75, 0x28, 0xFF, 0x75,
		0x24, 0xFF, 0x75, 0x20, 0xFF, 0x75, 0x1C,
		0xFF, 0x75, 0x18, 0xFF, 0x75, 0x14, 0xFF, 0x75,
		0x10, 0xFF, 0x75, 0x0C, 0xFF, 0x75, 0x08,
		0xFF, 0x15, -1, -1, -1, -1,
		0xE9, -1, -1, -1, -1,
		0x8B, 0x7D, 0x10;	// NOP

	patch +=
		-1, -1, -1, -1, -1, -1, -1,
		-1, -1, -1, -1, -1, -1, -1,
		-1, -1, -1, -1, -1, -1, -1,
		-1, -1, -1, -1, -1, -1, -1, -1,
		-1, -1, -1, -1, -1, -1, -1,
		0x90, 0xE8, 0x01FF, 0x01FF, 0x01FF, 0x01FF,
		-1, -1, -1, -1, -1,
		-1, -1, -1;

	MemoryPatch mp(addrCreateWindowExW, patch, backup);

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

bool CPatcher_WindowPosition::ReadINI(void)
{
	if (ReadINI_Bool(L"WindowPosition"))
		return Install();
	return true;
}

bool CPatcher_WindowPosition::WriteINI(void)
{
	WriteINI_Bool(L"WindowPosition", IsInstalled());
	return true;
}