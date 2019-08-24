#pragma once

#include "../Main.h"
#include "../FileSystem.h"
#include "../MemoryPatch.h"

class IGenericPatcher
{
public:
	IGenericPatcher( void ) {
		installed = false;
		patchname = "";
	}
	virtual ~IGenericPatcher( void ) {}
	virtual bool Install( void ) {
		if (patches.empty()) return false;

		bool result = true;
		vector<MemoryPatch>::iterator it;
		for (it = patches.begin(); it != patches.end(); it++)
		{
			result &= (*it).Apply();
		}
		if (result) {
			installed = true;
			WriteLog("Patch installation successful: %s.\n", patchname.c_str());
		} else {
			WriteLog("Patch installation failed: %s.\n", patchname.c_str());
		}
		return result;
	}
	virtual bool Uninstall( void ) {
		bool result = true;
		vector<MemoryPatch>::iterator it;
		for (it = patches.begin(); it != patches.end(); it++)
			result &= (*it).Revert();
		installed = false;
		return result;
	}
	virtual bool IsInstalled( void ) {
		return installed;
	}
	virtual bool Toggle( void ) {
		if (IsInstalled())
			return Uninstall();
		else return Install();
	}
	virtual bool ReadINI( void ) = 0;
	virtual bool WriteINI( void ) = 0;

protected:
	bool CheckPatches( void ) {
		try {
			vector<MemoryPatch>::iterator it;
			for (it = patches.begin(); it != patches.end(); it++) {
				if (!(*it).Check()) {
					WriteLog("ERROR: Patch at address 0x%08lX failed key check.\n", (*it).GetAddr());
					(*it).Dump();
					patches.clear();
					return false;
				}
			}
			return true;
		} catch(exception& e) {
			DebugLog(e.what());
			return false;
		}
	}

	vector<MemoryPatch> patches;
	bool installed;
	string patchname; // For logging
};