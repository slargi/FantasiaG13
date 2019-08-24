#pragma once

/* Disable Nighttime
 * Cause daylight appearance between the hours of 18:00 and 4:00.
 * PATCHES: Renderer2.dll
 */

#include "../Main.h"
#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_DisableNighttime : public IGenericPatcher {
public:
	CPatcher_DisableNighttime();
	bool ReadINI( void );
	bool WriteINI( void );

private:
	// Hook functions
	static void patchNighttime(void);
};

typedef Singleton<CPatcher_DisableNighttime> SngPatcher_DisableNighttime;