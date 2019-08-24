#pragma once

/* Name Of Mod
 * Description of mod
 * PATCHES: XXX.dll
 *
 * CTRL+H "NameOfMod"
 */

#include "../Main.h"
#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_NameOfMod : public IGenericPatcher {
public:
	CPatcher_NameOfMod();
	bool ReadINI( void );
	bool WriteINI( void );

private:
	// Hook functions
	// Variables for hook functions
};

typedef Singleton<CPatcher_NameOfMod> SngPatcher_NameOfMod;