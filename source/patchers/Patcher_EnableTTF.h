#pragma once

/* Enable TTF
 */

#include "../Main.h"
#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_EnableTTF : public IGenericPatcher {
public:
	CPatcher_EnableTTF();
	bool ReadINI(void);
	bool WriteINI(void);

private:
	// Hook functions
	// Variables for hook functions
};

typedef Singleton<CPatcher_EnableTTF> SngPatcher_EnableTTF;