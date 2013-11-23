#pragma once
#include "baseuserpackage.h"

//�״δ���������߳�ʱ������
//NavigatePackage�������Ѿ�����������Ҫ��urlʱ�򷢳�.
class CreateAndNavigatePackage : public BasePackage
{
public:
	CreateAndNavigatePackage(void);
	~CreateAndNavigatePackage(void);

	virtual size_t EncodeLogicBody(BYTE* pResult,size_t len);
	virtual size_t DecodeLogicBody(const BYTE* pBuffer,size_t len);
	virtual size_t GetLogicBodyLen();

public:
	std::string m_strUrl;
	HWND m_hParentWnd;
	DWORD m_dwMark;
};
