
// SearchFeatures.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CSearchFeaturesApp: 
// �йش����ʵ�֣������ SearchFeatures.cpp
//

class CSearchFeaturesApp : public CWinApp
{
public:
	CSearchFeaturesApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CSearchFeaturesApp theApp;