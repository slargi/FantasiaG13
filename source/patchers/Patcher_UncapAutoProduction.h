#pragma once

/* Uncap Auto Production
 * PATCHES: Pleione.dll
 */

#include "../Main.h"
#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_UncapAutoProduction : public IGenericPatcher {
public:
	CPatcher_UncapAutoProduction();
	bool ReadINI(void);
	bool WriteINI(void);

private:
	// Hook functions
	// Variables for hook functions
};

typedef Singleton<CPatcher_UncapAutoProduction> SngPatcher_UncapAutoProduction;