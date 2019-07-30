#pragma once
#include "GameObject.h"
class CItem :
	public CGameObject
{
public:
	CItem();
	~CItem();
public:
	virtual void Initialize();
	virtual int Update();
	virtual void Render(HDC hDC);

protected:
	virtual void Release();

private:
	ITEM_TYPE	m_ItemType;
	JELLY_TYPE	m_JellyType;

};

