#pragma once

/* Item Split Quantity
 * Changes the default item quantity 
 * when splitting
 * PATCHES: Pleione.dll
 *
 * CTRL+H "ItemSplitQuantity"
 */

#include "../Main.h"
#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_ItemSplitQuantity : public IGenericPatcher {
public:
	CPatcher_ItemSplitQuantity();
	bool ReadINI(void);
	bool WriteINI(void);
	int GetQuantity(void);
	// Options
	bool SetQuantity(int value);
private:
	// Hook functions
	static void ModifyQuantity(void);
	// Variables for hook functions
	static int itemQuantity;
	static LPBYTE addrTargetReturn;
};

typedef Singleton<CPatcher_ItemSplitQuantity> SngPatcher_ItemSplitQuantity;