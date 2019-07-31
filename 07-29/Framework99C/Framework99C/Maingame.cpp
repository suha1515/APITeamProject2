#include "stdafx.h"
#include "Maingame.h"
#include "Player.h"
#include "Monster.h"
#include "Mouse.h"
#include "BackGround.h"
#include "BitManager.h"
#include "GameObject.h"
#include "SpawnManager.h"
#include "Floor.h"
#include"Obstacle.h"
#include "Jelly.h"

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
	BackDC = CreateCompatibleDC(m_hDC);
	HBITMAP m_back = (HBITMAP)LoadImageW(hInst, L"texture//background.bmp", IMAGE_BITMAP,
		0, 0, LR_LOADFROMFILE);
	SelectObject(BackDC, m_back);
	BMP->Initialize();
	
	m_SpawnManager = new CSpawnManager;
	m_SpawnManager->Initialize();
	srand((unsigned)time(nullptr));

	CGameObject* pGameObject = nullptr;
	//m_pPlayer = new CPlayer;
	// BackGround
	pGameObject = CAbstractFactory<CBackGround>::CreateObject();
	pGameObject->Initialize();
	CObjectMgr::GetInstance()->AddObject(OBJECT_BACKGROUND, pGameObject);

	// Player
	pGameObject = CAbstractFactory<CPlayer>::CreateObject();
	pGameObject->SetPos(100, 350);
	CObjectMgr::GetInstance()->AddObject(OBJECT_PLAYER, pGameObject);	

	CStageManager::GetInstance()->Initialize();
	
	//6200
	//pGameObject = CAbstractFactory<CFloor>::CreateObject();
	//pGameObject->SetPos(900, 250);
	//dynamic_cast<CFloor*>(pGameObject)->SetType(STAGE2_HANG);
	//CObjectMgr::GetInstance()->AddObject(OBJECT_FLOOR, pGameObject);

	/*pGameObject = CAbstractFactory<CObstacle>::CreateObject();
	pGameObject->SetPos(800, 275);
	dynamic_cast<CObstacle*>(pGameObject)->SetType(OBSTACLE_TRAP2,ANIMATION);
	CObjectMgr::GetInstance()->AddObject(OBJECT_OBSTACLE, pGameObject);*/



	//pGameObject = CAbstractFactory<CJelly>::CreateObject();
	//pGameObject->SetPos(900, 370);
	//dynamic_cast<CJelly*>(pGameObject)->SetJellyType(BLUE_BEAN);
	//CObjectMgr::GetInstance()->AddObject(OBJECT_OBSTACLE, pGameObject);

	//floor
	/*pGameObject = CAbstractFactory<CFloor>::CreateObject();
	CObjectMgr::GetInstance()->AddObject(OBJECT_FLOOR, pGameObject);
	pGameObject->SetPos(62, 450);
*/
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
	m_SpawnManager->SpawnFloor();
	m_SpawnManager->SpawnObstacle();
	m_SpawnManager->SpawnJelly();
	m_SpawnManager->SpwanHangFloor();
	CStageManager::GetInstance()->StageProgress += (-1*CScrollMgr::m_fScrollX);
	cout << CStageManager::GetInstance()->StageProgress << endl;
	//m_SpawnManager->SpawnJelly();
	CKeyMgr::GetInstance()->Update();
	CObjectMgr::GetInstance()->Update();
}

void CMaingame::Render()
{
	//배경화면출력 하는곳

	// 단일 배경화면 출력
	//BMP->PopS_BG(1, 0, 0);

	// 배경 스크롤 (W = 가로, H = 세로)

	
	//키보드에 따라 배경 움직이기
	/*if (GetAsyncKeyState(VK_RIGHT))
		scr_x += 3;
	BMP->Manual_BackGround(1, scr_x+, scr_y);*/

	//모든 렌더는 BackDC에
	CObjectMgr::GetInstance()->Render(BackDC);


	if (GetAsyncKeyState('A'))
	{
		test += 1;;
	}

	

	//더블버퍼링
	
	BitBlt(m_hDC, 0, 0, WINCX, WINCY, BackDC, 0, 0, SRCCOPY);
}	

void CMaingame::Release()
{
	// GetDC함수로 할당받은 DC는 아래 함수로 해제해주어야 한다.
	ReleaseDC(g_hWnd, m_hDC);	

	CKeyMgr::GetInstance()->DestroyInstance();
	CObjectMgr::GetInstance()->DestroyInstance();
}

