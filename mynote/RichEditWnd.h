#pragma once

#include "UniString.h"

class RichEditWnd
{
public:
	RichEditWnd(HWND hWnd);
	virtual ~RichEditWnd(void);
	bool Create();
	void SetFileName(LPWSTR newName);

private:
	HWND hRichEdit;
	HWND hParentWnd;
	void MoveControl(int x, int y, int w, int h);

	UniString fileName;
};

