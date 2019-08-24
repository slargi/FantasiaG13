#pragma once

/* Use Bitmap Fonts
 * Use bitmap fonts instead of vector fonts to prevent window lag.
 * PATCHES: Renderer2.dll
 */

#include "../Main.h"
#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_UseBitmapFonts : public IGenericPatcher {
public:
	CPatcher_UseBitmapFonts();
	bool ReadINI( void );
	bool WriteINI( void );
private:
};

typedef Singleton<CPatcher_UseBitmapFonts> SngPatcher_UseBitmapFonts;