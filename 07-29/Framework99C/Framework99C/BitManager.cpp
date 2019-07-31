#include"stdafx.h"
#include "BitManager.h"
#include"Bit.h"
#include "Resource.h"
#include "GameObject.h"
void BitManager::Initialize()
{
	//���ǻ��� ��ü ����ũ�⺸�� ũ�⸦ ũ�� �Է��ϸ� �ȶ�ϴ�.
	//���� ������ ���ϱ�
	SET_RGB(255, 0, 255);


	//Ǫ���Լ� �����
	//(�ּ�,Ȥ�� ���ҽ� ���̵�  ,  ����, ���� , �����Ӱ���(��������))


	//Back �߰� 
	Push_BG(L"texture//background.bmp", 1000, 1000);  //ó�� ����
	Push_BG(L"texture//������.bmp", 2000, 500);
	
	Push_BG(L"texture//������2.bmp", 2000, 500);

	Push_Obj(L"texture//��������Ű.bmp", 3192, 288, 11);
	
	
	Push_Obj(L"texture//stage1//��������1_�ٴ�.bmp", 100, 100);
	Push_Obj(L"texture//stage1//��ֹ�//�۰�.bmp", 63, 99);			//Y�� 365			2
	Push_Obj(L"texture//stage1//��ֹ�//�۰�2.bmp", 63, 99);		//Y�� 365			3
	Push_Obj(L"texture//stage1//��ֹ�//��ũ.bmp", 80, 113);		//Y�� 355			4
	Push_Obj(L"texture//stage1//��ֹ�//��ũ1.bmp", 134, 482);		//Y��  70 , -300	5
	Push_Obj(L"texture//stage1//��ֹ�//��ũ2.bmp", 106, 193);		//Y�� 315 ,	-100	6
	Push_Obj(L"texture//stage1//��ֹ�//��ũ3.bmp", 71, 216);		//Y�� 300 ,	-120	7
	Push_Obj(L"texture//stage1//��ֹ�//��ũ4.bmp", 86, 482);		//Y��  70 , -300	8
	Push_Obj(L"texture//stage1//��ֹ�//����ũ.bmp", 59, 193);		//Y�� 315 , -100	9
	Push_Obj(L"texture//stage1//��ֹ�//�ִϸ��̼�_����.bmp", 324, 131,4);//345			10
	Push_Obj(L"texture//stage1//��ֹ�//����_����.bmp", 81, 131);		  //345			11
	Push_Obj(L"texture//stage1//��ֹ�//�ִϸ��̼�_����2.bmp", 435, 190, 4);//			12	

	Push_Obj(L"texture//stage1//��������1_����.bmp", 129, 52);				//	y200	13

	//������&����
	Push_Item(L"texture//stage1//����//�Ķ�_����.bmp", 20, 25);		//	370 y �⺻�� 	 0 
	Push_Item(L"texture//stage1//����//���_��.bmp", 55, 51);		//	370				 1
	Push_Item(L"texture//stage1//����//��ȫ_��.bmp", 55, 51);		//					 2
	
	//Push_BG(L"texture//test1.bmp", 1000, 1000);
	//Push_BG(L"texture//test2.bmp", 4000, 2000);
	//Push_BG(L"texture//keroro.bmp", 140, 50, 3);

	//�÷��̾� �߰�
	
	/*Push_Player(L"texture//keroro.bmp", 140, 50);
	Push_Player(L"texture\\test1.bmp", 500, 500);*/

	// ����Ʈ �߰�
	// ������ �߰�
	//����Ʈ �߰�
	//��Ÿ�߰�



}


void BitManager::Auto_BackGround_W(int index, int speed)
{
	BG.at(index)->Out_BackGround_W(speed);
}

void BitManager::Auto_BackGround_H(int index, int speed)
{
	BG.at(index)->Out_BackGround_H(speed);
}

void BitManager::Manual_BackGround(int index, int x, int y)
{
	BG.at(index)->Out_BackGround(x, y);
}

void BitManager::SET_RGB(int R, int G, int B)
{
	RGB[0] = R;
	RGB[1] = G;
	RGB[2] = B;
}
int BitManager::Get_RGB(int i) {
	return RGB[i];
}

void BitManager::Push_BG(int ID, int Width, int Height, int MaxFraim)
{
	BG.push_back(new CBit);
	BG.back()->SetUp(ID, Width, Height, MaxFraim);
}
void BitManager::Push_Obj(int ID, int Width, int Height, int MaxFraim)
{
	Obj.push_back(new CBit);
	Obj.back()->SetUp(ID, Width, Height, MaxFraim);
}

void BitManager::Push_Item(int ID, int Width, int Height, int MaxFraim)
{
	Item.push_back(new CBit);
	Item.back()->SetUp(ID, Width, Height, MaxFraim);

}

void BitManager::Push_Effect(int ID, int Width, int Height, int MaxFraim)
{
	Effect.push_back(new CBit);
	Effect.back()->SetUp(ID, Width, Height, MaxFraim);
}

