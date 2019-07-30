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
	case ITEM_JELLY:
	{
		switch (m_JellyType)
		{
		case YELLOW_BEAR:
			break;
		case PINK_BEAR:
			break;
		case BLUE_BEAN:
			m_tInfo.fCX = 10;
			m_tInfo.fCY = 25/2;

			break;
		default:
			break;
		}
	}
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
	case ITEM_JELLY:
	{
		switch (m_JellyType)
		{
		case YELLOW_BEAR:
			break;
		case PINK_BEAR:
			break;
		case BLUE_BEAN:
			BMP->PopS_Item(0, m_tInfo.fX, m_tInfo.fY);
			break;
		default:
			break;
		}
	}
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

void CItem::SetItemType(ITEM_TYPE itemType, JELLY_TYPE jellyType )
{
	m_ItemType = itemType;
	m_JellyType = jellyType;
	Initialize();
}

void CItem::IsOutofRange()
{
	if (-200 >= m_tRect.left || -200 >= m_tRect.top || WINCY + 200 <= m_tRect.bottom)
		m_bIsDead = true;
}
