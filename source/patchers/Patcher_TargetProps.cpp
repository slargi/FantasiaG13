#include "Patcher_TargetProps.h"
#include "../Addr.h"
#include "../FileSystem.h"

//-----------------------------------------------------------------------------
// Static variable initialization

wchar_t CPatcher_TargetProps::dataStr[] = L"enemy|prop";

//-----------------------------------------------------------------------------
// Constructor

CPatcher_TargetProps::CPatcher_TargetProps( void )
{
	patchname = "Target Props";

	vector<WORD> patch;
	vector<WORD> backup;

	backup +=
		0x8D, 0x4D, 0xD0,					// +1D1: LEA ECX, [EBP-24]
		0x83, 0xF8, 0x01,					// +1D4: CMP eax, 1
		0x75, 0x07,							// +1D7: JNZ SHORT +0x07
		0x68, -1, -1, -1, -1,				// +1D9: PUSH OFFSET xxxxxxxx ("enemy")
		0xEB, 0x05;							// +1DD: JMP SHORT +0x05
	patch +=
		-1, -1, -1,
		-1, -1, -1,
		-1, -1,
		-1, 0x01FF, 0x01FF, 0x01FF, 0x01FF,	// +1D6: PUSH OFFSET dataStr
		-1, -1;
	MemoryPatch mp( NULL, patch, backup );
	mp.Search( L"Pleione.dll" );
	mp.PatchExactAddress( 0x01, (LPBYTE)(&dataStr) );
	
	patches += mp;
	if (CheckPatches())
		WriteLog("Patch initialization successful: %s.\n", patchname.c_str());
	else
		WriteLog("Patch initialization failed: %s.\n", patchname.c_str());
}

//-----------------------------------------------------------------------------
// INI Functions

bool CPatcher_TargetProps::ReadINI( void )
{
	if ( ReadINI_Bool( L"TargetProps" ))
		return Install();
	return true;
}

bool CPatcher_TargetProps::WriteINI( void )
{
	WriteINI_Bool( L"TargetProps", IsInstalled() );
	return true;
}