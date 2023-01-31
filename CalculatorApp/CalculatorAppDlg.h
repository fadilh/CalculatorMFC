
// CalculatorAppDlg.h : header file
//

#pragma once


// CCalculatorAppDlg dialog
class CCalculatorAppDlg : public CDialogEx
{
// Construction
public:
	CCalculatorAppDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALCULATORAPP_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton4();

	float num1, num2, ans;
	CString string1, string2;
	bool afterOperator;
	int operatorType;
	CString editResult;
	afx_msg void OnBnClickedBtn1();
	afx_msg void OnBnClickedBtn2();
	afx_msg void OnBnClickedBtn3();
	afx_msg void OnBnClickedBtn4();
	afx_msg void OnBnClickedBtn5();
	afx_msg void OnBnClickedBtn6();
	afx_msg void OnBnClickedBtn7();
	afx_msg void OnBnClickedBtn8();
	afx_msg void OnBnClickedBtn9();
	afx_msg void OnBnClickedBtnclr();
	afx_msg void OnBnClickedBtn0();
	afx_msg void OnBnClickedBtneq();
	afx_msg void OnBnClickedBtndiv();
	afx_msg void OnBnClickedBtnmult();
	afx_msg void OnBnClickedBtnsub();
	afx_msg void OnBnClickedBtnadd();
};
