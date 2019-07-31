#pragma once
#include "GameObject.h"
class CJelly :
	public CGameObject
{
public:
	CJelly();
	~CJelly();
public:
	virtual void Initialize();
	virtual int Update();
	virtual void Render(HDC hDC);

protected:
	virtual void Release();

public:
	void Move();
	void SetJellyType(JELLY_TYPE jellyType);

private:
	void IsOutofRange();

private:
	JELLY_TYPE		m_JellyType;
};

