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

	m_Speed = 400.f;
}

int CFloor::Update()
{
	if (m_bIsDead)
		return DEAD_OBJ;
	CGameObject::UpdateRect();
	Move();
	IsOutofRange();
	

	return NO_EVENT;
}

void CFloor::Render(HDC hDC)
{
	CGameObject::UpdateRect();
	BMP->PopS_Obj(0, m_tRect.left, m_tRect.top);
}

void CFloor::Move()
{
	m_tInfo.fX += CScrollMgr::m_fScrollX;
}

void CFloor::Release()
{
}

void CFloor::IsOutofRange()
{
	if (-200>= m_tRect.left || -200 >= m_tRect.top|| WINCY+200 <= m_tRect.bottom)
		m_bIsDead = true;
}
