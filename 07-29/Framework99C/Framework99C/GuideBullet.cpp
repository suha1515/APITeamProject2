#include "stdafx.h"
#include "GuideBullet.h"


CGuideBullet::CGuideBullet()
	: m_pTarget(nullptr)
{
}


CGuideBullet::~CGuideBullet()
{
	Release();
}

void CGuideBullet::Initialize()
{
	m_tInfo.fCX = 20.f;
	m_tInfo.fCY = 20.f;
	m_fSpeed = 5.f;
}

int CGuideBullet::Update()
{
	if (m_bIsDead)
		return DEAD_OBJ;

	IsMoving();

	return NO_EVENT;
}

void CGuideBullet::Render(HDC hDC)
{
	CGameObject::UpdateRect();
	Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CGuideBullet::Release()
{
}

void CGuideBullet::IsMoving()
{
	m_pTarget = CObjectMgr::GetInstance()->GetNearTarget(this, OBJECT_MONSTER);

	if (nullptr == m_pTarget)
	{
		m_bIsDead = true;
		return;
	}

	// 뺄셈 순서 주의!!!
	// 도착지 - 출발지 = 출발지에서 도착지로 향하는 방향.
	float w = m_pTarget->GetInfo().fX - m_tInfo.fX;
	float h = m_pTarget->GetInfo().fY - m_tInfo.fY;
	float d = sqrtf(w * w + h * h);

	// cos비 = 밑/빗
	// acosf이 반환하는 각도 범위는 0 ~ 180도이다.
	m_fAngle = acosf(w / d); // cos비를 인자로 삼아 끼인각을 라디안 단위로 반환한다.

	// 특정 구간에서 각도를 반전시켜주어야 한다.
	if (m_tInfo.fY < m_pTarget->GetInfo().fY)
		m_fAngle *= -1.f;

	// 구한 각도 방향으로 움직인다.
	m_tInfo.fX += cosf(m_fAngle) * m_fSpeed;
	m_tInfo.fY -= sinf(m_fAngle) * m_fSpeed;
}
