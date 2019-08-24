#include "Patcher_ShowItemPrice.h"
#include "../Addr.h"
#include "../FileSystem.h"

//-----------------------------------------------------------------------------
// Constructor

CPatcher_ShowItemPrice::CPatcher_ShowItemPrice( void )
{
	patchname = "Show Item Price";

	vector<WORD> patch;
	vector<WORD> backup;

	backup +=
		0x83, 0xF8, 0x02,					// +154: CMP EAX, 2
		0x0F, 0x85, 0x86, 0x01, 0x00, 0x00;	// +157: JNZ NEAR +186h
	patch +=
		-1, -1, -1,
		0x90, 0x90, 0x90, 0x90, 0x90, 0x90;	// +157: JNZ => NOP
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

bool CPatcher_ShowItemPrice::ReadINI( void )
{
	if ( ReadINI_Bool( L"ShowItemPrice" ))
		return Install();
	return true;
}

bool CPatcher_ShowItemPrice::WriteINI( void )
{
	WriteINI_Bool( L"ShowItemPrice", IsInstalled() );
	return true;
}