#include "Patcher_DisableFlashyDyes.h"
#include "../Addr.h"
#include "../FileSystem.h"

//-----------------------------------------------------------------------------
// Static variable initialization
LPBYTE CPatcher_DisableFlashyDyes::addrTargetReturn = NULL;
int CPatcher_DisableFlashyDyes::tempAddr = 0;
int CPatcher_DisableFlashyDyes::hexColorCode1 = 0;
int CPatcher_DisableFlashyDyes::hexColorCode2 = 0;
int CPatcher_DisableFlashyDyes::hexColorCode3 = 0;
int CPatcher_DisableFlashyDyes::tempDiff = 0;
//-----------------------------------------------------------------------------
// Constructor

CPatcher_DisableFlashyDyes::CPatcher_DisableFlashyDyes(void)
{
	patchname = "Disable Flashy Dyes";

	vector<WORD> patch;
	vector<WORD> backup;

	backup +=
		0x8B, 0x45, 0x18,	// mov     eax, [ebp+18]
		0x8B, 0x08;			// mov     ecx, [eax]

	patch +=
		0xE9, 0x01FF, 0x01FF, 0x01FF, 0x01FF;

	MemoryPatch mp((LPBYTE)0x638EB0FC, patch, backup);
	mp.PatchRelativeAddress(0x01, (LPBYTE)patchFlashyValue);
	addrTargetReturn = (LPBYTE)0x638EB101;

	patches += mp;
	if (CheckPatches())
		WriteLog("Patch initialization successful: %s.\n", patchname.c_str());
	else
		WriteLog("Patch initialization failed: %s.\n", patchname.c_str());
}

//-----------------------------------------------------------------------------
// Hook functions

NAKED void CPatcher_DisableFlashyDyes::patchFlashyValue()
{
	__asm {
		mov     eax, [ebp + 0x18]
		mov     ecx, [eax]
		mov		tempAddr, eax
		mov		hexColorCode1, ecx
		mov		ecx, [eax + 0x04]
		mov		hexColorCode2, ecx
		mov		ecx, [eax + 0x08]
		mov		hexColorCode3, ecx
	}

	if (hexColorCode1 >= 0x40000000 && hexColorCode1 <= 0x7F000000) {
		tempDiff = hexColorCode1 >> 24;
		tempDiff = tempDiff << 24;
		hexColorCode1 -= tempDiff;
		hexColorCode1 += 0xFF000000;
	}

	if (hexColorCode2 >= 0x40000000 && hexColorCode2 <= 0x7F000000) {
		tempDiff = hexColorCode2 >> 24;
		tempDiff = tempDiff << 24;
		hexColorCode2 -= tempDiff;
		hexColorCode2 += 0xFF000000;
	}

	if (hexColorCode3 >= 0x40000000 && hexColorCode3 <= 0x7F000000) {
		tempDiff = hexColorCode3 >> 24;
		tempDiff = tempDiff << 24;
		hexColorCode3 -= tempDiff;
		hexColorCode3 += 0xFF000000;
	}

	__asm {
		mov		ecx, hexColorCode1
		mov		eax, tempAddr
		mov		[eax], ecx
		mov		ecx, hexColorCode2
		mov		[eax+0x04], ecx
		mov		ecx, hexColorCode3
		mov		[eax+0x08], ecx
		mov     ecx, [eax]
		jmp		addrTargetReturn
	}
}

//-----------------------------------------------------------------------------
// INI Functions

bool CPatcher_DisableFlashyDyes::ReadINI(void)
{
	if (ReadINI_Bool(L"DisableFlashyDyes"))
		return Install();
	return true;
}

bool CPatcher_DisableFlashyDyes::WriteINI(void)
{
	WriteINI_Bool(L"DisableFlashyDyes", IsInstalled());
	return true;
}