#pragma once

// ���� ���� ������Ʈ�� �����ϴ� ������

// ������ ���� (�޵����� ����)
// M : N ���� ��ȣ ���⼺�� M : 1�� ���ߴ� ������ ����. 
// ��� ������Ʈ���� ���θ� ���� �����ڸ� �˸� ��ȣ�ۿ� ó���� �� �ִ�.

class CGameObject;
class CObjectMgr
{
private:
	CObjectMgr();
	~CObjectMgr();
	
public:
	CGameObject* GetPlayer() const;
	CGameObject* GetMouse() const;
	CGameObject* GetBackGround() const;
	CGameObject* GetNearTarget(CGameObject* pSrc, OBJECT_TYPE eType);
	const OBJLIST* GetObjectList(OBJECT_TYPE type);

public:
	void AddObject(OBJECT_TYPE eType, CGameObject* pObject);
	void Update();
	void Render(HDC hDC);
	
private:
	void Release();

private:
	OBJLIST	m_ObjLst[OBJECT_END];

public:
	static CObjectMgr* GetInstance()
	{
		if (nullptr == m_pInstance)
			m_pInstance = new CObjectMgr;

		return m_pInstance;
	}

	void DestroyInstance()
	{
		if (m_pInstance)
		{
			delete m_pInstance;
			m_pInstance = nullptr;
		}
	}

private:
	static CObjectMgr* m_pInstance;
};

