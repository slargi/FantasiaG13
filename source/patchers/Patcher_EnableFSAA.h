#pragma once

/* Enable FSAA
 * Enable full-screen antialiasing.
 * PATCHES: Pleione.dll
 */

#include "../Main.h"
#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_EnableFSAA : public IGenericPatcher {
public:
	CPatcher_EnableFSAA();
	bool ReadINI( void );
	bool WriteINI( void );

private:
	// Hook functions
	static void patchFSAA(void);

	// Variables for hook functions
	static LPBYTE addrReadFSAA;
	static LPBYTE addrReadFSAAQuality;
	static LPBYTE addrTargetReturn;
};

typedef Singleton<CPatcher_EnableFSAA> SngPatcher_EnableFSAA;