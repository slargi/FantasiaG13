#pragma once

/* No Channel Penalty Msg
 * PATCHES: Pleione.dll
 *
 * CTRL+H "NoChannelPenaltyMsg"
 */

#include "../Main.h"
#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_NoChannelPenaltyMsg : public IGenericPatcher {
public:
	CPatcher_NoChannelPenaltyMsg();
	bool ReadINI(void);
	bool WriteINI(void);

private:
	// Hook functions
	// Variables for hook functions
};

typedef Singleton<CPatcher_NoChannelPenaltyMsg> SngPatcher_NoChannelPenaltyMsg;