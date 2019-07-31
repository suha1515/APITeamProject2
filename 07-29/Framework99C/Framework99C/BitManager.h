#pragma once

//BackDC ��� extern ���� �ʿ�
//�̸� �����ϵ� ����� time.h �ʿ�


class CBit;
class BitManager
{
public:
	static BitManager* GetInstance() {
		static BitManager* im = new BitManager;
		return im;
	}

	void Initialize();

	//��� �ڵ��̵� ���ӿ� ���� ���� �Լ�, (��� �ε���  , ��浹���� ���ǵ�)
	void Auto_BackGround_W(int index = 0, int speed = 2);
	void Auto_BackGround_H(int index = 0,int speed = 2);

	//����̵��� ���� ���� ����Լ� ���׸��� ��ǥ�� ������ǥ 0,0�� ����ִ� �Լ��̴�.
	//(����) x�� ������Ű�� ���������� ���� ����
	//(����2) y�� ������Ű�� ������ ���� ���� 
	//��, WINCX,WINCY���� ���׸��� �� Ŀ���Ѵ�.
	void Manual_BackGround(int index, int nX, int nY,int frame = 0, int frameMax =0 );

	//��Ʈ���� ����� ����� ���� �����Լ��̴�.(Init���� ȣ���Ѵ�)
	void SET_RGB(int R, int G, int B);
	int Get_RGB(int i);

	//���ҽ� ID�� �׸��� �ִ� �Լ��� (Init�ȿ��ٰ� �ۼ�) 
	void Push_BG(int ID, int Width, int Height, int MaxFraim = 1);
	void Push_Obj(int ID, int Width, int Height, int MaxFraim = 1);
	void Push_Item(int ID, int Width, int Height, int MaxFraim = 1);
	void Push_Effect(int ID, int Width, int Height, int MaxFraim = 1);
	void Push_Player(int ID, int Width, int Height, int MaxFraim = 1);
	void Push_Number(int ID, int Width, int Height, int MaxFraim = 1);

	//��η� �׸��� �ִ� �Լ���(Init�ȿ��ٰ� �ۼ�)
	void Push_BG(const wstring& Path, int Width, int Height, int MaxFraim = 1);
	void Push_Obj(const wstring& Path, int Width, int Height, int MaxFraim = 1);
	void Push_Item(const wstring& Path, int Width, int Height, int MaxFraim = 1);
	void Push_Effect(const wstring& Path, int Width, int Height, int MaxFraim = 1);
	void Push_Player(const wstring& Path, int Width, int Height, int MaxFraim = 1);
	void Push_Number(const wstring& Path, int Width, int Height, int MaxFraim = 1);;

	//�׸� �迭�� �����ٰ� ����� �� �ִ� �Լ���
	vector<CBit*>& Pop_Back();
	vector<CBit*>& Pop_Mon();
	vector<CBit*>& Pop_Bul();
	vector<CBit*>& Pop_Eff();
	vector<CBit*>& Pop_Player();
	vector<CBit*>& Pop_Number();

	//���� �׸��� ����Ѵ�. �ε����� �ش��ϴ� �׸���  ��ǥ (x,y)�� ����Ѵ�.
	//0729 �η� �����Լ��� ����� �����. RGB ������ BIT.h ������� �ʱ�ȭ���� �Ѵ�.
	void PopS_BG(int index, int x, int y);
	void PopS_Obj(int index, int x, int y);
	void PopS_Item(int index, int x, int y);
	void PopS_Effect(int index, int x, int y);
	void PopS_Player(int index, int x, int y);
	void PopS_Number(int index, int x, int y);

	//���������� �׸���  ����Ѵ�. �ε����� �ش��ϴ� �׸���  ��ǥ (x,y)�� ����Ѵ�.
	//RGB������ BIT.h ������� �ʱ�ȭ���Ѵ�. 
	//������Ʈ�� m_index ������ ������ indextimer�� ������Ʈ�� �������ֵ��� �Ѵ�.
	//(����) 
	//PopM_Mon(0,0,0,m_index,5);
	//IndexTimer(5,200); 
	//�� ���ٷ� 5���� 0.2�ʸ��� ���ư���.
	void PopM_BG(int index, int x, int y, int Frame_Index, int FrameMax);
	void PopM_Obj(int index, int x, int y, int Frame_Index, int FrameMax);
	void PopM_Item(int index, int x, int y, int Frame_Index, int FrameMax);
	void PopM_Effect(int index, int x, int y, int Frame_Index, int FrameMax);
	void PopM_Player(int index, int x, int y, int Frame_Index, int FrameMax);
	void PopM_Number(int index, int x, int y, int Frame_Index, int FrameMax);



	//���� : PopA_Back(1(��ȣ), 100,100, this, ��ȯ�ӵ�(��������));
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