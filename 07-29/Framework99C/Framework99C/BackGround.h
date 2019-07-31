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
	// CGameObject을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render(HDC hDC) override;

	void SetAlphaBlend(int alphaValue=0);
private:
	virtual void Release() override;


private:
	list<LINE_INFO*>	m_LineLst;

	HDC AlphaDC;
	HBITMAP TempDC;
	HBITMAP OldTempDC;

	bool m_ReverseAlpha = false;

	Scene m_PrevScene;
	Scene m_CurScene;

	int alphaValue;
	float m_WaitTime = 0.0f;
};

