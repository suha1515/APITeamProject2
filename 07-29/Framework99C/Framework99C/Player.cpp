#include "stdafx.h"
#include "Player.h"
#include "Bullet.h"
#include "Shield.h"
#include "GuideBullet.h"
#include "BackGround.h"
#include "BitManager.h"
CPlayer::CPlayer()
	: m_fPosinX(0.f), m_fPosinY(0.f), m_bIsJump(false), m_fGroundY(0.f),
	m_fJumpForce(0.f), m_fJumpAcc(0.f), m_iJumpCount(0), bShelfChk(false), bShelfDownChk(false)
{
}


CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::Initialize()
{
	m_tInfo.fX = 100.f;
	m_tInfo.fY = 360.f;
	m_tInfo.fCX = 70.f;
	m_tInfo.fCY = 100.f;
	m_tInfo.iHealth = 9999; //�÷��̾� ü��!!! 0�̸� �÷��̾ �״°ɷ� üũ�� ���α׷��� �ٿ�ż� ü���� ���� �÷Ƚ��ϴ�.

	m_fSpeed = 5.f;
	m_fAngle = 90.f;
	m_fPosinLength = 100.f;

	m_tInfo.bGraceChk = false;
	bShelfChk = false;

	TimeOld = GetTickCount();
	TimeCur = GetTickCount();

	m_fJumpForce = 13.0f;

	m_iJumpCount = 2;
}

int CPlayer::Update()
{
	KeyInput();
	IsJump();
	IsDown();

	if (m_tInfo.iHealth <= 0) //�÷��̾� �ǰ� 0�̸� ���
		m_bIsDead = true;

	if (m_bIsDead)
		return DEAD_OBJ;

	//���÷��̾� ü�� �ٴ� �κ��Դϴ�!!!!!!��
	TimeCur = GetTickCount();
	if (TimeCur - TimeOld >= 1000) //�÷��̾� ü���� 1�ʿ� 1�� ���Դϴ�.
	{
		SetDamage(1);
		TimeOld = TimeCur;
	}

	//�ܼ�â�� �÷��̾� ü�� Ȯ��
	//cout << m_tInfo.iHealth << endl;
	//system("cls");
	return NO_EVENT;
}

void CPlayer::Render(HDC hDC)
{
	CGameObject::UpdateRect();

	//BMP->PopA_Once(0,0,60, this, 150);
	



	

	if (CKeyMgr::GetInstance()->KeyPressing(KEY_SPACE))
	{
		BMP->PopA_Player(1, m_tRect.left + 5, m_tRect.top - 23, this, 90);
		m_tInfo.fCY = 100.f;
	}
	else if(CKeyMgr::GetInstance()->KeyPressing(KEY_CTRL))
	{
		BMP->PopA_Player(2, m_tRect.left- 60, m_tRect.top - 30, this, 200);
		m_tInfo.fCY = 50;
	}
	else  //IDLE
	{
		BMP->PopA_Player(0, m_tRect.left - 30, m_tRect.top-23, this, 100);
		m_tInfo.fCY = 100.f;
	}

	HPEN hNewPen = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
	HPEN hOldPen = (HPEN)SelectObject(hDC, hNewPen);

	
	MoveToEx(hDC, m_tRect.left, m_tRect.top, nullptr);
	LineTo(hDC, m_tRect.right, m_tRect.top);
	LineTo(hDC, m_tRect.right, m_tRect.bottom);
	LineTo(hDC, m_tRect.left, m_tRect.bottom);
	LineTo(hDC, m_tRect.left, m_tRect.top);
	DeleteObject(SelectObject(hDC, hOldPen));

	//BMP->PopA_Once(1, m_tRect.left + 5, m_tRect.top - 23, this, 90);
}

void CPlayer::SetShelfChk(bool bShelf)
{
	bShelfChk = bShelf;
}

bool CPlayer::bIsJumpChk()
{
	return m_bIsJump;
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
	
	if (m_iJumpCount > 0)
	{
		if (CKeyMgr::GetInstance()->KeyDown(KEY_SPACE))
		{
			m_bIsJump = true;
			--m_iJumpCount; //���� ���� ������ ���� ���� Ƚ�� ����
			m_fJumpAcc = 0.f; //���ӵ� �ʱ�ȭ!
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

float CPlayer::IsJump()
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
				m_fJumpAcc += 0.08f;
				break;

			case 0:
				m_fJumpAcc += 0.08f;
				break;

			default:
				m_fJumpAcc = 0.f;
				break;
			}

			if (m_tInfo.fY + (m_tInfo.fCY * 0.5f) > GROUND) //���� ������
			{
				m_tInfo.fY = 360;

				m_bIsJump = false;
				m_iJumpCount = 2;
				m_fJumpAcc = 0.f;
			}
			return m_tInfo.fY;
		}
	}
	else
	{
		m_tInfo.fY = 360;
		m_iJumpCount = 2;
	}
}

void CPlayer::IsDown()
{
	if (bShelfDownChk)
	{
		if (m_tInfo.fY > GROUND)
		{
			m_tInfo.fY += m_fJumpForce * m_fJumpAcc - GRAVITY * powf(m_fJumpAcc, 2.f) * 0.5f;
			m_fJumpAcc += 0.08f;
		}
	}
}

void CPlayer::SetDownChk(bool bDown)
{
	bShelfDownChk = bDown;
}
