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
	m_tInfo.fX = 400.f;
	m_tInfo.fY = 400.f;
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
	IsJump();

	return NO_EVENT;
}

void CPlayer::Render(HDC hDC)
{
	CGameObject::UpdateRect();
	/*Rectangle(hDC, m_tRect.left - CScrollMgr::m_fScrollX,
		m_tRect.top,
		m_tRect.right - CScrollMgr::m_fScrollX,
		m_tRect.bottom);
*/
	BMP->PopA_BG(2, 0,60, this, 70);

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
	// �÷��̾ �����θ�ŭ ��ũ�ѵ� �����δ�.
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
	if (CKeyMgr::GetInstance()->KeyDown(KEY_SPACE))
		m_bIsJump = true;
}

bool CPlayer::IsGround()
{
	CGameObject* pBackGround = CObjectMgr::GetInstance()->GetBackGround();
	NULL_CHECK_RETURN(pBackGround, false);

	const list<LINE_INFO*>& LineLst = dynamic_cast<CBackGround*>(pBackGround)->GetLineLst();

	// �÷��̾ � ������ Ÿ���ϴ��� �˻�.
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

	// �� ���� ������ ������ ������
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
		// ���� ���� ����
		// y = �� * sin(90��) * ���ӵ� - �߷�(9.8) * ���ӵ��� ���� * 0.5
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
