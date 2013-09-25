// Test2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include "..\BrowserIPC\BrowserIPC.h"
char tmpBuff[1024];

void OnIPCRecvCallBack(HIPCSOCKET hConn, const char* lpData, unsigned long len, void* userdata)
{
	printf("%s \n", lpData);
}

void OnIPCSendCallBack(HIPCSOCKET hConn, const char* lpData, unsigned long len, void* userdata)
{
	IPCRecv(hConn, tmpBuff, 1024, NULL, OnIPCRecvCallBack);
}

int _tmain(int argc, _TCHAR* argv[])
{
	IPCStartup();
	HIPCSOCKET hSocket = IPCNewConnection();

	IPCAddress addr;
	addr.uPid = 2345;
	addr.uPort = 8000;
	IPCConnect(hSocket, addr, NULL, NULL);
	IPCSend(hSocket, "���ǿͻ��˰�", strlen("���ǿͻ��˰�"), NULL, OnIPCSendCallBack);

	MSG msg;
	while(::GetMessage(&msg, NULL, 0, 0))
	{
		if(msg.message == WM_QUIT)
		{
			break;
		}

		::TranslateMessage(&msg);
		::DispatchMessage(&msg);
	}

	system("pause");

	return 0;
}
