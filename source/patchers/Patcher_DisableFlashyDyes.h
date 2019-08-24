#pragma once

/* Disable Flashy Dyes
 */

#include "../Main.h"
#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_DisableFlashyDyes : public IGenericPatcher {
public:
	CPatcher_DisableFlashyDyes();
	bool ReadINI(void);
	bool WriteINI(void);

private:
	// Hook functions
	static void patchFlashyValue(void);
	static LPBYTE addrTargetReturn;
	static LPBYTE addrTargetReturn1;
	static LPBYTE addrTargetReturn2;
	// Variables for hook functions
	static int tempAddr;
	static int hexColorCode1;
	static int hexColorCode2;
	static int hexColorCode3;
	static int tempDiff;
};

typedef Singleton<CPatcher_DisableFlashyDyes> SngPatcher_DisableFlashyDyes;