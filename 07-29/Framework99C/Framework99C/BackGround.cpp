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
	// TODO: ���⿡ ��ȯ ������ �����մϴ�.
	return m_LineLst;
}

void CBackGround::Initialize()
{
	//��������_ù��° ��� ��Ʈ
	m_FirBackGScroll.x = 0;
	m_FirBackGScroll.y = 0;

	//��������_�ι�° ��� ��Ʈ
	m_SecBackGScroll.x = 1600;
	m_SecBackGScroll.y = 0;

	
	//��������_ù��° �ٴ� ��Ʈ
	m_FirFloorScroll.x = 0;
	m_FirFloorScroll.y = WINCY - 120;

	//��������_�ι�° �ٴ� ��Ʈ
	m_SecFloorScroll.x = 1488.f;
	m_SecFloorScroll.y = WINCY - 120;

	//��ũ�� ���ǵ�
	m_BackScrollSpeed = 350.f;
	m_FloorScrollSpeed = 500.f;
}

int CBackGround::Update()
{

	//POINT pt = {};
	//GetCursorPos(&pt);
	//ScreenToClient(g_hWnd, &pt);

	//// ScreenToClient�� ��ȯ�� ���콺��ǥ�� �׻� ȭ�� ���� ��ǥ�̴�.
	//// ȭ�� ��ǥ -> ���� ���� ��ǥ ��ȯ.
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
	//	// ���� ���� ��ǥ -> ȭ�� ��ǥ�� ��ȯ.
	//	MoveToEx(hDC, int(pLine->fStartX - CScrollMgr::m_fScrollX), (int)pLine->fStartY, nullptr);
	//	LineTo(hDC, int(pLine->fEndX - CScrollMgr::m_fScrollX), (int)pLine->fEndY);
	//}

	
	//Rectangle(hDC, m_FirstScroll.x, m_FirstScroll.y, 350, 450);
	//Rectangle(hDC, m_SecondScroll.x, m_SecondScroll.y, 350, 450);
	//����� ������Ʈ�� ��ũ�� ��ġ������ �����Ѵ�.
	ScrollBackGround();
	ImageManager::ROAD()->PopS_Background(0, m_FirBackGScroll.x, m_FirBackGScroll.y);
	ImageManager::ROAD()->PopS_Background(0, m_SecBackGScroll.x, m_SecBackGScroll.y);
	
	//�ٴ��� ������Ʈ�� ��ũ�� ��ġ�� ���� �����Ѵ�.
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
	
	//�� ��׶��尡 ȭ��󿡼� ������ ����������
	if (m_FirBackGScroll.x <= -1600)
	{
		m_FirBackGScroll.x = m_SecBackGScroll.x+1600;
	}
		
		
	if (m_SecBackGScroll.x <= -1600)
	{
		m_SecBackGScroll.x = m_FirBackGScroll.x +1600;
	}
		
	//��ġ�� �ٽ� ���������� �ű��.

	//�� �ٴ��� ȭ��� ������ ����������
	if (m_FirFloorScroll.x <= -1600)
		m_FirFloorScroll.x  = m_SecFloorScroll.x + 1600;
	if (m_SecFloorScroll.x <= -1600)
		m_SecFloorScroll.x = m_FirFloorScroll.x  + 1600;

	
	m_FirBackGScroll.x += CScrollMgr::m_fScrollX*0.5f;//m_BackScrollSpeed*DELTA_TIME;
	m_SecBackGScroll.x += CScrollMgr::m_fScrollX*0.5f;//m_BackScrollSpeed*DELTA_TIME;


	m_FirFloorScroll.x += CScrollMgr::m_fScrollX;//m_FloorScrollSpeed*DELTA_TIME;
	m_SecFloorScroll.x += CScrollMgr::m_fScrollX;//m_FloorScrollSpeed*DELTA_TIME;


}	
