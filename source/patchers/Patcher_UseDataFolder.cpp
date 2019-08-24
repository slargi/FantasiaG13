#include "Patcher_UseDataFolder.h"
#include "../Addr.h"
#include "../FileSystem.h"

//-----------------------------------------------------------------------------
// Constructor

CPatcher_UseDataFolder::CPatcher_UseDataFolder( void )
{
	patchname = "Use Data Folder";

	LPBYTE addrSetLookUpOrder = CAddr::Addr(CFileSystem_SetLookUpOrder);
	if (!addrSetLookUpOrder) {
		WriteLog("Patch initialization failed: %s.\n", patchname.c_str());
		WriteLog("   Missing dependency.\n");
		return;
	}

	vector<WORD> patch;
	vector<WORD> backup;

	backup +=
		0x8B, 0x45, 0xEC,	// MOV EAX, [EBP-14h]
		0x8B, 0x40, 0x04,	// MOV EAX, [EAX+04h]
		0x8B, 0x40, 0x18,	// MOV EAX, [EAX+18h]
		0x83, 0xE8, 0x01;	// SUB EAX, 0  (wat?)

	patch +=
		-1, -1, -1,
		-1, -1, -1,
		-1, -1, -1,
		-1, -1, 0x00;		// SUB EAX, 0 => SUB EAX, 1

	MemoryPatch mp( addrSetLookUpOrder + 0xAF, patch, backup );
	
	patches += mp;
	if (CheckPatches())
		WriteLog("Patch initialization successful: %s.\n", patchname.c_str());
	else
		WriteLog("Patch initialization failed: %s.\n", patchname.c_str());
}

//-----------------------------------------------------------------------------
// INI Functions

bool CPatcher_UseDataFolder::ReadINI( void )
{
	if ( ReadINI_Bool( L"DisableDataFolder" ))
		return Install();
	return true;
}

bool CPatcher_UseDataFolder::WriteINI( void )
{
	WriteINI_Bool( L"DisableDataFolder", IsInstalled() );
	return true;
}