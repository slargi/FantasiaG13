#include "Patcher_EnableMinimapZoom.h"
#include "../Addr.h"
#include "../FileSystem.h"

//-----------------------------------------------------------------------------
// Static variable initialization

//-----------------------------------------------------------------------------
// Constructor

CPatcher_EnableMinimapZoom::CPatcher_EnableMinimapZoom(void)
{
	patchname = "EnableMinimapZoom";

	vector<WORD> patch;
	vector<WORD> backup;

	backup +=
		0x89, 0x4E, 0x74;

	patch +=
		-1, 0x6E, -1;

	MemoryPatch mp((LPBYTE)0x6393956C, patch, backup);

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

bool CPatcher_EnableMinimapZoom::ReadINI(void)
{
	if (ReadINI_Bool(L"EnableMinimapZoom"))
		return Install();
	return true;
}

bool CPatcher_EnableMinimapZoom::WriteINI(void)
{
	WriteINI_Bool(L"EnableMinimapZoom", IsInstalled());
	return true;
}