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
public:
	void Move();
	void SetItemType(ITEM_TYPE itemType);
private:
	void IsOutofRange();
private:
	ITEM_TYPE	m_ItemType;


};

