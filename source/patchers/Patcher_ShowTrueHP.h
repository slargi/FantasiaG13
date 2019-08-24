#pragma once

/* Show True HP
 * Shows True HP that the game doesn't display for whatever reason
 * PATCHES: Pleione.dll
 *
 * CTRL+H "ShowTrueHP"
 */

#include "../Main.h"
#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_ShowTrueHP : public IGenericPatcher {
public:
	CPatcher_ShowTrueHP();
	bool ReadINI(void);
	bool WriteINI(void);

private:
	// Hook functions
	// static void GetTrueCurrentLife(void);
	static void GetTrueMaxLife(void);
	static void GetLifeMax(void);
	// Variables for hook functions
	static float currentLife;
	static float maxLife;
	static LPBYTE addrGetLife;
	static LPBYTE addrGetLifeMax;
	static LPBYTE addrGetLifeMaxBase;
	static LPBYTE addrGetInterfaceLifeDamaged;
	static LPBYTE addrGetLifePercent;
	static LPBYTE addrGetLifeDamaged;
	static LPBYTE addrGetLifeReturn;
	static LPBYTE addrGetLifeDamagedReturn;
};

typedef Singleton<CPatcher_ShowTrueHP> SngPatcher_ShowTrueHP;