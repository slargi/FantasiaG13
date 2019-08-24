#include "Patcher_UserCommands.h"
#include "../Addr.h"
#include "../FileSystem.h"

//-----------------------------------------------------------------------------
// Static variable initialization
wchar_t CPatcher_UserCommands::fantasiaTag[] = L"<Fantasia>";
wchar_t CPatcher_UserCommands::fantasiaMsg[] = L"";
LPBYTE CPatcher_UserCommands::addrTargetReturn = NULL;
LPBYTE CPatcher_UserCommands::addrCleanUp = NULL;
LPBYTE CPatcher_UserCommands::addrCStringT_Implement = NULL;
LPBYTE CPatcher_UserCommands::addrCStringT_Constr = NULL;
LPBYTE CPatcher_UserCommands::addrOnGetChatMessage = NULL;
LPBYTE CPatcher_UserCommands::addrGetInstance = NULL;
bool CPatcher_UserCommands::isCommand = false;
Reload CPatcher_UserCommands::reloadINI = NULL;
IntFunction CPatcher_UserCommands::getSkillID = NULL;
//-----------------------------------------------------------------------------
// Constructor

CPatcher_UserCommands::CPatcher_UserCommands(void)
{
	patchname = "UserCommands";

	addrCStringT_Implement = CAddr::Addr(CStringT_Implement);
	addrCStringT_Constr = CAddr::Addr(CStringTUni_Constr);
	if (!addrCStringT_Implement || !addrCStringT_Constr) {
		WriteLog("Patch initialization failed: %s.\n", patchname.c_str());
		WriteLog("   Missing dependency.\n");
		return;
	}

	vector<WORD> patch;
	vector<WORD> backup;

	backup +=
		0x6A, 0x0C,
		0xB8, 0x7E, 0x97, 0xD0, 0x63;

	patch +=
		0xE9, 0x01FF,
		0x01FF, 0x01FF, 0x01FF, 0x90, 0x90;

	MemoryPatch mp((LPBYTE)0x6386213B, patch, backup);
	mp.PatchRelativeAddress(0x01, (LPBYTE)UserCommands);
	addrTargetReturn = (LPBYTE)0x63862140;

	vector<WORD> patch1;
	vector<WORD> backup1;

	backup1 +=
		0x8A, 0xC3,
		0xE8, 0xB0, 0xB5, 0x49, 0x00;

	patch1 +=
		0xE9, 0x01FF,
		0x01FF, 0x01FF, 0x01FF, 0x90, 0x90;

	MemoryPatch mp1((LPBYTE)0x6386216D, patch1, backup1);
	mp1.PatchRelativeAddress(0x01, (LPBYTE)preventMsg);
	addrCleanUp = (LPBYTE)0x63CFD724;

	addrOnGetChatMessage = (LPBYTE)0x63A3EAAC;
	addrGetInstance = (LPBYTE)0x63FBDF38;
	
	patches += mp;
	patches += mp1;
	if (CheckPatches())
		WriteLog("Patch initialization successful: %s.\n", patchname.c_str());
	else
		WriteLog("Patch initialization failed: %s.\n", patchname.c_str());
}

//-----------------------------------------------------------------------------
// Hook functions
NAKED void CPatcher_UserCommands::UserCommands(void)
{
	__asm {
		// get start addr of msg (wchar_t)
		mov isCommand, 0
		mov eax, [eax]
		add eax, 0x1A

		// push character array
		sub	esp, 4h
		push eax

		call getCharacterArray
		add esp, 4h

		// original code
		push 0xC
		mov eax, 0x63D0977E
		jmp addrTargetReturn
	}
}

NAKED void CPatcher_UserCommands::preventMsg(void)
{
	if (isCommand) {
		__asm {
			mov al, 1
		}
	}
	else {
		__asm {
			mov al, 0
		}
	}
	__asm {
		call addrCleanUp
		ret 0004
	}
}

void __stdcall CPatcher_UserCommands::getCharacterArray(wchar_t* arr)
{
	if (wcsncmp(arr, L".", 1) == 0) {
		wchar_t* cmd = _wcslwr(arr);
		if (!wcscmp(cmd, L".reload") || !wcscmp(cmd, L".r")) {
			reloadINI();
			swprintf_s(fantasiaMsg, 255, L"Reload Complete");
		}
		else if (!wcscmp(cmd, L".ping") || !wcscmp(cmd, L".p")) {
			swprintf_s(fantasiaMsg, 255, L"pong");
		}
		else if (!wcscmp(cmd, L".help") || !wcscmp(cmd, L".h")) {
			swprintf_s(fantasiaMsg, 255, L"Available commands:\n"
											 ".help .h - displays available commands\n"
											 ".reload .r - reloads all patches\n"
											 ".ping .p - displays 'pong' back\n"
											 ".swap .s - (currently) tells you the Skill ID you swapped combat mastery with");
		}
		else if (!wcsncmp(cmd, L".swap", 6) || !wcsncmp(cmd, L".s", 2)) {
			int skillID = getSkillID();

			if (skillID) {
				swprintf_s(fantasiaMsg, 255, L"Combat attack currently swapped to Skill ID: %d", skillID);
			}
			else {
				swprintf_s(fantasiaMsg, 255, L"Combat attack is not swapped currently");
			}
		}
		else {
			swprintf_s(fantasiaMsg, 255, L"Invalid command");
		}
		__asm {
			pushad

			// get and push fantasiamsg
			sub esp, 4h
			lea ecx, dword ptr ss : [ebp - 14h]
			call addrCStringT_Constr
			and dword ptr ss : [ebp - 4h] , 0
			push offset fantasiaMsg
			call addrCStringT_Implement

			// get and push fantasiatag
			sub esp, 4h
			lea ecx, dword ptr ss : [ebp - 10h]
			call addrCStringT_Constr
			and dword ptr ss : [ebp - 4h] , 0
			push offset fantasiaTag
			call addrCStringT_Implement

			// push contents to display message
			push 0
			push eax
			push 0
			push 0
			lea ecx, [ebp - 14h]
			push ecx
			lea ecx, [ebp - 10h]
			push ecx
			mov ecx, [addrGetInstance]
			mov ecx, [ecx]
			call addrOnGetChatMessage
			add esp, 8h
			popad
		}
		swprintf_s(fantasiaMsg, 255, L"");
		isCommand = true;
	}
}

//-----------------------------------------------------------------------------
// INI Functions

bool CPatcher_UserCommands::addMasterFunctions(Reload ReloadFunc, IntFunction GetSkillID)
{
	reloadINI = ReloadFunc;
	getSkillID = GetSkillID;
	return true;
}

bool CPatcher_UserCommands::ReadINI(void)
{
	if (ReadINI_Bool(L"UserCommands"))
		return Install();
	return true;
}

bool CPatcher_UserCommands::WriteINI(void)
{
	WriteINI_Bool(L"UserCommands", IsInstalled());
	return true;
}