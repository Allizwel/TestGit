// Register.cpp : 实现文件
//
#include <atlbase.h>
#include "stdafx.h"
#include "MFCApplication.h"
#include "Register.h"
#include "MFCApplicationDlg.h"
#include "afxdialogex.h"
#include "Login.h"
#include<string>


// Register 对话框

IMPLEMENT_DYNAMIC(Register, CDialogEx)

Register::Register(CWnd* pParent /*=NULL*/)
	: CDialogEx(Register::IDD, pParent)
{

}

Register::~Register()
{

}

//重载初始化函数，对注册界面对话框进行初始化
BOOL Register::OnInitDialog() {
    //注册界面小区管理系统字体设置
    SetWindowPos(NULL, 0, 0, 1000, 600, SWP_NOMOVE);//设置窗口的大小
    font.CreatePointFont(300, _T("华文行楷"), NULL);
    GetDlgItem(IDC_STATIC)->SetFont(&font);
    return true;
}

void Register::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
}

void Register::OnClose() {
    AfxGetMainWnd()->SendMessage(WM_CLOSE);
}


BEGIN_MESSAGE_MAP(Register, CDialogEx)
    ON_BN_CLICKED(IDC_BUTTON2, &Register::OnBnClickedButton2)
    ON_BN_CLICKED(IDC_BUTTON1, &Register::OnBnClickedButton1)
END_MESSAGE_MAP()


// Register 消息处理程序


void Register::OnBnClickedButton2()
{
    // TODO:  在此添加控件通知处理程序代码
    EndDialog(IDOK);
    CMFCApplicationDlg dlg;
    INT_PTR nResponse = dlg.DoModal();
}


void Register::OnBnClickedButton1()
{
    // TODO:  在此添加控件通知处理程序代码
    Login log;
    log.readFromFile("User_list.txt");
    map<CString, CString>::iterator it;
    GetDlgItem(IDC_EDIT1)->GetWindowText(name);
    GetDlgItem(IDC_EDIT2)->GetWindowText(password);
    GetDlgItem(IDC_EDIT3)->GetWindowText(password_confirm);

    if (name.GetLength() == 0){
        //用户名为空
        AfxMessageBox(_T("用户名不能为空"));
        return;
    }
    if (password.GetLength() < 8) {
        //密码长度不足
        AfxMessageBox(_T("密码长度应不小于8！"));
        return;
    }
    if (password != password_confirm) {
        //两次密码不匹配
        AfxMessageBox(_T("两次密码不相同！"));
        return;
    }
    int i = 0;
    while (i < name.GetLength()) {
        if (isRightType(name[i])) {
            i++;
        }
        else {
            AfxMessageBox(_T("用户名格式不正确！"));
            return;
        }
    }
    i = 0;
    while (i < password.GetLength()) {
        if (isRightType(password[i])) {
            i++;
        }
        else {
            AfxMessageBox(_T("密码格式不正确！"));
            return;
        }
    }

    //用户名是否存在
    for (it = log.user_login_list.begin(); it != log.user_login_list.end(); it++) {
        if (name == it->first) {
            break;
        }
    }
    if (it != log.user_login_list.end()) {
        //用户名已存在
        AfxMessageBox(_T("用户名已存在！"));
        return;
    }
    else{
        //允许注册
        writeToFile("Register_list.txt");
        if (AfxMessageBox(_T("注册成功"))) {
            EndDialog(IDOK);
            CMFCApplicationDlg dlg;
            INT_PTR nResponse = dlg.DoModal();
        }

    }
}

//将等待注册成功的用户写入Register.txt中
void Register::writeToFile(const char *fpath) {
    ofstream output(fpath, ios::app);//在文件尾写入，而非覆盖整个文件内容
    CStringA stra1(name);
    CStringA stra2(password);
    output << stra1 << ',' << stra2 << endl;
}

bool Register::isRightType(char ch) {
    if ((ch > 64 && ch < 91) || (ch > 96 && ch < 123) || (ch > 47 && ch < 58)) {
        return true;
    }
    return false;
}
