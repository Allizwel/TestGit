#pragma once
#include <string>
#include <map>

// Login �Ի���

class Login : public CDialogEx
{
	DECLARE_DYNAMIC(Login)

public:
	Login(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Login();
    bool Judge(CString name, CString password, int identity);
    void readFromFile(const char *fpath);

// �Ի�������
	enum { IDD = IDD_MFCAPPLICATION_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()

public:
    string user_name;
    string user_password;
    map<CString, CString> user_login_list;
};
