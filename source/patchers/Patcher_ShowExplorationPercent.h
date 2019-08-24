#pragma once

/* Show Exploration Percent
 * Shows the percentage towards your next exploration level in the character window.
 * PATCHES: Pleione.dll
 */

#include "../Main.h"
#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_ShowExplorationPercent : public IGenericPatcher {
public:
	CPatcher_ShowExplorationPercent();
	bool ReadINI( void );
	bool WriteINI( void );

private:
	// Hook functions
	static void patchFunc(void);
	static void __stdcall patchFormat(wchar_t *, float percent);
	// Variables for hook functions
	static wchar_t dataExplStr[];
	static wchar_t dataPercentStr[8];
	static LPBYTE addrGetExploLevel;
	static LPBYTE addrGetExploExpPercent;
	static LPBYTE addrFormatterInsertPwchar;
	static LPBYTE addrPatch;
};

typedef Singleton<CPatcher_ShowExplorationPercent> SngPatcher_ShowExplorationPercent;