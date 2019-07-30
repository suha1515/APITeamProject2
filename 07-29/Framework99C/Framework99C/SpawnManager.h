#pragma once
class CSpawnManager
{
public:
	CSpawnManager();
	~CSpawnManager();
public:
	void SpawnFloor();
	void SpawnJelly();
	void Initialize();

private:
	int m_FloorRate;
	int m_FloorCount;

	int m_InitPosX;
	int m_InitPosY;
};

