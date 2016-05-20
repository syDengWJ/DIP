
// Thresholding1Dlg.h : 头文件
//

#pragma once


// CThresholding1Dlg 对话框
class CThresholding1Dlg : public CDialogEx
{
// 构造
public:
	CThresholding1Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_THRESHOLDING1_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

	CString fileName;
// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOpenBtn();
	afx_msg void OnBnClickedThresholdingBtn();
	afx_msg void OnBnClickedCloseBtn();

	// 改变窗体大小
	void Resize(void);
	
	afx_msg void OnClose();

private:
	int picWidth,picHeight;
};
