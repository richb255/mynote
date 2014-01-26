#pragma once
class FrameWindow
{
public:
	FrameWindow(void);
	virtual ~FrameWindow(void);
	static LRESULT FrameWndProc(HWND hWndFrame, HWND hwndClient, UINT uMsg, WPARAM wParam, LPARAM lParam);
	static LPWSTR GetWindowClassName();

private:
	HWND hFrameWnd;
	HWND hClientWnd;

	int Create(WPARAM wParam, LPARAM lParam);
};

