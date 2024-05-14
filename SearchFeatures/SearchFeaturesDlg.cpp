
// SearchFeaturesDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SearchFeatures.h"
#include "SearchFeaturesDlg.h"
#include "afxdialogex.h"
#include "FeatureCode.h"
#include <tlhelp32.h>
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


// CSearchFeaturesDlg �Ի���



CSearchFeaturesDlg::CSearchFeaturesDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSearchFeaturesDlg::IDD, pParent)
    , m_hProcess(INVALID_HANDLE_VALUE)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSearchFeaturesDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_COMBO_PROCESSLIST, m_comboProcessList);
}

BEGIN_MESSAGE_MAP(CSearchFeaturesDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
    ON_BN_CLICKED(IDOK, &CSearchFeaturesDlg::OnBnClickedOk)
    ON_CBN_SELCHANGE(IDC_COMBO_PROCESSLIST, &CSearchFeaturesDlg::OnCbnSelchangeComboProcesslist)
    ON_BN_CLICKED(IDC_BTN_SEARCH, &CSearchFeaturesDlg::OnBnClickedBtnSearch)
END_MESSAGE_MAP()


// CSearchFeaturesDlg ��Ϣ�������

BOOL CSearchFeaturesDlg::OnInitDialog()
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

    GetAllProcess();

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CSearchFeaturesDlg::OnSysCommand(UINT nID, LPARAM lParam)
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
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CSearchFeaturesDlg::OnPaint()
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
HCURSOR CSearchFeaturesDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSearchFeaturesDlg::OnBnClickedOk()
{
    // TODO:  �ڴ���ӿؼ�֪ͨ����������
    //CDialogEx::OnOK();
}


BOOL CSearchFeaturesDlg::PreTranslateMessage(MSG* pMsg)
{
    if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_ESCAPE)
    {
        return TRUE;
    }

    return CDialogEx::PreTranslateMessage(pMsg);
}


void CSearchFeaturesDlg::GetAllProcess()
{
    HANDLE hProcess;                        //���̾��
    BOOL bProcess = FALSE;                  //��ȡ������Ϣ�ĺ�������ֵ

    PROCESSENTRY32 pe;                    //���������Ϣ
    pe.dwSize = sizeof(PROCESSENTRY32);

    hProcess = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);//��ȡ���̿���
    CString strTitle;
    bProcess = Process32First(hProcess, &pe);              //��ȡ��һ��������Ϣ
    while (bProcess)
    {
//         strTitle.Format(_T("[%d] "), pe.th32ProcessID);
//         strTitle += pe.szExeFile;
        strTitle.Format(_T("%s [%d]"), pe.szExeFile, pe.th32ProcessID);
        m_comboProcessList.InsertString(-1, strTitle);
        //m_mapProcessList.insert(std::make_pair(pe.th32ProcessID,pe.szExeFile));
        bProcess = Process32Next(hProcess, &pe);
    }
}

void CSearchFeaturesDlg::OnCbnSelchangeComboProcesslist()
{
    if (m_hProcess != INVALID_HANDLE_VALUE)
    {
        CloseHandle(m_hProcess);
    }
    //ȡ����ID
    CString strPid;
    m_comboProcessList.GetWindowText(strPid);

    int nPosLeft = strPid.Find(_T("["));
    int nPosRight = strPid.Find(_T("]"));
    if (nPosLeft == -1 || nPosRight == -1)
    {
        return;
    }
    strPid = strPid.Right(nPosRight-nPosLeft);
    strPid.Replace(_T("]"), _T(""));
    m_hProcess = GetProcessHandle(_ttoi(strPid));
}

inline HANDLE CSearchFeaturesDlg::GetProcessHandle(DWORD dwPid)
{
    TOKEN_PRIVILEGES priv = { 0 };
    HANDLE hToken = NULL;
    if (OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken))
    {
        priv.PrivilegeCount = 1;
        priv.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;

        if (LookupPrivilegeValue(NULL, SE_DEBUG_NAME, &priv.Privileges[0].Luid))
            AdjustTokenPrivileges(hToken, FALSE, &priv, 0, NULL, NULL);

        CloseHandle(hToken);
    }

    return OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwPid);
}

//////////////////////////////////////////////////
#include <windows.h>







/////////////////////////////

void CSearchFeaturesDlg::OnBnClickedBtnSearch()
{
    if (m_hProcess == INVALID_HANDLE_VALUE)
    {
        MessageBox(_T("��δѡ�����"));
        return;
    }
    /*
    findMatchingCode() ����˵����
    1) hProcess		Ҫ�򿪵Ľ��̾��
    2) markCode		������,֧��ͨ�����**������: 55 8b ec ** 56 83 ec 20 ** ** 08 d9 ee
    3) memBeginAddr		��ʼ������ַ
    4) memEndAddr		����������ַ
    5) retAddr[]		��¼�ҵ��ĵ�ַ,�����������ǰһ��Ҫ��0���� DWORD retAddr[32] = {0};  ���� DWORD *retAddr = new DWORD[32]();
    6) deviation		�������ַ��Ŀ���ַ��ƫ�ƾ��룬�ϸ�����
    7) isCall		�Ƿ�Ϊ��CALL����ת��ַ��true �� retAddr[] ���ص���CALL��ת�ĵ�ַ
    8) isAll		�Ƿ�������з��ϵĵ�ַ��false�ҵ���һ�����ϵĵ�ַ��ͽ���������true����������ֱ��������ַ���ڽ�����ַ��memEndAddr��
    return����ֵ		�ҵ��ĵ�ַ����
    �Ѳ����ڴ�����Ǳ�������û��ѡ��
    */
    FeatureCode fc;
    DWORD retAddr[32] = { 0 };
    DWORD dwCount = fc.FindMatchingCode(m_hProcess, "85 C0 74 44 8B 40 ?? 85 C0 74 3D 83 B8 ?? ?? ?? ?? 00 74 34 8B 0D ?? ?? ?? ?? 85 C9 74 2A 8B 01 FF 50 ?? 85 C0", 0x00401000, 0x07FFFFFF, retAddr, -4, false, false);
    DWORD dwValue;
    ReadProcessMemory(m_hProcess,(LPVOID)retAddr[0],&dwValue,4,NULL);
}
