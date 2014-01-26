#pragma once
class AboutDialog
{
public:
	AboutDialog(void);
	virtual ~AboutDialog(void);

	static INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
};

