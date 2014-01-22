#include "StdAfx.h"
#include "DocumentWindow.h"


DocumentWindow::DocumentWindow(void)
{
}


DocumentWindow::~DocumentWindow(void)
{
}

LRESULT DocumentWindow::WndProc(HWND hWndChild, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return DefMDIChildProc(hWndChild, uMsg, wParam, lParam);
}