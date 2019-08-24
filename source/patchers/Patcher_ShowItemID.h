#pragma once

/* Show Item ID
 * Displays Item ID in tooltip
 */

#include "../Main.h"
#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_ShowItemID : public IGenericPatcher {
public:
	CPatcher_ShowItemID();
	bool ReadINI(void);
	bool WriteINI(void);

private:
	// Hook functions
	// static void FindItem(void);
	static void GetItemID(void);
	static void patchDataColorString();
	static void __stdcall injectItemID();

	// Variables for hook functions
	static wchar_t dataColorString1[];
	static int itemID;
	static bool printed;
	static LPBYTE addrCommonAPI;
	static LPBYTE addrg_cStandardAPIMgrBlock;
	static LPBYTE addrTargetReturn;
	static LPBYTE addrTargetReturn1;
};

typedef Singleton<CPatcher_ShowItemID> SngPatcher_ShowItemID;