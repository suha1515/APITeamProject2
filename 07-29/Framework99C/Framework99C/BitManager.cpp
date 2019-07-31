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
	Push_BG(L"texture//stage2���2.bmp", 2000, 500);
	Push_BG(L"texture//stage2���1.bmp", 2000, 500);
	
	


	
	
	

	Push_Obj(L"texture//stage1//��������1_�ٴ�.bmp", 100, 100);					 //0
	Push_Obj(L"texture//stage1//��ֹ�//����.bmp", 63, 99);						//1
	Push_Obj(L"texture//stage1//��ֹ�//��ũ.bmp", 80, 113);						//2
	Push_Obj(L"texture//stage1//��ֹ�//�ִϸ��̼�_����.bmp", 324, 131,4);	//3

	
	

	//������&����
	Push_Item(L"texture//stage1//����//�Ķ�_����.bmp", 20, 25);

	
	//Push_BG(L"texture//test1.bmp", 1000, 1000);
	//Push_BG(L"texture//test2.bmp", 4000, 2000);
	//Push_BG(L"texture//keroro.bmp", 140, 50, 3);

	//�÷��̾� �߰�
	
	Push_Player(L"texture//Run.bmp", 449, 125, 4);
	Push_Player(L"texture//Jump.bmp", 762, 145, 6);
	Push_Player(L"texture//Slide.bmp", 300, 107, 2);  // �÷��̾� �����̵�
	Push_Player(L"texture//ü�¹�.bmp", 760, 20,1);
	


	// ����Ʈ �߰�
	// ������ �߰�
	//����Ʈ �߰�
	//��Ÿ�߰�



}


void BitManager::Auto_BackGround_W(int index,int speed)
{
	BG.at(index)->Out_BackGround_W(BackDC,speed);
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
