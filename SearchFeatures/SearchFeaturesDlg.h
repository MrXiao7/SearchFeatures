
// SearchFeaturesDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "FeatureCode.h"


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

    afx_msg void OnCbnSelchangeComboProcesslist();

    afx_msg void OnBnClickedBtnTest();

    afx_msg void OnBnClickedBtnSearch();

    
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

    DWORD Seach(std::string markCode, DWORD retAddr[]);

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
};
