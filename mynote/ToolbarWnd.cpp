#include "StdAfx.h"
#include "ToolbarWnd.h"


ToolbarWnd::ToolbarWnd(HWND hWnd)
{
	hParentWnd = hWnd;
}


ToolbarWnd::~ToolbarWnd(void)
{
}

void ToolbarWnd::MoveBar(int x, int y, int w, int h)
{
	MoveWindow(hToolbarWnd, x, y, w, h, TRUE);
}


