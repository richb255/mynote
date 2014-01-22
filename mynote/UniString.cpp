#include "StdAfx.h"
#include "UniString.h"

UniString::UniString(void)
{
}

UniString::UniString(wchar_t* str)
{
	assign(str);
}


UniString::~UniString(void)
{
}

int UniString::LoadString(int nId, HINSTANCE hinst)
{
	wchar_t* buff = new wchar_t[1000];
	int len = ::LoadString(hinst, nId, buff, 1000);

	delete buff;
	return len;
}