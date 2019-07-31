#pragma once
class CSpawnManager
{
public:
	CSpawnManager();
	~CSpawnManager();
public:
	void SpawnFloor();
	void SpwanHangFloor();
	void SpawnJelly();
	void SpawnObstacle();
	void Initialize();


private:
	int m_FloorRate;
	int m_FloorCount;

	int m_InitPosX;
	int m_InitPosY;

private:
	list<SPAWN_OBSTACLE_INFO>	m_ObstacleList;	//장애물 스폰정보
	list<SPAWN_ITEM_INFO>		m_ItemList;		//아이템 스폰정보
	list<SPAWN_FLOOR_INFO>		m_FloorList;	//바닥 스폰정보
	list<SPAWN_JELLY_INFO>		m_JellyList;	//젤리 스폰정보
public:
	float						m_StageDist;
};

