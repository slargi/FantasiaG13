#include "Patcher_EnableNPCEquipView.h"
#include "../Addr.h"
#include "../FileSystem.h"

//-----------------------------------------------------------------------------
// Static variable initialization

//-----------------------------------------------------------------------------
// Constructor

CPatcher_EnableNPCEquipView::CPatcher_EnableNPCEquipView(void)
{
	patchname = "EnableNPCEquipView";

	vector<WORD> patch;
	vector<WORD> backup;

	backup +=
		0x0F, 0x85, 0xEE, 0x00, 0x00, 0x00;

	patch +=
		0x90, 0x90, 0x90, 0x90, 0x90, 0x90;

	MemoryPatch mp((LPBYTE)0x6392CDA2, patch, backup);

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

bool CPatcher_EnableNPCEquipView::ReadINI(void)
{
	if (ReadINI_Bool(L"EnableNPCEquipView"))
		return Install();
	return true;
}

bool CPatcher_EnableNPCEquipView::WriteINI(void)
{
	WriteINI_Bool(L"EnableNPCEquipView", IsInstalled());
	return true;
}