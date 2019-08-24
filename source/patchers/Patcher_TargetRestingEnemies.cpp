#include "Patcher_TargetRestingEnemies.h"
#include "../Addr.h"
#include "../FileSystem.h"

//-----------------------------------------------------------------------------
// Static variable initialization

//-----------------------------------------------------------------------------
// Constructor

CPatcher_TargetRestingEnemies::CPatcher_TargetRestingEnemies(void)
{
	patchname = "Target Resting Enemies";

	// Mimic patch
	vector<WORD> patch1;
	vector<WORD> backup1;
	backup1 +=
		0xE8, 0xE1, 0x28, 0xFA, 0xFF;

	patch1 +=
		0xB8, 0x01, 0x00, 0x00, 0x00;

	MemoryPatch mp1( NULL, patch1, backup1);
	mp1.Search(L"Standard.dll");

	// Watermelon patch
	vector<WORD> patch2;
	vector<WORD> backup2;
	backup2 +=
		0xE8, 0x65, 0x28, 0xFA, 0xFF, 0x85, 0xC0;

	patch2 +=
		0xB8, 0x01, 0x00, 0x00, 0x00, -1, -1;

	MemoryPatch mp2(NULL, patch2, backup2);
	mp2.Search(L"Standard.dll");

	// Sulfur Golem patch
	vector<WORD> patch3;
	vector<WORD> backup3;
	backup3 +=
		0xE8, 0x29, 0x28, 0xFA, 0xFF, 0x85, 0xC0;

	patch3 +=
		0xB8, 0x01, 0x00, 0x00, 0x00, -1, -1;

	MemoryPatch mp3(NULL, patch3, backup3);
	mp3.Search(L"Standard.dll");

	// Flying book patch
	vector<WORD> patch4;
	vector<WORD> backup4;
	backup4 +=
		0xE8, 0xB1, 0x27, 0xFA, 0xFF, 0x85, 0xC0;

	patch4 +=
		0xB8, 0x01, 0x00, 0x00, 0x00, -1, -1;

	MemoryPatch mp4(NULL, patch4, backup4);
	mp4.Search(L"Standard.dll");

	patches += mp1;
	patches += mp2;
	patches += mp3;
	patches += mp4;
	if (CheckPatches())
		WriteLog("Patch initialization successful: %s.\n", patchname.c_str());
	else
		WriteLog("Patch initialization failed: %s.\n", patchname.c_str());
}

//-----------------------------------------------------------------------------
// Hook functions

//-----------------------------------------------------------------------------
// INI Functions

bool CPatcher_TargetRestingEnemies::ReadINI(void)
{
	if (ReadINI_Bool(L"TargetRestingEnemies"))
		return Install();
	return true;
}

bool CPatcher_TargetRestingEnemies::WriteINI(void)
{
	WriteINI_Bool(L"TargetRestingEnemies", IsInstalled());
	return true;
}