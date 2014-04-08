#include "StdAfx.h"
#include "RichEditWnd.h"


RichEditWnd::RichEditWnd(HWND hWnd)
{
	hParentWnd = hWnd;
	hRichEdit = NULL;
}


RichEditWnd::~RichEditWnd(void)
{
}

bool RichEditWnd::Create()
{
	hRichEdit = CreateWindowEx(0, L"richedit", NULL, WS_CHILD|WS_VISIBLE, CW_USEDEFAULT,
	0, CW_USEDEFAULT, 0, hParentWnd, NULL, (HINSTANCE)GetModuleHandle(NULL), NULL);
	if(!hRichEdit)
		return false;

	return true;
}

void RichEditWnd::MoveControl(int x, int y, int w, int h)
{
	MoveWindow(hRichEdit, x, y, w, h, TRUE);
}

