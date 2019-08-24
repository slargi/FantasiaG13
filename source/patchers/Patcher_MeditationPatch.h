#pragma once

/* Name Of Mod
 */

#include "../Main.h"
#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_MeditationPatch : public IGenericPatcher {
public:
	CPatcher_MeditationPatch();
	bool ReadINI(void);
	bool WriteINI(void);

private:
	// Hook functions
	// Variables for hook functions
};

typedef Singleton<CPatcher_MeditationPatch> SngPatcher_MeditationPatch;