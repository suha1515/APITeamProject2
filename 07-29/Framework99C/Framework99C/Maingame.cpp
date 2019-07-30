#include "stdafx.h"
#include "Maingame.h"
#include "Player.h"
#include "Monster.h"
#include "Mouse.h"
#include "BackGround.h"

#include "Floor.h"
#include "SpawnManager.h"
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
	// GetDC: 출력 DC 생성 함수.
	m_hDC = GetDC(g_hWnd);
	g_hDC = m_hDC;

	//------------더블 버퍼링---------------------
	//현재 클라이언트의 크기 구함
	RECT clientRect;
	GetClientRect(g_hWnd, &clientRect);

	BackDC = CreateCompatibleDC(m_hDC);

	//g_hBitmap = CreateCompatibleBitmap(m_hDC, clientRect.right, clientRect.bottom);
	//g_hOldBit = (HBITMAP)SelectObject(BackDC, g_hBitmap);
	////---------------------------------------------

	////이미지 로더 초기화
	//ImageManager::ROAD()->Init();

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

	//Floor
	pGameObject = CAbstractFactory<CFloor>::CreateObject();
	CObjectMgr::GetInstance()->AddObject(OBJECT_FLOOR, pGameObject);

	m_SpawnManager = new CSpawnManager;
	m_SpawnManager->Initialize();

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
}

void CMaingame::Update()
{
	CKeyMgr::GetInstance()->Update();
	CObjectMgr::GetInstance()->Update();
	m_SpawnManager->SpawnFloor();
}

void CMaingame::Render()
{
	Rectangle(BackDC, 0, 0, WINCX, WINCY);
	CObjectMgr::GetInstance()->Render(BackDC);
	BitBlt(g_hDC, 0, 0, WINCX, WINCY, BackDC, 0, 0, SRCCOPY);

	//배경화면출력 하는곳

	// 단일 배경화면 출력
	BMP->PopS_BG(1, 0, 0);

	// 배경 스크롤 (W = 가로, H = 세로)
	BMP->Auto_BackGround_W(1, 3);

	//키보드에 따라 배경 움직이기
	/*if (GetAsyncKeyState(VK_RIGHT))
		scr_x += 3;
	BMP->Manual_BackGround(1, scr_x+, scr_y);*/

	//모든 렌더는 BackDC에
	CObjectMgr::GetInstance()->Render(BackDC);
	m_pPlayer->Render(BackDC);





	//더블버퍼링
	BitBlt(m_hDC, 0, 0, WINCX, WINCY, BackDC, 0, 0, SRCCOPY);
}	

void CMaingame::Release()
{
	// GetDC함수로 할당받은 DC는 아래 함수로 해제해주어야 한다.
	ReleaseDC(g_hWnd, m_hDC);	
	
	// 더블버퍼링 해제
	SelectObject(BackDC, g_hOldBit);
	DeleteDC(BackDC);

	CKeyMgr::GetInstance()->DestroyInstance();
	CObjectMgr::GetInstance()->DestroyInstance();
}
