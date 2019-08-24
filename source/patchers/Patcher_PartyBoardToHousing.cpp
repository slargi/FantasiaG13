#include "Patcher_PartyBoardToHousing.h"
#include "../Addr.h"
#include "../FileSystem.h"

//-----------------------------------------------------------------------------
// Static variable initialization

//-----------------------------------------------------------------------------
// Constructor

CPatcher_PartyBoardToHousing::CPatcher_PartyBoardToHousing(void)
{
	patchname = "Party Board To Housing";


	// Party Board
	vector<WORD> patch1;
	vector<WORD> backup1;

	backup1 +=
		0xE8, 0xE1, 0x20, 0x21, 0x00, 0xE9, 0x31, 0x02, 0x00, 0x00;

	patch1 +=
		-1, 0xC0, 0xE7, 0x0A, -1, -1, -1, -1, -1, -1;

	MemoryPatch mp1( NULL, patch1, backup1);
	mp1.Search(L"Pleione.dll");

	// Party Button 1
	vector<WORD> patch2;
	vector<WORD> backup2;

	backup2 +=
		0xE8, 0xA7, 0xE0, 0xF6, 0xFF, 0xEB, 0x07;

	patch2 +=
		-1, 0x86, 0xA7, 0xE0, -1, -1, -1;

	MemoryPatch mp2(NULL, patch2, backup2);
	mp2.Search(L"Pleione.dll");

	// Party Button 2
	vector<WORD> patch3;
	vector<WORD> backup3;

	backup3 +=
		0xE8, 0x2F, 0x10, 0xF7, 0xFF, 0xE9, 0x4C, 0x03, 0x00, 0x00;

	patch3 +=
		-1, 0x0E, 0xD7, 0xE0, -1, -1, -1, -1, -1, -1;

	MemoryPatch mp3(NULL, patch3, backup3);
	mp3.Search(L"Pleione.dll");

	patches += mp1;
	patches += mp2;
	patches += mp3;
	if (CheckPatches())
		WriteLog("Patch initialization successful: %s.\n", patchname.c_str());
	else
		WriteLog("Patch initialization failed: %s.\n", patchname.c_str());
}

//-----------------------------------------------------------------------------
// Hook functions

//-----------------------------------------------------------------------------
// INI Functions

bool CPatcher_PartyBoardToHousing::ReadINI(void)
{
	if (ReadINI_Bool(L"PartyBoardToHousing"))
		return Install();
	return true;
}

bool CPatcher_PartyBoardToHousing::WriteINI(void)
{
	WriteINI_Bool(L"PartyBoardToHousing", IsInstalled());
	return true;
}