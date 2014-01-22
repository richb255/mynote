#include "StdAfx.h"
#include "FrameWindow.h"


FrameWindow::FrameWindow(void)
{
}


FrameWindow::~FrameWindow(void)
{
}

LRESULT FrameWindow::FrameWndProc(HWND hWndFrame, HWND hwndClient, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	FrameWindow* frame = (FrameWindow*)GetProp(hWndFrame, L"FrameWindowPointer");

    switch(uMsg)
	{
	case WM_NCCREATE:
        if(NULL == frame)
		{
			frame = new FrameWindow();
			SetProp(hWndFrame, L"FrameWindowPointer", frame);
		}
		return DefFrameProc(hWndFrame, hwndClient, uMsg, wParam, lParam);

	default:
	   return DefFrameProc(hWndFrame, hwndClient, uMsg, wParam, lParam);
	}
}

LPWSTR FrameWindow::GetWindowClassName()
{
	return L"MyNoteMainFrameWindowClass";
}

