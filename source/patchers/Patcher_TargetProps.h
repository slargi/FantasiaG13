#pragma once

/* Target Props
 * Enable CTRL-targeting props while in combat mode.
 * PATCHES: Pleione.dll
 */

#include "../Main.h"
#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_TargetProps : public IGenericPatcher {
public:
	CPatcher_TargetProps();
	bool ReadINI( void );
	bool WriteINI( void );

private:
	// Variables for hook functions
	static wchar_t dataStr[];
};

typedef Singleton<CPatcher_TargetProps> SngPatcher_TargetProps;