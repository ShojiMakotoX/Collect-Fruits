#pragma once
#include "../Library/SceneBase.h"
#include "Stage.h"
#include "Fruit.h"


/// <summary>
/// ゲームプレイのシーンを制御する
/// </summary>
class PlayScene : public SceneBase
{
public:
	PlayScene();
	~PlayScene();
	void Update() override;
	void Draw() override;

private:
	Stage stage;
	Fruit fruit;
};
