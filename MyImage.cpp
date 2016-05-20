#include "StdAfx.h"
#include "MyImage.h"


CMyImage::CMyImage(void)
{
}

CMyImage::CMyImage(CString fileName)
{
	this->Load(fileName);
	
	int width = GetWidth();
	int height = GetHeight();

	
	GetHist();
	GetHistgram();
}


CMyImage::~CMyImage(void)
{
}





// ·µ»Ø»Ò¶ÈÍ¼ÏñµÄÏñËØ¾ØÕó
int** CMyImage::GetHist(void)
{
	int width = GetWidth();
	int height = GetHeight();
	int i=0,j=0,k=0;
	COLORREF color;

	hist = new int *[width];
	for (int i=0;i<width;i++)
		hist[i] = new int[height];
	for (i=0;i<width;i++) {
		for (j=0;j<height;j++) {
			color = GetPixel(i,j);
			CString str;
			str.Format(_T("%d"),GetRValue(color));
			hist[i][j] = _ttoi(str);
		}
	}

	return hist;
}


int* CMyImage::GetHistgram(void)
{
	int i,j,k;
	int width = GetWidth();
	int height = GetHeight();
	
	for (i=0;i<NUM_OF_GRAYDEGREE;i++)
		hist_gram[i] = 0;

	for (i=0;i<width;i++) {
		for (j=0;j<height;j++) {
			for (k=0;k<NUM_OF_GRAYDEGREE;k++) {
				if (hist[i][j] == k) {
					hist_gram[k] += 1;
				}
			}
		}
	}
	return hist_gram;
}

int CMyImage::GetMeanThresholding(void)
{
	GetHistgram();

	int sum = 0,amount = 0;
	for (int i=0;i<NUM_OF_GRAYDEGREE;i++)
		sum += i * hist_gram[i];
	amount = GetWidth()*GetHeight();
	return sum/amount;
}

int CMyImage::GetPTileThreshold(int PTile)
{
	GetHistgram();
	int amount = GetWidth()*GetHeight();
	int sum = 0;
	for (int i=0;i<NUM_OF_GRAYDEGREE;i++) {
		sum += hist_gram[i];
		if (sum >= amount * PTile / 100)
			return i;
	}
	return -1;
}
