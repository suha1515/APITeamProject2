#include "stdafx.h"
#include "Obstacle.h"


CObstacle::CObstacle()
{
}

CObstacle::~CObstacle()
{
}

void CObstacle::Initialize()
{
	m_IsFall = false;
	m_IsActive = false;
	switch (m_ObsType)
	{
	case OBSTACLE_GIMLET:
		m_tInfo.fCX = 63;
		m_tInfo.fCY = 99;
		break;
	case OBSTACLE_GIMLET2:
		m_tInfo.fCX = 63;
		m_tInfo.fCY = 99;
		break;
	case OBSTACLE_GIMLETS:
		m_tInfo.fCX = 81;
		m_tInfo.fCY = 131;
		break;
	case OBSTACLE_GIMLETS2:
		m_tInfo.fCX = 435;
		m_tInfo.fCY = 190;
		break;
	case OBSTACLE_FORK:
		m_tInfo.fCX = 80;
		m_tInfo.fCY = 113;
		break;
	case OBSTACLE_FORK1:
		m_tInfo.fCX = 134;
		m_tInfo.fCY = 482;
		break;
	case OBSTACLE_FORK2:
		m_tInfo.fCX = 106;
		m_tInfo.fCY = 193;
		break;
	case OBSTACLE_FORK3:
		m_tInfo.fCX = 71;
		m_tInfo.fCY = 216;
		break;
	case OBSTACLE_FORK4:
		m_tInfo.fCX = 86;
		m_tInfo.fCY = 482;
		break;
	case OBSTACLE_LONGFORK:
		m_tInfo.fCX = 59;
		m_tInfo.fCY = 193;
		break;
		//스테이지2
	case OBSTACLE_PORTION:
		m_tInfo.fCX = 122;
		m_tInfo.fCY = 251;
		break;
	case OBSTACLE_PORTION2:
		m_tInfo.fCX = 122;
		m_tInfo.fCY = 251;
		break;
	case OBSTACLE_SKULL:
		m_tInfo.fCX = 104;
		m_tInfo.fCY = 135;
		break;
	case OBSTACLE_ONION:
		m_tInfo.fCX = 170;
		m_tInfo.fCY = 475;
		break;
	case OBSTACLE_FROG:
		m_tInfo.fCX = 170;
		m_tInfo.fCY = 475;
		break;
	case OBSTACLE_TRAP:
		m_tInfo.fCX = 692/4;
		m_tInfo.fCY = 138;
		break;
	case OBSTACLE_TRAP2:
		m_tInfo.fCX = 850/4;
		m_tInfo.fCY = 290;
		break;
	default:
		break;
	}
}

int CObstacle::Update()
{
	if (m_bIsDead)
		return DEAD_OBJ;
	CGameObject::UpdateRect();
	Move();
	CheckMove();
	IsOutofRange();


	return NO_EVENT;
}

