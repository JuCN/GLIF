#pragma once
#include "ClientSocket.h"



// Boîte de dialogue DiagTest

class DiagTest : public CDialogEx
{
	DECLARE_DYNAMIC(DiagTest)

public:
	DiagTest(CWnd* pParent = NULL);   // constructeur standard
	virtual ~DiagTest();

// Données de boîte de dialogue
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FENETRE_TEST };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // Prise en charge de DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();

private:
	const int PORT = 8080;
	CAsyncSocket sock;
protected:
	CString textToSend;
public:
	afx_msg void OnBnClickedSend();
	afx_msg void OnBnClickedConnect();
};
