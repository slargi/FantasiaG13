#pragma once

/* Modify Zoom Limit
 * Modify the maximum zoom distance (1~50000).
 * PATCHES: Renderer2.dll
 */

#include "../Main.h"
#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_ModifyZoomLimit : public IGenericPatcher {
public:
	CPatcher_ModifyZoomLimit();
	bool ReadINI( void );
	bool WriteINI( void );
	bool SetLimit(int value);
	int GetLimit(void);

private:
	static float zoomLimit;
};

typedef Singleton<CPatcher_ModifyZoomLimit> SngPatcher_ModifyZoomLimit;