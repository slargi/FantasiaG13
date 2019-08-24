#pragma once

/* Show Simple FPS
 * PATCHES: Renderer2.dll
 */

#include "../Main.h"
#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_ShowSimpleFPS : public IGenericPatcher {
public:
	CPatcher_ShowSimpleFPS();
	bool ReadINI(void);
	bool WriteINI(void);

private:
	// Hook functions
	// Variables for hook functions
};

typedef Singleton<CPatcher_ShowSimpleFPS> SngPatcher_ShowSimpleFPS;