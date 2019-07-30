#pragma once

class CBit
{
public:
	CBit();
	~CBit();



public:
	void SetUp(int ID, int Width, int Height, int MaxFraim = 1);
	void SetUp(const wstring& wstrFilePath, int Width, int Height, int MaxFraim = 1);
	HDC GetMemDC(void);
	int GetFrame();

	void Output(HDC hDC, int nX, int nY, int nFrame = 0, int nFrameMax = 1);
public:

	void Out_BackGround_W(int speed = 3);
	void Out_BackGround_H(int speed = 3);
	void Out_BackGround(int x, int y);

private:

	//비트맵의 크기정보들
	int m_nWidth;
	int m_nHeight;
	int m_MaxFraim;

	//비트맵을 미리 그려놓을 DC와 
	//비트맵의 정보를 가지고 있을 핸들
	HDC m_MemDC;
	HBITMAP m_bit;
	HBITMAP m_obit;

	//백그라운드 호출카운트값
	int count = 1;

	//배경 지우는 RGB 값 
	int R = 255, G = 0, B = 255;
};

