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
			// 두 사각형의 충돌을 검사하는 API 함수
			if (IntersectRect(&rc, &(pDest->GetRect()), &(pSource->GetRect())))
			{
				pSource->SetDamage(10);

				pSource->SetTime(GetTickCount()); //충돌확인 이전, 충돌되자마자 시간값 얻어오기

				pSource->SetGraceChk(true); //충돌했다고 알려준다.
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
			// 두 사각형의 충돌을 검사하는 API 함수
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

				if (fMoveX > fMoveY) // 파고든 깊이가 짧은 쪽으로 밀어낼 것.
				{
					// Y축 밀어내기
					if (pDest->GetInfo().fY > fY)
					{
						// 위로 밀어낼 것.						
						pSource->SetPos(fX, fY - fMoveY);
					}
					else
						pSource->SetPos(fX, fY + fMoveY);
				}
				else
				{
					// X축 밀어내기
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
		//x축에 대하여 겹치는지 체크.
		if (dstRect.right - srcRect.left > 0 && srcRect.right - dstRect.left>0)
		{
			//y축에 대하여 겹치는지 체크.
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
	// 두 사각형의 X축 가로 반지름 합	
	float fRadiusX = pDest->GetInfo().fCX * 0.5f + pSource->GetInfo().fCX * 0.5f;

	// 두 사각형의 X축 거리를 절대 값으로 구함.
	// fabs(X): X의 절대 값을 구하는 함수. <math.h>에서 제공.
	float fDistX = fabs(pDest->GetInfo().fX - pSource->GetInfo().fX);

	// 두 사각형의 Y축 세로 반지름 합.
	float fRadiusY = pDest->GetInfo().fCY * 0.5f + pSource->GetInfo().fCY * 0.5f;

	// 두 사각형의 Y축 거리
	float fDistY = fabs(pDest->GetInfo().fY - pSource->GetInfo().fY);

	if (fRadiusX >= fDistX && fRadiusY >= fDistY)
	{
		// 파고든 x, y 깊이
		*pMoveX = fRadiusX - fDistX;
		*pMoveY = fRadiusY - fDistY;

		return true;
	}

	return false;
}

bool CCollsionMgr::CheckSphere(const CGameObject* pDest, const CGameObject* pSource)
{
	// 반지름 합
	float fSumRad = pDest->GetInfo().fCX * 0.5f + pSource->GetInfo().fCX * 0.5f;

	// 중점 간 거리
	float w = pDest->GetInfo().fX - pSource->GetInfo().fX;
	float h = pDest->GetInfo().fY - pSource->GetInfo().fY;

	// 피타고라스	
	float d = sqrtf(w * w + h * h);	

	return d <= fSumRad;
}
