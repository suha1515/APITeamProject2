#pragma once

//BackDC 라는 extern 변수 필요
//미리 컴파일된 헤더에 time.h 필요


class CBit;
class BitManager
{
public:
	static BitManager* GetInstance() {
		static BitManager* im = new BitManager;
		return im;
	}

	void Initialize();

	//배경 자동이동 게임에 대한 오토 함수, (배경 인덱스  , 배경돌리는 스피드)
	void Auto_BackGround_W(int index = 0, int speed = 2);
	void Auto_BackGround_H(int index = 0,int speed = 2);

	//배경이동에 대한 수동 출력함수 배경그림의 좌표를 랜더좌표 0,0에 찍어주는 함수이다.
	//(예시) x를 증가시키면 오른쪽으로 가는 느낌
	//(예시2) y를 증가시키면 밑으로 가는 느낌 
	//단, WINCX,WINCY보다 배경그림이 더 커야한다.
	void Manual_BackGround(int index, int nX, int nY,int frame = 0, int frameMax =0 );

	//비트맵의 배경을 지우는 색상값 설정함수이다.(Init에서 호출한다)
	void SET_RGB(int R, int G, int B);
	int Get_RGB(int i);

	//리소스 ID로 그림을 넣는 함수들 (Init안에다가 작성) 
	void Push_BG(int ID, int Width, int Height, int MaxFraim = 1);
	void Push_Obj(int ID, int Width, int Height, int MaxFraim = 1);
	void Push_Item(int ID, int Width, int Height, int MaxFraim = 1);
	void Push_Effect(int ID, int Width, int Height, int MaxFraim = 1);
	void Push_Player(int ID, int Width, int Height, int MaxFraim = 1);
	void Push_Number(int ID, int Width, int Height, int MaxFraim = 1);

	//경로로 그림을 넣는 함수들(Init안에다가 작성)
	void Push_BG(const wstring& Path, int Width, int Height, int MaxFraim = 1);
	void Push_Obj(const wstring& Path, int Width, int Height, int MaxFraim = 1);
	void Push_Item(const wstring& Path, int Width, int Height, int MaxFraim = 1);
	void Push_Effect(const wstring& Path, int Width, int Height, int MaxFraim = 1);
	void Push_Player(const wstring& Path, int Width, int Height, int MaxFraim = 1);
	void Push_Number(const wstring& Path, int Width, int Height, int MaxFraim = 1);;

	//그림 배열을 가져다가 사용할 수 있는 함수들
	vector<CBit*>& Pop_Back();
	vector<CBit*>& Pop_Mon();
	vector<CBit*>& Pop_Bul();
	vector<CBit*>& Pop_Eff();
	vector<CBit*>& Pop_Player();
	vector<CBit*>& Pop_Number();

	//단일 그림을 출력한다. 인덱스에 해당하는 그림을  좌표 (x,y)에 출력한다.
	//0729 부로 단일함수도 배경을 지운다. RGB 설정은 BIT.h 멤버변수 초기화에서 한다.
	void PopS_BG(int index, int x, int y);
	void PopS_Obj(int index, int x, int y);
	void PopS_Item(int index, int x, int y);
	void PopS_Effect(int index, int x, int y);
	void PopS_Player(int index, int x, int y);
	void PopS_Number(int index, int x, int y);

	//스프라이의 그림중  출력한다. 인덱스에 해당하는 그림을  좌표 (x,y)에 출력한다.
	//RGB설정은 BIT.h 멤버변수 초기화로한다. 
	//오브젝트에 m_index 변수를 돌리고 indextimer를 오브젝트가 가지고있도록 한다.
	//(예시) 
	//PopM_Mon(0,0,0,m_index,5);
	//IndexTimer(5,200); 
	//위 두줄로 5장이 0.2초마다 돌아간다.
	void PopM_BG(int index, int x, int y, int Frame_Index, int FrameMax);
	void PopM_Obj(int index, int x, int y, int Frame_Index, int FrameMax);
	void PopM_Item(int index, int x, int y, int Frame_Index, int FrameMax);
	void PopM_Effect(int index, int x, int y, int Frame_Index, int FrameMax);
	void PopM_Player(int index, int x, int y, int Frame_Index, int FrameMax);
	void PopM_Number(int index, int x, int y, int Frame_Index, int FrameMax);



	//사용법 : PopA_Back(1(번호), 100,100, this, 전환속도(생략가능));
	void PopA_BG(int index, int x, int y, CGameObject* co, clock_t time = 150);
	void PopA_Obj(int index, int x, int y, CGameObject* co, clock_t time = 150);
	void PopA_Item(int index, int x, int y, CGameObject* co, clock_t time = 150);
	void PopA_Effect(int index, int x, int y, CGameObject* co, clock_t time = 150);
	void PopA_Player(int index, int x, int y, CGameObject* co, clock_t time = 150);
	void PopA_Once(int index, int x, int y, CGameObject* co, clock_t time = 150);
	void PopA_Number(int index, int x, int y, CGameObject* co, clock_t time = 150);

	
private:
	vector<CBit*> BG;
	vector<CBit*> Obj;
	vector<CBit*> Item;
	vector<CBit*> Effect;
	vector<CBit*> Player;
	vector<CBit*> Number;
	//vector<CBIT*> ITEM;
	//vector<CBIT*> ETC;


	int RGB[3];
};