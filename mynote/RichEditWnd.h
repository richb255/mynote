#pragma once
class RichEditWnd
{
public:
	RichEditWnd(HWND hWnd);
	virtual ~RichEditWnd(void);
	bool Create();

private:
	HWND hRichEdit;
	HWND hParentWnd;
	void MoveControl(int x, int y, int w, int h);
};

