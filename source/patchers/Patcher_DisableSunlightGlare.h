#pragma once

/* Disable Sunlight Glare
 * PATCHES: Renderer2.dll
 */

#include "../Main.h"
#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_DisableSunlightGlare : public IGenericPatcher {
public:
	CPatcher_DisableSunlightGlare();
	bool ReadINI(void);
	bool WriteINI(void);

private:
	// Hook functions
	// Variables for hook functions
};

typedef Singleton<CPatcher_DisableSunlightGlare> SngPatcher_DisableSunlightGlare;