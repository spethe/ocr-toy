// CaptureAndRecognize.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

_fnInitEngine pFnInitEngine;
_fnCaliberateCamera pFnCaliberateCamera;
_fnRecognizeChars pFnRecognizeChars;
_fnFreeEngine pFnFreeEngine;
_fnEngineVersionInfo pFnEngineVersionInfo;

int _tmain(int argc, _TCHAR* argv[])
{
	TCHAR strEnginesFilePath[MAX_FILE_PATH];
	TCHAR strFolderPath[MAX_FILE_PATH]={0};
	GetModuleFileName(NULL, strFolderPath, _MAX_PATH); 
	*wcsrchr(strFolderPath,'\\') = '\0';
	wcscpy(strEnginesFilePath,strFolderPath);
	wcscat(strEnginesFilePath,L"\\OCRtoyDLL.dll");

	HINSTANCE m_HIDevRecEngineDLL = LoadLibrary(strEnginesFilePath);

	if (m_HIDevRecEngineDLL == NULL) return 0;

	pFnInitEngine        = (_fnInitEngine)GetProcAddress(m_HIDevRecEngineDLL,"fn_InitEngine");
	pFnCaliberateCamera  = (_fnCaliberateCamera)GetProcAddress(m_HIDevRecEngineDLL,"fn_CaliberateCamera");
	pFnRecognizeChars    = (_fnRecognizeChars)GetProcAddress(m_HIDevRecEngineDLL,"fn_RecognizeChars");
	pFnFreeEngine        = (_fnFreeEngine)GetProcAddress(m_HIDevRecEngineDLL,"fn_FreeEngine");
	pFnEngineVersionInfo = (_fnEngineVersionInfo)GetProcAddress(m_HIDevRecEngineDLL,"fn_EngineVersionInfo");

	FreeLibrary(m_HIDevRecEngineDLL);
	m_HIDevRecEngineDLL = NULL;

	return 0;
}

