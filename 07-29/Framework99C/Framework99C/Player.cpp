#include "stdafx.h"
#include "Player.h"
#include "Bullet.h"
#include "Shield.h"
#include "GuideBullet.h"
#include "BackGround.h"
#include "BitManager.h"
CPlayer::CPlayer()
	: m_fPosinX(0.f), m_fPosinY(0.f), m_bIsJump(false), m_fGroundY(0.f),
	m_fJumpForce(0.f), m_fJumpAcc(0.f)
{
}


CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::Initialize()
{
	m_tInfo.fCX = 100.f;
	m_tInfo.fCY = 100.f;

	m_fSpeed = 5.f;
	m_fAngle = 90.f;
	m_fPosinLength = 100.f;

	m_fJumpForce = 20.f;
}

int CPlayer::Update()
{
	KeyInput();
	//IsJump();
	CGameObject::UpdateRect();
	return NO_EVENT;
}

void CPlayer::Render(HDC hDC)
{
	
//	Rectangle(hDC, 100, 100, 300, 300);

	BMP->PopA_Once(0,0,60, this, 150);
	HPEN hNewPen = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
	HPEN hOldPen = (HPEN)SelectObject(hDC, hNewPen);

	MoveToEx(hDC, m_tRect.left, m_tRect.top, nullptr);
	LineTo(hDC, m_tRect.right, m_tRect.top);
	LineTo(hDC, m_tRect.right, m_tRect.bottom);
	LineTo(hDC, m_tRect.left, m_tRect.bottom);
	LineTo(hDC, m_tRect.left, m_tRect.top);



	if (GetAsyncKeyState(VK_SPACE))
	{
		BMP->PopA_Player(1, 20, 287, this, 90); // 점프
	}
	else if(GetAsyncKeyState(VK_CONTROL))
	{
		BMP->PopA_Player(2, 20, 305, this, 200); // 슬라이드
	}
	else  
	{
		BMP->PopA_Player(0, 20, 287, this, 100); // 달리기
	}
	// BMP->PopA_Player(3, 20, 287, this, 100); // 충돌했을때


	// 체력바 테스트
	// m_Hp 수정하면 체력 다는 정도 조절 가능
	curtime = clock(); 
	if (curtime - oldtime > 100)
	{
		m_Hp += 2;
		oldtime = clock();
	}
	BMP->Manual_BackGround(4, 100, 21, 0, 0);
	BMP->Manual_BackGround(3, 134, 30, m_Hp, 0);

	
	



	DeleteObject(SelectObject(hDC, hOldPen));



	



}

void CPlayer::Release()
{
}

CGameObject* CPlayer::CreateBullet()
{
	return CAbstractFactory<CBullet>::CreateObject(m_fPosinX, m_fPosinY, m_fAngle);
}

CGameObject* CPlayer::CreateBullet(BULLET_DIRECTION eDir)
{
	CGameObject* pBullet = CAbstractFactory<CBullet>::CreateObject(m_tInfo.fX, m_tInfo.fY);
	dynamic_cast<CBullet*>(pBullet)->SetDirection(eDir);

	return pBullet;
}

CGameObject* CPlayer::CreateShield()
{
	return CAbstractFactory<CShield>::CreateObject();
}

CGameObject* CPlayer::CreateGuideBullet()
{
	return CAbstractFactory<CGuideBullet>::CreateObject(m_fPosinX, m_fPosinY);
}

void CPlayer::KeyInput()
{
	// 플레이어가 움직인만큼 스크롤도 움직인다.
	if (CKeyMgr::GetInstance()->KeyDown(KEY_LEFT))
	{
		m_tInfo.fX -= m_fSpeed;
		CScrollMgr::m_fScrollX += m_fSpeed;
	}
	if (CKeyMgr::GetInstance()->KeyDown(KEY_RIGHT))
	{
		m_tInfo.fX +=m_fSpeed;
		CScrollMgr::m_fScrollX -= m_fSpeed;
	}
	
}

bool CPlayer::IsGround()
{
	CGameObject* pBackGround = CObjectMgr::GetInstance()->GetBackGround();
	NULL_CHECK_RETURN(pBackGround, false);

	const list<LINE_INFO*>& LineLst = dynamic_cast<CBackGround*>(pBackGround)->GetLineLst();

	// 플레이어가 어떤 라인을 타야하는지 검사.
	LINE_INFO* pTarget = nullptr;

	for (auto& pLine : LineLst)
	{
		if (pLine->fStartX <= m_tInfo.fX && m_tInfo.fX <= pLine->fEndX)
		{
			pTarget = pLine;
			break;
		}
	}

	NULL_CHECK_RETURN(pTarget, false);

	// 두 점을 지나는 직선의 방정식
	// y = (y2 - y1) / (x2 - x1) * (x - x1) + y1
	float x1 = pTarget->fStartX;
	float y1 = pTarget->fStartY;
	float x2 = pTarget->fEndX;
	float y2 = pTarget->fEndY;

	m_fGroundY = (y2 - y1) / (x2 - x1) * (m_tInfo.fX - x1) + y1;
	return true;
}

void CPlayer::IsJump()
{
	bool bIsGround = IsGround();

	if (m_bIsJump)
	{
		// 수직 낙하 공식
		// y = 힘 * sin(90도) * 가속도 - 중력(9.8) * 가속도의 제곱 * 0.5
		m_tInfo.fY -= m_fJumpForce * m_fJumpAcc - GRAVITY * powf(m_fJumpAcc, 2.f) * 0.5f;
		m_fJumpAcc += 0.25f;

		
		if (bIsGround && m_tInfo.fY + m_tInfo.fCY * 0.5f > m_fGroundY)
		{
			m_tInfo.fY = m_fGroundY;
			m_tInfo.fY -= m_tInfo.fCY * 0.5f;

			m_bIsJump = false;
			m_fJumpAcc = 0.f;			
		}
	}
	else
	{
		m_tInfo.fY = m_fGroundY;
		m_tInfo.fY -= m_tInfo.fCY * 0.5f;
	}
}
