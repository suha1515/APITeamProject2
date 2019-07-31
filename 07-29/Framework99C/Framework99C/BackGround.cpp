#include "stdafx.h"
#include "BackGround.h"


CBackGround::CBackGround()
{
	alphaValue = 0;
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

}

int CBackGround::Update()
{
	//12000 진행시 다음 씬으로 진행
	if (CStageManager::GetInstance()->CurrentScene == STAGE1)
	{
		if (CStageManager::GetInstance()->StageProgress >= 12000)
		{
			CStageManager::GetInstance()->IsSceneChange = true;
		}
	}
	

	return NO_EVENT;
}

void CBackGround::Render(HDC hDC)
{
	if (CStageManager::GetInstance()->CurrentScene == STAGE1)
	{
		BMP->Auto_BackGround_W(1, 1);
		BMP->Auto_BackGround_W(0, 2);
		
	}
	else if (CStageManager::GetInstance()->CurrentScene == STAGE2)
	{
		BMP->Auto_BackGround_W(2, 1);
		BMP->Auto_BackGround_W(3, 2);
	}
	
	
	if (CStageManager::GetInstance()->IsSceneChange)
	{
		if (!m_ReverseAlpha)
		{
		if (alphaValue == 255)
		 {
			CStageManager::GetInstance()->CurrentScene = STAGE2;
			if (m_WaitTime >= 3.0f)
			{
				m_ReverseAlpha = true;
				m_WaitTime -= m_WaitTime;
			}
			m_WaitTime += g_DeltaTime;
		 }
		else
			{
				alphaValue++;
				alphaValue = min(255, alphaValue);
			}
		}
		if (m_ReverseAlpha)
		{
			alphaValue--;
			alphaValue = max(0, alphaValue);
			if (alphaValue == 0)
			{
				CStageManager::GetInstance()->IsSceneChange = false;
			}	
		}
		SetAlphaBlend(alphaValue);
	}
	
	//BMP->Auto_BackGround_W(2, 3);


}

void CBackGround::SetAlphaBlend(int alphaValue)
{
	AlphaDC = CreateCompatibleDC(BackDC);
	TempDC = CreateCompatibleBitmap(BackDC, WINCX, WINCY);
	OldTempDC = (HBITMAP)SelectObject(AlphaDC, TempDC);

	
	//검은사진 가져오기
	HDC hDC;
	hDC = GetDC(g_hWnd);
	HDC m_MemDC = CreateCompatibleDC(hDC);
	HBITMAP m_hBitMap = (HBITMAP)LoadImageW(hInst, L"texture//페이드인아웃.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	HBITMAP m_OldBit = (HBITMAP)SelectObject(m_MemDC, m_hBitMap);

	TransparentBlt(AlphaDC, 0, 0, WINCX, WINCY, BackDC, 0, 0, WINCX, WINCY, RGB(255, 0, 255));
	TransparentBlt(AlphaDC, 0, 0, WINCX, WINCY, m_MemDC, 0, 0, WINCX, WINCY, RGB(255, 0, 255));

	BLENDFUNCTION bf;
	bf.BlendOp = AC_SRC_OVER;
	bf.BlendFlags = 0;
	bf.SourceConstantAlpha = alphaValue;
	bf.AlphaFormat = 0;

	AlphaBlend(BackDC, 0, 0, WINCX, WINCY, AlphaDC, 0, 0, WINCX, WINCY, bf);
	
	ReleaseDC(g_hWnd, hDC);
}

void CBackGround::Release()
{
	
}
