#include "stdafx.h"
#include "Monster.h"


CMonster::CMonster()
	: m_pTarget(nullptr)
{
}


CMonster::~CMonster()
{
	Release();
}

void CMonster::Initialize()
{
	m_tInfo.fX = 400.f;
	m_tInfo.fY = 200.f;
	m_tInfo.fCX = 100.f;
	m_tInfo.fCY = 100.f;

	m_tInfo.iDMG = 1;
	m_fSpeed = 5.f;
}

int CMonster::Update()
{
	if (m_bIsDead)
		return DEAD_OBJ;

	//IsMoving();
	//IsOutRange();

	return NO_EVENT;
}

void CMonster::Render(HDC hDC)
{
	CGameObject::UpdateRect();
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CMonster::Release()
{
}

void CMonster::IsMoving()
{
	m_pTarget = CObjectMgr::GetInstance()->GetMouse();
	NULL_CHECK(m_pTarget);

	// ���� ���� ����!!!
	// ������ - ����� = ��������� �������� ���ϴ� ����.
	float w = m_pTarget->GetInfo().fX - m_tInfo.fX;
	float h = m_pTarget->GetInfo().fY - m_tInfo.fY;
	float d = sqrtf(w * w + h * h);

	// cos�� = ��/��
	// acosf�� ��ȯ�ϴ� ���� ������ 0 ~ 180���̴�.
	m_fAngle = acosf(w / d); // cos�� ���ڷ� ��� ���ΰ��� ���� ������ ��ȯ�Ѵ�.

	// Ư�� �������� ������ ���������־�� �Ѵ�.
	if (m_tInfo.fY < m_pTarget->GetInfo().fY)
		m_fAngle *= -1.f;

	// ���� ���� �������� �����δ�.
	m_tInfo.fX += cosf(m_fAngle) * m_fSpeed;
	m_tInfo.fY -= sinf(m_fAngle) * m_fSpeed;
}

void CMonster::IsOutRange()
{
	CGameObject::UpdateRect();

	if (0 >= m_tRect.left || WINCX <= m_tRect.right)
		m_fSpeed *= -1.f;
}
