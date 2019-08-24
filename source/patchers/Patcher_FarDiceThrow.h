#pragma once

/* Far Dice Throw
 * PATCHES: Skill.dll
 */

#include "../Main.h"
#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_FarDiceThrow : public IGenericPatcher {
public:
	CPatcher_FarDiceThrow();
	bool ReadINI(void);
	bool WriteINI(void);

private:
	// Hook functions
	static void SetThrowRadius(void);
	// Variables for hook functions
	static float throwRadius;
	static LPBYTE addrTargetReturn;
};

typedef Singleton<CPatcher_FarDiceThrow> SngPatcher_FarDiceThrow;