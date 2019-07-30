#include "stdafx.h"
#include "GameObject.h"


CGameObject::CGameObject()
	: m_fSpeed(0.f), m_fAngle(0.f), m_bIsDead(false)
{
}


CGameObject::~CGameObject()
{
}

const INFO & CGameObject::GetInfo() const
{
	// TODO: 여기에 반환 구문을 삽입합니다.
	return m_tInfo;
}

const RECT & CGameObject::GetRect() const
{
	// TODO: 여기에 반환 구문을 삽입합니다.
	return m_tRect;
}

void CGameObject::SetPos(float x, float y)
{
	m_tInfo.fX = x;
	m_tInfo.fY = y;
}

void CGameObject::SetAngle(float fAngle)
{
	m_fAngle = fAngle;
}

void CGameObject::SetDead(bool bIsDead)
{
	m_bIsDead = bIsDead;
}

void CGameObject::SetDamage(int dmg)
{
	m_tInfo.iHealth -= dmg;
}

void CGameObject::SetHealth(int iHealth)
{
	m_tInfo.iHealth = iHealth;
}

void CGameObject::SetGraceChk(bool bCollision)
{
	m_tInfo.bGraceChk = bCollision;
}

void CGameObject::SetTime(DWORD dwTime)
{
	m_tInfo.dwOldTime = dwTime;
}

DWORD CGameObject::GetTime()
{
	return m_tInfo.dwOldTime;
}

void CGameObject::UpdateRect()
{
	m_tRect.left = static_cast<LONG>(m_tInfo.fX - m_tInfo.fCX * 0.5f);
	m_tRect.top = static_cast<LONG>(m_tInfo.fY - m_tInfo.fCY * 0.5f);
	m_tRect.right = static_cast<LONG>(m_tInfo.fX + m_tInfo.fCX * 0.5f);
	m_tRect.bottom = static_cast<LONG>(m_tInfo.fY + m_tInfo.fCY * 0.5f);
}
