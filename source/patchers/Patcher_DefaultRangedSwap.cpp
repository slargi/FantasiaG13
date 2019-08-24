#include "Patcher_DefaultRangedSwap.h"
#include "../Addr.h"
#include "../FileSystem.h"
#include <string>

//-----------------------------------------------------------------------------
// Static variable initialization
unsigned short CPatcher_DefaultRangedSwap::swapValue = 0;
LPBYTE CPatcher_DefaultRangedSwap::addrTargetReturn = NULL;
//-----------------------------------------------------------------------------
// Constructor

CPatcher_DefaultRangedSwap::CPatcher_DefaultRangedSwap(void)
{
	patchname = "Default Ranged Swap";

	LPBYTE addrGetBasicRangedAttackSkill = CAddr::Addr(ISkillMgr_GetBasicRangedAttackSkill);
	if (!addrGetBasicRangedAttackSkill) {
		WriteLog("Patch initialization failed: %s.\n", patchname.c_str());
		WriteLog("   Missing dependency.\n");
		return;
	}

	vector<WORD> backup;
	vector<WORD> patch;

	backup +=
		0xB8, 0x12, 0x52, 0x00, 0x00, 0x75, 0x03, 0x83, 0xC0, 0xF7;

	patch +=
		0xE9, 0x01FF, 0x01FF, 0x01FF, 0x01FF, 0x90, 0x90, 0x90, 0x90, 0x90;
	
	MemoryPatch mp(addrGetBasicRangedAttackSkill + 0x0E, patch, backup);
	mp.PatchRelativeAddress(0x01, (LPBYTE)ModifySwap);
	addrTargetReturn = addrGetBasicRangedAttackSkill + 0x18;

	patches += mp;
	if (CheckPatches())
		WriteLog("Patch initialization successful: %s.\n", patchname.c_str());
	else
		WriteLog("Patch initialization failed: %s.\n", patchname.c_str());
}

//-----------------------------------------------------------------------------
// Hook functions
NAKED void CPatcher_DefaultRangedSwap::ModifySwap() {
	__asm {	
		mov ax,0x5212
		jne ModifyRetn
		sub ax,swapValue
	ModifyRetn:
		jmp addrTargetReturn
	}
}

bool CPatcher_DefaultRangedSwap::SetSwap(int num) {
	if (patches.empty()) return false;
	switch (num) {
		// Magnum Shot
		case 1:
			swapValue = 8;
			break;
		// Mari AR
		case 2:
			swapValue = 7;
			break;
		// AR
		case 3:
			swapValue = 6;
			break;
		// Support Shot
		case 4:
			swapValue = 4;
			break;
		// Mirage Missile
		case 5:
			swapValue = 3;
			break;
		// Crash Shot
		case 6:
			swapValue = -1001;
			break;
		// Ranged Attack
		default:
			swapValue = 0;
			break;
	}
	return true;
}

int CPatcher_DefaultRangedSwap::GetSwap() {
	int num = 0;
	switch (swapValue) {
		// Magnum Shot
		case 8:
			num = 1;
			break;
		// Mari AR
		case 7:
			num = 2;
			break;
		// AR
		case 6:
			num = 3;
			break;
		// Support Shot
		case 4:
			num = 4;
			break;
		// Mirage Missile
		case 3:
			num = 5;
			break;
		// Crash Shot (-1001 turns into 64535)
		case 64535:
			num = 6;
			break;
		// Ranged Attack
		default:
			num = 0;
			break;
	}
	return num;
}
//-----------------------------------------------------------------------------
// INI Functions

bool CPatcher_DefaultRangedSwap::ReadINI(void)
{
	if (ReadINI_Bool(L"DefaultRangedSwap")) {
		int tempValue = ReadINI_Int(L"DefaultRangedSwap", 0, 6);
		if (!SetSwap(tempValue))
			return false;
		return Install();
	}
	return true;
}

bool CPatcher_DefaultRangedSwap::WriteINI(void)
{
	WriteINI_Bool(L"DefaultRangedSwap", IsInstalled());
	return true;
}