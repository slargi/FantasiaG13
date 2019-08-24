#pragma once

/* Enter Remote Shop
 * Enable opening of player shops from a distance.
 * PATCHES: Pleione.dll
 */

#include "../Main.h"
#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_EnterRemoteShop : public IGenericPatcher {
public:
	CPatcher_EnterRemoteShop();
	bool ReadINI( void );
	bool WriteINI( void );

private:
	// Hook functions
	// Variables for hook functions
};

typedef Singleton<CPatcher_EnterRemoteShop> SngPatcher_EnterRemoteShop;