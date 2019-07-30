#pragma once
#include "GameObject.h"
class CBackGround :
	public CGameObject
{
public:
	CBackGround();
	virtual ~CBackGround();

public:
	const list<LINE_INFO*>& GetLineLst() const;

public:
	// CGameObject��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render(HDC hDC) override;

private:
	virtual void Release() override;

	void ScrollBackGround();

private:
	list<LINE_INFO*>	m_LineLst;
	POSf				m_FirBackGScroll;
	POSf				m_SecBackGScroll;

	POSf				m_FirFloorScroll;
	POSf				m_SecFloorScroll;

	float				m_BackScrollSpeed;
	float				m_FloorScrollSpeed;
};

