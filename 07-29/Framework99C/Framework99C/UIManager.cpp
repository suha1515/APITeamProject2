#include "stdafx.h"
#include "UIManager.h"
#include "Center.h"


void UIManager::Update(HDC hDC)
{
	HP_Bar(hDC);
}

void UIManager::HP_Bar(HDC hDC)
{
	//LPCWSTR str = TEXT("HP");

	////100~500 까지의 체력을 백분율로 출력
	////400 * hp /maxhp + 100
	//INFO temp = Center::ROAD()->Get_PlayerINFO();
	//int HP = (600 * temp.HP / temp.MaxHp) % 601 + 100;
	//brush = CreateSolidBrush(RGB(100, 0, 0));
	//obrush = (HBRUSH)SelectObject(hDC, brush);
	//ImageManager::ROAD()->PopS_Back(8, 100, 200);

	////Rectangle(hDC, 100, 690 + 150, HP, 700 + 150);
	//SelectObject(hDC, obrush);
	//DeleteObject(brush);
}

UIManager::UIManager()
{
}


UIManager::~UIManager()
{
}

