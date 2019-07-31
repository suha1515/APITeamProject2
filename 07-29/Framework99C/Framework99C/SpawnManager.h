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
	list<SPAWN_OBSTACLE_INFO>	m_ObstacleList;	//��ֹ� ��������
	list<SPAWN_ITEM_INFO>		m_ItemList;		//������ ��������
	list<SPAWN_FLOOR_INFO>		m_FloorList;	//�ٴ� ��������
	list<SPAWN_JELLY_INFO>		m_JellyList;	//���� ��������
public:
	float						m_StageDist;
};

