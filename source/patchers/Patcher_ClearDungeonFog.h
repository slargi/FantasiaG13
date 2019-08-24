#pragma once

/* Clear Dungeon Fog
 * Clear fog of war on dungeon minimaps.
 * PATCHES: Standard.dll
 */

#include "../Main.h"
#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_ClearDungeonFog : public IGenericPatcher {
public:
	CPatcher_ClearDungeonFog();
	bool ReadINI( void );
	bool WriteINI( void );
private:
};

typedef Singleton<CPatcher_ClearDungeonFog> SngPatcher_ClearDungeonFog;