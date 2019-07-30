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

	//��Ʈ���� ũ��������
	int m_nWidth;
	int m_nHeight;
	int m_MaxFraim;

	//��Ʈ���� �̸� �׷����� DC�� 
	//��Ʈ���� ������ ������ ���� �ڵ�
	HDC m_MemDC;
	HBITMAP m_bit;
	HBITMAP m_obit;

	//��׶��� ȣ��ī��Ʈ��
	int count = 1;

	//��� ����� RGB �� 
	int R = 255, G = 0, B = 255;
};

