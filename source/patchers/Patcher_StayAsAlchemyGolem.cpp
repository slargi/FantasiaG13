#include "Patcher_StayAsAlchemyGolem.h"
#include "../Addr.h"
#include "../FileSystem.h"

//-----------------------------------------------------------------------------
// Static variable initialization

//-----------------------------------------------------------------------------
// Constructor

CPatcher_StayAsAlchemyGolem::CPatcher_StayAsAlchemyGolem(void)
{
	patchname = "Stay As Alchemy Golem";

	vector<WORD> patch;
	vector<WORD> backup;

	backup +=
		0x0F, 0x84, 0xEC, 0x02, 0x00, 0x00, 0x8B, 0x4E, 0x28;

	patch +=
		-1, 0x81, -1, -1, -1, -1, -1, -1, -1;

	MemoryPatch mp(NULL, patch, backup);
	mp.Search(L"Pleione.dll");

	patches += mp;
	if (CheckPatches())
		WriteLog("Patch initialization successful: %s.\n", patchname.c_str());
	else
		WriteLog("Patch initialization failed: %s.\n", patchname.c_str());
}

//-----------------------------------------------------------------------------
// Hook functions

//-----------------------------------------------------------------------------
// INI Functions

bool CPatcher_StayAsAlchemyGolem::ReadINI(void)
{
	if (ReadINI_Bool(L"StayAsAlchemyGolem"))
		return Install();
	return true;
}

bool CPatcher_StayAsAlchemyGolem::WriteINI(void)
{
	WriteINI_Bool(L"StayAsAlchemyGolem", IsInstalled());
	return true;
}