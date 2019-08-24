#pragma once

/* Detect Unpack
*  ...yeah
 * PATCHES: ESL.dll
 */

#include "../Main.h"
#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_DetectUnpack : public IGenericPatcher {
public:
	CPatcher_DetectUnpack();
	bool StartDetection(LPBYTE addr);
	bool ReadINI(void);
	bool WriteINI(void);

private:
	// Hook functions
	static void CPatcher_DetectUnpack::Detection(void);
	// Variables for hook functions
	static LPBYTE CPatcher_DetectUnpack::addrTargetReturn;
};

typedef Singleton<CPatcher_DetectUnpack> SngPatcher_DetectUnpack;