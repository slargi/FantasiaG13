#pragma once

/* Window Size
 * Modifies window size
 * PATCHES: ESL.dll
 */

#include "../Main.h"
#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_WindowPosition : public IGenericPatcher {
public:
	CPatcher_WindowPosition();
	bool ReadINI(void);
	bool WriteINI(void);

private:
	// Hook functions
	// Variables for hook functions
};

typedef Singleton<CPatcher_WindowPosition> SngPatcher_WindowPosition;