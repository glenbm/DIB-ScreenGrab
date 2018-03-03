#pragma once

#include "stdafx.h"
#include <windows.h>;

class BitmapHeaders
{
public:
	void Initialize(int w, int h, int bpp);

	BITMAPFILEHEADER file;
	BITMAPINFOHEADER info;

private:
	int width, height, bitsPerPixel, size;

};
