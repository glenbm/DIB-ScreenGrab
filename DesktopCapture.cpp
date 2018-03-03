#include "stdafx.h"
#include "DesktopCapture.h"

void DesktopCapture::Capture(int w, int h)
{
	width = w;
	height = h;

	hDesktopWnd = GetDesktopWindow();
	hDesktopDC = GetDC(hDesktopWnd);
	hCaptureDC = CreateCompatibleDC(hDesktopDC);
	hCaptureBitmap = CreateCompatibleBitmap(hDesktopDC, width, height);

	SelectObject(hCaptureDC, hCaptureBitmap);

	BitBlt(hCaptureDC, 0, 0, width, height, hDesktopDC, 0, 0, SRCCOPY | CAPTUREBLT);
}

void DesktopCapture::GetPixelData(int bitsPerPixel)
{
	int totalSize = width * height * bitsPerPixel;

	firstPixel = new unsigned char[totalSize];

	BITMAPINFO infoHeader = { 0 };

	infoHeader.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	infoHeader.bmiHeader.biWidth = width;
	infoHeader.bmiHeader.biHeight = height;
	infoHeader.bmiHeader.biPlanes = 1;
	infoHeader.bmiHeader.biSizeImage = totalSize;
	infoHeader.bmiHeader.biBitCount = bitsPerPixel;
	infoHeader.bmiHeader.biCompression = BI_RGB;

	GetDIBits(hDesktopDC, hCaptureBitmap, 0, height, &firstPixel, &infoHeader, DIB_RGB_COLORS);

}