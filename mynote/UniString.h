#pragma once

#include <string> 

class UniString :
	public std::wstring
{
public:
	UniString(void);
	UniString(wchar_t* str);
	int LoadString(int nId, HINSTANCE hinst = (HINSTANCE)GetModuleHandle(NULL));
	virtual ~UniString(void);
};

