#pragma once
#include "Center.h"


class CPlayer;
//ü�¹� �� UI
class UIManager
{
public: 
	static UIManager* ROAD() 
	{
		static UIManager* ui = new UIManager;
		return ui;
	}

public:
	void Initialize();
	void Update();
	void Render(HDC hDC);
	void HP_Bar(HDC hDC); 


		

private:
	HBRUSH brush, obrush;
	UIManager();
	~UIManager();



};

