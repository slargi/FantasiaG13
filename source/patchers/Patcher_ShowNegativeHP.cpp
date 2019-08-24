#include "Patcher_ShowNegativeHP.h"
#include "../Addr.h"
#include "../FileSystem.h"

//-----------------------------------------------------------------------------
// Static variable initialization

//-----------------------------------------------------------------------------
// Constructor

CPatcher_ShowNegativeHP::CPatcher_ShowNegativeHP(void)
{
	patchname = "Show Negative HP";

	vector<WORD> patch;
	vector<WORD> backup;

	backup +=
		0x7D, 0x03;	// NOP

	patch +=
		0xEB, -1;	// NOP => NOP

	MemoryPatch mp((LPBYTE)(0x63AC9E84), patch, backup);

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

bool CPatcher_ShowNegativeHP::ReadINI(void)
{
	if (ReadINI_Bool(L"ShowNegativeHP"))
		return Install();
	return true;
}

bool CPatcher_ShowNegativeHP::WriteINI(void)
{
	WriteINI_Bool(L"ShowNegativeHP", IsInstalled());
	return true;
}