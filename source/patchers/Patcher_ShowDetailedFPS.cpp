#include "Patcher_ShowDetailedFPS.h"
#include "../Addr.h"
#include "../FileSystem.h"

//-----------------------------------------------------------------------------
// Static variable initialization

//-----------------------------------------------------------------------------
// Constructor

CPatcher_ShowDetailedFPS::CPatcher_ShowDetailedFPS(void)
{
	patchname = "ShowDetailedFPS";

	vector<WORD> patch;
	vector<WORD> backup;

	backup +=
		0x0F, 0x84, 0xB2, 0x05, 0x00, 0x00, 0x8B, 0x45, 0xC4;

	patch +=
		0x90, 0x90, 0x90, 0x90, 0x90, 0x90, -1, -1, -1;	// NOP => NOP

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

bool CPatcher_ShowDetailedFPS::ReadINI(void)
{
	if (ReadINI_Bool(L"ShowDetailedFPS"))
		return Install();
	return true;
}

bool CPatcher_ShowDetailedFPS::WriteINI(void)
{
	WriteINI_Bool(L"ShowDetailedFPS", IsInstalled());
	return true;
}