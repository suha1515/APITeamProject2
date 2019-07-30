#include "stdafx.h"
#include "ImageManager.h"
#include "Resource.h"
#include "Bit.h"


ImageManager * ImageManager::ROAD()
{
	static ImageManager* im = new ImageManager;
	return im;
	
}

void ImageManager::Init()
{
	//여기에 이미지 추가
	//---스테이지1_오븐 백그라운드 2개
	Push_Back(IDB_BITMAP1, 1600, 700); 
	Push_Back(IDB_BITMAP2, 1600, 700);
	Push_Back(IDB_BITMAP4, 1600, 120);
	//---------------------------------

	//---스테이지1_바닥 2개
	Push_Object(IDB_BITMAP3, 124, 120);
	//Push_Back(IDB_BITMAP4, 1488, 120);
	//---------------------------------
	//---젤리--------------------------
	Push_Item(IDB_BITMAP5, 25, 34);
	//---------------------------------
}

void ImageManager::Auto_BackGround()
{
	BackGround.at(1)->Out_BackGround1(2);
	BackGround.at(1)->Out_BackGround2(2);
}

void ImageManager::Push_Back(int ID, int Width, int Height)
{
	BackGround.push_back(new CBit);
	BackGround.back()->SetUp(ID, Width, Height);
}

void ImageManager::Push_Eff(int ID, int Width, int Height)
{
	Effect.push_back(new CBit);
	Effect.back()->SetUp(ID, Width, Height);
}

void ImageManager::Push_Player(int ID, int Width, int Height)
{
	Player.push_back(new CBit);
	Player.back()->SetUp(ID, Width, Height);
}

void ImageManager::Push_Object(int ID, int Width, int Height)
{
	Object.push_back(new CBit);
	Object.back()->SetUp(ID, Width, Height);
}

void ImageManager::Push_Item(int ID, int Width, int Height)
{
	Item.push_back(new CBit);
	Item.back()->SetUp(ID, Width, Height);
}

vector<CBit*>& ImageManager::Pop_BackGround()
{
	return BackGround;
	// TODO: 여기에 반환 구문을 삽입합니다.
}

vector<CBit*>& ImageManager::Pop_Player()
{
	return Player;
	// TODO: 여기에 반환 구문을 삽입합니다.
}

vector<CBit*>& ImageManager::Pop_Object()
{
	return Object;
	// TODO: 여기에 반환 구문을 삽입합니다.
}

vector<CBit*>& ImageManager::Pop_Item()
{
	return Item;
	// TODO: 여기에 반환 구문을 삽입합니다.
}

vector<CBit*>& ImageManager::Pop_Effect()
{
	return Effect;
	// TODO: 여기에 반환 구문을 삽입합니다.
}

void ImageManager::PopS_Background(int index, int x, int y)
{
	BackGround.at(index)->Output(BackDC, x, y);
}

void ImageManager::PopS_Player(int index, int x, int y)
{
	Player.at(index)->Output(BackDC, x, y);
}

void ImageManager::PopS_Object(int index, int x, int y)
{
	Object.at(index)->Output(BackDC, x, y);
}

void ImageManager::PopS_Item(int index, int x, int y)
{
	Item.at(index)->Output(BackDC, x, y);
}

void ImageManager::PopS_Effect(int index, int x, int y)
{
	Effect.at(index)->Output(BackDC, x, y);
}

void ImageManager::PopM_Background(int index, int x, int y, int Frame, int FrameMax)
{
	BackGround.at(index)->Output(BackDC, x, y, Frame, FrameMax);
}

void ImageManager::PopM_Player(int index, int x, int y, int Frame, int FrameMax)
{
	Player.at(index)->Output(BackDC, x, y, Frame, FrameMax);
}

void ImageManager::PopM_Object(int index, int x, int y, int Frame, int FrameMax)
{
	Object.at(index)->Output(BackDC, x, y, Frame, FrameMax);
}

void ImageManager::PopM_Item(int index, int x, int y, int Frame, int FrameMax)
{
	Item.at(index)->Output(BackDC, x, y, Frame, FrameMax);
}

void ImageManager::PopM_Effect(int index, int x, int y, int Frame, int FrameMax)
{
	Effect.at(index)->Output(BackDC, x, y, Frame, FrameMax);
}

