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


	m_tInfo.fY = 650;
	
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
	ImageManager::ROAD()->PopS_Object(0, m_tRect.left, m_tRect.top);
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
	if (-500>= m_tRect.left || -200 >= m_tRect.top|| WINCY+200 <= m_tRect.bottom)
		m_bIsDead = true;
}
