#pragma once

/* Display Names from afar
 * PATCHES: Pleione.dll
 *
 * CTRL+H "DisplayNamesFar"
 */

#include "../Main.h"
#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_DisplayNamesFar : public IGenericPatcher {
public:
	CPatcher_DisplayNamesFar();
	bool ReadINI(void);
	bool WriteINI(void);

private:
	// Hook functions
	// Variables for hook functions
};

typedef Singleton<CPatcher_DisplayNamesFar> SngPatcher_DisplayNamesFar;