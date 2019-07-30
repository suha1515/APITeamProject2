#pragma once
#include "GameObject.h"
class CFloor :
	public CGameObject
{
public:
	CFloor();
	~CFloor();

public:
	virtual void Initialize();
	virtual int Update();
	virtual void Render(HDC hDC);

public:
	void Move();

protected:
	virtual void Release();

	float		m_Speed;
};

