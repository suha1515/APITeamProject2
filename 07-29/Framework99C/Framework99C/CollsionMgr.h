#pragma once
class CCollsionMgr
{
	DECLARE_SINGLE_TONE(CCollsionMgr)
private:
	void Initialize();

public:
	//ÄíÅ°·±
	static void CollisionImpe(const OBJLIST& dstLst, const OBJLIST& srcLst);
	static void CollisionShelf(const OBJLIST& dstLst, const OBJLIST& srcLst);


	static void CollisionRectEX(const OBJLIST& dstLst, const OBJLIST& srcLst);
	static void CollisionSphere(const OBJLIST& dstLst, const OBJLIST& srcLst);
	CGameObject* CollisionRectReturn(const CGameObject* pDst, OBJECT_TYPE type);
private:
	static bool CheckRect(const CGameObject* pDest, const CGameObject* pSource, float* pMoveX, float* pMoveY);
	static bool CheckSphere(const CGameObject* pDest, const CGameObject* pSource);
};

