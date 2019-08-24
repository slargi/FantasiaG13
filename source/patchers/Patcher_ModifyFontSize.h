#pragma once

/* Modify Font Size
 */

#include "../Main.h"
#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_ModifyFontSize : public IGenericPatcher {
public:
	CPatcher_ModifyFontSize();
	int GetFontSize(void);
	bool SetFontSize(int);
	bool ReadINI(void);
	bool WriteINI(void);

private:
	// Hook functions
	static void PatchFontSize(void);
	// Variables for hook functions
	static int fontSize;
	static LPBYTE addrTargetReturn;
};

typedef Singleton<CPatcher_ModifyFontSize> SngPatcher_ModifyFontSize;