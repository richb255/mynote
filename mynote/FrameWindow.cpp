#include "StdAfx.h"
#include "FrameWindow.h"
#include "DocumentWindow.h"
#include "AboutDialog.h"
#include "Resource.h"


FrameWindow::FrameWindow(HWND hWnd)
{
	hFrameWnd = hWnd;
    hClientWnd = NULL;
}


FrameWindow::~FrameWindow(void)
{
}

LRESULT FrameWindow::FrameWndProc(HWND hWndFrame, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    FrameWindow* frame = (FrameWindow*)GetProp(hWndFrame, L"FrameWindowPointer");

    switch(uMsg)
    {
    case WM_NCCREATE:
        if(NULL == frame)
        {
            frame = new FrameWindow(hWndFrame);
            SetProp(hWndFrame, L"FrameWindowPointer", frame);
        }
        return TRUE;

    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case IDM_ABOUT:
            DialogBox((HINSTANCE)GetModuleHandle(NULL), MAKEINTRESOURCE(IDD_ABOUTBOX), hWndFrame, AboutDialog::About);
            break;

		case IDM_NEW:
			frame->NewDocument(wParam, lParam);
			break;

        case IDM_EXIT:
            DestroyWindow(hWndFrame);
            break;

        default:
            if(frame)
                return DefFrameProc(hWndFrame, frame->hClientWnd, uMsg, wParam, lParam);
	        else
		        return DefFrameProc(hWndFrame, NULL, uMsg, wParam, lParam);
        }
        break;
        
    case WM_CREATE:
        return frame->Create(wParam, lParam);

    case WM_DESTROY:
        RemoveProp(hWndFrame,  L"FrameWindowPointer");
        if(frame)
            delete frame;
        PostQuitMessage(0);
        return 0;

    default:
       if(frame)
           return DefFrameProc(hWndFrame, frame->hClientWnd, uMsg, wParam, lParam);
	   else
		   return DefFrameProc(hWndFrame, NULL, uMsg, wParam, lParam);
    }

       if(frame)
           return DefFrameProc(hWndFrame, frame->hClientWnd, uMsg, wParam, lParam);
	   else
		   return DefFrameProc(hWndFrame, NULL, uMsg, wParam, lParam);
}

LPWSTR FrameWindow::GetWindowClassName()
{
    return L"MyNoteMainFrameWindowClass";
}

int FrameWindow::Create(WPARAM wParam, LPARAM lParam)
{
   CLIENTCREATESTRUCT ccs;

   ccs.hWindowMenu = GetSubMenu (GetMenu(hFrameWnd),  1);
	    ccs.idFirstChild = IDM_WINDOWCHILD;

   hClientWnd = CreateWindow(L"MDICLIENT", NULL, WS_CHILD | WS_CLIPCHILDREN | WS_VSCROLL | WS_HSCROLL,
      0, 0, 0, 0, hFrameWnd, (HMENU)1000, (HINSTANCE)GetModuleHandle(NULL), (LPSTR)&ccs);

   if (!hClientWnd)
   {
      return -1;
   }

    
    return 0;
}

void FrameWindow::NewDocument(WPARAM wParam, LPARAM lParam)
{
   HWND hChildWnd = CreateWindowEx(WS_EX_MDICHILD, DocumentWindow::GetWindowClassName(), NULL, MDIS_ALLCHILDSTYLES | WS_VISIBLE | WS_CHILD | WS_CLIPCHILDREN | WS_VSCROLL | WS_HSCROLL,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, hClientWnd, NULL, (HINSTANCE)GetModuleHandle(NULL), NULL);

   ShowWindow(hClientWnd, SW_SHOW);
}