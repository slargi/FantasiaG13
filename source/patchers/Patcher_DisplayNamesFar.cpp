#include "Patcher_DisplayNamesFar.h"
#include "../Addr.h"
#include "../FileSystem.h"

//-----------------------------------------------------------------------------
// Static variable initialization
const float VISIONRANGE = 30000;
//-----------------------------------------------------------------------------
// Constructor

CPatcher_DisplayNamesFar::CPatcher_DisplayNamesFar(void)
{
	patchname = "Display Names Far";

	//	Vision range 1
	vector<WORD> patch1;
	vector<WORD> backup1;
	backup1 +=
		0xD9, 0x05, 0x64, 0x1F, 0xDD, 0x63;

	patch1 +=
		-1, -1, ((int)(&VISIONRANGE) & 0xFF),
		(((int)(&VISIONRANGE) & 0xFF00) >> 8),
		(((int)(&VISIONRANGE) & 0xFF0000) >> 16),
		(((int)(&VISIONRANGE) & 0xFF000000) >> 24);

	MemoryPatch mp1((LPBYTE)(0x63AEF969), patch1, backup1);

	//	Vision range 2
	vector<WORD> patch2;
	vector<WORD> backup2;
	backup2 +=
		0xD9, 0x05, 0x64, 0x1F, 0xDD, 0x63;

	patch2 +=
		-1, -1, ((int)(&VISIONRANGE) & 0xFF),
		(((int)(&VISIONRANGE) & 0xFF00) >> 8),
		(((int)(&VISIONRANGE) & 0xFF0000) >> 16),
		(((int)(&VISIONRANGE) & 0xFF000000) >> 24);

	MemoryPatch mp2((LPBYTE)(0x63C3BF24), patch2, backup2);

	//	Name Transparency 1 (Props)
	vector<WORD> patch3;
	vector<WORD> backup3;
	backup3 +=
		0x7A, 0x2C;

	patch3 +=
		0xEB, -1;

	MemoryPatch mp3((LPBYTE)0x63B01BD7, patch3, backup3);

	//	Name Transparency 2 (I forgot)
	vector<WORD> patch4;
	vector<WORD> backup4;
	backup4 +=
		0x7A, 0x4D;

	patch4 +=
		0xEB, -1;

	MemoryPatch mp4((LPBYTE)0x63C3C27B, patch4, backup4);

	//	Name Transparency 3 (Player Name)
	vector<WORD> patch5;
	vector<WORD> backup5;
	backup5 +=
		0x7A, 0x73;

	patch5 +=
		0xEB, -1;

	MemoryPatch mp5((LPBYTE)0x63C3BB07, patch5, backup5);

	//	Name Transparency 4 (Guild Name)
	vector<WORD> patch6;
	vector<WORD> backup6;
	backup6 +=
		0x7A, 0x12;

	patch6 +=
		0xEB, -1;

	MemoryPatch mp6((LPBYTE)0x63C3AACF, patch6, backup6);

	// Name Transparency 5 (Item Name)
	vector<WORD> patch7;
	vector<WORD> backup7;
	backup7 +=
		0x7A, 0x2C;

	patch7 +=
		0xEB, -1;
	
	MemoryPatch mp7((LPBYTE)0x63B3AB14, patch7, backup7);

	// Name Transparency 6 (Guild Name 2)
	vector<WORD> patch8;
	vector<WORD> backup8;
	backup8 +=
		0x7A, 0x12;

	patch8 +=
		0xEB, -1;
	MemoryPatch mp8((LPBYTE)0x63C3AE23, patch8, backup8);

	// Vision Range (Item)
	vector<WORD> patch9;
	vector<WORD> backup9;
	backup9 +=
		0x74, 0x15;

	patch9 +=
		0xEB, -1;
	MemoryPatch mp9((LPBYTE)0x63B3A7B0, patch9, backup9);

	// Vision Range (Guild)
	vector<WORD> patch10;
	vector<WORD> backup10;
	backup10 +=
		0xD9, 0x05, 0x64, 0x1F, 0xDD, 0x63;

	patch10 +=
		-1, -1, ((int)(&VISIONRANGE) & 0xFF),
		(((int)(&VISIONRANGE) & 0xFF00) >> 8),
		(((int)(&VISIONRANGE) & 0xFF0000) >> 16),
		(((int)(&VISIONRANGE) & 0xFF000000) >> 24);

	MemoryPatch mp10((LPBYTE)0x63C3AAA8, patch10, backup10);

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
	if (CheckPatches())
		WriteLog("Patch initialization successful: %s.\n", patchname.c_str());
	else
		WriteLog("Patch initialization failed: %s.\n", patchname.c_str());
}

//-----------------------------------------------------------------------------
// Hook functions

//-----------------------------------------------------------------------------
// INI Functions

bool CPatcher_DisplayNamesFar::ReadINI(void)
{
	if (ReadINI_Bool(L"DisplayNamesFar"))
		return Install();
	return true;
}

bool CPatcher_DisplayNamesFar::WriteINI(void)
{
	WriteINI_Bool(L"DisplayNamesFar", IsInstalled());
	return true;
}