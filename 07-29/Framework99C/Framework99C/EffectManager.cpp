#include "stdafx.h"
#include "EffectManager.h"


void EffectManager::Render(HDC hDC)
{
	for (auto i : CallVector)
	{
		(*this.*(i.second))(hDC);
	}
}

void EffectManager::Boom(HDC hDC)
{
}

void EffectManager::Shield(HDC hDC)
{
	/*OBJLIST* BM = BulletManeger::ROAD()->Get_mlist();
	OBJLIST::iterator iter = BM->begin();
	for (; iter != BM->end();)
	{
		if (Center::ROAD()->Circle((*iter)->GetInfo().fX, (*iter)->GetInfo().fY, Center::ROAD()->Get_PlayerINFO().fX, Center::ROAD()->Get_PlayerINFO().fY, 75, (*iter)->GetInfo().fCX))
		{
			(*iter)->Dead();
			iter = BM->erase(iter);
		}
		else
			iter++;
	}
	ImageManger::ROAD()->PopM_Back(9, Center::ROAD()->Get_PlayerINFO().fX - 75, Center::ROAD()->Get_PlayerINFO().fY - 75, 0, 1);*/
	//이미지 좌표 -50 +50 크기 100 100
}

void EffectManager::Update()
{
	vector<pair<pair<clock_t, clock_t>, void (EffectManager::*)(HDC)>>::iterator iter = CallVector.begin();

	for (; iter != CallVector.end();)
	{
		curtime = clock();
		if (curtime - iter->first.first > iter->first.second)
			iter = CallVector.erase(iter);
		else
			iter++;
	}
}

//void EffectManager::Set_Boom(clock_t time)
//{
//	CallVector.push_back(make_pair(make_pair(clock(), time), EMA[0]));
//}

void EffectManager::Set_Shield(clock_t time)
{
	CallVector.push_back(make_pair(make_pair(clock(), time), EMA[1]));
}

EffectManager::EffectManager()
{
}


EffectManager::~EffectManager()
{
}
