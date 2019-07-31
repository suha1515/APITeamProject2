#include "stdafx.h"
#include "Item.h"


CItem::CItem()
{
}


CItem::~CItem()
{
}

void CItem::Initialize()
{
	switch (m_ItemType)
	{
		break;
	case ITEM_HEALTH:
		break;
	case ITEM_MAGNET:
		break;
	default:
		break;
	}
}

int CItem::Update()
{
	if (m_bIsDead)
		return DEAD_OBJ;
	CGameObject::UpdateRect();
	Move();
	IsOutofRange();

	return NO_EVENT;
}

void CItem::Render(HDC hDC)
{
	switch (m_ItemType)
	{
	break;
	case ITEM_HEALTH:
		break;
	case ITEM_MAGNET:
		break;
	default:
		break;
	}
}

void CItem::Release()
{
}

void CItem::Move()
{
	m_tInfo.fX += CScrollMgr::m_fScrollX;
}

void CItem::SetItemType(ITEM_TYPE itemType)
{
	m_ItemType = itemType;
	Initialize();
}

void CItem::IsOutofRange()
{
	if (-200 >= m_tRect.left || WINCY + 200 <= m_tRect.bottom)
		m_bIsDead = true;
}
