#include "Patcher_MoveToSameChannel.h"
#include "../Addr.h"
#include "../FileSystem.h"

//-----------------------------------------------------------------------------
// Constructor

CPatcher_MoveToSameChannel::CPatcher_MoveToSameChannel( void )
{
	patchname = "Move To Same Channel";

	vector<WORD> patch;
	vector<WORD> backup;

	backup +=
		0x83, 0xC0, 0x0C,					// + E9: ADD EAX, 0Ch
		0x50,								// + EC: PUSH EAX
		0xE8, -1, -1, -1, -1,				// + ED: CALL xxxxxxxx
		0x84, 0xC0,							// + F2: TEST AL, AL
		0x59, 0x59,							// + F4: POP ECX (x2)
		0x0F, 0x84, 0x8C, 0x00, 0x00, 0x00,	// + F6: JZ NEAR +0x8C
		0x68, -1, -1, -1, -1,				// + FC: PUSH OFFSET xxxxxxxx
		0x8D, 0x4D, 0xE0;					// +101: LEA ECX, [EBP-20h]
	patch +=
		-1, -1, -1,
		-1,
		-1, -1, -1, -1, -1,
		-1, -1,
		-1, -1,
		0x90, 0xE9, -1, -1, -1, -1,			// + F6: JZ NEAR +0x8C => NOP, JMP NEAR +0x8C
		-1, -1, -1, -1, -1,
		-1, -1, -1;

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

bool CPatcher_MoveToSameChannel::ReadINI( void )
{
	if ( ReadINI_Bool( L"MoveToSameChannel" ))
		return Install();
	return true;
}

bool CPatcher_MoveToSameChannel::WriteINI( void )
{
	WriteINI_Bool( L"MoveToSameChannel", IsInstalled() );
	return true;
}