void BitManager::Push_Player(int ID, int Width, int Height, int MaxFraim)
{
	Player.push_back(new CBit);
	Player.back()->SetUp(ID, Width, Height, MaxFraim);
}

void BitManager::Push_BG(const wstring & Path, int Width, int Height, int MaxFraim)
{
	BG.push_back(new CBit);
	BG.back()->SetUp(Path, Width, Height, MaxFraim);
}

void BitManager::Push_Obj(const wstring & Path, int Width, int Height, int MaxFraim)
{
	Obj.push_back(new CBit);
	Obj.back()->SetUp(Path, Width, Height, MaxFraim);
}

void BitManager::Push_Item(const wstring & Path, int Width, int Height, int MaxFraim)
{

	Item.push_back(new CBit);
	Item.back()->SetUp(Path, Width, Height, MaxFraim);
}

void BitManager::Push_Effect(const wstring & Path, int Width, int Height, int MaxFraim)
{

	Effect.push_back(new CBit);
	Effect.back()->SetUp(Path, Width, Height, MaxFraim);
}

void BitManager::Push_Player(const wstring & Path, int Width, int Height, int MaxFraim)
{
	Player.push_back(new CBit);
	Player.back()->SetUp(Path, Width, Height, MaxFraim);
}

vector<CBit*>& BitManager::Pop_Back()
{
	return BG;
}

vector<CBit*>& BitManager::Pop_Mon()
{
	return Obj;
}

vector<CBit*>& BitManager::Pop_Bul()
{
	return Item;
}

vector<CBit*>& BitManager::Pop_Eff()
{
	return Effect;
}

vector<CBit*>& BitManager::Pop_Player()
{
	return Player;
}

void BitManager::PopM_BG(int index, int x, int y, int Frame_Index, int FrameMax)
{
	BG.at(index)->Output(BackDC, x, y, Frame_Index, FrameMax);
}

void BitManager::PopM_Obj(int index, int x, int y, int Frame_Index, int FrameMax)
{
	Obj.at(index)->Output(BackDC, x, y, Frame_Index, FrameMax);
}

void BitManager::PopM_Item(int index, int x, int y, int Frame_Index, int FrameMax)
{
	Item.at(index)->Output(BackDC, x, y, Frame_Index, FrameMax);
}

void BitManager::PopM_Effect(int index, int x, int y, int Frame_Index, int FrameMax)
{
	Effect.at(index)->Output(BackDC, x, y, Frame_Index, FrameMax);
}

void BitManager::PopM_Player(int index, int x, int y, int Frame_Index, int FrameMax)
{
	Player.at(index)->Output(BackDC, x, y, Frame_Index, FrameMax);
}

void BitManager::PopA_BG(int index, int x, int y, CGameObject *co, clock_t time)
{
	int frame = co->IndexTimer(BG.at(index)->GetFrame(), time);
	BG.at(index)->Output(BackDC, x, y, frame, BG.at(index)->GetFrame());
}

void BitManager::PopA_Obj(int index, int x, int y, CGameObject * co, clock_t time)
{
	int frame = co->IndexTimer(Obj.at(index)->GetFrame(), time);
	Obj.at(index)->Output(BackDC, x, y, frame, Obj.at(index)->GetFrame());
}

void BitManager::PopA_Item(int index, int x, int y, CGameObject * co, clock_t time)
{
	int frame = co->IndexTimer(Item.at(index)->GetFrame(), time);
	Item.at(index)->Output(BackDC, x, y, frame, Item.at(index)->GetFrame());
}

void BitManager::PopA_Effect(int index, int x, int y, CGameObject * co, clock_t time)
{
	int frame = co->IndexTimer(Effect.at(index)->GetFrame(), time);
	Effect.at(index)->Output(BackDC, x, y, frame, Effect.at(index)->GetFrame());
}

void BitManager::PopA_Player(int index, int x, int y, CGameObject * co, clock_t time)
{
	int frame = co->IndexTimer(Player.at(index)->GetFrame(), time);
	Player.at(index)->Output(BackDC, x, y, frame, Player.at(index)->GetFrame());
}

void BitManager::PopA_Once(int index2, int x, int y, CGameObject * co, clock_t time)
{
	int frame = co->IndexTimerOnce(Obj.at(index2)->GetFrame(), time);
	Obj.at(index2)->Output(BackDC, x, y, frame, Obj.at(index2)->GetFrame());
}


void BitManager::PopS_BG(int index, int x, int y)
{
	BG.at(index)->Output(BackDC, x, y);
}

void BitManager::PopS_Obj(int index, int x, int y)
{
	Obj.at(index)->Output(BackDC, x, y);
}

void BitManager::PopS_Item(int index, int x, int y)
{
	Item.at(index)->Output(BackDC, x, y);
}

void BitManager::PopS_Effect(int index, int x, int y)
{
	Effect.at(index)->Output(BackDC, x, y);
}

void BitManager::PopS_Player(int index, int x, int y)
{
	Player.at(index)->Output(BackDC, x, y);
}