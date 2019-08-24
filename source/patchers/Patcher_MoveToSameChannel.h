#pragma once

/* Move To Same Channel
 * Enable moving to the same channel you are currently on
 * PATCHES: Pleione.dll
 */

#include "../Main.h"
#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_MoveToSameChannel : public IGenericPatcher {
public:
	CPatcher_MoveToSameChannel();
	bool ReadINI( void );
	bool WriteINI( void );
private:
};

typedef Singleton<CPatcher_MoveToSameChannel> SngPatcher_MoveToSameChannel;