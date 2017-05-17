// ClientSocket.cpp : fichier d'implémentation
//

#include "stdafx.h"
#include "AnalyseGenomeMFC.h"
#include "ConnectedSocket.h"

using namespace std;

ConnectedSocket::ConnectedSocket()
{
}

ConnectedSocket::~ConnectedSocket()
{
}

void ConnectedSocket::OnReceive(int nErrorCode)
{
	const int BUFF_LEN = 2048;
	char szBuff[BUFF_LEN];

	int nReceivedSize = Receive(szBuff, BUFF_LEN);
	TRACE1("Receive %d bytes\n", nReceivedSize);

	if(nReceivedSize <= 0)
		TRACE1("Socket Error : %d\n", GetLastError());
		return;

	szBuff[nReceivedSize] = '\0';
	TRACE(szBuff);

	string strResponse = "J'ai bien reçu ta merde\n";

	int nSentBytes = 0;
	const char* pszBuff = strResponse.c_str();
	int nResponseSize = strResponse.length();

	while (nSentBytes < nResponseSize)
	{
		nSentBytes = Send(pszBuff, nResponseSize);
		nResponseSize = nResponseSize - nSentBytes;
		pszBuff = pszBuff + nSentBytes;
	}

	CAsyncSocket::OnReceive(nErrorCode);
}
