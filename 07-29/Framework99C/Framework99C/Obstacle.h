#pragma once
#include "GameObject.h"
class CObstacle :
	public CGameObject
{
public:
	CObstacle();
	~CObstacle();

public:
	virtual void Initialize();
	virtual int Update() ;
	virtual void Render(HDC hDC) ;

public:
	void Move();
	void IsOutofRange();
	void SetType(OBSTACLE_TYPE obsType, OBSTACLE_MOVETYPE moveType);
public:
	void CheckMove();
protected:
	virtual void Release() ;

private:
	OBSTACLE_TYPE		m_ObsType;
	OBSTACLE_MOVETYPE	m_MoveType;

	bool				m_IsFall;
	bool				m_IsActive;

};

