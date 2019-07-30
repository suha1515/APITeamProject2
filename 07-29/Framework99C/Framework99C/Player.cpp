#include "stdafx.h"
#include "Player.h"
#include "Bullet.h"
#include "Shield.h"
#include "GuideBullet.h"
#include "BackGround.h"

CPlayer::CPlayer()
	: m_fPosinX(0.f), m_fPosinY(0.f), m_bIsJump(false), m_fGroundY(0.f),
	m_fJumpForce(0.f), m_fJumpAcc(0.f), m_iJumpCount(0)
{
}


CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::Initialize()
{
	m_tInfo.fX = 400.f;
	m_tInfo.fY = 400.f;
	m_tInfo.fCX = 100.f;
	m_tInfo.fCY = 100.f;
	m_tInfo.iHealth = 100;
	m_fSpeed = 10.f;
	m_fAngle = 90.f;
	m_fPosinLength = 100.f;

	m_tInfo.bGraceChk = false;

	TimeOld = GetTickCount();
	TimeCur = GetTickCount();

	m_fJumpForce = 20.f;

	m_iJumpCount = 2;


	//테스트임니다
	linevector.push_back({ 600,400,900,400 });
	linevector.push_back({ 200,500,600,500 });
}

int CPlayer::Update()
{
	KeyInput();
	IsJump();

	if (m_tInfo.iHealth <= 0) //플레이어 피가 0이면 사망
		m_bIsDead = true;

	if (m_bIsDead)
		return DEAD_OBJ;

	TimeCur = GetTickCount();
	if (TimeCur - TimeOld >= 1000) //플레이어 체력이 1초에 1씩 깎입니다.
	{
		SetDamage(1);
		TimeOld = TimeCur;
	}
	return NO_EVENT;
}

void CPlayer::Render(HDC hDC)
{
	CGameObject::UpdateRect();

	//플레이어 체력바입니다.
	if (m_tInfo.iHealth >= 0)
	{
		Rectangle(hDC, 50,
			5,
			10 * m_tInfo.iHealth,
			50);
	}

	//플레이어 위치입니다.
	Rectangle(hDC, m_tRect.left - CScrollMgr::m_fScrollX, 
		m_tRect.top, 
		m_tRect.right - CScrollMgr::m_fScrollX,
		m_tRect.bottom);	

	//테스트임니다
	for (auto i : linevector)
	{
		MoveToEx(hDC, i.fStartX, i.fStartY, nullptr);
		LineTo(hDC, i.fEndX, i.fEndY);
	}

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
	if (CKeyMgr::GetInstance()->KeyPressing(KEY_LEFT))
	{
		m_tInfo.fX -= m_fSpeed;
		CScrollMgr::m_fScrollX -= m_fSpeed;
	}
	if (CKeyMgr::GetInstance()->KeyPressing(KEY_RIGHT))
	{
		m_tInfo.fX += m_fSpeed;
		CScrollMgr::m_fScrollX += m_fSpeed;
	}

	if (m_iJumpCount > 0)
	{
		if (CKeyMgr::GetInstance()->KeyDown(KEY_SPACE))
		{
 			m_bIsJump = true;
			--m_iJumpCount; //점프 누를 때마다 점프 가능 횟수 감소
		}
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
		if (m_iJumpCount >= 0) //점프 횟수가 0보다 같거나 크다면 점프 가능
		{
			// 수직 낙하 공식
			// y = 힘 * sin(90도) * 가속도 - 중력(9.8) * 가속도의 제곱 * 0.5
			m_tInfo.fY -= m_fJumpForce * m_fJumpAcc - GRAVITY * powf(m_fJumpAcc, 2.f) * 0.5f;

			switch (m_iJumpCount) //점프 가능 횟수가 1이거나 0일 경우
			{
			case 1:
				m_fJumpAcc += 0.15f;
				break;

			case 0:
				m_fJumpAcc += 0.08f;
				break;
			}

			if (bIsGround && m_tInfo.fY + m_tInfo.fCY * 0.5f > m_fGroundY) //땅에 닿으면
			{
				m_tInfo.fY = m_fGroundY;
				m_tInfo.fY -= m_tInfo.fCY * 0.5f;

				m_bIsJump = false;
				m_iJumpCount = 2;
				m_fJumpAcc = 0.f;
			}
		}
	}
	else
	{
		m_tInfo.fY = m_fGroundY;
		m_tInfo.fY -= m_tInfo.fCY * 0.5f;
		m_iJumpCount = 2;
	}
}
