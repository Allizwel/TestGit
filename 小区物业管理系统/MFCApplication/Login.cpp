// Login.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication.h"
#include "Login.h"
#include "afxdialogex.h"
#include "Register.h"


// Login 对话框

IMPLEMENT_DYNAMIC(Login, CDialogEx)

Login::Login(CWnd* pParent /*=NULL*/)
	: CDialogEx(Login::IDD, pParent)
{

}

Login::~Login()
{
}

void Login::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


bool Login::Judge(CString name, CString password, int identity) {
    if (name == "") {
        //未输入用户名
        AfxMessageBox(_T("请输入用户名！"));
        return false;
    }
    if (password == "") {
        //未输入密码
        AfxMessageBox(_T("请输入密码！"));
        return false;
    }
    if (identity == 0) {
        //管理员身份登录
        readFromFile("Administrator_list.txt");
    }
    else if (identity == 1) {
        //业主身份登录
        readFromFile("User_list.txt");
    }
    else {
        //未选择身份
        AfxMessageBox(_T("请选择身份！"));
        return false;
    }
    map<CString, CString>::iterator it;
    for (it = user_login_list.begin(); it != user_login_list.end(); it++) {
        if (name == it->first && password == it->second) {
            break;
        }
    }
    if (it == user_login_list.end()) {
        //用户名或密码不正确
        AfxMessageBox(_T("用户名或密码错误！"));
        return false;
    }
    return true;
}


//从文件中读取所有的用户或者管理员账号以及密码
void Login::readFromFile(const char *fpath) {
    ifstream input(fpath);
    int count;
    CString user;
    CString password;
    string uu;
    string pp;
    for (string s; getline(input, s);) {
        count = 0;
        uu = "";
        pp = "";
        for (int i = 0; s[i] != ','; i++) {
            uu += s[i];
            count++;
        }
        for (int i = count + 1; s[i] != '\0'; i++) {
            pp += s[i];
            count++;
        }
        user = uu.c_str();
        password = pp.c_str();
        user_login_list.insert(pair<CString, CString>(user, password));
    }
}


BEGIN_MESSAGE_MAP(Login, CDialogEx)
END_MESSAGE_MAP()


// Login 消息处理程序



