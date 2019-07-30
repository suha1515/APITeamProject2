#pragma once
class CSpawnManager
{
public:
	CSpawnManager();
	~CSpawnManager();
public:
	void SpawnFloor();
	void Initialize();

private:
	int m_FloorRate;
	int m_FloorCount;

	INFO m_PrevPos;
	POSi m_PreFloorPos;
	int* PrevFloorPos;
};

