#include "Patcher_NoChannelMoveDenial.h"
#include "../Addr.h"
#include "../FileSystem.h"

//-----------------------------------------------------------------------------
// Static variable initialization

//-----------------------------------------------------------------------------
// Constructor

CPatcher_NoChannelMoveDenial::CPatcher_NoChannelMoveDenial(void)
{
	patchname = "No Channel Move Denial";

	LPBYTE addrXXX = CAddr::Addr(kernel32_CreateRemoteThread);
	if (!addrXXX) {
		WriteLog("Patch initialization failed: %s.\n", patchname.c_str());
		WriteLog("   Missing dependency.\n");
		return;
	}

	vector<WORD> patch;
	vector<WORD> backup;

	backup +=
		0x3B, 0xF3, 0x0F, 0x84, 0x16, 0x02, 0x00, 0x00, 0x8D, 0x4D, 0xF0, 0x90;	// NOP

	patch +=
		-1, -1, 0x90, 0xE9, -1, -1, -1, -1, -1, -1, -1, -1;	// NOP => NOP

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

bool CPatcher_NoChannelMoveDenial::ReadINI(void)
{
	if (ReadINI_Bool(L"NoChannelMoveDenial"))
		return Install();
	return true;
}

bool CPatcher_NoChannelMoveDenial::WriteINI(void)
{
	WriteINI_Bool(L"NoChannelMoveDenial", IsInstalled());
	return true;
}