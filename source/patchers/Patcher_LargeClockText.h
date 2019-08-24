#pragma once

/* Large Clock Text
 * Increase the size of the in-game clock.  Can cause cut-off text.
 * PATCHES: Pleione.dll
 */

#include "../Main.h"
#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_LargeClockText : public IGenericPatcher {
public:
	CPatcher_LargeClockText();
	bool ReadINI( void );
	bool WriteINI( void );
private:
	static wchar_t dataClockString[];
};

typedef Singleton<CPatcher_LargeClockText> SngPatcher_LargeClockText;