void CObstacle::Render(HDC hDC)
{
	switch (m_ObsType)
	{
	case OBSTACLE_GIMLET:
		BMP->PopS_Obj(1, m_tRect.left, m_tRect.top);
		break;
	case OBSTACLE_GIMLET2:
			BMP->PopS_Obj(2, m_tRect.left, m_tRect.top);
		break;
	case OBSTACLE_GIMLETS:
		if (!m_IsActive)
		{
			BMP->PopS_Obj(10, m_tRect.left, m_tRect.top);
		}
		else
		 BMP->PopA_Once(9, m_tRect.left, m_tRect.top, this, 70);
		break;
	case OBSTACLE_GIMLETS2:
		BMP->PopA_Once(11, m_tRect.left, m_tRect.top, this, 150);
		break;
	case OBSTACLE_FORK:
		BMP->PopS_Obj(3, m_tRect.left, m_tRect.top);
		break;
	case OBSTACLE_FORK1:
		BMP->PopS_Obj(4, m_tRect.left, m_tRect.top);
		break;
	case OBSTACLE_FORK2:
		BMP->PopS_Obj(5, m_tRect.left, m_tRect.top);
		break;
	case OBSTACLE_FORK3:
		BMP->PopS_Obj(6, m_tRect.left, m_tRect.top);
		break;
	case OBSTACLE_FORK4:
		BMP->PopS_Obj(7, m_tRect.left, m_tRect.top);
		break;
	case OBSTACLE_LONGFORK:
		BMP->PopS_Obj(8, m_tRect.left, m_tRect.top);
		break;
		//스테이지2
	case OBSTACLE_PORTION:
		BMP->PopS_Obj(15, m_tRect.left, m_tRect.top);
		break;
	case OBSTACLE_PORTION2:
		BMP->PopS_Obj(16, m_tRect.left, m_tRect.top);
		break;
	case OBSTACLE_SKULL:
		BMP->PopS_Obj(17, m_tRect.left, m_tRect.top);
		break;
	case OBSTACLE_ONION:
		BMP->PopS_Obj(18, m_tRect.left, m_tRect.top);
		break;
	case OBSTACLE_FROG:
		BMP->PopS_Obj(19, m_tRect.left, m_tRect.top);
		break;
	case OBSTACLE_TRAP:
		if (!m_IsActive)
		{
			BMP->PopS_Obj(21, m_tRect.left, m_tRect.top);
		}
		else
			BMP->PopA_Once(20, m_tRect.left, m_tRect.top, this, 70);
		break;
	case OBSTACLE_TRAP2:
		if (!m_IsActive)
		{
			BMP->PopS_Obj(23, m_tRect.left, m_tRect.top);
		}
		else
			BMP->PopA_Once(22, m_tRect.left, m_tRect.top, this, 70);
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

void CObstacle::Move()
{
	m_tInfo.fX += CScrollMgr::m_fScrollX;
	
	
	if (m_ObsType == OBSTACLE_TYPE::OBSTACLE_FORK1&&m_IsFall)
	{
		if (m_tInfo.fY <= 40.0f)
		{
			m_tInfo.fY += CScrollMgr::m_fScrollY;
		}
	}
	
	if (m_ObsType == OBSTACLE_TYPE::OBSTACLE_FORK2&&m_IsFall)
	{
		if (m_tInfo.fY <= 300.0f)
		{
			m_tInfo.fY += CScrollMgr::m_fScrollY;
		}
	}
	if (m_ObsType == OBSTACLE_SKULL&&m_IsFall)
	{
		if (m_tInfo.fY <= 355.0f)
		{
			m_tInfo.fY += CScrollMgr::m_fScrollY;
		}
	}

	if ((m_ObsType == OBSTACLE_FROG||m_ObsType==OBSTACLE_ONION)&&m_IsFall)
	{
		if (m_tInfo.fY <= 70.0f)
		{
			m_tInfo.fY += CScrollMgr::m_fScrollY;
		}
	}
	
}

void CObstacle::IsOutofRange()
{
	if (-200 >= m_tRect.left|| WINCY + 200 <= m_tRect.bottom)
		m_bIsDead = true;
}

void CObstacle::SetType(OBSTACLE_TYPE obsType, OBSTACLE_MOVETYPE moveType)
{
	m_ObsType = obsType;
	m_MoveType = moveType;
	Initialize();
}

void CObstacle::CheckMove()
{
	CGameObject* pPlayer = CObjectMgr::GetInstance()->GetPlayer();
	switch (m_MoveType)
	{
	case STOP:
		break;
	case FALLING:
	case UPTODOWN:
	case ANIMATION:
		if (fabs(pPlayer->GetInfo().fX - m_tInfo.fX) <= 500.0f && !m_IsFall)
		{
			m_IsFall = true;
			m_IsActive = true;
		}
		break;
	default:
		break;
	}
}

void CObstacle::Release()
{
}
