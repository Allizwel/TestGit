#pragma once
#include "resource.h"

// UserSystem �Ի���

class UserSystem : public CDialogEx
{
	DECLARE_DYNAMIC(UserSystem)

public:
	UserSystem(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~UserSystem();
    virtual BOOL OnInitDialog();

// �Ի�������
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
