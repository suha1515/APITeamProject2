#pragma once
#include "GameObject.h"
#include "Monster.h"
#include "Player.h"
#include "Bullet.h"
class Center
{
	static Center* ROAD() 
	{
		static Center* cnt = new Center;
		return cnt;
	}
public:
	Center();
	~Center();

	INFO Get_PlayerINFO();
	void TimerM(CGameObject* Mon, clock_t time);
	void Dead_Effect(double x, double y, clock_t time);
	int GetTick();
				
private:
	CGameObject* m_pPlayer;
	OBJLIST* m_objlist_Obj;
	vector<pair<pair<double, double>, pair<clock_t, clock_t>>> PlayerDeadVec;
	vector<pair<CGameObject*, pair<clock_t, clock_t>>> MTimerVec;
	int					m_tick = 0;

};

