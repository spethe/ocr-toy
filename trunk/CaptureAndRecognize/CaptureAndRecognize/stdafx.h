// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>

#include <cv.h>
#include <cxcore.h>
#include <highgui.h>

#include "Toy.h"
typedef void (*_fnInitEngine)();
typedef int  (*_fnRecognizeChars)(IplImage* inputImage,int fAlphaNumeral,g_OCRCharInfo** g_OutputCharInfoAll);
typedef int  (*_fnCaliberateCamera)(IplImage* inputImage,g_Resolution cameraReso,g_Resolution screenResolution);
typedef void (*_fnFreeEngine)();
typedef char*(*_fnEngineVersionInfo)();

#define MAX_FILE_PATH 256
