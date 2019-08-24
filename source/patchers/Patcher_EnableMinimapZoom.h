#pragma once

/* Enable Minimap Zoom
 * CTRL+H "EnableMinimapZoom"
 */

#include "../Main.h"
#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_EnableMinimapZoom : public IGenericPatcher {
public:
	CPatcher_EnableMinimapZoom();
	bool ReadINI(void);
	bool WriteINI(void);

private:
	// Hook functions
	// Variables for hook functions
};

typedef Singleton<CPatcher_EnableMinimapZoom> SngPatcher_EnableMinimapZoom;