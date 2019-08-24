#pragma once

/* Move While Talking
 * Allow moving while talking to NPCs.
 * PATCHES: Pleione.dll
 */

#include "../Main.h"
#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_MoveWhileTalking : public IGenericPatcher {
public:
	CPatcher_MoveWhileTalking();
	bool ReadINI( void );
	bool WriteINI( void );
private:
};

typedef Singleton<CPatcher_MoveWhileTalking> SngPatcher_MoveWhileTalking;