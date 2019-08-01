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
	switch (m_FloorType)
	{
	case STAGE1_BOTTOM:
		m_tInfo.fCX = 100;
		m_tInfo.fCY = 100;

		m_tHitBox.heigth = 100;
		m_tHitBox.width = 100;
		break;
	case STAGE1_HANG:
		m_tInfo.fCX = 129;
		m_tInfo.fCY = 52;

		m_tHitBox.width = 129;
		m_tHitBox.heigth = 52;
		break;
	case STAGE2_BOTTOM:
		m_tInfo.fCX = 100;
		m_tInfo.fCY = 100;

		m_tHitBox.width = 100;
		m_tHitBox.heigth =100;
		break;
	case STAGE2_HANG:
		m_tHitBox.width = 129;
		m_tHitBox.heigth = 52;
		break;
	default:
		break;
	}
}

int CFloor::Update()
{
	if (m_bIsDead)
		return DEAD_OBJ;
	CGameObject::UpdateRect();
	CGameObject::UpdateHitBox();

	Move();
	IsOutofRange();


	return NO_EVENT;
}

void CFloor::Render(HDC hDC)
{
	switch (m_FloorType)
	{
	case STAGE1_BOTTOM:
		BMP->PopS_Obj(0, m_tRect.left, m_tRect.top);
		break;
	case STAGE1_HANG:
		BMP->PopS_Obj(12, m_tRect.left, m_tRect.top);
		break;
	case STAGE2_BOTTOM:
		BMP->PopS_Obj(13, m_tRect.left, m_tRect.top);
		break;
	case STAGE2_HANG:
		BMP->PopS_Obj(14, m_tRect.left, m_tRect.top);
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

	hNewPen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	hOldPen = (HPEN)SelectObject(hDC, hNewPen);

	MoveToEx(hDC, m_tHitRect.left, m_tHitRect.top, nullptr);
	LineTo(hDC, m_tHitRect.right, m_tHitRect.top);
	LineTo(hDC, m_tHitRect.right, m_tHitRect.bottom);
	LineTo(hDC, m_tHitRect.left, m_tHitRect.bottom);
	LineTo(hDC, m_tHitRect.left, m_tHitRect.top);

	DeleteObject(SelectObject(hDC, hOldPen));
	
}

void CFloor::Move()
{
	m_tInfo.fX += CScrollMgr::m_fScrollX;
}

void CFloor::SetType(FLOOR_TYPE type)
{
	m_FloorType = type;
	Initialize();
}

void CFloor::Release()
{
}

void CFloor::IsOutofRange()
{
	if (-200>= m_tRect.left || -200 >= m_tRect.top|| WINCY+200 <= m_tRect.bottom)
		m_bIsDead = true;
}
