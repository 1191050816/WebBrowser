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

	DWORD CreateBrowserThread(LPCTSTR strUrl);
	void DestroyBrowserThread(DWORD dwThreadID);

protected:
	BrowserThreadManager(void);
	~BrowserThreadManager(void);

private:
	std::map<DWORD, BrowserThreadItem*> m_BrowserThreadItems;
};
