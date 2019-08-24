#pragma once

/* No Channel Move Denial
 * PATCHES: Pleione.dll
 */

#include "../Main.h"
#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_NoChannelMoveDenial : public IGenericPatcher {
public:
	CPatcher_NoChannelMoveDenial();
	bool ReadINI(void);
	bool WriteINI(void);

private:
	// Hook functions
	// Variables for hook functions
};

typedef Singleton<CPatcher_NoChannelMoveDenial> SngPatcher_NoChannelMoveDenial;