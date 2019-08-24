#pragma once

/* Disable Gray Fog
 * PATCHES: Renderer2.dll
 */

#include "../Main.h"
#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_DisableGrayFog : public IGenericPatcher {
public:
	CPatcher_DisableGrayFog();
	bool ReadINI(void);
	bool WriteINI(void);

private:
	// Hook functions
	// Variables for hook functions
};

typedef Singleton<CPatcher_DisableGrayFog> SngPatcher_DisableGrayFog;