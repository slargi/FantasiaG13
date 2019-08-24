#include "Patcher_DisableScreenShake.h"
#include "../Addr.h"
#include "../FileSystem.h"

//-----------------------------------------------------------------------------
// Static variable initialization

//-----------------------------------------------------------------------------
// Constructor

CPatcher_DisableScreenShake::CPatcher_DisableScreenShake(void)
{
	patchname = "Disable Screen Shake";

	LPBYTE addrEnableVibrate = CAddr::Addr(CCamera_EnableVibrate);
	if (!addrEnableVibrate) {
		WriteLog("Patch initialization failed: %s.\n", patchname.c_str());
		WriteLog("   Missing dependency.\n");
		return;
	}

	vector<WORD> patch;
	vector<WORD> backup;

	backup +=
		0xD9, 0x04, 0x30;

	patch +=
		-1, 0xEE, 0x90;

	MemoryPatch mp(addrEnableVibrate + 0x2C, patch, backup);

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

bool CPatcher_DisableScreenShake::ReadINI(void)
{
	if (ReadINI_Bool(L"DisableScreenShake"))
		return Install();
	return true;
}

bool CPatcher_DisableScreenShake::WriteINI(void)
{
	WriteINI_Bool(L"DisableScreenShake", IsInstalled());
	return true;
}