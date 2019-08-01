#include "stdafx.h"
#include "CollsionMgr.h"
#include "GameObject.h"
#include "Player.h"

DEFINE_SINGLE_TONE(CCollsionMgr)
void CCollsionMgr::Initialize(){}

void CCollsionMgr::CollisionImpe(const OBJLIST& dstLst, const OBJLIST& srcLst)
{
	RECT rc = {};

	for (auto& pDest : dstLst)
	{
		for (auto& pSource : srcLst)
		{
			// BOOL IntersectRect(RECT* pOut, const RECT* pIn1, const RECT* pIn2)
			// �� �簢���� �浹�� �˻��ϴ� API �Լ�
			if (IntersectRect(&rc, &(pDest->GetRect()), &(pSource->GetRect())))
			{
				pSource->SetDamage(10);

				pSource->SetTime(GetTickCount()); //�浹Ȯ�� ����, �浹���ڸ��� �ð��� ������

				pSource->SetGraceChk(true); //�浹�ߴٰ� �˷��ش�.
			}
		}
	}
}

void CCollsionMgr::CollisionShelf(const OBJLIST & dstLst, const OBJLIST & srcLst)
{
	RECT rc = {};

	float fJumpForce = 13.f;
	float fJumpAcc = 0.f;
	float fChangeY = 0.f;
	bool bShelfChk = true;

	for (auto& pDest : dstLst)
	{
		for (auto& pSource : srcLst)
		{
			// BOOL IntersectRect(RECT* pOut, const RECT* pIn1, const RECT* pIn2)
			// �� �簢���� �浹�� �˻��ϴ� API �Լ�
			if (IntersectRect(&rc, &(pDest->GetRect()), &(pSource->GetRect())))
			{
				bShelfChk = true;

					if (dynamic_cast<CPlayer*>(pSource)->bIsJumpChk())
					{
						dynamic_cast<CPlayer*>(pSource)->IsJump();
							if(pSource->GetInfo().fY > pDest->GetInfo().fY)
								pSource->SetY(pDest->GetInfo().fY - (pSource->GetInfo().fCY*0.5f));
					}
					else
					{
						pSource->SetY(pDest->GetInfo().fY - (pSource->GetInfo().fCY*0.5f));
					}
			}
			else
			{
				if (bShelfChk && pSource->GetInfo().fY > pDest->GetInfo().fY)
				{
					dynamic_cast<CPlayer*>(pSource)->SetDownChk(true);
				}

				bShelfChk = false;
			}
		}
	}
}

void CCollsionMgr::CollisionRectEX(const OBJLIST& dstLst, const OBJLIST& srcLst)
{
	float fMoveX = 0.f, fMoveY = 0.f;

	for (auto& pDest : dstLst)
	{
		for (auto& pSource : srcLst)
		{			
			if (CheckRect(pDest, pSource, &fMoveX, &fMoveY))
			{
				float fX = pSource->GetInfo().fX;
				float fY = pSource->GetInfo().fY;

				if (fMoveX > fMoveY) // �İ�� ���̰� ª�� ������ �о ��.
				{
					// Y�� �о��
					if (pDest->GetInfo().fY > fY)
					{
						// ���� �о ��.						
						pSource->SetPos(fX, fY - fMoveY);
					}
					else
						pSource->SetPos(fX, fY + fMoveY);
				}
				else
				{
					// X�� �о��
					if (pDest->GetInfo().fX > fX)
						pSource->SetPos(fX - fMoveX, fY);
					else
						pSource->SetPos(fX + fMoveX, fY);
				}
			}
		}
	}
}

void CCollsionMgr::CollisionSphere(const OBJLIST& dstLst, const OBJLIST& srcLst)
{
	for (auto& pDest : dstLst)
	{
		for (auto& pSource : srcLst)
		{			
			if (CheckSphere(pDest, pSource))
			{
				pDest->SetDead(true);
				pSource->SetDead(true);
			}
		}
	}
}

CGameObject * CCollsionMgr::CollisionRectReturn(const CGameObject * pDst, OBJECT_TYPE type)
{
	RECT dstRect = pDst->GetRect();
	OBJLIST objlst = CObjectMgr::GetInstance()->GetObjectList(type);
	OBJLIST::iterator iter_begin = objlst.begin();
	OBJLIST::iterator iter_end = objlst.end();

	for (; iter_begin != iter_end; ++iter_begin)
	{
		RECT srcRect = (*iter_begin)->GetRect();
		//x�࿡ ���Ͽ� ��ġ���� üũ.
		if (dstRect.right - srcRect.left > 0 && srcRect.right - dstRect.left>0)
		{
			//y�࿡ ���Ͽ� ��ġ���� üũ.
			if (dstRect.bottom - srcRect.top > 0 && srcRect.bottom - dstRect.top>0)
			{
				cout << "hit colider!" << endl;
				return (*iter_begin);
			}
		}
	}
	return nullptr;
}

bool CCollsionMgr::CheckRect(
	const CGameObject* pDest, const CGameObject* pSource, 
	float* pMoveX, float* pMoveY)
{
	// �� �簢���� X�� ���� ������ ��	
	float fRadiusX = pDest->GetInfo().fCX * 0.5f + pSource->GetInfo().fCX * 0.5f;

	// �� �簢���� X�� �Ÿ��� ���� ������ ����.
	// fabs(X): X�� ���� ���� ���ϴ� �Լ�. <math.h>���� ����.
	float fDistX = fabs(pDest->GetInfo().fX - pSource->GetInfo().fX);

	// �� �簢���� Y�� ���� ������ ��.
	float fRadiusY = pDest->GetInfo().fCY * 0.5f + pSource->GetInfo().fCY * 0.5f;

	// �� �簢���� Y�� �Ÿ�
	float fDistY = fabs(pDest->GetInfo().fY - pSource->GetInfo().fY);

	if (fRadiusX >= fDistX && fRadiusY >= fDistY)
	{
		// �İ�� x, y ����
		*pMoveX = fRadiusX - fDistX;
		*pMoveY = fRadiusY - fDistY;

		return true;
	}

	return false;
}

bool CCollsionMgr::CheckSphere(const CGameObject* pDest, const CGameObject* pSource)
{
	// ������ ��
	float fSumRad = pDest->GetInfo().fCX * 0.5f + pSource->GetInfo().fCX * 0.5f;

	// ���� �� �Ÿ�
	float w = pDest->GetInfo().fX - pSource->GetInfo().fX;
	float h = pDest->GetInfo().fY - pSource->GetInfo().fY;

	// ��Ÿ���	
	float d = sqrtf(w * w + h * h);	

	return d <= fSumRad;
}
