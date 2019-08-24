#include "Patcher_TalkToUnequippedEgo.h"
#include "../Addr.h"
#include "../FileSystem.h"

//-----------------------------------------------------------------------------
// Constructor

CPatcher_TalkToUnequippedEgo::CPatcher_TalkToUnequippedEgo( void )
{
	patchname = "Talk To Unequipped Ego";

	vector<WORD> patch;
	vector<WORD> backup;

	backup +=
		0x84, 0xC0,							// +5B: TEST AL, AL
		0x0F, 0x85, 0x83, 0x00, 0x00, 0x00,	// +5D: JNZ NEAR +0x83
		0x68, -1, -1, -1, -1,				// +63: PUSH OFFSET xxxxxxxx (code.client.msg.equip_ego_weapon_request)
		0x8D, 0x4D, 0xEC;					// +68: LEA ECX, [EBP-14]
	patch +=
		-1, -1,
		0x90, 0xE9, -1, -1, -1, -1,			// +5D: JNZ => NOP, JMP
		-1, -1, -1, -1, -1,	-1, -1, -1;

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

bool CPatcher_TalkToUnequippedEgo::ReadINI( void )
{
	if ( ReadINI_Bool( L"TalkToUnequippedEgo" ))
		return Install();
	return true;
}

bool CPatcher_TalkToUnequippedEgo::WriteINI( void )
{
	WriteINI_Bool( L"TalkToUnequippedEgo", IsInstalled() );
	return true;
}