#include "stdafx.h"
#include "StageManager.h"

DEFINE_SINGLE_TONE(CStageManager)

void CStageManager::Initialize()
{
	CurrentScene = STAGE1;
	PreviousScene = CurrentScene;

	IsSceneChange = false;
}

void CStageManager::Update()
{

}
