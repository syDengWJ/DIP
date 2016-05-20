
// Thresholding1Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Thresholding1.h"
#include "Thresholding1Dlg.h"
#include "afxdialogex.h"

#include "PictureDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CThresholding1Dlg 对话框




CThresholding1Dlg::CThresholding1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CThresholding1Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CThresholding1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CThresholding1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_OPEN_BTN, &CThresholding1Dlg::OnBnClickedOpenBtn)
	ON_BN_CLICKED(IDC_THRESHOLDING_BTN, &CThresholding1Dlg::OnBnClickedThresholdingBtn)
	ON_BN_CLICKED(IDC_CLOSE_BTN, &CThresholding1Dlg::OnBnClickedCloseBtn)
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// CThresholding1Dlg 消息处理程序

BOOL CThresholding1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CThresholding1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CThresholding1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CThresholding1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CThresholding1Dlg::OnBnClickedOpenBtn()
{
	CImage image;
	CRect rect;
	CFileDialog openDlg(TRUE,_T("*"),_T("*.tif"),OFN_OVERWRITEPROMPT,_T("所有文件(*.*)"),NULL);
	if (IDOK == openDlg.DoModal()) {

		fileName = openDlg.GetPathName();

		image.Load(fileName);
		picWidth = image.GetWidth();
		picHeight= image.GetHeight();

		Resize();

		GetDlgItem(IDC_PICTURE)->GetClientRect(&rect);

		CDC *pDC = GetDlgItem(IDC_PICTURE)->GetDC();
		image.Draw(pDC->m_hDC, rect);
		ReleaseDC(pDC);

		GetDlgItem(IDC_THRESHOLDING_BTN)->EnableWindow(TRUE);
	}
}

CPictureDlg* pDlg;
void CThresholding1Dlg::OnBnClickedThresholdingBtn()
{	
	pDlg = new CPictureDlg();
	pDlg->m_filename = fileName;
	CPictureDlg::count += 1;
	pDlg->Create(IDD_PICTURE_DIALOG,this);
	
	pDlg->ShowWindow(SW_SHOW);
}


void CThresholding1Dlg::OnBnClickedCloseBtn()
{
	CDialogEx::OnOK();
}

// 改变窗体大小
void CThresholding1Dlg::Resize(void)
{
	CRect rectPic;
	double rx,ry;
	GetDlgItem(IDC_PICTURE)->GetClientRect(&rectPic);	//获取图片框的大小
	if (picWidth && picHeight) {
		rx = picWidth*1.0 / rectPic.Width();
		ry = picHeight*1.0 / rectPic.Height();
	}

	//获取屏幕像素
	int cxScrn = ::GetSystemMetrics(SM_CXFULLSCREEN);
	int cyScrn = ::GetSystemMetrics(SM_CYFULLSCREEN);

	//对话框
	CRect rect;
	GetClientRect(&rect);
	int w = rx*rect.Width();
	int h = ry*rect.Height();
	MoveWindow((cxScrn-w)/2,(cyScrn-h)/2,w,h);
	//打开按钮
	CRect rectOpen;
	GetDlgItem(IDC_OPEN_BTN)->GetClientRect(&rectOpen);
	GetDlgItem(IDC_OPEN_BTN)->MoveWindow(0,0,rx*rectOpen.Width(),ry*rectOpen.Height());

	GetDlgItem(IDC_OPEN_BTN)->GetClientRect(&rectOpen);
	//二值化按钮
	CRect rectThrshd;
	GetDlgItem(IDC_THRESHOLDING_BTN)->GetClientRect(&rectThrshd);
	GetDlgItem(IDC_THRESHOLDING_BTN)->MoveWindow(0,rectOpen.Height()+100,rx*rectThrshd.Width(),ry*rectThrshd.Height());
	//关闭按钮
	CRect rectClose;
	GetDlgItem(IDC_CLOSE_BTN)->GetClientRect(&rectClose);
	GetDlgItem(IDC_CLOSE_BTN)->MoveWindow(0,rectOpen.Height()*2+200,rx*rectClose.Width(),ry*rectClose.Height());
	//图片框
	GetDlgItem(IDC_PICTURE)->GetClientRect(&rectPic);
	GetDlgItem(IDC_PICTURE)->MoveWindow(rectOpen.Width()+20,0,picWidth,picHeight);

}

void CThresholding1Dlg::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CDialogEx::OnOK();
	CDialogEx::OnClose();
}
