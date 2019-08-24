#pragma once

/* Name Of Mod
 * Description of mod
 * PATCHES: XXX.dll
 *
 * CTRL+H "TimeAlarm"
 */

#include "../Main.h"
#include "../Singleton.h"
#include "GenericPatcher.h"

class CPatcher_TimeAlarm : public IGenericPatcher {
public:
	CPatcher_TimeAlarm();
	bool Uninstall( void );
	bool Toggle( void );

	bool ReadINI( void );
	bool WriteINI( void );
	bool ReadINIAll( void );
	static bool IsPatchEnabled(void);
	static bool PatchToggle(void);
	static bool PatchEnable(void);
	static bool PatchDisable(void);

	static wchar_t dataBuf[256];

	static int CurNo;

	static int tempRinged;
	static int tempUsing;
	static int tempHour;
	static int tempHour1;
	static int tempHour2;
	static int tempMin;
	static int tempMin1;
	static int tempMin2;
	static int tempCode;
	static wchar_t *tempText;

	static int AlarmRinged[10];
	static int AlarmUsing[10];
	static int AlarmHour[10];
	static int AlarmHour1[10];
	static int AlarmHour2[10];
	static int AlarmMin[10];
	static int AlarmMin1[10];
	static int AlarmMin2[10];
	static int AlarmCode[10];
	static wchar_t AlarmText[10][256];

	static int DisableDummy;

	static int AlarmErrorRange1;
	static int AlarmErrorRange2;

	static wchar_t NaoRecharged[];
private:
	// Options
	static bool PatchEnabled;
	static bool SetString(wchar_t * string);
	static void __stdcall patchFormat(wchar_t * buff,wchar_t * str,int min,int hour);
	// Hook functions
	static void patchTimeAlarm(void);
	static void patchTimeAlarmCaption(void);
	// Variables for hook functions
	LPBYTE funcPointer1;
	LPBYTE funcPointer2;
	LPBYTE funcPointer3;
	static LPBYTE addrAlarm;
	static LPBYTE addrNoAlarm;
	static LPBYTE addrTargetReturn;
	static LPBYTE addrTargetReturn2;
	static LPBYTE addrGetGlobalTime;
	static LPBYTE addrShowCaption;
	static LPBYTE addrShowChatMsg;
	static LPBYTE addrCStringTUni_wchar;
	static LPBYTE addrGetObjectId;
	static LPBYTE addrGlobalTimeToGameTime;
	static LPBYTE addrIsUsingNaosSupport;
	static LPBYTE addrUsableContents;
};

typedef Singleton<CPatcher_TimeAlarm> SngPatcher_TimeAlarm;