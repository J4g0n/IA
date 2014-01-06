#include "calcEntropy.h"

histogram computeHist(bitMap bm, BITMAPINFOHEADER *bmInfoHeader){
	int sizeHist = (int) pow(2, bmInfoHeader->biBitCount);
	double *histo = (double *) calloc(sizeHist,sizeof(double));
	int i;
	int height = bmInfoHeader->biHeight;
	int width = bmInfoHeader->biWidth;
	int nbTotal = height*width;

	// initialisation de l'histogramme
	for (i = 0; i < nbTotal; i++) {
		//printf("%d\t",bm[i]);
		histo[(unsigned int) bm[i]]+=1;
	}

	return histo;
}

double computeEntropy(bitMap bm, BITMAPINFOHEADER *bmInfoHeader, histogram histo, int L, int D) {
	double p,result = 0;
	int i;
	int color;
	int nbElem = 0;
	int height = bmInfoHeader->biHeight;
	int width = bmInfoHeader->biWidth;
	int nbTotal = (int) height*width;

	for (i = L; i < L+D; i++) {
		nbElem += histo[i];
	}

	printf("%d\n",nbTotal);

	// calcul de l'entropie à proprement parler
	for (i = 0; i < nbTotal; i++) {
		color = bm[i];
		if (color>=L && color<L+D) {
			//printf("%d:%d\t",i,(int) histo[i]);
			p=(double) histo[color]/ (double) nbElem;
			result -= p*log(p);
		}
	}

	return result/(log(2)*(double)nbElem);
}

//double findMaxEntropy
