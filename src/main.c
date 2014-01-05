#include "bmpImg.h"

int main (int argc, char *argv[]) {
	BITMAPINFOHEADER bmapIHeader;
	unsigned char *bmap = LoadBitmapFile("/home/j4g0n/IA/80.bmp",&bmapIHeader);

	printf("taille header info:%x\n", bmapIHeader.biSize);
	printf("largeur:%x\n", bmapIHeader.biWidth);
	printf("hauteur:%x\n", bmapIHeader.biHeight);
	printf("color planes:%x\n", bmapIHeader.biPlanes);
	printf("debut bitmap:%x\n", bmapIHeader.biBitCount);
	printf("type compression:%x\n", bmapIHeader.biCompression);
	printf("taille image en byte:%x\n", bmapIHeader.biSizeImage);
	printf("nombre couleurs utilisées:%x\n", bmapIHeader.biClrUsed);
	printf("nombre couleurs importantes:%x\n", bmapIHeader.biClrImportant);
	return 0;
}
