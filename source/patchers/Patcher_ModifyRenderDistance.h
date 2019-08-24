#pragma once

/* Modify Render Distance
 * PATCHES: Renderer2.dll
 */

#include "../Main.h"
#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_ModifyRenderDistance : public IGenericPatcher {
public:
	CPatcher_ModifyRenderDistance();
	bool ReadINI(void);
	bool WriteINI(void);
	bool SetDistance(float newDistance);
	int GetRenderDistance();
private:
	// Hook functions
	static void SetRenderDistance();
	// Variables for hook functions
	static float renderDistanceLimit;
	static LPBYTE addrTargetReturn;
	static LPBYTE addrRenderDistanceLimit;
};

typedef Singleton<CPatcher_ModifyRenderDistance> SngPatcher_ModifyRenderDistance;