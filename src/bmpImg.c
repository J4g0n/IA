#include "bmpImg.h"

unsigned char *LoadBitmapFile(char *filename, BITMAPINFOHEADER *bitmapInfoHeader)
{
	FILE *filePtr; //our file pointer
	BITMAPFILEHEADER bitmapFileHeader; //our bitmap file header
	unsigned char *bitmapImage; //store image data
	int imageIdx=0;  //image index counter
	unsigned char tempRGB;  //our swap variable

	//open filename in read binary mode
	filePtr = fopen(filename,"rb");
	if (filePtr == NULL)
		return NULL;

	//read the bitmap file header
	fread(&bitmapFileHeader.bfType, 2,1,filePtr);
	fread(&bitmapFileHeader.bfSize, 4,1,filePtr);
	fread(&bitmapFileHeader.bfReserved1, 2,1,filePtr);
	fread(&bitmapFileHeader.bfReserved2, 2,1,filePtr);
	fread(&bitmapFileHeader.bfOffBits, 4,1,filePtr);
	printf("%d %d %d %d %d\n", 
				bitmapFileHeader.bfType,
				bitmapFileHeader.bfSize,
				bitmapFileHeader.bfReserved1,
				bitmapFileHeader.bfReserved2,
				bitmapFileHeader.bfOffBits);

	//verify that this is a bmp file by check bitmap id
	if (bitmapFileHeader.bfType !=0x4D42)
	{
		fclose(filePtr);
		return NULL;
	}

	//read the bitmap info header
//	fseek(filePtr,14,SEEK_SET);
	fread(bitmapInfoHeader, sizeof(BITMAPINFOHEADER),1,filePtr);

	//move file point to the begging of bitmap data
	fseek(filePtr, bitmapFileHeader.bfOffBits, SEEK_SET);

	//allocate enough memory for the bitmap image data
	bitmapImage = (unsigned char*)malloc(bitmapInfoHeader->biSizeImage);

	//verify memory allocation
	if (!bitmapImage)
	{
		free(bitmapImage);
		fclose(filePtr);
		return NULL;
	}

	//read in the bitmap image data
	fread(bitmapImage,sizeof(char),bitmapInfoHeader->biSizeImage,filePtr);

	//make sure bitmap image data was read
	if (bitmapImage == NULL)
	{
		fclose(filePtr);
		return NULL;
	}

	//swap the r and b values to get RGB (bitmap is BGR)
	for (imageIdx = 0;imageIdx < bitmapInfoHeader->biSizeImage;imageIdx+=3)
	{
		tempRGB = bitmapImage[imageIdx];
		bitmapImage[imageIdx] = bitmapImage[imageIdx + 2];
		bitmapImage[imageIdx + 2] = tempRGB;
	}

	//close file and return bitmap iamge data
	fclose(filePtr);
	return bitmapImage;
}
