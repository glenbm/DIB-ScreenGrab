#pragma once

#include "stdafx.h";
#include "BitmapHeaders.h";
#include "DesktopCapture.h";
#include <windows.h>;

class ScreenCapture {

public:
	void StartCapture();

private:

	BitmapHeaders bmpHeaders;
	DesktopCapture captureData;

	unsigned char* buffer;

	int width, height;
	int bitsPerPixel;
	int totalSize;

};