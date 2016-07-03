// UserSystem.cpp : 实现文件
//

#include "stdafx.h"
#include "UserSystem.h"
#include "afxdialogex.h"


// UserSystem 对话框

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


// UserSystem 消息处理程序
BOOL UserSystem::OnInitDialog() {
    SetWindowPos(NULL, 0, 0, 1000, 600, SWP_NOMOVE);//设置窗口的大小
    return true;
}