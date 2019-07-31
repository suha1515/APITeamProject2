#pragma once
#include "GameObject.h"
class CPlayer :
	public CGameObject
{
public:
	CPlayer();
	virtual ~CPlayer();

public:
	// CGameObject을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render(HDC hDC) override;

	void SetShelfChk(bool bShelf);
	bool bIsJumpChk();
	float IsJump();
	void IsDown();
	void SetDownChk(bool bDown);

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

private:		
	float		m_fPosinX; // 포신의 끝점 X
	float		m_fPosinY; // 포신의 끝점 Y
	float		m_fPosinLength; // 포신 길이

	bool		m_bIsJump;
	float		m_fGroundY;

	float		m_fJumpForce;	// 점프 힘(v)
	float		m_fJumpAcc;		// 점프 가속도(t)

	clock_t curtime;
	clock_t oldtime;
	
	int			m_iJumpCount; //점프 가능 횟수

	DWORD TimeOld;
	DWORD TimeCur;
	
	bool bShelfDownChk;
	bool bShelfChk;
};

