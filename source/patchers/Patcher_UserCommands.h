#pragma once

/* User Commands
 */

#include "../Main.h"
#include "../Singleton.h"
#include "GenericPatcher.h"

typedef bool(*Reload)(void);
typedef int(*IntFunction)(void);

class CPatcher_UserCommands : public IGenericPatcher {
public:
	CPatcher_UserCommands();
	bool addMasterFunctions(Reload, IntFunction);
	bool ReadINI(void);
	bool WriteINI(void);

private:
	// Hook functions
	static void UserCommands();
	static void preventMsg();
	// Variables for hook functions
	static wchar_t fantasiaTag[256];
	static wchar_t fantasiaMsg[256];
	static LPBYTE addrTargetReturn;
	static LPBYTE addrCleanUp;
	static LPBYTE addrCStringT_Implement;
	static LPBYTE addrCStringT_Constr;
	static LPBYTE addrOnGetChatMessage;
	static LPBYTE addrGetInstance;
	static Reload reloadINI;
	static IntFunction getSkillID;
	static bool isCommand;
	static void __stdcall getCharacterArray(wchar_t*);
};

typedef Singleton<CPatcher_UserCommands> SngPatcher_UserCommands;