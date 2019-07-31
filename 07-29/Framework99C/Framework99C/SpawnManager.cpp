#include "stdafx.h"
#include "SpawnManager.h"
#include "Floor.h"
#include "Item.h"
#include "Obstacle.h"
#include "Jelly.h"


CSpawnManager::CSpawnManager()
{
}


CSpawnManager::~CSpawnManager()
{
}
void CSpawnManager::Initialize()
{
	// 스폰순서.. 바보코딩임..

	//스테이지 1 장애물
	m_ObstacleList.push_back(SPAWN_OBSTACLE_INFO(1200, 365, 1000, OBSTACLE_TYPE::OBSTACLE_GIMLET2));
	m_ObstacleList.push_back(SPAWN_OBSTACLE_INFO(1200, 365, 1500, OBSTACLE_TYPE::OBSTACLE_GIMLET2));
	m_ObstacleList.push_back(SPAWN_OBSTACLE_INFO(1200, 315, 2000, OBSTACLE_TYPE::OBSTACLE_FORK2));
	m_ObstacleList.push_back(SPAWN_OBSTACLE_INFO(1200, 70, 2500, OBSTACLE_TYPE::OBSTACLE_FORK1));
	m_ObstacleList.push_back(SPAWN_OBSTACLE_INFO(1200, 365, 3000, OBSTACLE_TYPE::OBSTACLE_GIMLET));
												 
	m_ObstacleList.push_back(SPAWN_OBSTACLE_INFO(1200, 315, 3500, OBSTACLE_TYPE::OBSTACLE_FORK2));
												 
	m_ObstacleList.push_back(SPAWN_OBSTACLE_INFO(1200, 70, 4000, OBSTACLE_TYPE::OBSTACLE_FORK1));
	m_ObstacleList.push_back(SPAWN_OBSTACLE_INFO(1200, 70, 4200, OBSTACLE_TYPE::OBSTACLE_FORK1));
	m_ObstacleList.push_back(SPAWN_OBSTACLE_INFO(1200, 70, 4400, OBSTACLE_TYPE::OBSTACLE_FORK1));
	m_ObstacleList.push_back(SPAWN_OBSTACLE_INFO(1200, 70, 4600, OBSTACLE_TYPE::OBSTACLE_FORK1));
												
	m_ObstacleList.push_back(SPAWN_OBSTACLE_INFO(1200, 365, 5000, OBSTACLE_TYPE::OBSTACLE_GIMLET2));
	m_ObstacleList.push_back(SPAWN_OBSTACLE_INFO(1200, 365, 5500, OBSTACLE_TYPE::OBSTACLE_GIMLET2));
												 
	m_ObstacleList.push_back(SPAWN_OBSTACLE_INFO(1200, -100, 6000, OBSTACLE_TYPE::OBSTACLE_FORK2,OBSTACLE_MOVETYPE::FALLING));
	m_ObstacleList.push_back(SPAWN_OBSTACLE_INFO(1200, -300, 6400, OBSTACLE_TYPE::OBSTACLE_FORK1, OBSTACLE_MOVETYPE::UPTODOWN));
	m_ObstacleList.push_back(SPAWN_OBSTACLE_INFO(1200,  365, 6900, OBSTACLE_TYPE::OBSTACLE_GIMLET));
	m_ObstacleList.push_back(SPAWN_OBSTACLE_INFO(1200, -100, 7300, OBSTACLE_TYPE::OBSTACLE_FORK2, OBSTACLE_MOVETYPE::FALLING));
												
	m_ObstacleList.push_back(SPAWN_OBSTACLE_INFO(1200, -300, 7700, OBSTACLE_TYPE::OBSTACLE_FORK1, OBSTACLE_MOVETYPE::UPTODOWN));
	m_ObstacleList.push_back(SPAWN_OBSTACLE_INFO(1200, -300, 8000, OBSTACLE_TYPE::OBSTACLE_FORK1, OBSTACLE_MOVETYPE::UPTODOWN));
	m_ObstacleList.push_back(SPAWN_OBSTACLE_INFO(1200, -300, 8300, OBSTACLE_TYPE::OBSTACLE_FORK1, OBSTACLE_MOVETYPE::UPTODOWN));

	m_ObstacleList.push_back(SPAWN_OBSTACLE_INFO(1200, -100, 8700, OBSTACLE_TYPE::OBSTACLE_FORK2, OBSTACLE_MOVETYPE::FALLING));
	m_ObstacleList.push_back(SPAWN_OBSTACLE_INFO(1200, 345, 9100, OBSTACLE_TYPE::OBSTACLE_GIMLETS, OBSTACLE_MOVETYPE::ANIMATION));
	m_ObstacleList.push_back(SPAWN_OBSTACLE_INFO(1200, 345, 9600, OBSTACLE_TYPE::OBSTACLE_GIMLETS, OBSTACLE_MOVETYPE::ANIMATION));
	m_ObstacleList.push_back(SPAWN_OBSTACLE_INFO(1200, 345, 9900, OBSTACLE_TYPE::OBSTACLE_GIMLETS, OBSTACLE_MOVETYPE::ANIMATION));

	//스테이지 1 접시
	m_FloorList.push_back(SPAWN_FLOOR_INFO(1200, 200, 5230, STAGE1_HANG));
	m_FloorList.push_back(SPAWN_FLOOR_INFO(1200, 200, 5360, STAGE1_HANG));
	m_FloorList.push_back(SPAWN_FLOOR_INFO(1200, 200, 5490, STAGE1_HANG));
	m_FloorList.push_back(SPAWN_FLOOR_INFO(1200, 200, 5620, STAGE1_HANG));
	m_FloorList.push_back(SPAWN_FLOOR_INFO(1200, 200, 5750, STAGE1_HANG));
	/*m_FloorList.push_back(SPAWN_FLOOR_INFO(1200, 200, 5200, STAGE1_HANG));
	m_FloorList.push_back(SPAWN_FLOOR_INFO(1200, 200, 5200, STAGE1_HANG));
	m_FloorList.push_back(SPAWN_FLOOR_INFO(1200, 200, 5200, STAGE1_HANG));*/

	//스테이지 1 젤리
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 500, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 530, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 560, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 590, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 620, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 650, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 680, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 710, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 740, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 770, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 800, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 830, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 860, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 890, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 340, 920, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 310, 950, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 280, 980, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 280,1010 , BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 310, 1040, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 340, 1070, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 1100, BLUE_BEAN));

	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 1130, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 1160, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 1190, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 1210, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 1240, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 1270, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 1300, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 1330, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 1360, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 1390, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 340, 1410, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 310, 1440, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 280, 1470, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 280, 1500, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 280, 1530, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 310, 1560, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 340, 1590, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 1620, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 1650, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 1680, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 1710, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 1740, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 1770, BLUE_BEAN));

	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 1800, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 1830, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 330, 1860, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 290, 1890, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 250, 1910, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 210, 1940, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 170, 1970, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 170, 2000, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 170, 2030, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 170, 2060, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 210, 2090, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 250, 2120, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 290, 2150, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 330, 2180, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 2210, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 2240, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 2270, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 2300, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 2330, BLUE_BEAN));


	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 2370, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 2400, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 2430, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 2460, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 2490, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 2510, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 2540, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 2570, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 2600, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 2630, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 2660, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 2690, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 2720, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 2750, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 2780, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 2810, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 2840, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 2870, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 2900, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 340, 2930, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 310, 2960, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 280, 2990, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 280, 3020, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 280, 3050, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 310, 3080, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 340, 3110, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 3140, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 3170, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 3170, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 3170, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 3170, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 3170, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 3200, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 3230, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 3260, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 330, 3290, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 290, 3320, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 250, 3350, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 210, 3380, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 170, 3410, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 170, 3440, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 170, 3470, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 170, 3500, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 170, 3530, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 170, 3530, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 170, 3560, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 210, 3590, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 250, 3620, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 290, 3650, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 330, 3680, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 3710, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 3740, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 3770, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 3800, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 3830, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 3870, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 3900, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 3930, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 3970, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 4000, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 4030, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 4060, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 4090, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 4120, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 4150, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 4180, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 4210, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 4240, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 4270, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 4300, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 4330, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 4360, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 4390, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 4420, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 4450, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 4480, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 4510, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 4540, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 4570, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 4600, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 4630, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 4660, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 4690, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 4720, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 4750, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 4780, BLUE_BEAN));







}
void CSpawnManager::SpawnFloor()
{	
	const OBJLIST* object = CObjectMgr::GetInstance()->GetObjectList(OBJECT_TYPE::OBJECT_FLOOR);
	OBJLIST::const_iterator iter_begin = object->begin();
	OBJLIST::const_iterator iter_end = object->end();
	if (object->size() < 17)
	{
		if (iter_begin == iter_end)
		{
			CGameObject* pGameObject = CAbstractFactory<CFloor>::CreateObject();
			pGameObject->SetPos(50, 470);
			dynamic_cast<CFloor*>(pGameObject)->SetType(STAGE1_BOTTOM);
			CObjectMgr::GetInstance()->AddObject(OBJECT_FLOOR, pGameObject);
			
		}
		else
		{
			CGameObject* pGameObject = CAbstractFactory<CFloor>::CreateObject();
			pGameObject->SetPos(object->back()->GetInfo().fX + 100, 470);
			dynamic_cast<CFloor*>(pGameObject)->SetType(STAGE1_BOTTOM);
			CObjectMgr::GetInstance()->AddObject(OBJECT_FLOOR, pGameObject);
			
		}
	}
	//cout << m_FloorCount << endl;
}

