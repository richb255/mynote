#include "StdAfx.h"
#include "FrameWindow.h"
#include "AboutDialog.h"
#include "Resource.h"


FrameWindow::FrameWindow(void)
{
	hClientWnd = NULL;
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
		return TRUE;

	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDM_ABOUT:
			DialogBox((HINSTANCE)GetModuleHandle(NULL), MAKEINTRESOURCE(IDD_ABOUTBOX), hWndFrame, AboutDialog::About);
			break;

		case IDM_EXIT:
			DestroyWindow(hWndFrame);
			break;

		default:
			return DefFrameProc(hWndFrame, hwndClient, uMsg, wParam, lParam);
		}
		return 0;
        
	case WM_CREATE:
		return frame->Create(wParam, lParam);

	case WM_DESTROY:
		RemoveProp(hWndFrame,  L"FrameWindowPointer");
		if(frame)
			delete frame;
		PostQuitMessage(0);
		return 0;

	default:
	   return DefFrameProc(hWndFrame, hwndClient, uMsg, wParam, lParam);
	}

	return DefFrameProc(hWndFrame, hwndClient, uMsg, wParam, lParam);
}

LPWSTR FrameWindow::GetWindowClassName()
{
	return L"MyNoteMainFrameWindowClass";
}

int FrameWindow::Create(WPARAM wParam, LPARAM lParam)
{
	
	return 0;
}

