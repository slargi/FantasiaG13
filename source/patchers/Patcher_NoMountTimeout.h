#pragma once

/* No Mount Timeout
 * PATCHES: Pleione.dll
 */

#include "../Main.h"
#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_NoMountTimeout : public IGenericPatcher {
public:
	CPatcher_NoMountTimeout();
	bool ReadINI(void);
	bool WriteINI(void);

private:
	// Hook functions
	// Variables for hook functions
};

typedef Singleton<CPatcher_NoMountTimeout> SngPatcher_NoMountTimeout;