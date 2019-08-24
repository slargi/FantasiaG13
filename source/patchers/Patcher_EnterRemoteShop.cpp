#include "Patcher_EnterRemoteShop.h"
#include "../Addr.h"
#include "../FileSystem.h"

//-----------------------------------------------------------------------------
// Constructor

CPatcher_EnterRemoteShop::CPatcher_EnterRemoteShop( void )
{
	patchname = "Enter Remote Shop";

	vector<WORD> patch;
	vector<WORD> backup;

	backup +=
		0xD9, 0x5D, 0xF8,				// +117: FSTP [EBP-10]
		0xD9, 0x05, -1, -1, -1, -1,		// +11A: FLD xxxxxxxx
		0xD8, 0x5D, 0xF8,				// +120: FCOMP [EBP-10]
		0xDF, 0xE0,						// +123: FSTSW AX
		0xF6, 0xC4, 0x01,				// +125: TEST AH, 1
		0x75, 0x15;						// +128: JNZ SHORT +15

	patch +=
		-1, -1, -1,
		-1, -1, -1, -1, -1, -1,
		-1, -1, -1,
		-1, -1,
		-1, -1, -1,
		0x90, 0x90;						// +128: JNZ => NOP

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

bool CPatcher_EnterRemoteShop::ReadINI( void )
{
	if ( ReadINI_Bool( L"EnterRemoteShop" ))
		return Install();
	return true;
}

bool CPatcher_EnterRemoteShop::WriteINI( void )
{
	WriteINI_Bool( L"EnterRemoteShop", IsInstalled() );
	return true;
}