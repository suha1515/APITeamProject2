#pragma once

class CGameObject;
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
	
	int scr_x = 0;
	int scr_y = 0;

	int test = 0;
	CSpawnManager* m_SpawnManager;
};

