#include "Patcher_ShowNegativeStats.h"
#include "../Addr.h"
#include "../FileSystem.h"

//-----------------------------------------------------------------------------
// Static variable initialization

//-----------------------------------------------------------------------------
// Constructor

CPatcher_ShowNegativeStats::CPatcher_ShowNegativeStats(void)
{
	patchname = "Show Negative Stats";

	LPBYTE addrGetStrength = CAddr::Addr(IParameter_GetStrength);
	LPBYTE addrGetDexterity = CAddr::Addr(IParameter_GetDexterity);
	LPBYTE addrGetIntelligence = CAddr::Addr(IParameter_GetIntelligence);
	LPBYTE addrGetWill = CAddr::Addr(IParameter_GetWill);
	LPBYTE addrGetLuck = CAddr::Addr(IParameter_GetLuck);
	if (!addrGetStrength ||
		!addrGetDexterity ||
		!addrGetIntelligence ||
		!addrGetWill ||
		!addrGetLuck) {
		WriteLog("Patch initialization failed: %s.\n", patchname.c_str());
		WriteLog("   Missing dependency.\n");
		return;
	}

	// Strength Patch
	vector<WORD> patch1;
	vector<WORD> backup1;

	backup1 +=
		0x74, 0x05, 0xDD, 0xD8, 0xD9, 0x45, 0xFC;

	patch1 +=
		0x90, 0x90, -1, -1, -1, -1, -1;

	MemoryPatch mp1(addrGetStrength + 0x35, patch1, backup1);

	// Dexterity Patch
	vector<WORD> patch2;
	vector<WORD> backup2;

	backup2 +=
		0x74, 0x05, 0xDD, 0xD8, 0xD9, 0x45, 0xFC;

	patch2 +=
		0x90, 0x90, -1, -1, -1, -1, -1;

	MemoryPatch mp2(addrGetDexterity + 0x35, patch2, backup2);

	// Intelligence Patch
	vector<WORD> patch3;
	vector<WORD> backup3;

	backup3 +=
		0x74, 0x05, 0xDD, 0xD8, 0xD9, 0x45, 0xFC;

	patch3 +=
		0x90, 0x90, -1, -1, -1, -1, -1;

	MemoryPatch mp3(addrGetIntelligence + 0x35, patch3, backup3);

	// Will Patch
	vector<WORD> patch4;
	vector<WORD> backup4;

	backup4 +=
		0x74, 0x05, 0xDD, 0xD8, 0xD9, 0x45, 0xFC;

	patch4 +=
		0x90, 0x90, -1, -1, -1, -1, -1;

	MemoryPatch mp4(addrGetWill + 0x56, patch4, backup4);

	// Luck Patch
	vector<WORD> patch5;
	vector<WORD> backup5;

	backup5 +=
		0x74, 0x05, 0xDD, 0xD8, 0xD9, 0x45, 0xFC;

	patch5 +=
		0x90, 0x90, -1, -1, -1, -1, -1;

	MemoryPatch mp5(addrGetLuck + 0x85, patch5, backup5);

	patches += mp1;
	patches += mp2;
	patches += mp3;
	patches += mp4;
	patches += mp5;
	if (CheckPatches())
		WriteLog("Patch initialization successful: %s.\n", patchname.c_str());
	else
		WriteLog("Patch initialization failed: %s.\n", patchname.c_str());
}

//-----------------------------------------------------------------------------
// Hook functions

//-----------------------------------------------------------------------------
// INI Functions

bool CPatcher_ShowNegativeStats::ReadINI(void)
{
	if (ReadINI_Bool(L"ShowNegativeStats"))
		return Install();
	return true;
}

bool CPatcher_ShowNegativeStats::WriteINI(void)
{
	WriteINI_Bool(L"ShowNegativeStats", IsInstalled());
	return true;
}