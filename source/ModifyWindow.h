#pragma once

#include "Main.h"

class CModifyWindow
{
public:
	static HWND FindMabiHWnd( void );
	static bool SpawnModifier( int, int );
	static bool IsMinimized( void );
private:
	static bool ModifyMenu( void );
	static bool UpdateMenu( void );
	static bool UpdateIcon( void );
	static DWORD WINAPI CModifyWindow::ModifierThreadMain( LPVOID lpParam );
	static BOOL EnumThreadWindows_fn(HWND hwnd, LPARAM lparam);
	static LRESULT APIENTRY FantasiaWndFunc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam );
};