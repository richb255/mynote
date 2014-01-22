#pragma once
class mApplication
{
public:
	mApplication(HINSTANCE hInstance, int nCmdShow);
	virtual ~mApplication(void);
	int run();

private:
	HWND       hMainWnd;
	HINSTANCE  hInst;
	HACCEL     hAccelTable;
	int        nShowCmd;

	BOOL CreateMainWindow(HINSTANCE hInstance, int nCmdShow);
	BOOL RegisterWindowClasses(HINSTANCE hInstance);
};

