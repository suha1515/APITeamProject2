#pragma once
class CGameObject
{
public:
	CGameObject();
	virtual ~CGameObject();

public:
	const INFO& GetInfo() const;
	const RECT& GetRect() const;

public:
	void SetPos(float x, float y);
	void SetAngle(float fAngle);
	void SetDead(bool bIsDead);

	// virtual
public:
	virtual void Initialize() = 0;
	virtual int Update() = 0;
	virtual void Render(HDC hDC) = 0;

public://������ ���Ǹ� �����Լ���
	int IndexTimer(int frame, clock_t time = 100);
	int IndexTimerOnce(int frame, clock_t time = 100);
	void Set_index(int index);
	void Set_oldtime();

	void Set_Index2(int index2);
	void Set_oldtime2();

	clock_t Get_oldtime();
	clock_t Get_oldtime2();

protected:
	virtual void Release() = 0;

	// 
protected:
	void UpdateRect();

protected:
	INFO	m_tInfo;
	RECT	m_tRect;

	float	m_fSpeed;
	float	m_fAngle;

	bool	m_bIsDead;


	//���� ����
	int		m_index = 0;
	int		m_index2 = 0;
	clock_t m_oldtime = 0;
	clock_t m_oldtime2 = 0;
};

