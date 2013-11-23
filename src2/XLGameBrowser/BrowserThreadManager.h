#pragma once
//********************************************************************************************
//
//			ÿ��������̹߳�����
//
//
//
//
//*********************************************************************************************//
class BrowserThreadItem;
class BrowserThreadManager
{
public:
	static BrowserThreadManager* Instance()
	{
		static BrowserThreadManager instance;
		return &instance;
	}

	DWORD CreateBrowserThread(HWND hParent, LPCTSTR strUrl, DWORD dwMark);
	void DestroyBrowserThread(DWORD dwThreadID);
	BrowserThreadItem* FindBrowserItem(DWORD dwThreadID);

protected:
	BrowserThreadManager(void);
	~BrowserThreadManager(void);

private:
	std::map<DWORD, BrowserThreadItem*> m_BrowserThreadItems;
};