void CSpawnManager::SpwanHangFloor()
{
	list<SPAWN_FLOOR_INFO>::iterator iter_begin = m_FloorList.begin();
	list<SPAWN_FLOOR_INFO>::iterator iter_end = m_FloorList.end();
	for (; iter_begin != iter_end;)
	{
		if (m_StageDist>iter_begin->spawn_Time)
		{
			CGameObject * pGameObject = CAbstractFactory<CFloor>::CreateObject();
			pGameObject->SetPos(iter_begin->pos_X, iter_begin->pos_Y);
			dynamic_cast<CFloor*>(pGameObject)->SetType(iter_begin->m_FloorType);
			CObjectMgr::GetInstance()->AddObject(OBJECT_FLOOR, pGameObject);

			iter_begin = m_FloorList.erase(iter_begin);
		}
		else
			++iter_begin;
	}
}

void CSpawnManager::SpawnJelly()
{
	list<SPAWN_JELLY_INFO>::iterator iter_begin = m_JellyList.begin();
	list<SPAWN_JELLY_INFO>::iterator iter_end = m_JellyList.end();
	for (; iter_begin != iter_end;)
	{
		if (m_StageDist>iter_begin->spawn_Time)
		{
			CGameObject * pGameObject = CAbstractFactory<CJelly>::CreateObject();
			pGameObject->SetPos(iter_begin->pos_X, iter_begin->pos_Y);
			dynamic_cast<CJelly*>(pGameObject)->SetJellyType(iter_begin->m_JellyType);
			CObjectMgr::GetInstance()->AddObject(OBJECT_JELLY, pGameObject);

			iter_begin = m_JellyList.erase(iter_begin);
		}
		else
			++iter_begin;
	}
}

void CSpawnManager::SpawnObstacle()
{
	list<SPAWN_OBSTACLE_INFO>::iterator iter_begin = m_ObstacleList.begin();
	list<SPAWN_OBSTACLE_INFO>::iterator iter_end = m_ObstacleList.end();
	for (; iter_begin != iter_end;)
	{
		if (m_StageDist>iter_begin->spawn_Time)
		{
			CGameObject * pGameObject = CAbstractFactory<CObstacle>::CreateObject();
			pGameObject->SetPos(iter_begin->pos_X, iter_begin->pos_Y);
			dynamic_cast<CObstacle*>(pGameObject)->SetType(iter_begin->m_ObsType, iter_begin->m_MoveType);
			CObjectMgr::GetInstance()->AddObject(OBJECT_OBSTACLE, pGameObject);

			iter_begin=m_ObstacleList.erase(iter_begin);
		}
		else
		++iter_begin;
	}
	
}


