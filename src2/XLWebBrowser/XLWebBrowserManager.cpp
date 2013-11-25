// XLWebBrowserManager.cpp : Implementation of CXLWebBrowserManager

#include "stdafx.h"
#include "XLWebBrowserManager.h"

// CXLWebBrowserManager
CXLWebBrowserManager::CXLWebBrowserManager()
{

}

HRESULT CXLWebBrowserManager::FinalConstruct()
{
	HostComunication::Instance()->Init();
	HostComunication::Instance()->AddEventHandler(this);
	return S_OK;
}

void CXLWebBrowserManager::FinalRelease()
{
	HostComunication::Instance()->Uninit();
}

STDMETHODIMP CXLWebBrowserManager::CreateBrowser(LONG dwProcessID, LONG hParentWnd, IXLMSWebBrowser** ppMSWebBrowser)
{
	// TODO: Add your implementation code here
	XLMSWebBrowserObjType* pMSWebBrowser = NULL;
	XLMSWebBrowserObjType::CreateInstance(&pMSWebBrowser);

	pMSWebBrowser->Create(dwProcessID, (HWND)hParentWnd);

	pMSWebBrowser->AddRef();
	CComPtr<IXLMSWebBrowser> spWebBrowser = pMSWebBrowser;
	spWebBrowser.CopyTo(ppMSWebBrowser);

	m_BrowserList.push_back(pMSWebBrowser);
	return S_OK;
}

STDMETHODIMP CXLWebBrowserManager::DestroyBrowser(IXLMSWebBrowser* pMSWebBrowser)
{
	// TODO: �ڴ����ʵ�ִ���
	ATLASSERT(pMSWebBrowser);
	if(pMSWebBrowser)
	{
		pMSWebBrowser->Destroy();
	}

	return S_OK;
}

STDMETHODIMP CXLWebBrowserManager::DestroyBrowser2(LONG dwProcessID, LONG dwThreadID)
{
	// TODO: �ڴ����ʵ�ִ���
 	std::list<CXLMSWebBrowser*>::iterator it = m_BrowserList.begin();
 	for(; it != m_BrowserList.end(); ++it)
 	{
 		if((*it)->GetBrowserProcessID() == dwProcessID && (*it)->GetBrowserThreadID() == dwThreadID)
 		{
 			(*it)->Destroy();
 			break;
 		}
 	}

	return S_OK;
}

void CXLWebBrowserManager::OnConnect()
{

}

void CXLWebBrowserManager::OnProcessCreated(DWORD dwProcessID)
{
	std::list<CXLMSWebBrowser*>::iterator it = m_BrowserList.begin();
	for(; it != m_BrowserList.end(); ++it)
	{
		//�������ǻ��ҵ����processid�ģ�������ڵ����̶��������Ļ���
		//����ͨ��ֻ�е�һ���������̵�������յ����¼���������ֱ���ڴ˽��̴���������������յ����¼�...
		if((*it)->GetBrowserProcessID() == dwProcessID)
		{
			(*it)->OnProcessCreated();
			break;
		}
	}
}

void CXLWebBrowserManager::OnBrowserCreated(DWORD dwProcessID, DWORD dwThreadID, DWORD dwMark)
{
	std::list<CXLMSWebBrowser*>::iterator it = m_BrowserList.begin();
	for(; it != m_BrowserList.end(); ++it)
	{
		if((*it)->GetBrowserProcessID() == dwProcessID && (*it)->GetMarkCookie() == dwMark)
		{
			(*it)->OnBrowserCreated(dwThreadID);
			break;
		}
	}
}
