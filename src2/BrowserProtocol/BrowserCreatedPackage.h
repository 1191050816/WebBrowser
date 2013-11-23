#pragma once
#include "baseuserpackage.h"

/*
������Ѵ�����package
*/

class BrowserCreatedPackage : public BasePackage
{
public:
	BrowserCreatedPackage();
	virtual ~BrowserCreatedPackage(void);

	virtual size_t EncodeLogicBody(BYTE* pResult,size_t len);
	virtual size_t DecodeLogicBody(const BYTE* pBuffer,size_t len);
	virtual size_t GetLogicBodyLen();

public:
	DWORD m_dwBrowserThreadID;
	DWORD m_dwMark;
};
