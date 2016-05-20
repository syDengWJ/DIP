
// Thresholding1Dlg.h : ͷ�ļ�
//

#pragma once


// CThresholding1Dlg �Ի���
class CThresholding1Dlg : public CDialogEx
{
// ����
public:
	CThresholding1Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_THRESHOLDING1_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

	CString fileName;
// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOpenBtn();
	afx_msg void OnBnClickedThresholdingBtn();
	afx_msg void OnBnClickedCloseBtn();

	// �ı䴰���С
	void Resize(void);
	
	afx_msg void OnClose();

private:
	int picWidth,picHeight;
};
