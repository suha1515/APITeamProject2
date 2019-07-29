#pragma once

class CBit;
class ImageManager
{
public:
	
	static ImageManager* ROAD();

	void Init();
	void Auto_BackGround();

	void Push_Back(int ID, int Width, int Height);
	void Push_Eff(int ID, int Width, int Height);
	void Push_Player(int ID, int Width, int Height);
	void Push_Object(int ID, int Width, int Height);
	void Push_Item(int ID, int Width, int Height);

	vector<CBit*>& Pop_BackGround();
	vector<CBit*>& Pop_Player();
	vector<CBit*>& Pop_Object();
	vector<CBit*>& Pop_Item();
	vector<CBit*>& Pop_Effect();

	void PopS_Background(int index, int x, int y);
	void PopS_Player(int index, int x, int y);
	void PopS_Object(int index, int x, int y);
	void PopS_Item(int index, int x, int y);
	void PopS_Effect(int index, int x, int y);

	void PopM_Background(int index, int x, int y, int Frame, int FrameMax);
	void PopM_Player(int index, int x, int y, int Frame, int FrameMax);
	void PopM_Object(int index, int x, int y, int Frame, int FrameMax);
	void PopM_Item(int index, int x, int y, int Frame, int FrameMax);
	void PopM_Effect(int index, int x, int y, int Frame, int FrameMax);


private:
	vector<CBit*>	BackGround;
	vector<CBit*>	Player;
	vector<CBit*>	Object;
	vector<CBit*>	Item;
	vector<CBit*>	Effect;
};

