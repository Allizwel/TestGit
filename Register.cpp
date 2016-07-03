// Register.cpp : ʵ���ļ�
//
#include <atlbase.h>
#include "stdafx.h"
#include "MFCApplication.h"
#include "Register.h"
#include "MFCApplicationDlg.h"
#include "afxdialogex.h"
#include "Login.h"
#include<string>


// Register �Ի���

IMPLEMENT_DYNAMIC(Register, CDialogEx)

Register::Register(CWnd* pParent /*=NULL*/)
	: CDialogEx(Register::IDD, pParent)
{

}

Register::~Register()
{

}

//���س�ʼ����������ע�����Ի�����г�ʼ��
BOOL Register::OnInitDialog() {
    //ע�����С������ϵͳ��������
    SetWindowPos(NULL, 0, 0, 1000, 600, SWP_NOMOVE);//���ô��ڵĴ�С
    font.CreatePointFont(300, _T("�����п�"), NULL);
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


// Register ��Ϣ�������


void Register::OnBnClickedButton2()
{
    // TODO:  �ڴ���ӿؼ�֪ͨ����������
    EndDialog(IDOK);
    CMFCApplicationDlg dlg;
    INT_PTR nResponse = dlg.DoModal();
}


void Register::OnBnClickedButton1()
{
    // TODO:  �ڴ���ӿؼ�֪ͨ����������
    Login log;
    log.readFromFile("User_list.txt");
    map<CString, CString>::iterator it;
    GetDlgItem(IDC_EDIT1)->GetWindowText(name);
    GetDlgItem(IDC_EDIT2)->GetWindowText(password);
    GetDlgItem(IDC_EDIT3)->GetWindowText(password_confirm);

    if (name.GetLength() == 0){
        //�û���Ϊ��
        AfxMessageBox(_T("�û�������Ϊ��"));
        return;
    }
    if (password.GetLength() < 8) {
        //���볤�Ȳ���
        AfxMessageBox(_T("���볤��Ӧ��С��8��"));
        return;
    }
    if (password != password_confirm) {
        //�������벻ƥ��
        AfxMessageBox(_T("�������벻��ͬ��"));
        return;
    }
    int i = 0;
    while (i < name.GetLength()) {
        if (isRightType(name[i])) {
            i++;
        }
        else {
            AfxMessageBox(_T("�û�����ʽ����ȷ��"));
            return;
        }
    }
    i = 0;
    while (i < password.GetLength()) {
        if (isRightType(password[i])) {
            i++;
        }
        else {
            AfxMessageBox(_T("�����ʽ����ȷ��"));
            return;
        }
    }

    //�û����Ƿ����
    for (it = log.user_login_list.begin(); it != log.user_login_list.end(); it++) {
        if (name == it->first) {
            break;
        }
    }
    if (it != log.user_login_list.end()) {
        //�û����Ѵ���
        AfxMessageBox(_T("�û����Ѵ��ڣ�"));
        return;
    }
    else{
        //����ע��
        writeToFile("Register_list.txt");
        if (AfxMessageBox(_T("ע��ɹ�"))) {
            EndDialog(IDOK);
            CMFCApplicationDlg dlg;
            INT_PTR nResponse = dlg.DoModal();
        }

    }
}

//���ȴ�ע��ɹ����û�д��Register.txt��
void Register::writeToFile(const char *fpath) {
    ofstream output(fpath, ios::app);//���ļ�βд�룬���Ǹ��������ļ�����
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
