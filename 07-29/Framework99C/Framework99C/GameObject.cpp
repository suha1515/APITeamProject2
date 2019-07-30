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
	// TODO: ���⿡ ��ȯ ������ �����մϴ�.
	return m_tInfo;
}

const RECT & CGameObject::GetRect() const
{
	// TODO: ���⿡ ��ȯ ������ �����մϴ�.
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

void CGameObject::UpdateRect()
{
	m_tRect.left = static_cast<LONG>(m_tInfo.fX - m_tInfo.fCX * 0.5f);
	m_tRect.top = static_cast<LONG>(m_tInfo.fY - m_tInfo.fCY * 0.5f);
	m_tRect.right = static_cast<LONG>(m_tInfo.fX + m_tInfo.fCX * 0.5f);
	m_tRect.bottom = static_cast<LONG>(m_tInfo.fY + m_tInfo.fCY * 0.5f);
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

void CGameObject::Set_index(int index)
{
	m_index = index;
}

void CGameObject::Set_oldtime()
{
	m_oldtime = clock();
}

clock_t CGameObject::Get_oldtime()
{
	return m_oldtime;
}
