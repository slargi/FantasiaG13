#pragma once

/* Stay as Alchemy Golem
 * Prevents switch back to character when out of bounds
 * PATCHES: Pleione.dll
 */

#include "../Main.h"
#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_StayAsAlchemyGolem : public IGenericPatcher {
public:
	CPatcher_StayAsAlchemyGolem();
	bool ReadINI(void);
	bool WriteINI(void);

private:
	// Hook functions
	// Variables for hook functions
};

typedef Singleton<CPatcher_StayAsAlchemyGolem> SngPatcher_StayAsAlchemyGolem;