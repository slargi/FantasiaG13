#pragma once

/* Show Clock Minutes
 * PATCHES: Pleione.dll
 */

#include "../Main.h"
#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_ShowClockMinutes : public IGenericPatcher {
public:
	CPatcher_ShowClockMinutes();
	bool ReadINI(void);
	bool WriteINI(void);

private:
	// Hook functions
	// Variables for hook functions
};

typedef Singleton<CPatcher_ShowClockMinutes> SngPatcher_ShowClockMinutes;