#pragma once

/* Enable Cutscene Skip
 * PATCHES: Pleione.dll
 *
 * CTRL+H "EnableCutsceneSkip"
 */

#include "../Main.h"
#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_EnableCutsceneSkip : public IGenericPatcher {
public:
	CPatcher_EnableCutsceneSkip();
	bool ReadINI(void);
	bool WriteINI(void);

private:
	// Hook functions
	// Variables for hook functions
};

typedef Singleton<CPatcher_EnableCutsceneSkip> SngPatcher_EnableCutsceneSkip;