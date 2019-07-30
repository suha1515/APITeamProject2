#include "stdafx.h"
#include "BackGround.h"


CBackGround::CBackGround()
{
}


CBackGround::~CBackGround()
{
	Release();
}

const list<LINE_INFO*>& CBackGround::GetLineLst() const
{
	// TODO: 여기에 반환 구문을 삽입합니다.
	return m_LineLst;
}

void CBackGround::Initialize()
{
	//스테이지_첫번째 배경 벨트
	m_FirBackGScroll.x = 0;
	m_FirBackGScroll.y = 0;

	//스테이지_두번째 배경 벨트
	m_SecBackGScroll.x = 1600;
	m_SecBackGScroll.y = 0;

	
	//스테이지_첫번째 바닥 벨트
	m_FirFloorScroll.x = 0;
	m_FirFloorScroll.y = WINCY - 120;

	//스테이지_두번째 바닥 벨트
	m_SecFloorScroll.x = 1488.f;
	m_SecFloorScroll.y = WINCY - 120;

	//스크롤 스피드
	m_BackScrollSpeed = 350.f;
	m_FloorScrollSpeed = 500.f;
}

int CBackGround::Update()
{

	//POINT pt = {};
	//GetCursorPos(&pt);
	//ScreenToClient(g_hWnd, &pt);

	//// ScreenToClient로 변환된 마우스좌표는 항상 화면 상의 좌표이다.
	//// 화면 좌표 -> 게임 월드 좌표 변환.
	//pt.x += (LONG)CScrollMgr::m_fScrollX;

	//if (CKeyMgr::GetInstance()->KeyDown(KEY_LBUTTON))
	//{
	//	LINE_INFO* pLine = new LINE_INFO;
	//	pLine->fStartX = (float)pt.x;
	//	pLine->fStartY = (float)pt.y;
	//	pLine->fEndX = (float)pt.x;
	//	pLine->fEndY = (float)pt.y;

	//	m_LineLst.push_back(pLine);
	//}

	//if (CKeyMgr::GetInstance()->KeyUp(KEY_LBUTTON))
	//{
	//	m_LineLst.back()->fEndX = (float)pt.x;
	//	m_LineLst.back()->fEndY = (float)pt.y;
	//}



	return NO_EVENT;
}

void CBackGround::Render(HDC hDC)
{
	//// auto: LINE_INFO*
	//for (auto& pLine : m_LineLst)
	//{
	//	// 게임 월드 좌표 -> 화면 좌표로 변환.
	//	MoveToEx(hDC, int(pLine->fStartX - CScrollMgr::m_fScrollX), (int)pLine->fStartY, nullptr);
	//	LineTo(hDC, int(pLine->fEndX - CScrollMgr::m_fScrollX), (int)pLine->fEndY);
	//}

	
	//Rectangle(hDC, m_FirstScroll.x, m_FirstScroll.y, 350, 450);
	//Rectangle(hDC, m_SecondScroll.x, m_SecondScroll.y, 350, 450);
	//배경을 업데이트된 스크롤 위치에따라 렌더한다.
	ScrollBackGround();
	ImageManager::ROAD()->PopS_Background(0, m_FirBackGScroll.x, m_FirBackGScroll.y);
	ImageManager::ROAD()->PopS_Background(0, m_SecBackGScroll.x, m_SecBackGScroll.y);
	
	//바닥을 업데이트된 스크롤 위치에 따라 렌더한다.
	ImageManager::ROAD()->PopS_Background(2, m_FirFloorScroll.x, m_FirFloorScroll.y);
	ImageManager::ROAD()->PopS_Background(2, m_SecFloorScroll.x, m_SecFloorScroll.y);
}

void CBackGround::Release()
{
	/*for_each(m_LineLst.begin(), m_LineLst.end(), SafeDelete<LINE_INFO*>);
	m_LineLst.clear();*/
}

void CBackGround::ScrollBackGround()
{
	
	//각 백그라운드가 화면상에서 완전히 사라졌을경우
	if (m_FirBackGScroll.x <= -1600)
	{
		m_FirBackGScroll.x = m_SecBackGScroll.x+1600;
	}
		
		
	if (m_SecBackGScroll.x <= -1600)
	{
		m_SecBackGScroll.x = m_FirBackGScroll.x +1600;
	}
		
	//위치를 다시 오른쪽으로 옮긴다.

	//각 바닥이 화면상에 완전히 사라졌을경우
	if (m_FirFloorScroll.x <= -1600)
		m_FirFloorScroll.x  = m_SecFloorScroll.x + 1600;
	if (m_SecFloorScroll.x <= -1600)
		m_SecFloorScroll.x = m_FirFloorScroll.x  + 1600;

	
	m_FirBackGScroll.x += CScrollMgr::m_fScrollX*0.5f;//m_BackScrollSpeed*DELTA_TIME;
	m_SecBackGScroll.x += CScrollMgr::m_fScrollX*0.5f;//m_BackScrollSpeed*DELTA_TIME;


	m_FirFloorScroll.x += CScrollMgr::m_fScrollX;//m_FloorScrollSpeed*DELTA_TIME;
	m_SecFloorScroll.x += CScrollMgr::m_fScrollX;//m_FloorScrollSpeed*DELTA_TIME;


}	
