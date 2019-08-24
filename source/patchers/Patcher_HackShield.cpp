#include "Patcher_HackShield.h"
#include "../Addr.h"
#include "../FileSystem.h"

//-----------------------------------------------------------------------------
// Static variable initialization

BYTE   CPatcher_HackShield::pushBackup[4]    = { 0x00, 0x00, 0x00, 0x00 };
LPBYTE CPatcher_HackShield::addrCRT          = NULL;
LPBYTE CPatcher_HackShield::addrReturn       = NULL;
LPBYTE CPatcher_HackShield::targetEntry      = NULL;
int    CPatcher_HackShield::ignoredHSThreads = 1;

//-----------------------------------------------------------------------------
// Constructor

CPatcher_HackShield::CPatcher_HackShield( void )
{
    LPBYTE addrKernelBaseCRTX, addrKernel32CRT;

	patchname = "CRT Patch";

    addrKernelBaseCRTX = CAddr::Addr(kernelbase_CreateRemoteThreadEx);
	addrKernel32CRT    = CAddr::Addr(kernel32_CreateRemoteThread);

	if (!addrKernel32CRT)
	{
		WriteLog("Patch initialization failed: %s.\n", patchname.c_str());
		WriteLog("   Missing dependency.\n");
		return;
	}

    addrCRT = addrKernel32CRT;
    if (addrKernelBaseCRTX)
    {
        DebugLog("Patching CRTX.\n");
        addrCRT = addrKernelBaseCRTX;
    }

	vector<WORD> patch;
	vector<WORD> backup;

	// CreateRemoteThread[Ex] begins with 0x68 (PUSH xxxxxxxx), so we
    // save the value of the push in order to reproduce it later.
	MemoryPatch::ReadMem( addrCRT + 1, pushBackup, 4 );

	backup +=
		-1,   -1, -1, -1, -1,			        // -05: NOP (x5) or INT3 (x5)
		0x68, -1, -1, -1, -1;				    // +00: PUSH xxxxxxxx
	patch +=
		0xE9, 0x01FF, 0x01FF, 0x01FF, 0x01FF,	// -05: JMP LONG patchCRT
		0xEB, 0xF9,								// +00: JMP SHORT -5
		0x90, 0x90, 0x90;						// +02: NOP x3
	addrReturn = addrCRT + 0x05;

	MemoryPatch mp( addrCRT - 0x05, patch, backup );
	mp.PatchRelativeAddress( 0x01, (LPBYTE)patchCRT );

	patches += mp;
	if (CheckPatches())
		WriteLog("Patch initialization successful: %s.\n", patchname.c_str());
	else
		WriteLog("Patch initialization failed: %s.\n", patchname.c_str());
}

//-----------------------------------------------------------------------------
// Hook functions

NAKED void CPatcher_HackShield::patchCRT( void )
{
	__asm {
		// If we have already looked up our target entry point, pass this bit
		CMP		targetEntry, 0
		JNZ		gotTargetEntry
	}

	// Get the module handle for EhSvc.dll -> this is a pointer to the base
	// of the DLL, which can be loaded into a variable location at runtime.
	// The result -should- be stored in EAX, though I guess it's compiler-
	// dependent.  It works on Visual Studio 2008 Pro.  And any reasonable
	// compiler should do the same.  Would have done this as a CALL instruction
	// but the way I tried it, the inline assembler didn't like the string.
	(LPBYTE)GetModuleHandle( L"EhSvc.dll" );

	__asm {
		// The result is 0 (NULL) if EhSvc.dll has not yet been loaded
		CMP		EAX, 0
		JZ		notHSThread

		// We have the base of EhSvc.dll -- the target entry point in
		// HackShield 5.2.4.828 is base+64FC6.
		ADD		EAX, 0x64FC6
		MOV		targetEntry, EAX

gotTargetEntry:
		// If the entry point for this thread (ESP+10h) is not our target,
		// go back to CreateRemoteThread as if nothing happened :)
		MOV		EAX, targetEntry
        CMP     DWORD PTR SS:[ESP+0x10], EAX
        JNE     notHSThread

		// This thread has our target entry point-- check if we are
		// supposed to ignore this one
		CMP		ignoredHSThreads, 0
		JZ		patchThisThread

		// Ignore this thread and go back to CRT
		SUB		ignoredHSThreads, 1

notHSThread:
		// We patched over a PUSH xxxxxxxx (68 xx xx xx xx)
		// Since we patched over real code, we have to execute it before
		// we jump back.
		MOV		EAX, DWORD PTR pushBackup // DWORD pushBackup = "xx xx xx xx" above
		PUSH	EAX
		// Return to CreateRemoteThread after the hook code
		JMP		addrReturn

		// Found our target thread!
patchThisThread:
	}

	// Remove the hook
	SngPatcher_HackShield::Instance()->Uninstall();

	__asm {
		// Set the thread's entry point to our dummy function
		MOV		DWORD PTR SS:[ESP+0x10], offset dummyFunction
		// Return to CreateRemoteThread (no more hook code in the way)
		JMP		addrCRT
	}
}

DWORD WINAPI CPatcher_HackShield::dummyFunction( LPVOID lpParam )
{
	while(g_isRunning) {
		Sleep(INFINITE);
	}
	return 0;
}

//-----------------------------------------------------------------------------
// INI Functions

bool CPatcher_HackShield::ReadINI( void )
{
    if ( !ReadINI_Bool( L"DisableCRTPatch" )) {
		return Install();
    }
	return true;
}

bool CPatcher_HackShield::WriteINI( void )
{
	// This patch cannot be disabled or enabled at runtime
	return true;
}