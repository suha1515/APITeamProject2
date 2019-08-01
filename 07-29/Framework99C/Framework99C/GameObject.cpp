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

const RECT & CGameObject::GetHitBox() const
{
	return m_tHitRect;
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

void CGameObject::SetY(float fY)
{
	m_tInfo.fY = fY;
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
void CGameObject::UpdateHitBox()
{
	m_tHitRect.left = static_cast<LONG>(m_tInfo.fX - m_tHitBox.width*0.5f);
	m_tHitRect.top = static_cast<LONG> (m_tInfo.fY -  m_tHitBox.heigth*0.5f);
	m_tHitRect.right = static_cast<LONG>(m_tInfo.fX + m_tHitBox.width*0.5f);
	m_tHitRect.bottom = static_cast<LONG>(m_tInfo.fY + m_tHitBox.heigth*0.5f);
}
int CGameObject::IndexTimer(int frame, clock_t time)
{
	if (clock() - m_oldtime > time)
	{
		m_index = (m_index + 1) % frame;
		m_oldtime = clock();
	}
	return m_index;
}

int CGameObject::IndexTimerOnce(int frame, clock_t time)
{
	if (clock() - m_oldtime2 > time)
	{
		if (m_index2 < frame - 1)
		{
			m_index2++;
		}
		else
		{
			frame = -1;
			
		}
		m_oldtime2 = clock();
	}
	return m_index2;
}

void CGameObject::Set_index(int index)
{
	m_index = index;
}

void CGameObject::Set_oldtime()
{
	m_oldtime = clock();
}

void CGameObject::Set_Index2(int index2)
{
	m_index2 = index2;
}

void CGameObject::Set_oldtime2()
{
	m_oldtime2 = clock();
}

clock_t CGameObject::Get_oldtime()
{
	return m_oldtime;
}

clock_t CGameObject::Get_oldtime2()
{
	return m_oldtime2;
}
