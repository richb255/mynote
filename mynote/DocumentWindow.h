#pragma once
class DocumentWindow
{
public:
	static LRESULT WndProc(HWND hWndChild, UINT uMsg, WPARAM wParam, LPARAM lParam);
	DocumentWindow(void);
	virtual ~DocumentWindow(void);
};

