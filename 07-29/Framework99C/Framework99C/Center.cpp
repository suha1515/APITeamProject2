#include "stdafx.h"
#include "Center.h"


Center::Center()
{
}


Center::~Center()
{
}

INFO Center::Get_PlayerINFO()
{
	return m_pPlayer->GetInfo();
}

//사용법 :  TimerM(this, 충격상태시간)
void Center::TimerM(CGameObject * Mon, clock_t time)
{
	clock_t curtime = clock();
	MTimerVec.push_back(make_pair(Mon, make_pair(curtime, time)));
}

void Center::Dead_Effect(double x, double y, clock_t time)
{
	clock_t curtime = clock();
	PlayerDeadVec.push_back(make_pair(make_pair(x, y), make_pair(curtime, time)));
}

int Center::GetTick()
{
	return m_tick;
}
