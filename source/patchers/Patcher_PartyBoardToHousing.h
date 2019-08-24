#pragma once

/* Party Board to Housing
 * PATCHES: Pleione.dll
 *
 * CTRL+H "PartyBoardToHousing"
 */

#include "../Main.h"
#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_PartyBoardToHousing : public IGenericPatcher {
public:
	CPatcher_PartyBoardToHousing();
	bool ReadINI(void);
	bool WriteINI(void);

private:
	// Hook functions
	// Variables for hook functions
};

typedef Singleton<CPatcher_PartyBoardToHousing> SngPatcher_PartyBoardToHousing;