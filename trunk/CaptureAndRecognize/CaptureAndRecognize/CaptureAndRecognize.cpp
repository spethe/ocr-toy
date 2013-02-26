// CaptureAndRecognize.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	// Open the file.
	IplImage *img = cvLoadImage("fourCorners.bmp");
	if (!img)
	{
		printf("Error: Couldn't open the image file.\n");
		return 1;
	}

	// Display the image.
	cvNamedWindow("Image:", CV_WINDOW_AUTOSIZE);
	cvShowImage("Image:", img);

	// Wait for the user to press a key in the GUI window.
	cvWaitKey(0);

	// Free the resources.
	cvDestroyWindow("Image:");
	cvReleaseImage(&img);

	return 0;
}

