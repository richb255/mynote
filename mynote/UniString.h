#pragma once

using namespace std;

#include <string> 

class UniString :
	public wstring
{
public:
	UniString(void);
	UniString(wchar_t* str);
	int LoadString(int nId, HINSTANCE hinst = (HINSTANCE)GetModuleHandle(NULL));
	virtual ~UniString(void);
};

