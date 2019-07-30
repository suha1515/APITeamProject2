#pragma once
#include "Center.h"


//체력바 등 UI
class UIManager
{
	static UIManager* ROAD() 
	{
		static UIManager* ui = new UIManager;
		return ui;
	}

public:
	void Update(HDC hDC);
	void HP_Bar(HDC hDC); 
		

private:
	HBRUSH brush, obrush;
	UIManager();
	~UIManager();
};

