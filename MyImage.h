#pragma once
#include "atlimage.h"

#define NUM_OF_GRAYDEGREE 256

class CMyImage :
	public CImage
{
public:
	CMyImage(void);
	CMyImage(CString fileName);
	~CMyImage(void);
private:
	int **hist;
	int hist_gram[NUM_OF_GRAYDEGREE];
public:
	// ·µ»Ø»Ò¶ÈÍ¼ÏñµÄÏñËØ¾ØÕó
	int** GetHist(void);
	int* GetHistgram(void);

	int GetMeanThresholding();
	int GetPTileThreshold(int PTile=50);
};

