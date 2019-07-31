#include "stdafx.h"
#include"Bit.h"
#include"BitManager.h"


void CBit::SetUp(int ID, int Width, int Height, int MaxFraim)
{
	HDC  hdc;
	hdc = GetDC(g_hWnd);

	m_MemDC = CreateCompatibleDC(hdc);
	m_bit = (HBITMAP)LoadBitmap(hInst, MAKEINTRESOURCE(ID));
	m_obit = (HBITMAP)SelectObject(m_MemDC, m_bit);
	ReleaseDC(g_hWnd, hdc);

	m_nWidth = Width;
	m_nHeight = Height;
	m_MaxFraim = MaxFraim;
}
void CBit::SetUp(const wstring & wstrFilePath, int Width, int Height, int MaxFraim)
{
	HDC hDC;
	hDC = GetDC(g_hWnd);
	m_MemDC = CreateCompatibleDC(hDC);


	m_bit = (HBITMAP)LoadImageW(hInst, wstrFilePath.c_str(), IMAGE_BITMAP,
		0, 0, LR_LOADFROMFILE);
	m_obit = (HBITMAP)SelectObject(m_MemDC, m_bit);

	ReleaseDC(g_hWnd, hDC);
	m_nWidth = Width;
	m_nHeight = Height;
	m_MaxFraim = MaxFraim;
}


HDC CBit::GetMemDC(void)
{
	return m_MemDC;
}

int CBit::GetFrame()
{
	return m_MaxFraim;
}




void CBit::Output(HDC hDC, int nX, int nY, int nFrame, int nFrameMax) // 모든 출력
{

	int  nWidth = m_nWidth / nFrameMax;
	RECT  rcSour = { 0, 0, nWidth, m_nHeight };
	OffsetRect(&rcSour, nWidth * nFrame, 0);
	GdiTransparentBlt(hDC, nX, nY, nWidth, m_nHeight, m_MemDC, rcSour.left, rcSour.top, nWidth, m_nHeight, RGB(R, G, B)); // 색지우기

}


void CBit::Out_BackGround_H(int speed) // 스크롤
{
	BitBlt(BackDC, 0, 0, m_nWidth, count, m_MemDC, 0, m_nHeight - count, SRCCOPY);
	BitBlt(BackDC, 0, count, m_nWidth, m_nHeight - count, m_MemDC, 0, 0, SRCCOPY);
	
	count += speed;
	if (count > m_nHeight)
		count = 0;
	
}

void CBit::Out_BackGround(int x, int y)
{
	RECT	rc = { 0, 0,m_nWidth,m_nHeight };
	BitBlt(BackDC, 0, 0, WINCX, WINCY, m_MemDC, x, y, SRCCOPY);
	


}

void CBit::Out_BackGround_W(HDC hDC,int speed)
{

	/*BitBlt(BackDC, 0, 0, m_nWidth - count, m_nHeight, m_MemDC, count, 0, SRCCOPY);
	BitBlt(BackDC, m_nWidth - count, 0, m_nWidth, m_nHeight, m_MemDC, 0, 0, SRCCOPY);*/
	GdiTransparentBlt(hDC, 0, 0, m_nWidth-count, m_nHeight, m_MemDC, count, 0, m_nWidth-count, m_nHeight, RGB(R, G, B)); // 색지우기
	GdiTransparentBlt(hDC, m_nWidth - count, 0, m_nWidth, m_nHeight, m_MemDC, 0, 0, m_nWidth, m_nHeight, RGB(R, G, B)); // 색지우기
	
	count += speed;
	if (count > m_nWidth)
		count = 0;
}



CBit::CBit()
{
	R = BitManager::GetInstance()->Get_RGB(0);
	G = BitManager::GetInstance()->Get_RGB(1);
	B = BitManager::GetInstance()->Get_RGB(2);
}


CBit::~CBit()
{
	SelectObject(m_MemDC, m_obit);
	DeleteObject(m_bit);
	DeleteDC(m_MemDC);
}
