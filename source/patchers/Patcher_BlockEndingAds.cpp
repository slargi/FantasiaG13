#include "Patcher_BlockEndingAds.h"
#include "../Addr.h"
#include "../FileSystem.h"

//-----------------------------------------------------------------------------
// Constructor

CPatcher_BlockEndingAds::CPatcher_BlockEndingAds( void )
{
	patchname = "Block Ending Ads";

	LPBYTE addrCleanUp = CAddr::Addr(CPleione_CleanUp);
	if (!addrCleanUp)
	{
		WriteLog("Patch initialization failed: %s.\n", patchname.c_str());
		WriteLog("   Missing dependency.\n");
		return;
	}

	vector<WORD> patch;
	vector<WORD> backup;

	backup +=
		0x6A, 0x3C,					// +540: PUSH 3Ch
		0xFF, 0x75, 0xE8,			// +542: PUSH [EBP-18h]
		0x57,						// +545: PUSH EDI
		0x90, 0xE8, -1, -1, -1, -1,	// +546: CALL xxxxxxxx (CStringT::GetSafeContent)
		0x50,						// +54C: PUSH EAX
		0x90, 0xE8, -1, -1, -1, -1,	// +54D: CALL xxxxxxxx (CADBalloon::ShowAd)
		0x83, 0xC4, 0x14;			// +553: ADD ESP, 14h
	patch +=
		-1, -1,
		-1, -1, -1,
		-1,
		-1, -1, -1, -1, -1, -1,
		-1,
		-1, 0x90, 0x90, 0x90, 0x90, 0x90,	// +54D: NOP (x5)
		-1, -1, -1;

	MemoryPatch mp( addrCleanUp + 0x5AB, patch, backup );

	patches += mp;
	if (CheckPatches())
		WriteLog("Patch initialization successful: %s.\n", patchname.c_str());
	else
		WriteLog("Patch initialization failed: %s.\n", patchname.c_str());
}

//-----------------------------------------------------------------------------
// INI Functions

bool CPatcher_BlockEndingAds::ReadINI( void )
{
	if ( ReadINI_Bool( L"BlockEndingAds" ))
		return Install();
	return true;
}

bool CPatcher_BlockEndingAds::WriteINI( void )
{
	WriteINI_Bool( L"BlockEndingAds", IsInstalled() );
	return true;
}