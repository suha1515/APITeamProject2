#include "stdafx.h"
#include "Floor.h"


CFloor::CFloor()
{
}


CFloor::~CFloor()
{
}

void CFloor::Initialize()
{
	m_tInfo.fCX = 124;
	m_tInfo.fCY = 120;

	m_tInfo.fX = m_tInfo.fCX / 2;
	m_tInfo.fY = m_tInfo.fCY / 2;
	
	m_Speed = 400.f;
}

int CFloor::Update()
{
	return 0;
}

void CFloor::Render(HDC hDC)
{
}

void CFloor::Move()
{
}

void CFloor::Release()
{
}
