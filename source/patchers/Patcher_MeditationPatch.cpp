#include "Patcher_MeditationPatch.h"
#include "../Addr.h"
#include "../FileSystem.h"

//-----------------------------------------------------------------------------
// Static variable initialization
//-----------------------------------------------------------------------------
// Constructor

CPatcher_MeditationPatch::CPatcher_MeditationPatch(void)
{
	patchname = "MeditationPatch";

	LPBYTE addrFindConditionId = CAddr::Addr(CConditionDescMgr_FindConditionID);
	LPBYTE addrLoadData = CAddr::Addr(CConditionDescMgr_LoadData);
	LPBYTE addrLoadXML = CAddr::Addr(CConditionDescMgr_LoadXML);
	LPBYTE addrGetConditionNum = CAddr::Addr(IConditionMgr_GetConditionNum);
	LPBYTE addrWriteToDB = CAddr::Addr(IConditionMgr_WriteToDB);
	LPBYTE addrWriteToFile = CAddr::Addr(IConditionMgr_WriteToFile);
	LPBYTE addrWriteMsgFast = CAddr::Addr(IConditionMgr_WriteMsgFast);
	LPBYTE addrUpdate = CAddr::Addr(IConditionMgr_Update);
	if (!addrFindConditionId ||
		!addrLoadData ||
		!addrLoadXML ||
		!addrGetConditionNum ||
		!addrWriteToDB ||
		!addrWriteToFile ||
		!addrWriteMsgFast ||
		!addrUpdate) {
		WriteLog("Patch initialization failed: %s.\n", patchname.c_str());
		WriteLog("   Missing dependency.\n");
		return;
	}

	// FindConditionID first patch
	vector<WORD> patch;
	vector<WORD> backup;

	backup +=
		0xB8, 0xA1, 0x00, 0x00, 0x00;

	patch +=
		-1, 0xA2, -1, -1, -1, -1;

	MemoryPatch mp(addrFindConditionId+0x16, patch, backup);

	// LoadData second patch
	vector<WORD> patch1;
	vector<WORD> backup1;

	backup1 +=
		0x3D, 0xA1, 0x00, 0x00, 0x00;

	patch1 +=
		-1, 0xA2, -1, -1, -1, -1;

	MemoryPatch mp1(addrLoadData + 0x357, patch1, backup1);

	// LoadXML third patch
	vector<WORD> patch2;
	vector<WORD> backup2;

	backup2 +=
		0x81, 0x7D, 0x68, 0xA1, 0x00, 0x00, 0x00;

	patch2 +=
		-1, -1, -1, 0xA2, -1, -1, -1;

	MemoryPatch mp2(addrLoadXML + 0x590, patch2, backup2);

	// Item equip desc? fourth patch (sub_10054927)
	vector<WORD> patch3;
	vector<WORD> backup3;

	backup3 +=
		0xC7, 0x40, 0x04, 0xA1, 0x00, 0x00, 0x00;

	patch3 +=
		-1, -1, -1, 0xA2, -1, -1, -1;

	MemoryPatch mp3(NULL, patch3, backup3);
	mp3.Search(L"Standard.dll");

	// GetConditionNum fifth patch
	vector<WORD> patch4;
	vector<WORD> backup4;

	backup4 +=
		0x81, 0xFE, 0xA1, 0x00, 0x00, 0x00;

	patch4 +=
		-1, -1, 0xA2, -1, -1, -1;

	MemoryPatch mp4(addrGetConditionNum + 0x17, patch4, backup4);

	// WriteToDB sixth patch
	vector<WORD> patch5;
	vector<WORD> backup5;

	backup5 +=
		0x80, 0x7D, 0xE4, 0xA1;

	patch5 +=
		-1, -1, -1, 0xA2;

	MemoryPatch mp5(addrWriteToDB + 0x223, patch5, backup5);

	// WriteToFile seventh patch
	vector<WORD> patch6;
	vector<WORD> backup6;

	backup6 +=
		0x80, 0x7D, 0xF0, 0xA1;

	patch6 +=
		-1, -1, -1, 0xA2;

	MemoryPatch mp6(addrWriteToFile + 0x6E, patch6, backup6);

	// WriteMsgFast eigth patch
	vector<WORD> patch7;
	vector<WORD> backup7;

	backup7 +=
		0x81, 0xFF, 0xA1, 0x00, 0x00, 0x00;

	patch7 +=
		-1, -1, 0xA2, -1, -1, -1;

	MemoryPatch mp7(addrWriteMsgFast + 0xBF, patch7, backup7);

	// Update ninth patch pt 1
	vector<WORD> patch8;
	vector<WORD> backup8;

	backup8 +=
		0xC7, 0x45, 0xE4, 0xA1, 0x00, 0x00, 0x00;

	patch8 +=
		-1, -1, -1, 0xA2, -1, -1, -1;

	MemoryPatch mp8(addrUpdate + 0x5A, patch8, backup8);

	// Update ninth patch pt 2
	vector<WORD> patch9;
	vector<WORD> backup9;

	backup9 +=
		0x3D, 0xA1, 0x00, 0x00, 0x00;

	patch9 +=
		-1, 0xA2, -1, -1, -1;

	MemoryPatch mp9(addrUpdate + 0xCB, patch9, backup9);

	// Update ninth patch pt 3
	vector<WORD> patch10;
	vector<WORD> backup10;

	backup10 +=
		0x81, 0xFB, 0xA1, 0x00, 0x00, 0x00;

	patch10 +=
		-1, -1, 0xA2, -1, -1, -1;

	MemoryPatch mp10(addrUpdate + 0x1E5, patch10, backup10);

	// Pleione CConditionMgr::Update Patch
	vector<WORD> patch11;
	vector<WORD> backup11;

	backup11 +=
		0x81, 0xFB, 0xA1, 0x00, 0x00, 0x00;

	patch11 +=
		-1, -1, 0xA2, -1, -1, -1;

	MemoryPatch mp11((LPBYTE)0x63916876, patch11, backup11);

	patches += mp;
	patches += mp1;
	patches += mp2;
	patches += mp3;
	patches += mp4;
	patches += mp5;
	patches += mp6;
	patches += mp7;
	patches += mp8;
	patches += mp9;
	patches += mp10;
	patches += mp11;
	if (CheckPatches())
		WriteLog("Patch initialization successful: %s.\n", patchname.c_str());
	else
		WriteLog("Patch initialization failed: %s.\n", patchname.c_str());
}

//-----------------------------------------------------------------------------
// Hook functions

//-----------------------------------------------------------------------------
// INI Functions

bool CPatcher_MeditationPatch::ReadINI(void)
{
	if (ReadINI_Bool(L"MeditationPatch"))
		return Install();
	return true;
}

bool CPatcher_MeditationPatch::WriteINI(void)
{
	WriteINI_Bool(L"MeditationPatch", IsInstalled());
	return true;
}