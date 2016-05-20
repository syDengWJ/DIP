
// Thresholding1Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Thresholding1.h"
#include "Thresholding1Dlg.h"
#include "afxdialogex.h"

#include "PictureDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CThresholding1Dlg �Ի���




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


// CThresholding1Dlg ��Ϣ�������

BOOL CThresholding1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CThresholding1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CThresholding1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CThresholding1Dlg::OnBnClickedOpenBtn()
{
	CImage image;
	CRect rect;
	CFileDialog openDlg(TRUE,_T("*"),_T("*.tif"),OFN_OVERWRITEPROMPT,_T("�����ļ�(*.*)"),NULL);
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

// �ı䴰���С
void CThresholding1Dlg::Resize(void)
{
	CRect rectPic;
	double rx,ry;
	GetDlgItem(IDC_PICTURE)->GetClientRect(&rectPic);	//��ȡͼƬ��Ĵ�С
	if (picWidth && picHeight) {
		rx = picWidth*1.0 / rectPic.Width();
		ry = picHeight*1.0 / rectPic.Height();
	}

	//��ȡ��Ļ����
	int cxScrn = ::GetSystemMetrics(SM_CXFULLSCREEN);
	int cyScrn = ::GetSystemMetrics(SM_CYFULLSCREEN);

	//�Ի���
	CRect rect;
	GetClientRect(&rect);
	int w = rx*rect.Width();
	int h = ry*rect.Height();
	MoveWindow((cxScrn-w)/2,(cyScrn-h)/2,w,h);
	//�򿪰�ť
	CRect rectOpen;
	GetDlgItem(IDC_OPEN_BTN)->GetClientRect(&rectOpen);
	GetDlgItem(IDC_OPEN_BTN)->MoveWindow(0,0,rx*rectOpen.Width(),ry*rectOpen.Height());

	GetDlgItem(IDC_OPEN_BTN)->GetClientRect(&rectOpen);
	//��ֵ����ť
	CRect rectThrshd;
	GetDlgItem(IDC_THRESHOLDING_BTN)->GetClientRect(&rectThrshd);
	GetDlgItem(IDC_THRESHOLDING_BTN)->MoveWindow(0,rectOpen.Height()+100,rx*rectThrshd.Width(),ry*rectThrshd.Height());
	//�رհ�ť
	CRect rectClose;
	GetDlgItem(IDC_CLOSE_BTN)->GetClientRect(&rectClose);
	GetDlgItem(IDC_CLOSE_BTN)->MoveWindow(0,rectOpen.Height()*2+200,rx*rectClose.Width(),ry*rectClose.Height());
	//ͼƬ��
	GetDlgItem(IDC_PICTURE)->GetClientRect(&rectPic);
	GetDlgItem(IDC_PICTURE)->MoveWindow(rectOpen.Width()+20,0,picWidth,picHeight);

}

void CThresholding1Dlg::OnClose()
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CDialogEx::OnOK();
	CDialogEx::OnClose();
}
