#include "StdAfx.h"
#include "mApplication.h"
#include "FrameWindow.h"
#include "Resource.h"

mApplication::mApplication(HINSTANCE hInstance, int nCmdShow)
{
	hInst    = hInstance;
	nShowCmd = nCmdShow;

}


mApplication::~mApplication(void)
{
}

int mApplication::run()
{
    MSG msg;
	HACCEL hAccelTable;

	if(!RegisterWindowClasses(hInst))
		return 0;

	hAccelTable = LoadAccelerators(hInst, MAKEINTRESOURCE(IDC_MYNOTE));

	CreateMainWindow(hInst, nShowCmd);

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!/*TranslateMDISysAccel(hwndMDIClient, &msg) && */TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int) msg.wParam;
}

BOOL mApplication::CreateMainWindow(HINSTANCE hInstance, int nCmdShow)
{
   hMainWnd = CreateWindow(FrameWindow::GetWindowClassName(), L"myNote", WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

   if (!hMainWnd)
   {
      return FALSE;
   }

   ShowWindow(hMainWnd, nCmdShow);
   UpdateWindow(hMainWnd);

   return TRUE;
}

BOOL mApplication::RegisterWindowClasses(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= (WNDPROC)FrameWindow::FrameWndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 40;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MYNOTE));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_MYNOTE);
	wcex.lpszClassName	= FrameWindow::GetWindowClassName();
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	if(!RegisterClassEx(&wcex))
		return FALSE;

	return TRUE;
}
