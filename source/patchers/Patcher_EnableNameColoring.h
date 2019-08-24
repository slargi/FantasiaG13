#pragma once

/* Enable Name Coloring
 * Enable coloring of ALT names based on character type.
 * PATCHES: Pleione.dll
 */

#include "../Main.h"
#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_EnableNameColoring : public IGenericPatcher {
public:
	CPatcher_EnableNameColoring();
	bool ReadINI( void );
	bool WriteINI( void );

private:
	// Hook functions
	static void patchNameColoring(void);

	// Variables for hook functions
	static LPBYTE addrTarget;
	static LPBYTE addrIsElf;
	static LPBYTE addrIsGiant;
	static LPBYTE addrIsPet;
	static LPBYTE addrIsNPC;
	static LPBYTE addrIsGoodNPC;
};

typedef Singleton<CPatcher_EnableNameColoring> SngPatcher_EnableNameColoring;