#include "stdafx.h"
#include "Maingame.h"
#include "Player.h"
#include "Monster.h"
#include "Mouse.h"
#include "BackGround.h"

CMaingame::CMaingame()	
{
	
}

CMaingame::~CMaingame()
{
	Release();
}

void CMaingame::Initialize()
{
	// GetDC: ��� DC ���� �Լ�.
	m_hDC = GetDC(g_hWnd);

	srand((unsigned)time(nullptr));

	CGameObject* pGameObject = nullptr;

	// BackGround
	pGameObject = CAbstractFactory<CBackGround>::CreateObject();
	CObjectMgr::GetInstance()->AddObject(OBJECT_BACKGROUND, pGameObject);

	// Player
	pGameObject = CAbstractFactory<CPlayer>::CreateObject();
	CObjectMgr::GetInstance()->AddObject(OBJECT_PLAYER, pGameObject);	

	////// Monster �׽�Ʈ ���� ������Ҿ��
	pGameObject = CAbstractFactory<CMonster>::CreateObject();
	CObjectMgr::GetInstance()->AddObject(OBJECT_MONSTER, pGameObject);

	// Mouse
	//pGameObject = CAbstractFactory<CMouse>::CreateObject();
	//CObjectMgr::GetInstance()->AddObject(OBJECT_MOUSE, pGameObject);	
}

void CMaingame::Update()
{
	CKeyMgr::GetInstance()->Update();
	CObjectMgr::GetInstance()->Update();
}

void CMaingame::Render()
{
	Rectangle(m_hDC, 0, 0, WINCX, WINCY);
	CObjectMgr::GetInstance()->Render(m_hDC);
}	

void CMaingame::Release()
{
	// GetDC�Լ��� �Ҵ���� DC�� �Ʒ� �Լ��� �������־�� �Ѵ�.
	ReleaseDC(g_hWnd, m_hDC);	

	CKeyMgr::GetInstance()->DestroyInstance();
	CObjectMgr::GetInstance()->DestroyInstance();
}
