// CaptureAndRecognize.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

_fnInitEngine pFnInitEngine;
_fnCaliberateCamera pFnCaliberateCamera;
_fnRecognizeChars pFnRecognizeChars;
_fnFreeEngine pFnFreeEngine;
_fnEngineVersionInfo pFnEngineVersionInfo;

int doSomething();

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

	doSomething();

	FreeLibrary(m_HIDevRecEngineDLL);
	m_HIDevRecEngineDLL = NULL;

	return 0;
}

int doSomething()
{
	//----Calibrate the camera / screen
	//This image needs to be shown on the LCD screen
	IplImage *image = cvLoadImage("fourCorners.bmp");
	cvNamedWindow( "mywindow", CV_WINDOW_AUTOSIZE );
	cvShowImage("mywindow",image);

	CvCapture* capture = cvCaptureFromCAM(0);
	if ( !capture )
	{
		fprintf( stderr, "ERROR: capture is NULL \n" );
		getchar();
		return -1;
	}

	IplImage *curr_frame = cvQueryFrame(capture);

	//--Calibrate
	g_Resolution screenResolution;
	screenResolution.width = 1024; //width of the screen
	screenResolution.height = 600; //height of the screen
	g_Resolution cameraResolution;
	cameraResolution.width  = curr_frame->width;  //width of the camera
	cameraResolution.height = curr_frame->height; //height of the camera

	int calibrationFlag = pFnCaliberateCamera(curr_frame, cameraResolution, screenResolution);
	if(calibrationFlag == 1)
	{
		printf("caliberation done\n");
	}
	else
	{
		printf("caliberation failed\n");
		return 0;
	}

	//--Init engine
	pFnInitEngine();
	printf("Engine initialised successfully...\n");

	int recog=0;
	g_OCRCharInfo *g_Output=(g_OCRCharInfo *)malloc(sizeof(g_OCRCharInfo));
	if(g_Output==NULL)
	{
		printf("Mem allocation problem");
	}

	while (true)
	{
		// Get one frame
		curr_frame = cvQueryFrame( capture );
		if ( !curr_frame )
		{
			fprintf( stderr, "ERROR: frame is null...\n" );
			getchar();
			break;
		}
		cvShowImage( "mywindow", curr_frame );

		Sleep(10); // in milisecond

		recog = pFnRecognizeChars(curr_frame,0,&g_Output);
		printf("\n\n\nTest:chars recog count %d",recog);

		for(int i=0; i<recog; i++)
			printf("\nTest: Angle:%f Char:%x Bounded by:(%d,%d)(%d,%d) with centroid at(%d,%d) ",
			g_Output->g_Angle[i],
			g_Output->g_UnicodeChars[i],
			(g_Output->boundingBoxes[i]).minX,
			(g_Output->boundingBoxes[i]).minY,
			(g_Output->boundingBoxes[i]).maxX,
			(g_Output->boundingBoxes[i]).maxY,
			(g_Output->centroids[i]).x,
			(g_Output->centroids[i]).y);

		if ((cvWaitKey(10) & 255) == 27) break;
	}

	cvDestroyWindow( "mywindow" );
	cvReleaseCapture( &capture );

	pFnFreeEngine();
	printf("Engine freed successfully...\n");
}
