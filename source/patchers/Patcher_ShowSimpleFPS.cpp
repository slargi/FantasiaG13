#include "Patcher_ShowSimpleFPS.h"
#include "../Addr.h"
#include "../FileSystem.h"

//-----------------------------------------------------------------------------
// Static variable initialization

//-----------------------------------------------------------------------------
// Constructor

CPatcher_ShowSimpleFPS::CPatcher_ShowSimpleFPS(void)
{
	patchname = "Show Simple FPS";

	vector<WORD> patch;
	vector<WORD> backup;

	backup +=
		0x0F, 0x84, 0x56, 0x02, 0x00, 0x00, 0x8B, 0x45, 0xE0;

	patch +=
		0x90, 0x90, 0x90, 0x90, 0x90, 0x90, -1, -1, -1;

	MemoryPatch mp( NULL, patch, backup);
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

bool CPatcher_ShowSimpleFPS::ReadINI(void)
{
	if (ReadINI_Bool(L"ShowSimpleFPS"))
		return Install();
	return true;
}

bool CPatcher_ShowSimpleFPS::WriteINI(void)
{
	WriteINI_Bool(L"ShowSimpleFPS", IsInstalled());
	return true;
}