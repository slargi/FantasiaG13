#pragma once

/* Show Negative HP
 * PATCHES: Pleione.dll
 */

#include "../Main.h"
#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_ShowNegativeHP : public IGenericPatcher {
public:
	CPatcher_ShowNegativeHP();
	bool ReadINI(void);
	bool WriteINI(void);

private:
	// Hook functions
	// Variables for hook functions
};

typedef Singleton<CPatcher_ShowNegativeHP> SngPatcher_ShowNegativeHP;