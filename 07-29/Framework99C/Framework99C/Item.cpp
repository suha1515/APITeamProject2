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
			m_tInfo.fCX = 12;
			m_tInfo.fCY = 17;

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
	return 0;
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
			ImageManager::ROAD()->PopS_Item(0, m_tRect.left, m_tRect.top);
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
