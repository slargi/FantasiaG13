#include "Patcher_MoveWhileTalking.h"
#include "../Addr.h"
#include "../FileSystem.h"

//-----------------------------------------------------------------------------
// Constructor

CPatcher_MoveWhileTalking::CPatcher_MoveWhileTalking( void )
{
	patchname = "Move While Talking";
    
	vector<WORD> patch;
	vector<WORD> backup;

	backup +=
		0x56,								// +00: PUSH ESI
		0x8B, 0xF1,	0x8B,					// +01: MOV ESI, ECX
		0x06, 0xFF, 0x50, 0x14, 0x84,		// +03: CALL xxxxxxxx
		0xC0, 0x74, 0x18, 0x8B,				// +08: CMP DWORD PTR [EAX+4Ch], 0
		0x46, 0x04,							// +0C: JZ SHORT +13h
		0x8B, 0x88,							// +0E: MOV EAX, [ESI]
		0x88,							// +10: MOV ECX, ESI
		0x00, 0x00, 0x00, 0x90,
		0xE8, -1, -1, -1, -1;
	patch +=
		-1,
		-1, -1, -1,
		-1, -1, -1, -1, -1,
		-1, -1, -1, -1,
		0xEB, -1,
		-1, -1,
		-1,
		-1, -1, -1, -1,
		-1, -1, -1, -1, -1;

	MemoryPatch mp( NULL, patch, backup );
	mp.Search( L"Pleione.dll" );
	
	patches += mp;
	if (CheckPatches())
		WriteLog("Patch initialization successful: %s.\n", patchname.c_str());
	else
		WriteLog("Patch initialization failed: %s.\n", patchname.c_str());
}

//-----------------------------------------------------------------------------
// INI Functions

bool CPatcher_MoveWhileTalking::ReadINI( void )
{
	if ( ReadINI_Bool( L"MoveWhileTalking" ))
		return Install();
	return true;
}

bool CPatcher_MoveWhileTalking::WriteINI( void )
{
	WriteINI_Bool( L"MoveWhileTalking", IsInstalled() );
	return true;
}