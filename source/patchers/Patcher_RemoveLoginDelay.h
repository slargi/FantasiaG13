#pragma once

/* Remove Login Delay
 * Removes the 30-second login delay after disconnecting.
 * PATCHES: Pleione.dll
 */

#include "../Main.h"
#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_RemoveLoginDelay : public IGenericPatcher {
public:
	CPatcher_RemoveLoginDelay();
	bool ReadINI( void );
	bool WriteINI( void );

private:
	// Hook functions
	// Variables for hook functions
};

typedef Singleton<CPatcher_RemoveLoginDelay> SngPatcher_RemoveLoginDelay;