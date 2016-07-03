#pragma once
#include <string>
#include <map>

// Login 对话框

class Login : public CDialogEx
{
	DECLARE_DYNAMIC(Login)

public:
	Login(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Login();
    bool Judge(CString name, CString password, int identity);
    void readFromFile(const char *fpath);

// 对话框数据
	enum { IDD = IDD_MFCAPPLICATION_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()

public:
    string user_name;
    string user_password;
    map<CString, CString> user_login_list;
};
