// Login.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication.h"
#include "Login.h"
#include "afxdialogex.h"
#include "Register.h"


// Login �Ի���

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
        //δ�����û���
        AfxMessageBox(_T("�������û�����"));
        return false;
    }
    if (password == "") {
        //δ��������
        AfxMessageBox(_T("���������룡"));
        return false;
    }
    if (identity == 0) {
        //����Ա��ݵ�¼
        readFromFile("Administrator_list.txt");
    }
    else if (identity == 1) {
        //ҵ����ݵ�¼
        readFromFile("User_list.txt");
    }
    else {
        //δѡ�����
        AfxMessageBox(_T("��ѡ����ݣ�"));
        return false;
    }
    map<CString, CString>::iterator it;
    for (it = user_login_list.begin(); it != user_login_list.end(); it++) {
        if (name == it->first && password == it->second) {
            break;
        }
    }
    if (it == user_login_list.end()) {
        //�û��������벻��ȷ
        AfxMessageBox(_T("�û������������"));
        return false;
    }
    return true;
}


//���ļ��ж�ȡ���е��û����߹���Ա�˺��Լ�����
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


// Login ��Ϣ�������



