#include "bmpImg.h"
#include "calcEntropy.h"

int main (int argc, char *argv[]) {
	BITMAPINFOHEADER bmapIHeader;
	bitMap bmap = LoadBitmapFile("80.bmp",&bmapIHeader);
	histogram hist = computeHist(bmap, &bmapIHeader);

/*
	printf("taille header info:%x\n", bmapIHeader.biSize);
	printf("largeur:%x\n", bmapIHeader.biWidth);
	printf("hauteur:%x\n", bmapIHeader.biHeight);
	printf("color planes:%x\n", bmapIHeader.biPlanes);
	printf("profondeur:%x\n", bmapIHeader.biBitCount);
	printf("type compression:%x\n", bmapIHeader.biCompression);
	printf("taille image en byte:%x\n", bmapIHeader.biSizeImage);
	printf("nombre couleurs utilisées:%x\n", bmapIHeader.biClrUsed);
	printf("nombre couleurs importantes:%x\n", bmapIHeader.biClrImportant);
	*/
	
	double entropy = computeEntropy(bmap, &bmapIHeader, hist, 100, 50);

	printf("entropy:%f\n",entropy);
	return 0;
}
