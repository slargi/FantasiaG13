#include "Patcher_DetectUnpack.h"
#include "../Addr.h"
#include "../FileSystem.h"

//-----------------------------------------------------------------------------
// Static variable initialization
LPBYTE addrSetLookUpOrder = NULL;
LPBYTE StartPatching = NULL;
//-----------------------------------------------------------------------------
// Constructor

CPatcher_DetectUnpack::CPatcher_DetectUnpack(void)
{
	patchname = "Detect Unpack";

	addrSetLookUpOrder = CAddr::Addr(CFileSystem_SetLookUpOrder);
	if (!addrSetLookUpOrder) {
		WriteLog("Patch initialization failed: %s.\n", patchname.c_str());
		WriteLog("   Missing dependency.\n");
		return;
	}

	vector<WORD> patch;
	vector<WORD> backup;

	backup +=
		0x6A, 0x0C,
		0xB8, -1, -1, -1, -1;

	patch +=
		0xE9, 0x01FF, 0x01FF, 0x01FF, 0x01FF,
		0x90, 0x90;

	MemoryPatch mp(addrSetLookUpOrder, patch, backup);
	mp.PatchRelativeAddress(0x01, (LPBYTE)Detection);

	patches += mp;
	if (CheckPatches())
		WriteLog("Patch initialization successful: %s.\n", patchname.c_str());
	else
		WriteLog("Patch initialization failed: %s.\n", patchname.c_str());
}

//-----------------------------------------------------------------------------
// Hook functions
NAKED void CPatcher_DetectUnpack::Detection(void)
{
	__asm {
		pushad
		call StartPatching
		popad
		jmp addrSetLookUpOrder
	}
}

//-----------------------------------------------------------------------------
// INI Functions

bool CPatcher_DetectUnpack::StartDetection(LPBYTE addr)
{
	StartPatching = addr;
	return Install();
}

bool CPatcher_DetectUnpack::ReadINI(void)
{
	if (ReadINI_Bool(L"DetectUnpack"))
		return Install();
	return true;
}

bool CPatcher_DetectUnpack::WriteINI(void)
{
	WriteINI_Bool(L"DetectUnpack", IsInstalled());
	return true;
}