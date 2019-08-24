#pragma once

/* Show Combat Power
 * Show combat power numerically.
 * PATCHES: Pleione.dll
 */

#include "../Main.h"
#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_ShowCombatPower : public IGenericPatcher {
public:
	CPatcher_ShowCombatPower();
	bool ReadINI( void );
	bool WriteINI( void );
	bool Toggle(int);
	bool IsInstalled(int);

private:
	// Hook functions
	static void patchCP1(void);
	static void patchCP2(void);
	static void __stdcall patchCPFormat(wchar_t * buff, double h,double f,wchar_t* str);

	// Variables for hook functions
	static bool showMaxHP;
	static bool showCombatPower;
	static wchar_t dataBuf[256];
	static wchar_t dataStrNull[1];
	static LPBYTE addrCStringTConstr;
	static LPBYTE addrCStringTEquals;
	static LPBYTE addrGetCombatPower;
	static LPBYTE addrGetLifeMax;
	static LPBYTE addrTargetReturn;
};

typedef Singleton<CPatcher_ShowCombatPower> SngPatcher_ShowCombatPower;