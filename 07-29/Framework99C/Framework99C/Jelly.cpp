#include "stdafx.h"
#include "Jelly.h"


CJelly::CJelly()
{
}


CJelly::~CJelly()
{
}

void CJelly::Initialize()
{
	switch (m_JellyType)
	{
	case YELLOW_BEAR:
		m_tInfo.fCX = 55;
		m_tInfo.fCY = 51;
		break;
	case PINK_BEAR:
		m_tInfo.fCX = 55;
		m_tInfo.fCY = 51;
		break;
	case BLUE_BEAN:
		m_tInfo.fCX = 20;
		m_tInfo.fCY = 25;
		break;
	default:
		break;
	}
}

int CJelly::Update()
{
	if (m_bIsDead)
		return DEAD_OBJ;
	CGameObject::UpdateRect();
	Move();
	IsOutofRange();
	
	return NO_EVENT;
}

void CJelly::Render(HDC hDC)
{
	switch (m_JellyType)
	{
	case YELLOW_BEAR:
		BMP->PopS_Item(1, m_tRect.left, m_tRect.top);
		break;
	case PINK_BEAR:
		BMP->PopS_Item(2, m_tRect.left, m_tRect.top);
		break;
	case BLUE_BEAN:
		BMP->PopS_Item(0, m_tRect.left, m_tRect.top);
		break;
	default:
		break;
	}
	HPEN hNewPen = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
	HPEN hOldPen = (HPEN)SelectObject(hDC, hNewPen);

	MoveToEx(hDC, m_tRect.left, m_tRect.top, nullptr);
	LineTo(hDC, m_tRect.right, m_tRect.top);
	LineTo(hDC, m_tRect.right, m_tRect.bottom);
	LineTo(hDC, m_tRect.left, m_tRect.bottom);
	LineTo(hDC, m_tRect.left, m_tRect.top);

	DeleteObject(SelectObject(hDC, hOldPen));
}

void CJelly::Release()
{

}

void CJelly::Move()
{
	m_tInfo.fX += CScrollMgr::m_fScrollX;

	CGameObject* pPlayer = CObjectMgr::GetInstance()->GetPlayer();
	if (fabs(pPlayer->GetInfo().fX - m_tInfo.fX) <= 100.0f)
	{
		float dx = pPlayer->GetInfo().fX-m_tInfo.fX;
		float dy = pPlayer->GetInfo().fY-m_tInfo.fY;

		float angle = atan2f(dy, dx);

		m_tInfo.fX += cosf(angle)*3.0f;
		m_tInfo.fY += sinf(angle)*3.0f;
	}
}

void CJelly::SetJellyType(JELLY_TYPE jellyType)
{
	m_JellyType = jellyType;
	Initialize();
}

void CJelly::IsOutofRange()
{
	if (-200 >= m_tRect.left || WINCY + 200 <= m_tRect.bottom)
		m_bIsDead = true;
}
