#pragma once

#include <windows.h>
#include <CommDlg.h>

class FileDialogWnd
{
public:
	FileDialogWnd(void);
	virtual ~FileDialogWnd(void);
	bool GetSaveFileName(HWND hParent);
	bool GetOpenFileName(HWND hParent);

private:
	OPENFILENAME  ofn;
};

