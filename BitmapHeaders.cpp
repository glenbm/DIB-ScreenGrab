#include "stdafx.h"
#include "BitmapHeaders.h"

void BitmapHeaders::Initialize(int w, int h, int bpp)
{
	width = w;
	height = h;
	bitsPerPixel = bpp;
	size = width * height * bitsPerPixel;

	memset(&info, 0, sizeof(BITMAPINFOHEADER));
	memset(&file, 0, sizeof(BITMAPFILEHEADER));

	file.bfType = 0x4d42;
	file.bfReserved1 = 0;
	file.bfReserved2 = 0;
	file.bfSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
	file.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

	info.biSize = sizeof(BITMAPINFOHEADER);
	info.biWidth = width;
	info.biHeight = height;
	info.biPlanes = 1;
	info.biBitCount = bitsPerPixel;
	info.biCompression = BI_RGB;
	info.biSizeImage = size;
	info.biXPelsPerMeter = 0;
	info.biYPelsPerMeter = 0;
	info.biClrUsed = 0;
	info.biClrImportant = 0;
}
