#pragma once

/* Faster Interface Windows
 */

#include "../Main.h"
#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_FasterInterfaceWindows : public IGenericPatcher {
public:
	CPatcher_FasterInterfaceWindows();
	bool ReadINI(void);
	bool WriteINI(void);

private:
	// Hook functions
	// Variables for hook functions
};

typedef Singleton<CPatcher_FasterInterfaceWindows> SngPatcher_FasterInterfaceWindows;