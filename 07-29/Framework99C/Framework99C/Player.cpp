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


	//�׽�Ʈ�Ӵϴ�
	linevector.push_back({ 600,400,900,400 });
	linevector.push_back({ 200,500,600,500 });
}

int CPlayer::Update()
{
	KeyInput();
	IsJump();

	if (m_tInfo.iHealth <= 0) //�÷��̾� �ǰ� 0�̸� ���
		m_bIsDead = true;

	if (m_bIsDead)
		return DEAD_OBJ;

	TimeCur = GetTickCount();
	if (TimeCur - TimeOld >= 1000) //�÷��̾� ü���� 1�ʿ� 1�� ���Դϴ�.
	{
		SetDamage(1);
		TimeOld = TimeCur;
	}
	return NO_EVENT;
}

void CPlayer::Render(HDC hDC)
{
	CGameObject::UpdateRect();

	//�÷��̾� ü�¹��Դϴ�.
	if (m_tInfo.iHealth >= 0)
	{
		Rectangle(hDC, 50,
			5,
			10 * m_tInfo.iHealth,
			50);
	}

	//�÷��̾� ��ġ�Դϴ�.
	Rectangle(hDC, m_tRect.left - CScrollMgr::m_fScrollX, 
		m_tRect.top, 
		m_tRect.right - CScrollMgr::m_fScrollX,
		m_tRect.bottom);	

	//�׽�Ʈ�Ӵϴ�
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
	// �÷��̾ �����θ�ŭ ��ũ�ѵ� �����δ�.
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
			--m_iJumpCount; //���� ���� ������ ���� ���� Ƚ�� ����
		}
	}
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
		if (m_iJumpCount >= 0) //���� Ƚ���� 0���� ���ų� ũ�ٸ� ���� ����
		{
			// ���� ���� ����
			// y = �� * sin(90��) * ���ӵ� - �߷�(9.8) * ���ӵ��� ���� * 0.5
			m_tInfo.fY -= m_fJumpForce * m_fJumpAcc - GRAVITY * powf(m_fJumpAcc, 2.f) * 0.5f;

			switch (m_iJumpCount) //���� ���� Ƚ���� 1�̰ų� 0�� ���
			{
			case 1:
				m_fJumpAcc += 0.15f;
				break;

			case 0:
				m_fJumpAcc += 0.08f;
				break;
			}

			if (bIsGround && m_tInfo.fY + m_tInfo.fCY * 0.5f > m_fGroundY) //���� ������
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
