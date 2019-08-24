#include "Patcher_ElfLagFix.h"
#include "../Addr.h"
#include "../FileSystem.h"

//-----------------------------------------------------------------------------
// Static variable initialization

//-----------------------------------------------------------------------------
// Constructor

CPatcher_ElfLagFix::CPatcher_ElfLagFix(void)
{
	patchname = "Elf Lag Fix";

	LPBYTE addrIsEnableMovingAim = CAddr::Addr(ISkillMgr_IsEnableMovingAim);
	if (!addrIsEnableMovingAim) {
		WriteLog("Patch initialization failed: %s.\n", patchname.c_str());
		WriteLog("   Missing dependency.\n");
		return;
	}

	vector<WORD> patch;
	vector<WORD> backup;

	backup +=
		0x56, 0x8B, 0xF1, 0x8B, 0x06;

	patch +=
		0x30, 0xC0, 0xC2, 0x04, 0x00;

	MemoryPatch mp(addrIsEnableMovingAim, patch, backup);

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

bool CPatcher_ElfLagFix::ReadINI(void)
{
	if (ReadINI_Bool(L"ElfLagFix"))
		return Install();
	return true;
}

bool CPatcher_ElfLagFix::WriteINI(void)
{
	WriteINI_Bool(L"ElfLagFix", IsInstalled());
	return true;
}