#include "stdafx.h"
#include "Bit.h"


CBit::CBit()
{
}


CBit::~CBit()
{
	SelectObject(m_MemDC, m_obit);
	DeleteObject(m_bit);
	DeleteDC(m_MemDC);
}

void CBit::SetUp(int ID, int Width, int Height)
{
	HDC  hdc;
	hdc = GetDC(g_hWnd);

	m_MemDC = CreateCompatibleDC(hdc);
	m_bit = (HBITMAP)LoadBitmap(hInst, MAKEINTRESOURCE(ID));
	m_obit = (HBITMAP)SelectObject(m_MemDC, m_bit);

	ReleaseDC(g_hWnd, hdc);



	m_nWidth = Width;
	m_nHeight = Height;
}

void CBit::Output(HDC hDC, int nX, int nY, RECT rcSour)
{
	int  nWidth = rcSour.right - rcSour.left;
	int  nHeight = rcSour.bottom - rcSour.top;
	BitBlt(hDC, nX, nY, nWidth, nHeight, m_MemDC, rcSour.left, rcSour.top, SRCCOPY);
}

void CBit::Output(HDC hDC, int nX, int nY, int nFrame, int nFrameMax)
{
	int  nWidth = m_nWidth / nFrameMax;
	RECT  rcSour = { 0, 0, nWidth, m_nHeight };
	OffsetRect(&rcSour, nWidth * nFrame, 0);
	/*TransparentBlt(hDC, nX, nY, nWidth, m_nHeight,
	m_MemDC, rcSour.left, rcSour.top, nWidth, m_nHeight, RGB(255, 0, 255));*/
}

void CBit::Out_BackGround1(int speed)
{
}

void CBit::Out_BackGround2(int speed)
{
	BitBlt(BackDC, 0, 0, m_nWidth, count, m_MemDC, 0, m_nHeight - count, SRCCOPY);
	BitBlt(BackDC, 0, count, m_nWidth, m_nHeight - count, m_MemDC, 0, 0, SRCCOPY);
	count += 2;
	if (count > 1800)
		count = 0;
}
