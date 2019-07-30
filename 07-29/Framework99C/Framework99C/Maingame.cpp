#include "stdafx.h"
#include "Maingame.h"
#include "Player.h"
#include "Monster.h"
#include "Mouse.h"
#include "BackGround.h"
#include "BitManager.h"
#include "GameObject.h"

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
	BackDC = CreateCompatibleDC(m_hDC);
	HBITMAP m_back = (HBITMAP)LoadImageW(hInst, L"texture//background.bmp", IMAGE_BITMAP,
		0, 0, LR_LOADFROMFILE);
	SelectObject(BackDC, m_back);
	BMP->Initialize();
	


	srand((unsigned)time(nullptr));

	CGameObject* pGameObject = nullptr;
	m_pPlayer = new CPlayer;
	// BackGround
	pGameObject = CAbstractFactory<CBackGround>::CreateObject();
	CObjectMgr::GetInstance()->AddObject(OBJECT_BACKGROUND, pGameObject);

	// Player
	pGameObject = CAbstractFactory<CPlayer>::CreateObject();
	CObjectMgr::GetInstance()->AddObject(OBJECT_PLAYER, pGameObject);	

	////// Monster
	//for (int i = 0; i < 5; ++i)
	//{
	//	float x = float(rand() % (WINCX - 200)) + 100.f;
	//	float y = float(rand() % (WINCY - 200)) + 100.f;

	//	pGameObject = CAbstractFactory<CMonster>::CreateObject(x, y);
	//	CObjectMgr::GetInstance()->AddObject(OBJECT_MONSTER, pGameObject);	//	
	//}

	// Mouse
	//pGameObject = CAbstractFactory<CMouse>::CreateObject();
	//CObjectMgr::GetInstance()->AddObject(OBJECT_MOUSE, pGameObject);	
	/*m_hDC = GetDC(g_hWnd);
	BackDC = CreateCompatibleDC(m_hDC);
	m_back = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP1));
	SelectObject(BackDC, m_back);
	ImageManager::ROAD()->Init();
	ImageManager::ROAD()->PopM_Background(0, 0, 0,0);*/

}

void CMaingame::Update()
{
	CKeyMgr::GetInstance()->Update();
	CObjectMgr::GetInstance()->Update();
}

void CMaingame::Render()
{
	//���ȭ����� �ϴ°�

	// ���� ���ȭ�� ���
	BMP->PopS_BG(1, 0, 0);

	// ��� ��ũ�� (W = ����, H = ����)
	BMP->Auto_BackGround_W(1, 3);


	//Ű���忡 ���� ��� �����̱�
	/*if (GetAsyncKeyState(VK_RIGHT))
		scr_x += 3;
	BMP->Manual_BackGround(1, scr_x+, scr_y);*/

	//��� ������ BackDC��
	CObjectMgr::GetInstance()->Render(BackDC);
	m_pPlayer->Render(BackDC);





	//������۸�
	BitBlt(m_hDC, 0, 0, WINCX, WINCY, BackDC, 0, 0, SRCCOPY);

}	

void CMaingame::Release()
{
	// GetDC�Լ��� �Ҵ���� DC�� �Ʒ� �Լ��� �������־�� �Ѵ�.
	ReleaseDC(g_hWnd, m_hDC);	

	CKeyMgr::GetInstance()->DestroyInstance();
	CObjectMgr::GetInstance()->DestroyInstance();
}
