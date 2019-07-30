#pragma once
#include <time.h>
#include "GameObject.h"
#include"Bit.h"

class EffectManager
{
	static EffectManager* ROAD() 
	{
		static EffectManager* em = new EffectManager;
		return em;
	}

	//렌더함수들
	void Render(HDC hDC);
	void Boom(HDC hDC);
	void Shield(HDC hDC);


	//업데이트 함수들
	void Update();
	// 여기에 이펙트 추가
	//void Set_Boom(clock_t time);
	void Set_Shield(clock_t time);

private:
	clock_t curtime;
	EffectManager();
	~EffectManager();

	vector<pair<pair<clock_t, clock_t>, void (EffectManager::*)(HDC)>> CallVector;

	void (EffectManager::*EMA[2])(HDC) = { &EffectManager::Boom,&EffectManager::Shield };
};

