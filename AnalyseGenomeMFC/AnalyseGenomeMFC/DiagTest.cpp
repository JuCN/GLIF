// DiagTest.cpp : fichier d'implémentation
//

#include "stdafx.h"
#include "AnalyseGenomeMFC.h"
#include "DiagTest.h"
#include "afxdialogex.h"
#include <string>

using namespace std;


// Boîte de dialogue DiagTest

IMPLEMENT_DYNAMIC(DiagTest, CDialogEx)

DiagTest::DiagTest(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_FENETRE_TEST, pParent)
	, textToSend(_T("")) {
}

DiagTest::~DiagTest()
{
}

void DiagTest::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, textToSend);
}


BEGIN_MESSAGE_MAP(DiagTest, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &DiagTest::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_SEND, &DiagTest::OnBnClickedSend)
	ON_BN_CLICKED(ID_CONNECT, &DiagTest::OnBnClickedConnect)
END_MESSAGE_MAP()


// Gestionnaires de messages de DiagTest


void DiagTest::OnEnChangeEdit1() {
	// TODO:  S'il s'agit d'un contrôle RICHEDIT, le contrôle ne
	// envoyez cette notification sauf si vous substituez CDialogEx::OnInitDialog()
	// fonction et appelle CRichEditCtrl().SetEventMask()
	// avec l'indicateur ENM_CHANGE ajouté au masque grâce à l'opérateur OR.

	// TODO:  Ajoutez ici le code de votre gestionnaire de notification de contrôle
}


void DiagTest::OnBnClickedSend() {
	TRACE1("Je clique sur Send avec : %s\n", textToSend);
	sock.Send(textToSend, textToSend.GetLength());
}


void DiagTest::OnBnClickedConnect() {
	CString addr(_T("127.0.0.1"));
	sock.Create();

	if(!sock.Connect(addr, PORT)) {
		TRACE("Failed To Connect\n");
	}
}
