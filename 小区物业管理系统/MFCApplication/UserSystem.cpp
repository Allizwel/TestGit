// UserSystem.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "UserSystem.h"
#include "afxdialogex.h"


// UserSystem �Ի���

IMPLEMENT_DYNAMIC(UserSystem, CDialogEx)

UserSystem::UserSystem(CWnd* pParent /*=NULL*/)
	: CDialogEx(UserSystem::IDD, pParent)
{

}

UserSystem::~UserSystem()
{
}

void UserSystem::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(UserSystem, CDialogEx)
END_MESSAGE_MAP()


// UserSystem ��Ϣ�������
BOOL UserSystem::OnInitDialog() {
    SetWindowPos(NULL, 0, 0, 1000, 600, SWP_NOMOVE);//���ô��ڵĴ�С
    return true;
}