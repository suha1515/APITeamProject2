#pragma once
#include "GameObject.h"
class CJelly :
	public CGameObject
{
public:
	CJelly();
	~CJelly();
public:
public:
	virtual void Initialize();
	virtual int Update();
	virtual void Render(HDC hDC);

protected:
	virtual void Release();
};

