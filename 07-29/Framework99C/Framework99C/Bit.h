#pragma once
class CBit
{
public:
	CBit();
	~CBit();

public:
	void SetUp(int ID, int Width, int Height);
	inline HDC GetMemDC(void) { return m_MemDC; }
	void Output(HDC hDest, int nX, int nY) {
		//ù��° ���ڴ� �����, 2,3���� ������ġ(ũ��ƴ�)
		BitBlt(hDest, nX, nY, m_nWidth, m_nHeight, m_MemDC, 0, 0, SRCCOPY);
	}
	void Output(HDC hDC, int nX, int nY, RECT rcSour);
	void Output(HDC hDC, int nX, int nY, int nFrame, int nFrameMax);
public:

	void Out_BackGround1(int speed = 3);
	void Out_BackGround2(int speed = 3);

private:

	int m_nWidth;
	int m_nHeight;
	HDC m_MemDC;
	HBITMAP m_bit;
	HBITMAP m_obit;
	int sp = 1;
	int count = 1;
	int minus;
};

