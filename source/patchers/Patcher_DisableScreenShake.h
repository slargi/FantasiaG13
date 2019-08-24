#pragma once

/* Disable Screen Shake
 * PATCHES: Renderer2.dll
 */

#include "../Main.h"
#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_DisableScreenShake : public IGenericPatcher {
public:
	CPatcher_DisableScreenShake();
	bool ReadINI(void);
	bool WriteINI(void);

private:
	// Hook functions
	// Variables for hook functions
};

typedef Singleton<CPatcher_DisableScreenShake> SngPatcher_DisableScreenShake;