#pragma once

/* Enable Self Right-Click
 * Enable opening the right-click menu on your own character.
 * PATCHES: Pleione.dll
 */

#include "../Main.h"
#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_EnableSelfRightClick : public IGenericPatcher {
public:
	CPatcher_EnableSelfRightClick();
	bool ReadINI( void );
	bool WriteINI( void );

private:
	// Hook functions
	// Variables for hook functions
};

typedef Singleton<CPatcher_EnableSelfRightClick> SngPatcher_EnableSelfRightClick;