#pragma once

/* Target Resting Enemies
 * PATCHES: Standard.dll
 */

#include "../Main.h"
#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_TargetRestingEnemies : public IGenericPatcher {
public:
	CPatcher_TargetRestingEnemies();
	bool ReadINI(void);
	bool WriteINI(void);

private:
	// Hook functions
	// Variables for hook functions
};

typedef Singleton<CPatcher_TargetRestingEnemies> SngPatcher_TargetRestingEnemies;