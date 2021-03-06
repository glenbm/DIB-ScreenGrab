#include "stdafx.h"
#include <windows.h>
#include "ScreenCapture.h"

#include "base64.h"
#include "base64.cpp"

int main()
{
	ScreenCapture screenCapture;

	screenCapture.StartCapture();

    return 0;
}

void ScreenCapture::StartCapture()
{
	width = 100;
	height = 100;
	bitsPerPixel = 24;

	totalSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + width * height * bitsPerPixel;

	captureData.Capture(width, height);
	captureData.GetPixelData(bitsPerPixel);

	bmpHeaders.Initialize(width, height, bitsPerPixel);

	unsigned char * bmpBuff = new unsigned char[totalSize];

	int i = 0;
	memcpy((void *)&bmpBuff[i], (void *)&bmpHeaders.file, sizeof(BITMAPFILEHEADER));

	i += sizeof(BITMAPFILEHEADER);
	memcpy((void *)&bmpBuff[i], (void *)&bmpHeaders.info, sizeof(BITMAPINFOHEADER));

	i += sizeof(BITMAPINFOHEADER);
	memcpy((void *)&bmpBuff[i], (void *)captureData.firstPixel, totalSize);

	std::string encodedImage = base64_encode(bmpBuff, totalSize);
}
