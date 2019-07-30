#pragma once
#include "GameObject.h"
class CPlayer :
	public CGameObject
{
public:
	CPlayer();
	virtual ~CPlayer();

public:
	// CGameObject��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render(HDC hDC) override;

private:
	virtual void Release() override;

private:
	CGameObject* CreateBullet();
	CGameObject* CreateBullet(BULLET_DIRECTION eDir);
	CGameObject* CreateShield();
	CGameObject* CreateGuideBullet();

private:
	void KeyInput();
	bool IsGround();
	void IsJump();

private:		
	float		m_fPosinX; // ������ ���� X
	float		m_fPosinY; // ������ ���� Y
	float		m_fPosinLength; // ���� ����

	bool		m_bIsJump;
	float		m_fGroundY;

	float		m_fJumpForce;	// ���� ��(v)
	float		m_fJumpAcc;		// ���� ���ӵ�(t)

	int			m_iJumpCount; //���� ���� Ƚ��

	DWORD TimeOld;
	DWORD TimeCur;
	vector<LINE_INFO> linevector;
};

