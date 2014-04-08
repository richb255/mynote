#pragma once
class ToolbarWnd
{
public:
	ToolbarWnd(HWND hWnd);
	virtual ~ToolbarWnd(void);

private:
	HWND hToolbarWnd;
	HWND hParentWnd;
	void MoveBar(int x, int y, int w, int h);
};

