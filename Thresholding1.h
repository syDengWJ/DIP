
// Thresholding1.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������
#include "Thresholding1_i.h"


// CThresholding1App:
// �йش����ʵ�֣������ Thresholding1.cpp
//

class CThresholding1App : public CWinApp
{
public:
	CThresholding1App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
	BOOL ExitInstance(void);
};

extern CThresholding1App theApp;