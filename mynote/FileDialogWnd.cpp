#include "StdAfx.h"
#include "FileDialogWnd.h"


FileDialogWnd::FileDialogWnd(void)
{
  ZeroMemory(&ofn, sizeof(OPENFILENAME));
  ofn.lStructSize = sizeof(OPENFILENAME);

ofn.lpstrFile = new wchar_t[_MAX_PATH];
ofn.nMaxFile = _MAX_PATH;
ofn.lpstrFilter = L"All\0*.*\0Text\0*.TXT\0";
ofn.nFilterIndex = 1;
ofn.lpstrFileTitle = NULL;
ofn.nMaxFileTitle = 0;
ofn.lpstrInitialDir = NULL;
ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

}

FileDialogWnd::~FileDialogWnd(void)
{
	delete ofn.lpstrFile;
}

bool FileDialogWnd::GetSaveFileName(HWND hParent)
{
	ofn.hwndOwner = hParent;

	return (::GetSaveFileName(&ofn)==TRUE);
}

bool FileDialogWnd::GetOpenFileName(HWND hParent)
{
	ofn.hwndOwner = hParent;

	return (::GetOpenFileName(&ofn)==TRUE);
}