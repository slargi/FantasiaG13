#pragma once

/* Talk To Unequipped Ego
 * Allow conversation with unequipped spirit weapons.
 * PATCHES: Pleione.dll
 */

#include "../Main.h"
#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_TalkToUnequippedEgo : public IGenericPatcher {
public:
	CPatcher_TalkToUnequippedEgo();
	bool ReadINI( void );
	bool WriteINI( void );

private:
	// Hook functions
	// Variables for hook functions
};

typedef Singleton<CPatcher_TalkToUnequippedEgo> SngPatcher_TalkToUnequippedEgo;