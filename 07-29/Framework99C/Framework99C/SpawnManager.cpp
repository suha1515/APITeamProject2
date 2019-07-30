#include "stdafx.h"
#include "SpawnManager.h"
#include "Floor.h"
#include "Item.h"


CSpawnManager::CSpawnManager()
{
}


CSpawnManager::~CSpawnManager()
{
}
void CSpawnManager::Initialize()
{

}
void CSpawnManager::SpawnFloor()
{	
	const OBJLIST* object = CObjectMgr::GetInstance()->GetObjectList(OBJECT_TYPE::OBJECT_FLOOR);
	OBJLIST::const_iterator iter_begin = object->begin();
	OBJLIST::const_iterator iter_end = object->end();
	if (object->size() < 17)
	{
		if (iter_begin == iter_end)
		{
			CGameObject* pGameObject = CAbstractFactory<CFloor>::CreateObject();
			pGameObject->SetPos(50, 470);
			CObjectMgr::GetInstance()->AddObject(OBJECT_FLOOR, pGameObject);
			
		}
		else
		{
			CGameObject* pGameObject = CAbstractFactory<CFloor>::CreateObject();
			pGameObject->SetPos(object->back()->GetInfo().fX + 100, 470);
			CObjectMgr::GetInstance()->AddObject(OBJECT_FLOOR, pGameObject);
			
		}
	}
	//cout << m_FloorCount << endl;
}

void CSpawnManager::SpawnJelly()
{
	const OBJLIST* object = CObjectMgr::GetInstance()->GetObjectList(OBJECT_TYPE::OBJECT_ITEM);
	OBJLIST::const_iterator iter_begin = object->begin();
	OBJLIST::const_iterator iter_end = object->end();
	if (object->size() < 40)
	{
		if (iter_begin == iter_end)
		{
			CGameObject* pGameObject = CAbstractFactory<CItem>::CreateObject();
			pGameObject->SetPos(1000, 300);
			dynamic_cast<CItem*>(pGameObject)->SetItemType(ITEM_TYPE::ITEM_JELLY, JELLY_TYPE::BLUE_BEAN);
			CObjectMgr::GetInstance()->AddObject(OBJECT_ITEM, pGameObject);

		}
		else
		{
			CGameObject* pGameObject = CAbstractFactory<CItem>::CreateObject();
			pGameObject->SetPos(object->back()->GetInfo().fX +30, 300);
			dynamic_cast<CItem*>(pGameObject)->SetItemType(ITEM_TYPE::ITEM_JELLY, JELLY_TYPE::BLUE_BEAN);
			CObjectMgr::GetInstance()->AddObject(OBJECT_ITEM, pGameObject);

		}
	}
}


