#pragma once

/* Combat Mastery Swap
 */

#include "../Main.h"
#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_CombatMasterySwap : public IGenericPatcher {
public:
	CPatcher_CombatMasterySwap();
	bool ReadINI(void);
	bool WriteINI(void);
	short int GetSkillID(void) { return currentSkill;  }
private:
	// Hook functions
	static void patchCombatMastery(void);
	static void cancelSkill(void);
	static void cancelSkill1(void);
	static void completeSkill(void);
	static void setIsSkillOn(void);
	static void fixCharge(void);
	// Variables for hook functions
	static int isSkillOn;
	static int isCharge;
	static int petCheck;
	static short int skillCheck;
	static int currentSkill;
	static LPBYTE addrMintWriteWord;
	static LPBYTE addrCMessage;
	static LPBYTE addrComplete;
	static LPBYTE addrTargetReturn;
	static LPBYTE addrTargetReturn1;
	static LPBYTE addrTargetReturn2;
	static LPBYTE addrTargetReturn3;
	static LPBYTE addrTargetReturn4;
	static LPBYTE addrTargetReturn5;
	static LPBYTE addrTargetReturn6;
	static LPBYTE addrTargetReturn7;
	static LPBYTE oldAddr;
};

typedef Singleton<CPatcher_CombatMasterySwap> SngPatcher_CombatMasterySwap;