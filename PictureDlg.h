#pragma once

#include "MyImage.h"
// CPictureDlg �Ի���

class CPictureDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CPictureDlg)

public:
	CPictureDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPictureDlg();

// �Ի�������
	enum { IDD = IDD_PICTURE_DIALOG };
	
	CString m_filename;
	static int count;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();

	CMyImage image;
};
