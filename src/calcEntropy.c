#include "calcEntropy.h"

double computeEntropy(bitMap bm, BITMAPINFOHEADER *bmInfoHeader) {
	int sizeHist = (int) pow(2, bmInfoHeader->biBitCount);
	double p,result = 0;
	int i,j;
	int height = bmInfoHeader->biHeight;
	int width = bmInfoHeader->biWidth;
	double nbTotal = (double) height*width;
	double *histo = (double *) calloc(sizeHist,sizeof(double));

	// initialisation de l'histogramme
	for (i = 0; i < width*height; i++) {
		//printf("%d\t",bm[i]);
		histo[(unsigned int) bm[i]]+=1;
	}

	printf("%f\n",nbTotal);

	// calcul de l'entropie à proprement parler
	for (i = 0; i < sizeHist; i++) {
		if (histo[i]!=0) {
			printf("%d:%d\t",i,(int) histo[i]);
			p=histo[i]/nbTotal;
			result -= p*log(p);
		}
	}
	free(histo);

	return result*1/log(2);
}
