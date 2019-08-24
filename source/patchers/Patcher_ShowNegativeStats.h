#pragma once

/* Show Negative Stats
 * PATCHES: Pleione.dll
 */

#include "../Main.h"
#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_ShowNegativeStats : public IGenericPatcher {
public:
	CPatcher_ShowNegativeStats();
	bool ReadINI(void);
	bool WriteINI(void);

private:
	// Hook functions
	// Variables for hook functions
};

typedef Singleton<CPatcher_ShowNegativeStats> SngPatcher_ShowNegativeStats;