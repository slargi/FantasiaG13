#pragma once

/* Default Ranged Swap
 * PATCHES: Standard.dll
 */

#include "../Main.h"
#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_DefaultRangedSwap : public IGenericPatcher {
public:
	CPatcher_DefaultRangedSwap();
	bool ReadINI(void);
	bool WriteINI(void);
	bool SetSwap(int);
	static int GetSwap();
private:
	// Hook functions
	static void ModifySwap();
	// Variables for hook functions
	static unsigned short swapValue;
	static LPBYTE addrTargetReturn;
};

typedef Singleton<CPatcher_DefaultRangedSwap> SngPatcher_DefaultRangedSwap;