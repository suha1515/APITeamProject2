#include "stdafx.h"
#include "BackGround.h"


CBackGround::CBackGround()
{
}


CBackGround::~CBackGround()
{
	Release();
}

const list<LINE_INFO*>& CBackGround::GetLineLst() const
{
	// TODO: ���⿡ ��ȯ ������ �����մϴ�.
	return m_LineLst;
}

void CBackGround::Initialize()
{
	
}

int CBackGround::Update()
{
	
	return NO_EVENT;
}

void CBackGround::Render(HDC hDC)
{
	
	BMP->Auto_BackGround_W(1,1);
	BMP->Auto_BackGround_W(2, 3);

}

void CBackGround::Release()
{
	
}
