#include "Patcher_EnableSelfRightClick.h"
#include "../Addr.h"
#include "../FileSystem.h"

//-----------------------------------------------------------------------------
// Constructor

CPatcher_EnableSelfRightClick::CPatcher_EnableSelfRightClick( void )
{
	patchname = "Enable Self Right-Click";

	vector<WORD> patch;
	vector<WORD> backup;

	backup +=
		0x0F, 0x85, 0x1A, 0x02, 0x00, 0x00,		// +33: JNZ NEAR +212h
		0x3B, 0x55, 0x0C,						// +39: CMP EDX, [EBP+0Ch]
		0x0F, 0x85, 0x11, 0x02, 0x00, 0x00;		// +3C: JNZ NEAR +209h

	patch +=
		0x90, 0xE9, -1, -1, -1, -1,	// +33: JNZ => NOP, JMP
		-1, -1, -1,
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

bool CPatcher_EnableSelfRightClick::ReadINI( void )
{
	if ( ReadINI_Bool( L"EnableSelfRightClick" ))
		return Install();
	return true;
}

bool CPatcher_EnableSelfRightClick::WriteINI( void )
{
	WriteINI_Bool( L"EnableSelfRightClick", IsInstalled() );
	return true;
}