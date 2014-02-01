#include "StdAfx.h"
#include "DocumentWindow.h"


DocumentWindow::DocumentWindow(HWND hWnd)
{
	hChildWnd = hWnd;
}


DocumentWindow::~DocumentWindow(void)
{
}

LRESULT DocumentWindow::WndProc(HWND hWndChild, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	DocumentWindow* doc = (DocumentWindow*)GetProp(hWndChild, L"DocumentPointer");

	    switch(uMsg)
    {
    case WM_NCCREATE:
        if(NULL == doc)
        {
            doc = new DocumentWindow(hWndChild);
            SetProp(hWndChild, L"DocumentPointer", doc);
        }
        return TRUE;

	case WM_DESTROY:
		RemoveProp(hWndChild, L"DocumentPointer");
		if(doc)
			delete doc;
		return 0;

	default:
		return DefMDIChildProc(hWndChild, uMsg, wParam, lParam);
	}
	return DefMDIChildProc(hWndChild, uMsg, wParam, lParam);
}

LPWSTR DocumentWindow::GetWindowClassName()
{
    return L"MyNoteDocumentWindowClass";
}