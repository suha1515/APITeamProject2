#pragma once
#include "Center.h"
#include "ImageManager.h"

//ü�¹� �� UI
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

