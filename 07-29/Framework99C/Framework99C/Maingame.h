#pragma once

class CGameObject;
class UIManager;
class CMaingame
{
public:
	CMaingame();
	~CMaingame();

public:
	void Initialize();
	void Update();
	void Render();

private:
	void Release();

private:
	HDC		m_hDC;	
	
	HBITMAP m_back;
	CGameObject* m_pPlayer;
	


	int test = 0;
	CSpawnManager* m_SpawnManager;

};

