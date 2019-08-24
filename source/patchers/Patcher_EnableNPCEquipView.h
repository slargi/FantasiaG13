#pragma once

/* Enable NPC Equip View
 * Description of mod
 * PATCHES: XXX.dll
 *
 * CTRL+H "EnableNPCEquipView"
 */

#include "../Main.h"
#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_EnableNPCEquipView : public IGenericPatcher {
public:
	CPatcher_EnableNPCEquipView();
	bool ReadINI(void);
	bool WriteINI(void);

private:
	// Hook functions
	// Variables for hook functions
};

typedef Singleton<CPatcher_EnableNPCEquipView> SngPatcher_EnableNPCEquipView;