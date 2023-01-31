
// CalculatorAppDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "CalculatorApp.h"
#include "CalculatorAppDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CCalculatorAppDlg dialog



CCalculatorAppDlg::CCalculatorAppDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALCULATORAPP_DIALOG, pParent)
	, editResult(_T(""))
{
	num1 = num2 = ans = 0;
	string1 = string2 = _T("");
	afterOperator = false;
	operatorType = 0;
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalculatorAppDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, NUMS, editResult);
}

BEGIN_MESSAGE_MAP(CCalculatorAppDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(BTN1, &CCalculatorAppDlg::OnBnClickedBtn1)
	ON_BN_CLICKED(BTN2, &CCalculatorAppDlg::OnBnClickedBtn2)
	ON_BN_CLICKED(BTN3, &CCalculatorAppDlg::OnBnClickedBtn3)
	ON_BN_CLICKED(BTN4, &CCalculatorAppDlg::OnBnClickedBtn4)
	ON_BN_CLICKED(BTN5, &CCalculatorAppDlg::OnBnClickedBtn5)
	ON_BN_CLICKED(BTN6, &CCalculatorAppDlg::OnBnClickedBtn6)
	ON_BN_CLICKED(BTN7, &CCalculatorAppDlg::OnBnClickedBtn7)
	ON_BN_CLICKED(BTN8, &CCalculatorAppDlg::OnBnClickedBtn8)
	ON_BN_CLICKED(BTN9, &CCalculatorAppDlg::OnBnClickedBtn9)
	ON_BN_CLICKED(BTNCLR, &CCalculatorAppDlg::OnBnClickedBtnclr)
	ON_BN_CLICKED(BTN0, &CCalculatorAppDlg::OnBnClickedBtn0)
	ON_BN_CLICKED(BTNEQ, &CCalculatorAppDlg::OnBnClickedBtneq)
	ON_BN_CLICKED(BTNDIV, &CCalculatorAppDlg::OnBnClickedBtndiv)
	ON_BN_CLICKED(BTNMULT, &CCalculatorAppDlg::OnBnClickedBtnmult)
	ON_BN_CLICKED(BTNSUB, &CCalculatorAppDlg::OnBnClickedBtnsub)
	ON_BN_CLICKED(BTNADD, &CCalculatorAppDlg::OnBnClickedBtnadd)
END_MESSAGE_MAP()


// CCalculatorAppDlg message handlers

BOOL CCalculatorAppDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCalculatorAppDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCalculatorAppDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCalculatorAppDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CCalculatorAppDlg::OnBnClickedBtn1()
{
	if (!afterOperator)
	{
		string1 += _T("1");
		editResult = string1;
	}
	else {
		string2 += _T("1");
		editResult = string2;
	}
	UpdateData(FALSE);
}


void CCalculatorAppDlg::OnBnClickedBtn2()
{
	if (!afterOperator)
	{
		string1 += _T("2");
		editResult = string1;
	}
	else {
		string2 += _T("2");
		editResult = string2;
	}
	UpdateData(FALSE);
}


void CCalculatorAppDlg::OnBnClickedBtn3()
{
	if (!afterOperator)
	{
		string1 += _T("3");
		editResult = string1;
	}
	else {
		string2 += _T("3");
		editResult = string2;
	}
	UpdateData(FALSE);
}


void CCalculatorAppDlg::OnBnClickedBtn4()
{
	if (!afterOperator)
	{
		string1 += _T("4");
		editResult = string1;
	}
	else {
		string2 += _T("4");
		editResult = string2;
	}
	UpdateData(FALSE);
}


void CCalculatorAppDlg::OnBnClickedBtn5()
{
	if (!afterOperator)
	{
		string1 += _T("5");
		editResult = string1;
	}
	else {
		string2 += _T("5");
		editResult = string2;
	}
	UpdateData(FALSE);
}


void CCalculatorAppDlg::OnBnClickedBtn6()
{
	if (!afterOperator)
	{
		string1 += _T("6");
		editResult = string1;
	}
	else {
		string2 += _T("6");
		editResult = string2;
	}
	UpdateData(FALSE);
}


void CCalculatorAppDlg::OnBnClickedBtn7()
{
	if (!afterOperator)
	{
		string1 += _T("7");
		editResult = string1;
	}
	else {
		string2 += _T("7");
		editResult = string2;
	}
	UpdateData(FALSE);
}



void CCalculatorAppDlg::OnBnClickedBtn8()
{
	if (!afterOperator)
	{
		string1 += _T("8");
		editResult = string1;
	}
	else {
		string2 += _T("8");
		editResult = string2;
	}
	UpdateData(FALSE);
}


void CCalculatorAppDlg::OnBnClickedBtn9()
{
	if (!afterOperator)
	{
		string1 += _T("9");
		editResult = string1;
	}
	else {
		string2 += _T("9");
		editResult = string2;
	}
	UpdateData(FALSE);
}



void CCalculatorAppDlg::OnBnClickedBtnclr()
{
	string1 = string2 = _T("");
	editResult = string1;
	operatorType = 0;
	afterOperator = false;
	UpdateData(FALSE);
	
}


void CCalculatorAppDlg::OnBnClickedBtn0()
{
	if (!afterOperator)
	{
		if (string1.GetLength() > 0) {
			string1 += _T("0");
			editResult = string1;
			UpdateData(FALSE);
		}
	}
	else {
		if (string2.GetLength() > 0) {
			string2 += _T("0");
			editResult = string2;
			UpdateData(FALSE);
		}
	}
	
}


void CCalculatorAppDlg::OnBnClickedBtneq()
{
	if (editResult != _T(""))
	{
		num2 = _ttof(editResult);
		afterOperator = !afterOperator;
		editResult = _T("");
	}
	if (operatorType == 1)
	{
		ans = num1 + num2;
	}
	if (operatorType == 2)
	{
		ans = num1 - num2;
	}
	if (operatorType == 3)
	{
		ans = num1 * num2;
	}
	if (operatorType == 4)
	{
		ans = num1 / num2;
	}
	editResult.Format(_T("%.0f"), ans);
	UpdateData(FALSE);
	string1 = string2 = _T("");
}


void CCalculatorAppDlg::OnBnClickedBtndiv()
{
	if (editResult != _T(""))
	{
		num1 = _ttof(editResult);
		afterOperator = !afterOperator;
		editResult = _T("");
		operatorType = 4;
	}
}


void CCalculatorAppDlg::OnBnClickedBtnmult()
{
	if (editResult != _T(""))
	{
		num1 = _ttof(editResult);
		afterOperator = !afterOperator;
		editResult = _T("");
		operatorType = 3;
	}
}


void CCalculatorAppDlg::OnBnClickedBtnsub()
{
	if (editResult != _T(""))
	{
		num1 = _ttof(editResult);
		afterOperator = !afterOperator;
		editResult = _T("");
		operatorType = 2;
	}
}


void CCalculatorAppDlg::OnBnClickedBtnadd()
{
	if (editResult != _T(""))
	{
		num1 = _ttof(editResult);
		afterOperator = !afterOperator;
		editResult = _T("");
		operatorType = 1;
	}
}
