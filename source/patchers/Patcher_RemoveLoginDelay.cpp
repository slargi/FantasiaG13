#include "Patcher_RemoveLoginDelay.h"
#include "../Addr.h"
#include "../FileSystem.h"

/* Remove Login Delay
 * Removes the 30-second login delay after disconnecting.
 * PATCHES: Pleione.dll
 */

//-----------------------------------------------------------------------------
// Constructor

CPatcher_RemoveLoginDelay::CPatcher_RemoveLoginDelay( void )
{
	patchname = "Remove Login Delay";

	vector<WORD> patch;
	vector<WORD> backup;

	backup +=
		0x8B, 0xF1,						// +0C: MOV ESI, ECX
		0x89, 0x75, 0xDC,				// +0E: MOV [EBP-24h], ESI
		0x80, 0x7D, 0x08, 0x00,			// +11: CMP BYTE PTR [EBP+08h], 0
		0x0F, 0x84, -1, -1, -1, -1,		// +15: JZ xxxxxxxx
		0x83, 0x7E, 0x0C, 0x00,			// +1B: CMP DWORD PTR [ESI+0Ch], 0
		0x0F, 0x85, -1, -1, -1, -1,		// +1F: JNZ xxxxxxxx
		0x8B, 0x0D, -1, -1, -1, -1;	// +25: PUSH 1A0h

	patch +=
		-1, -1,
		-1, -1, -1,
		-1, -1, -1, -1,
		0x90, 0xE9, -1, -1, -1, -1,		// +15: NOP, JMP xxxxxxxx
		-1, -1, -1, -1,
		-1, -1, -1, -1, -1, -1,
		-1, -1, -1, -1, -1, -1;

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

bool CPatcher_RemoveLoginDelay::ReadINI( void )
{
	if ( ReadINI_Bool( L"RemoveLoginDelay" ))
		return Install();
	return true;
}

bool CPatcher_RemoveLoginDelay::WriteINI( void )
{
	WriteINI_Bool( L"RemoveLoginDelay", IsInstalled() );
	return true;
}