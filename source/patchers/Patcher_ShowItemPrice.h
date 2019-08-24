#pragma once

/* ShowItemPrice
 * Show the shop purchase and selling price in item descriptions.
 * PATCHES: Pleione.dll
 */

#include "../Main.h"
#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_ShowItemPrice : public IGenericPatcher {
public:
	CPatcher_ShowItemPrice();
	bool ReadINI( void );
	bool WriteINI( void );
private:
};

typedef Singleton<CPatcher_ShowItemPrice> SngPatcher_ShowItemPrice;