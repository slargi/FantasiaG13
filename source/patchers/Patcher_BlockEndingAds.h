#pragma once

/* Block Ending Ads
 * Block the popup ads on game exit.
 * PATCHES: Pleione.dll
 */

#include "../Main.h"
#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_BlockEndingAds : public IGenericPatcher {
public:
	CPatcher_BlockEndingAds();
	bool ReadINI( void );
	bool WriteINI( void );
private:
};

typedef Singleton<CPatcher_BlockEndingAds> SngPatcher_BlockEndingAds;