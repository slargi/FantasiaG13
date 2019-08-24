#pragma once

/* Enable Naked Mode
 * PATCHES: XXX.dll
 *
 * CTRL+H "EnableNakedMode"
 */

#include "../Main.h"
#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_EnableNakedMode : public IGenericPatcher {
public:
	CPatcher_EnableNakedMode();
	bool ReadINI(void);
	bool WriteINI(void);

private:
	// Hook functions
	// Variables for hook functions
};

typedef Singleton<CPatcher_EnableNakedMode> SngPatcher_EnableNakedMode;