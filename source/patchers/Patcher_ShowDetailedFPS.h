#pragma once

/* Show Detailed FPS
 * PATCHES: Renderer2.dll.dll
 *
 * CTRL+H "ShowDetailedFPS"
 */

#include "../Main.h"
#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_ShowDetailedFPS : public IGenericPatcher {
public:
	CPatcher_ShowDetailedFPS();
	bool ReadINI(void);
	bool WriteINI(void);

private:
	// Hook functions
	// Variables for hook functions
};

typedef Singleton<CPatcher_ShowDetailedFPS> SngPatcher_ShowDetailedFPS;