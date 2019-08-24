#include "Patcher_UseBitmapFonts.h"
#include "../Addr.h"
#include "../FileSystem.h"

//-----------------------------------------------------------------------------
// Constructor

CPatcher_UseBitmapFonts::CPatcher_UseBitmapFonts( void )
{
	patchname = "Use Bitmap Fonts";

	LPBYTE addrCompiler = CAddr::Addr(CDefaultCompiler_Compile);
	LPBYTE addrTagCompiler = CAddr::Addr(CDefaultTagCompiler_Compile);
	LPBYTE addrHTMLCompiler = CAddr::Addr(CHTMLCompiler_Compile);

	if (!addrCompiler ||
		!addrTagCompiler ||
		!addrHTMLCompiler)
	{
		WriteLog("Patch initialization failed: %s.\n", patchname.c_str());
		WriteLog("   Missing dependency.\n");
		return;
	}

	// Patch for CDefaultCompiler::Compile

	vector<WORD> patchCompiler;
	vector<WORD> backupCompiler;

	backupCompiler +=
		0x80, 0xBB, 0x80, 0x00, 0x00, 0x00, 0x00,	// +40: CMP BYTE PTR [EBX+80h], 0
		0x53,										// +47: PUSH EBX
		0xFF, 0x75, 0x08,							// +48: PUSH [EBP+08h]
		0x8B, 0xCE,									// +4B: MOV ECX, ESI
		0x74, 0x07;									// +4D: JZ SHORT +0x07
	patchCompiler +=
		-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
		0x90, 0x90;									// +4D: JZ => NOP
	MemoryPatch mpCompiler( addrCompiler + 0x40, patchCompiler, backupCompiler );
	
	// Patch for CDefaultTagCompiler::Compile

	vector<WORD> patchTagCompiler;
	vector<WORD> backupTagCompiler;

	backupTagCompiler +=
		0x80, 0xBE, 0x90, 0x00, 0x00, 0x00, 0x00,	// +153: CMP BYTE PTR [ESI+90h], 0
		0x8B, 0xCE,									// +15A: MOV ECX, ESI
		0x74, 0x11;									// +15C: JZ SHORT +0x11
	patchTagCompiler +=
		-1, -1, -1, -1, -1, -1, -1,	-1, -1,
		0x90, 0x90;									// +15C: JZ => NOP
	MemoryPatch mpTagCompiler( addrTagCompiler + 0x153, patchTagCompiler, backupTagCompiler );

	// Patch for CHTMLCompiler::Compile

	vector<WORD> patchHTMLCompiler;
	vector<WORD> backupHTMLCompiler;

	backupHTMLCompiler +=
		0x80, 0xBE, 0x90, 0x00, 0x00, 0x00, 0x00,	// +D6: CMP BYTE PTR [ESI+90h], 0
		0x0F, 0xB7, 0xC0,							// +DD: MOVZX EAX, AX
		0x8B, 0xCE,									// +E0: MOV ECX, ESI
		0x74, 0x0B;									// +E2: JZ SHORT +0x0B
	patchHTMLCompiler +=
		-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
		0x90, 0x90;									// +E2: JZ => NOP
	MemoryPatch mpHTMLCompiler( addrHTMLCompiler + 0xD6, patchHTMLCompiler, backupHTMLCompiler );

	// Add patches

	patches += mpCompiler;
	patches += mpTagCompiler;
	patches += mpHTMLCompiler;
	if (CheckPatches())
		WriteLog("Patch initialization successful: %s.\n", patchname.c_str());
	else
		WriteLog("Patch initialization failed: %s.\n", patchname.c_str());
}

//-----------------------------------------------------------------------------
// INI Functions

bool CPatcher_UseBitmapFonts::ReadINI( void )
{
	if ( ReadINI_Bool( L"UseBitmapFonts" ))
		return Install();
	return true;
}

bool CPatcher_UseBitmapFonts::WriteINI( void )
{
	WriteINI_Bool( L"UseBitmapFonts", IsInstalled() );
	return true;
}