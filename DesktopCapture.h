#pragma once
#include "stdafx.h"
#include "windows.h"

class DesktopCapture
{
public:

	void Capture(int w, int h);

	void GetPixelData(int bitsPerPixel);

	unsigned char* firstPixel;

private:
	HWND hDesktopWnd;
	HDC hDesktopDC;
	HDC hCaptureDC;
	HBITMAP hCaptureBitmap;

	int height, width;
};

