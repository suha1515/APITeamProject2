#include"stdafx.h"
#include "BitManager.h"
#include"Bit.h"
#include "Resource.h"
#include "GameObject.h"
void BitManager::Initialize()
{
	//주의사항 전체 사진크기보다 크기를 크게 입력하면 안뜹니다.
	//지울 배경색깔 정하기
	SET_RGB(255, 0, 255);


	//푸쉬함수 사용방법
	//(주소,혹은 리소스 아이디  ,  가로, 세로 , 프레임갯수(생략가능))


	//Back 추가 
	//Push_BG(L"texture//background.bmp", 1000, 1000);  //처음 세팅	
	Push_BG(L"texture//stage1//스테이지1_배경2.bmp", 2000, 500);
	Push_BG(L"texture//stage1//스테이지1_배경.bmp", 2000, 500);
	Push_BG(L"texture//stage2배경2.bmp", 2000, 500);
	Push_BG(L"texture//stage2배경1.bmp", 2000, 500);
	

	
	
	Push_Obj(L"texture//연습용쿠키.bmp", 3192, 288, 11);
	
	
	Push_Obj(L"texture//stage1//스테이지1_바닥.bmp", 100, 100);
	Push_Obj(L"texture//stage1//장애물//송곳.bmp", 63, 99);			//Y값 365			2
	Push_Obj(L"texture//stage1//장애물//송곳2.bmp", 63, 99);		//Y값 365			3
	Push_Obj(L"texture//stage1//장애물//포크.bmp", 80, 113);		//Y값 355			4
	Push_Obj(L"texture//stage1//장애물//포크1.bmp", 134, 482);		//Y값  70 , -300	5
	Push_Obj(L"texture//stage1//장애물//포크2.bmp", 106, 193);		//Y값 315 ,	-100	6
	Push_Obj(L"texture//stage1//장애물//포크3.bmp", 71, 216);		//Y값 300 ,	-120	7
	Push_Obj(L"texture//stage1//장애물//포크4.bmp", 86, 482);		//Y값  70 , -300	8
	Push_Obj(L"texture//stage1//장애물//긴포크.bmp", 59, 193);		//Y값 315 , -100	9dk
	Push_Obj(L"texture//stage1//장애물//애니메이션_가시.bmp", 324, 131,4);//345			10
	Push_Obj(L"texture//stage1//장애물//정지_가시.bmp", 81, 131);		  //345			11
	Push_Obj(L"texture//stage1//장애물//애니메이션_가시2.bmp", 435, 190, 4);//			12	

	Push_Obj(L"texture//stage1//스테이지1_접시.bmp", 129, 52);				//	y200	13

	//스테이지2
	Push_Obj(L"texture//stage2//스테이지2_바닥.bmp", 100, 100);				//14		
	Push_Obj(L"texture//stage2//스테이지2_선반.bmp", 129, 52);				//15		y 250
	Push_Obj(L"texture//stage2//스테이지2_포션병1.bmp", 122,251);			//16		  295	
	Push_Obj(L"texture//stage2//스테이지2_포션병2.bmp", 122, 251);			//17		  295
	Push_Obj(L"texture//stage2//스테이지2_해골.bmp", 104, 135);				//18		  355
	Push_Obj(L"texture//stage2//스테이지2_양파.bmp", 170, 475);				//19		  70	
	Push_Obj(L"texture//stage2//스테이지2_개구리.bmp", 170, 475);			//20		  70
	Push_Obj(L"texture//stage2//스테이지2_덫.bmp", 692,138 ,4);				//21		  355
	Push_Obj(L"texture//stage2//스테이지2_덫정지.bmp", 174, 138);			//22		  355	
	Push_Obj(L"texture//stage2//스테이지2_덫2.bmp", 850, 290,5);			//23		  275			
	Push_Obj(L"texture//stage2//스테이지2_덫2정지.bmp", 170, 290);			//24		  275
	//아이템&젤리
	Push_Item(L"texture//stage1//젤리//파란_젤리.bmp", 20, 25);		//	370 y 기본값 	 0 
	Push_Item(L"texture//stage1//젤리//노랑_곰.bmp", 55, 51);		//	370				 1
	Push_Item(L"texture//stage1//젤리//분홍_곰.bmp", 55, 51);		//					 2

	
	//Push_BG(L"texture//test1.bmp", 1000, 1000);
	//Push_BG(L"texture//test2.bmp", 4000, 2000);
	//Push_BG(L"texture//keroro.bmp", 140, 50, 3);

	//플레이어 추가
	
	Push_Player(L"texture//Run.bmp", 449, 125, 4);
	Push_Player(L"texture//Jump.bmp", 762, 145, 6);
	Push_Player(L"texture//Slide.bmp", 300, 107, 2);  // 플레이어 슬라이딩
	Push_Player(L"texture//체력바.bmp", 760, 20,1);
	


	// 이펙트 추가
	// 아이템 추가
	//이펙트 추가
	//기타추가



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
