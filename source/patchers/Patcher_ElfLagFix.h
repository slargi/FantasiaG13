#pragma once

/* Elf Lag Fix
 * Fixes range skill with large latency
 * PATCHES: Standard.dll
 */

#include "../Main.h"
#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_ElfLagFix : public IGenericPatcher {
public:
	CPatcher_ElfLagFix();
	bool ReadINI(void);
	bool WriteINI(void);

private:
	// Hook functions
	// Variables for hook functions
};

typedef Singleton<CPatcher_ElfLagFix> SngPatcher_ElfLagFix;