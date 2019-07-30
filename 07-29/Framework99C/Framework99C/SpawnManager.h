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
};

