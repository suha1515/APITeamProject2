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
	m_ObstacleList.push_back(SPAWN_OBSTACLE_INFO(1200, 315, 2010, OBSTACLE_TYPE::OBSTACLE_FORK2));
	m_ObstacleList.push_back(SPAWN_OBSTACLE_INFO(1200, 70,  2500, OBSTACLE_TYPE::OBSTACLE_FORK1));
	m_ObstacleList.push_back(SPAWN_OBSTACLE_INFO(1200, 365, 3010, OBSTACLE_TYPE::OBSTACLE_GIMLET));
												 
	m_ObstacleList.push_back(SPAWN_OBSTACLE_INFO(1200, 315, 3470, OBSTACLE_TYPE::OBSTACLE_FORK2));
												 
	m_ObstacleList.push_back(SPAWN_OBSTACLE_INFO(1200, 70, 4000, OBSTACLE_TYPE::OBSTACLE_FORK1));
	m_ObstacleList.push_back(SPAWN_OBSTACLE_INFO(1200, 70, 4200, OBSTACLE_TYPE::OBSTACLE_FORK1));
	m_ObstacleList.push_back(SPAWN_OBSTACLE_INFO(1200, 70, 4400, OBSTACLE_TYPE::OBSTACLE_FORK1));
	m_ObstacleList.push_back(SPAWN_OBSTACLE_INFO(1200, 70, 4600, OBSTACLE_TYPE::OBSTACLE_FORK1));
												
	m_ObstacleList.push_back(SPAWN_OBSTACLE_INFO(1200, 365, 5000, OBSTACLE_TYPE::OBSTACLE_GIMLET2));
	m_ObstacleList.push_back(SPAWN_OBSTACLE_INFO(1200, 365, 5500, OBSTACLE_TYPE::OBSTACLE_GIMLET2));
												 
	m_ObstacleList.push_back(SPAWN_OBSTACLE_INFO(1200, -100, 6000, OBSTACLE_TYPE::OBSTACLE_FORK2,OBSTACLE_MOVETYPE::FALLING));
	m_ObstacleList.push_back(SPAWN_OBSTACLE_INFO(1200, -300, 6400, OBSTACLE_TYPE::OBSTACLE_FORK1, OBSTACLE_MOVETYPE::UPTODOWN));
	m_ObstacleList.push_back(SPAWN_OBSTACLE_INFO(1200,  365, 6880, OBSTACLE_TYPE::OBSTACLE_GIMLET));
	m_ObstacleList.push_back(SPAWN_OBSTACLE_INFO(1200, -100, 7290, OBSTACLE_TYPE::OBSTACLE_FORK2, OBSTACLE_MOVETYPE::FALLING));
												
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
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 4810, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 4840, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 4870, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 4900, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 4930, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 4930, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 330, 4960, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 290, 4990, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 290, 5020, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 330, 5050, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 5080, BLUE_BEAN));

	//선반위 젤리들..
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 150, 5130, YELLOW_BEAR));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 150, 5200, YELLOW_BEAR));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 150, 5270, YELLOW_BEAR));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 150, 5340, YELLOW_BEAR));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 150, 5410, YELLOW_BEAR));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 150, 5490, YELLOW_BEAR));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 150, 5560, YELLOW_BEAR));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 150, 5630, YELLOW_BEAR));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 150, 5700, YELLOW_BEAR));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 150, 5770, YELLOW_BEAR));
	//

	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 5110, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 5140, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 5170, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 5200, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 5230, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 5260, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 5290, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 5310, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 5340, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 5370, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 5400, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 340, 5430, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 290, 5460, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 290, 5490, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 290, 5520, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 340, 5550, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 5580, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 5610, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 5640, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 5670, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 5700, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 5730, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 5760, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 5790, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 330, 5820, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 290, 5850, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 250, 5880, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 210, 5910, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 170, 5950, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 170, 5980, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 170, 6010, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 210, 6040, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 250, 6070, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 290, 6100, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 330, 6130, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 6160, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 6190, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 6220, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 6250, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 6280, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 6310, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 6340, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 6370, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 6400, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 6430, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 6460, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 6490, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 6520, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 6550, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 6580, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 6610, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 6640, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 6670, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 6700, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 6730, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 6760, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 6790, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 330, 6820, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 290, 6850, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 290, 6880, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 290, 6910, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 330, 6940, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 6970, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 7000, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 7030, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 7060, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 7090, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 330, 7120, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 290, 7150, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 250, 7180, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 210, 7210, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 170, 7240, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 170, 7270, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 170, 7300, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 170, 7330, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 210, 7360, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 250, 7390, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 290, 7420, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 330, 7450, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 7480, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 7510, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 7540, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 7570, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 7600, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 7630, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 7660, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 7690, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 7720, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 7750, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 7780, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 7810, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 7840, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 7870, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 7900, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 7930, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 7960, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 7990, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 8020, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 8050, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 8080, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 8110, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 8140, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 8170, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 8200, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 8230, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 8260, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 8290, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 8320, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 8350, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 8380, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 8410, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 370, 8440, BLUE_BEAN));


	//하트
	
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 255, 8490, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 255, 8510, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 255, 8530, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 255, 8590, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 255, 8610, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 255, 8630, BLUE_BEAN));		//	 ㅇㅇㅇ  ㅇㅇㅇ
	
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 275, 8470, BLUE_BEAN));     	// ㅇㅇㅇㅇㅇㅇㅇㅇㅇ
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 275, 8490, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 275, 8510, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 275, 8530, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 275, 8550, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 275, 8570, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 275, 8590, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 275, 8610, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 275, 8630, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 275, 8650, BLUE_BEAN));

	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 295, 8490, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 295, 8510, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 295, 8530, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 295, 8550, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 295, 8570, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 295, 8590, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 295, 8610, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 295, 8630, BLUE_BEAN));

	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 315, 8510, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 315, 8530, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 315, 8550, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 315, 8570, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 315, 8590, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 315, 8610, BLUE_BEAN));
	
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 335, 8530, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 335, 8550, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 335, 8570, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 335, 8590, BLUE_BEAN));

	

	//쥬
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 125, 9320, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 125, 9340, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 125, 9360, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 125, 9380, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 125, 9400, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 125, 9420, BLUE_BEAN));

	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 145, 9320, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 145, 9340, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 145, 9360, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 145, 9380, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 145, 9400, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 145, 9420, BLUE_BEAN));

	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 165, 9360, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 165, 9380, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 185, 9360, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 185, 9380, BLUE_BEAN));

	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 205, 9340, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 205, 9360, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 205, 9380, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 205, 9400, BLUE_BEAN));

	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 225, 9320, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 225, 9340, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 245, 9320, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 245, 9340, BLUE_BEAN));

	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 225, 9400, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 225, 9420, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 245, 9400, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 245, 9420, BLUE_BEAN));
	
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 285, 9300, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 285, 9320, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 285, 9340, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 285, 9360, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 285, 9380, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 285, 9400, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 285, 9420, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 285, 9440, BLUE_BEAN));

	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 305, 9300, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 305, 9320, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 305, 9340, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 305, 9360, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 305, 9380, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 305, 9400, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 305, 9420, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 305, 9440, BLUE_BEAN));

	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 325, 9320, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 325, 9340, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 345, 9320, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 345, 9340, BLUE_BEAN));

	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 325, 9400, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 325, 9420, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 345, 9400, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 345, 9420, BLUE_BEAN));

	//신
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 165, 9780, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 165, 9800, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 165, 9880, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 165, 9900, BLUE_BEAN));

	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 185, 9760, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 185, 9780, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 185, 9880, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 185, 9900, BLUE_BEAN));

	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 205, 9740, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 205, 9760, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 205, 9780, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 205, 9800, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 205, 9880, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 205, 9900, BLUE_BEAN));

	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 225, 9720, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 225, 9740, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 225, 9800, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 225, 9820, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 225, 9880, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 225, 9900, BLUE_BEAN));

	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 245, 9700, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 245, 9720, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 245, 9820, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 245, 9840, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 245, 9880, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 245, 9900, BLUE_BEAN));

	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 265, 9700, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 265, 9720, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 265, 9880, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 265, 9900, BLUE_BEAN));

	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 285, 9700, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 285, 9720, BLUE_BEAN));

	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 305, 9700, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 305, 9720, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 305, 9740, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 305, 9760, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 305, 9780, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 305, 9800, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 305, 9820, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 305, 9840, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 305, 9860, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 305, 9880, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 305, 9900, BLUE_BEAN));

	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 325, 9700, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 325, 9720, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 325, 9740, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 325, 9760, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 325, 9780, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 325, 9800, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 325, 9820, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 325, 9840, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 325, 9860, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 325, 9880, BLUE_BEAN));
	m_JellyList.push_back(SPAWN_JELLY_INFO(1200, 325, 9900, BLUE_BEAN));


}
void CSpawnManager::SpawnFloor()
{	
	const OBJLIST* object = CObjectMgr::GetInstance()->GetObjectList(OBJECT_TYPE::OBJECT_FLOOR);
	OBJLIST::const_iterator iter_begin = object->begin();
	OBJLIST::const_iterator iter_end = object->end();
	if (object->size() < 20)
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


