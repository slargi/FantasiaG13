#pragma once

/* Show True Food Quality
 * Show food quality numerically.
 * PATCHES: Pleione.dll
 */

#include "../Main.h"
#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_ShowTrueFoodQuality : public IGenericPatcher {
public:
	CPatcher_ShowTrueFoodQuality();
	bool ReadINI( void );
	bool WriteINI( void );

private:
	// Hook functions
	static void patchFoodQuality(void);
	static void patchFoodQualityFormat(wchar_t * buff,wchar_t* str,int d);

	// Variables for hook functions
	static wchar_t dataBuf[256];
	static LPBYTE addrCStringTEquals;
	static LPBYTE addrTargetReturn;
	LPBYTE funcPointer;
};

typedef Singleton<CPatcher_ShowTrueFoodQuality> SngPatcher_ShowTrueFoodQuality;