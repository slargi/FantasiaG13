#pragma once

/* Show Poison Durability
 *
 * CTRL+H "ShowPoisonDurability"
 */

#include "../Main.h"
#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_ShowPoisonDurability : public IGenericPatcher {
public:
	CPatcher_ShowPoisonDurability();
	bool ReadINI(void);
	bool WriteINI(void);
	static void __stdcall patchColorString();
private:
	// Hook functions
	static void GetItemPoison(void);
	static void StoreDurability(void);
	static void GetColorString(void);
	// Variables for hook functions
	static LPBYTE addrCallClear;
	static LPBYTE addrTargetReturn1;
	static LPBYTE addrTargetReturn2;
	static LPBYTE addrIsPoisoned;
	static LPBYTE addrGetItemBasePoison;
	static LPBYTE addrGetItemPotionPoison;
	static LPBYTE addrGetItemPotionPoisonDurability;
	static int poisonDurability;
	static wchar_t dataStr[];
};

typedef Singleton<CPatcher_ShowPoisonDurability> SngPatcher_ShowPoisonDurability;