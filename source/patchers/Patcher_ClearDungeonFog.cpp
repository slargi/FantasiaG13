#include "Patcher_ClearDungeonFog.h"
#include "../Addr.h"
#include "../FileSystem.h"

//-----------------------------------------------------------------------------
// Constructor

CPatcher_ClearDungeonFog::CPatcher_ClearDungeonFog( void )
{
	patchname = "Clear Dungeon Fog";

	LPBYTE addrSetFog = CAddr::Addr(CDungeonRegion_SetFog);
	if (!addrSetFog) {
		WriteLog("Patch initialization failed: %s.\n", patchname.c_str());
		WriteLog("   Missing dependency.\n");
		return;
	}

	vector<WORD> patch;
	vector<WORD> backup;

	backup +=
		0x8B, 0x01,				// +00: MOV EAX, [ECX]
		0x8A, 0x4C, 0x24, 0x04;	// +02: MOV CL, [ESP+04h]

	patch +=
		-1, -1,
		0x32, 0xC9, 0x90, 0x90;	// +02: XOR CL, CL | NOP (x2)

	MemoryPatch mp( addrSetFog, patch, backup );
	
	patches += mp;
	if (CheckPatches())
		WriteLog("Patch initialization successful: %s.\n", patchname.c_str());
	else
		WriteLog("Patch initialization failed: %s.\n", patchname.c_str());
}

//-----------------------------------------------------------------------------
// INI Functions

bool CPatcher_ClearDungeonFog::ReadINI( void )
{
	if ( ReadINI_Bool( L"ClearDungeonFog" ))
		return Install();
	return true;
}

bool CPatcher_ClearDungeonFog::WriteINI( void )
{
	WriteINI_Bool( L"ClearDungeonFog", IsInstalled() );
	return true;
}