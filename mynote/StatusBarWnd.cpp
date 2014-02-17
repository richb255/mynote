#include "StdAfx.h"
#include "StatusBarWnd.h"


StatusBarWnd::StatusBarWnd(HWND hWnd)
{
	hParentWnd = hWnd;
	hStatusWnd = NULL;
}


StatusBarWnd::~StatusBarWnd(void)
{
}

bool StatusBarWnd::Create()
{
	hStatusWnd = CreateStatusWindow(WS_CHILD|WS_VISIBLE, L"", hParentWnd, 2000);
	if(!hStatusWnd)
		return false;

	return true;
}

void StatusBarWnd::SetParts(unsigned int numParts, unsigned int* parts)
{
	SendMessage(hStatusWnd, SB_SETPARTS, (WPARAM)numParts, (LPARAM)parts);
}

void StatusBarWnd::SetText(LPWSTR lpText, unsigned int nPart, unsigned int nOption)
{
	SendMessage(hStatusWnd, SB_SETTEXT, (WPARAM)nPart|nOption, (LPARAM)lpText);
	UpdateWindow(hStatusWnd);
}

