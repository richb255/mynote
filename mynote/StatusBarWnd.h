#pragma once
class StatusBarWnd
{
public:
	StatusBarWnd(HWND hWnd);
	virtual ~StatusBarWnd(void);
	bool Create();
	void SetParts(unsigned int numParts, unsigned int* parts);
	void SetText(LPWSTR lpText, unsigned int nPart, unsigned int nOption = 0);

private:
	HWND hStatusWnd;
	HWND hParentWnd;
};

