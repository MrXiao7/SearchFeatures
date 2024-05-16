
// SearchFeaturesDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "FeatureCode.h"
#include "afxcmn.h"


// CSearchFeaturesDlg �Ի���
class CSearchFeaturesDlg : public CDialogEx
{
// ����
public:
	CSearchFeaturesDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_SEARCHFEATURES_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


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
    afx_msg void OnBnClickedOk();

    virtual BOOL PreTranslateMessage(MSG* pMsg);

    //ѡ��������������������ı���Ӧ����
    afx_msg void OnCbnSelchangeComboProcesslist();
    
    //���԰�ť��Ӧ����
    afx_msg void OnBnClickedBtnTest();

    //������ť��Ӧ����
    afx_msg void OnBnClickedBtnSearch();

    //��ӵ��б�ť��Ӧ����
    afx_msg void OnBnClickedBtnAddlist();

    //���������뵽�ļ���ť��Ӧ����
    afx_msg void OnBnClickedBtnSave();

    //�����������ļ���ť��Ӧ����
    afx_msg void OnBnClickedBtnLoad();

private:
    /*
    GetProcessHandle
    ͨ������id��ȡ���̾��
    ����Ϊ����id
    ����ֵΪ���̾��
    */
    inline HANDLE GetProcessHandle(DWORD dwPid);
    //���ڻ�ȡ��ǰ���н���
    void GetAllProcess();

    /*
    Search
    ���������룬���ڲ�������������������붼Ҫ������Ϊ�˴��븴�����Զ�����һ����������
    strMarkCode		������, ֧��ͨ�����**������: 55 8b ec ** 56 83 ec 20 * * ** 08 d9 ee
    dwRetAddrArr[]		��¼�ҵ��ĵ�ַ, �����������ǰһ��Ҫ��0���� DWORD retAddr[32] = { 0 };  ���� DWORD *retAddr = new DWORD[32]();
    */
    DWORD Search(std::string strMarkCode, DWORD dwRetAddrArr[]);

private:
    // ������ʾ�����б��ComboBox�ؼ�
    CComboBox m_comboProcessList;

    //�洢���̾��
    HANDLE m_hProcess;

    // ���������� ���Ҫ����C++����Ļ�����C++������
    CString m_strName;

    // ������ע�� ˵��
    CString m_strNotes;

    // ������
    CString m_strMarkCode;

    // Ҫ��ȡ��ƫ�� ��������Ͼ������� �����Ǹ���
    int m_nOffset;

    // Ҫ��ȡ�ĳ���
    UINT m_uLen;

    // ������������ʼ��ַ
    CString m_dwBeginAddr;

    //����������������ַ
    CString m_dwEndAddr;

    //�������б�
    CString m_strMarkCodeList;
    
    // �����û��������ͣ�0==��ַ 1==call 2==ƫ��
    int m_btnType;
    
    // ��ʾ�������������
    CListCtrl m_listResult;

    // ����Ҫ����ʲô���ԵĴ���
    CComboBox m_comboBoxLanguage;
};
