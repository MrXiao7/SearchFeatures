
// SearchFeaturesDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


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
    //���ڻ�ȡ��ǰ���н���
    void GetAllProcess();
private:
    // ������ʾ�����б��ComboBox�ؼ�
    CComboBox m_comboProcessList;
    HANDLE m_hProcess;
    CString m_szFeatureCode;
    UINT m_addrLen;
    int m_nOffset;
public:
    afx_msg void OnCbnSelchangeComboProcesslist();
    inline HANDLE GetProcessHandle(DWORD dwPid);
    afx_msg void OnBnClickedBtnSearch();
};
