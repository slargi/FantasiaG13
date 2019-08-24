#include "Patcher_LargeClockText.h"
#include "../Addr.h"
#include "../FileSystem.h"

//-----------------------------------------------------------------------------
// Static variable initialization

wchar_t CPatcher_LargeClockText::dataClockString[] = L"<large>{1}:{2} {0} </large>";

//-----------------------------------------------------------------------------
// Constructor

CPatcher_LargeClockText::CPatcher_LargeClockText( void )
{
	patchname = "Large Clock Text";

	vector<WORD> patch;
	vector<WORD> backup;

	backup +=
		0x68, -1, -1, -1, -1,						// +133: PUSH OFFSET xxxxxxxx ("{1}:{2} {0} ")
		0x8D, 0x4D, 0x50,							// +138: LEA ECX, [EBP+50h]
		0xC7, 0x45, 0xFC, 0x04, 0x00, 0x00, 0x00;	// +13B: MOV DWORD PTR [EBP-4], 4
	patch +=
		-1, 0x01FF, 0x01FF, 0x01FF, 0x01FF,			// +133: PUSH OFFSET dataClockString
		-1, -1, -1, -1, -1, -1, -1, -1, -1, -1;

	MemoryPatch mp( NULL, patch, backup );
	mp.Search( L"Pleione.dll" );
	mp.PatchExactAddress( 0x01, (LPBYTE)(&dataClockString) );
	
	patches += mp;
	if (CheckPatches())
		WriteLog("Patch initialization successful: %s.\n", patchname.c_str());
	else
		WriteLog("Patch initialization failed: %s.\n", patchname.c_str());
}

//-----------------------------------------------------------------------------
// INI Functions

bool CPatcher_LargeClockText::ReadINI( void )
{
	if ( ReadINI_Bool( L"LargeClockText" ))
		return Install();
	return true;
}

bool CPatcher_LargeClockText::WriteINI( void )
{
	WriteINI_Bool( L"LargeClockText", IsInstalled() );
	return true;
}