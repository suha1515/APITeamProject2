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
	void SetType(FLOOR_TYPE type);
private:
	void IsOutofRange();
protected:
	virtual void Release();



	float		m_Speed;
	FLOOR_TYPE  m_FloorType;
};

