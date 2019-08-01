#pragma once
class CStageManager
{
	DECLARE_SINGLE_TONE(CStageManager)
public:
	void Initialize();
	void Update();
public:
	float						StageProgress=0.0f;

	Scene						CurrentScene;
	Scene						PreviousScene;

	bool						IsSceneChange;
};

