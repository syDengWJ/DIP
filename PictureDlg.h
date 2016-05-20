#pragma once

#include "MyImage.h"
// CPictureDlg 对话框

class CPictureDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CPictureDlg)

public:
	CPictureDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CPictureDlg();

// 对话框数据
	enum { IDD = IDD_PICTURE_DIALOG };
	
	CString m_filename;
	static int count;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();

	CMyImage image;
};
