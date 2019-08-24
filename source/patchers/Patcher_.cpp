#include "Patcher_NameOfMod.h"
#include "../Addr.h"
#include "../FileSystem.h"

//-----------------------------------------------------------------------------
// Static variable initialization

//-----------------------------------------------------------------------------
// Constructor

CPatcher_NameOfMod::CPatcher_NameOfMod( void )
{
	patchname = "NameOfMod";

	LPBYTE addrXXX = CAddr::Addr(kernel32_CreateRemoteThread);
	if (!addrXXX) {
		WriteLog("Patch initialization failed: %s.\n", patchname.c_str());
		WriteLog("   Missing dependency.\n");
		return;
	}

	vector<WORD> patch;
	vector<WORD> backup;

	backup +=
		0x90, 0x90, 0x90;	// NOP

	patch +=
		0x90, 0x90, 0x90;	// NOP => NOP

	MemoryPatch mp( addrXXX + 0x00, patch, backup );
	
	patches += mp;
	if (CheckPatches())
		WriteLog("Patch initialization successful: %s.\n", patchname.c_str());
	else
		WriteLog("Patch initialization failed: %s.\n", patchname.c_str());
}

//-----------------------------------------------------------------------------
// Hook functions

//-----------------------------------------------------------------------------
// INI Functions

bool CPatcher_NameOfMod::ReadINI( void )
{
	if ( ReadINI_Bool( L"NameOfMod" ))
		return Install();
	return true;
}

bool CPatcher_NameOfMod::WriteINI( void )
{
	WriteINI_Bool( L"NameOfMod", IsInstalled() );
	return true;
}