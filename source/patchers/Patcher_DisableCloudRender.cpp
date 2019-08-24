#include "Patcher_DisableCloudRender.h"
#include "../Addr.h"
#include "../FileSystem.h"

//-----------------------------------------------------------------------------
// Static variable initialization

//-----------------------------------------------------------------------------
// Constructor

CPatcher_DisableCloudRender::CPatcher_DisableCloudRender( void )
{
	patchname = "Disable Cloud Render";

	LPBYTE addrRenderSkyTexture = CAddr::Addr(CRendererContext_RenderSkyTexture);
	if (!addrRenderSkyTexture) {
		WriteLog("Patch initialization failed: %s.\n", patchname.c_str());
		WriteLog("   Missing dependency.\n");
		return;
	}

	vector<WORD> patch;
	vector<WORD> backup;

	backup +=
		0x0F, 0x84, 0x3F, 0x08, 0x00, 0x00;

	patch +=
		0x90, 0xE9, -1, -1, -1, -1;

	MemoryPatch mp(addrRenderSkyTexture + 0x1C, patch, backup );
	
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

bool CPatcher_DisableCloudRender::ReadINI( void )
{
	if ( ReadINI_Bool( L"DisableCloudRender" ))
		return Install();
	return true;
}

bool CPatcher_DisableCloudRender::WriteINI( void )
{
	WriteINI_Bool( L"DisableCloudRender", IsInstalled() );
	return true;
}