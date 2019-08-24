#pragma once

/* Disable Cloud Render
 * PATCHES: Renderer2.dll
 *
 * CTRL+H "DisableCloudRender"
 */

#include "../Main.h"
#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_DisableCloudRender : public IGenericPatcher {
public:
	CPatcher_DisableCloudRender();
	bool ReadINI(void);
	bool WriteINI(void);

private:
	// Hook functions
	// Variables for hook functions
};

typedef Singleton<CPatcher_DisableCloudRender> SngPatcher_DisableCloudRender;