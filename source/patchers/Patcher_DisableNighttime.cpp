#include "Patcher_DisableNighttime.h"
#include "../Addr.h"
#include "../FileSystem.h"

//-----------------------------------------------------------------------------
// Constructor

CPatcher_DisableNighttime::CPatcher_DisableNighttime( void )
{
	patchname = "Disable Nighttime";

	LPBYTE addrSetSkyTime = CAddr::Addr(CAtmosphere_SetSkyTime);
	if (!addrSetSkyTime) {
		WriteLog("Patch initialization failed: %s.\n", patchname.c_str());
		WriteLog("   Missing dependency.\n");
		return;
	}

	vector<WORD> patch;
	vector<WORD> backup;

	backup +=
		-1, -1, -1, -1, -1;						// +00: No key (we are replacing the entire function)
	patch +=
		0xE9, 0x01FF, 0x01FF, 0x01FF, 0x01FF;	// +00: JMP patchNighttime

	MemoryPatch mp( addrSetSkyTime, patch, backup );
	mp.PatchRelativeAddress( 0x01, (LPBYTE)patchNighttime );
	
	patches += mp;
	if (CheckPatches())
		WriteLog("Patch initialization successful: %s.\n", patchname.c_str());
	else
		WriteLog("Patch initialization failed: %s.\n", patchname.c_str());
}

//-----------------------------------------------------------------------------
// Hook functions

NAKED void CPatcher_DisableNighttime::patchNighttime(void)
{
	__asm {
		MOV		EAX, DWORD PTR DS:[ECX]
		MOV		ECX, 3E2AAAADh				// 0x3E2AAAAD = 1/6 = 4:00
		CMP		ECX, DWORD PTR SS:[ESP+4h]
		JA		jmp_exit
		MOV		ECX, 3F400000h				// 0x3F400000 = 3/4 = 18:00
		CMP		ECX, DWORD PTR SS:[ESP+4h]
		JB		jmp_exit
		MOV		ECX, DWORD PTR SS:[ESP+4h]
	jmp_exit:								// ECX = time to set
		MOV		DWORD PTR DS:[EAX+0Ch], ECX
		RETN	4h
	}
}

//-----------------------------------------------------------------------------
// INI Functions

bool CPatcher_DisableNighttime::ReadINI( void )
{
	if ( ReadINI_Bool( L"DisableNighttime" ))
		return Install();
	return true;
}

bool CPatcher_DisableNighttime::WriteINI( void )
{
	WriteINI_Bool( L"DisableNighttime", IsInstalled() );
	return true;
}