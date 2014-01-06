#ifndef __CALCENTROPY_H_
#define __CALCENTROPY_H_

#include <stdlib.h>
#include <stdio.h>
#include <bmpImg.h>
#include <math.h>

typedef double *histogram;

double computeEntropy(bitMap bm, BITMAPINFOHEADER *bmapInfoHeader, histogram histo);
histogram computeHist(bitMap bm, BITMAPINFOHEADER *bmapInfoHeader);
	
#endif
