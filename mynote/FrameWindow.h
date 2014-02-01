#pragma once

#define WINDOWMENU  3   /* position of window menu               */
#define SHORTMENU   2   /* position of short version window menu */
#define IDM_WINDOWCHILD 4100

class FrameWindow
{
public:
	FrameWindow(HWND hWnd);
	virtual ~FrameWindow(void);
	static LRESULT FrameWndProc(HWND hWndFrame, UINT uMsg, WPARAM wParam, LPARAM lParam);
	static LPWSTR GetWindowClassName();

private:
	HWND hFrameWnd;
	HWND hClientWnd;

	int Create(WPARAM wParam, LPARAM lParam);
    void NewDocument(WPARAM wParam, LPARAM lParam);
};

