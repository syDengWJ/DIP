// PictureDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Thresholding1.h"
#include "PictureDlg.h"
#include "afxdialogex.h"


// CPictureDlg 对话框

IMPLEMENT_DYNAMIC(CPictureDlg, CDialogEx)

CPictureDlg::CPictureDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPictureDlg::IDD, pParent)
{
}

CPictureDlg::~CPictureDlg()
{
}

void CPictureDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CPictureDlg, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CPictureDlg 消息处理程序


BOOL CPictureDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	image.Load(m_filename);

	int i,j;

	int w = image.GetWidth();
	int h = image.GetHeight();

	MoveWindow((CPictureDlg::count-1) * w,0,w,h);
	GetDlgItem(IDC_PICTURE_STATIC)->MoveWindow(0,0,w,h);

	int** hist;
	hist = new int*[w];
	for (i=0;i<w;i++) {
		hist[i] = new int[h];
	}
	hist = image.GetHist();
	//
	int MAX;
	switch (CPictureDlg::count) {
	case 1:
		MAX = image.GetMeanThresholding();
		break;
	case 2:
		MAX = image.GetPTileThreshold(50);
		break;
	default:
		MAX = 256;
	}

	for (i=0;i<w;i++)
	{
		for (j=0;j<h;j++)
		{
			if (hist[i][j] >= MAX)
			{
				image.SetPixel(i,j,RGB(255,255,255));
			} else
				image.SetPixel(i,j,RGB(0,0,0));	
		}
	}


	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CPictureDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	
	CRect rect;
	GetDlgItem(IDC_PICTURE_STATIC)->GetClientRect(&rect);
	CDC *pDC = GetDlgItem(IDC_PICTURE_STATIC)->GetDC();
	image.Draw(pDC->m_hDC, rect);

	ReleaseDC(pDC);
}

int CPictureDlg::count = 0;