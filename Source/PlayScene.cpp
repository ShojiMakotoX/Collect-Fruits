#include "PlayScene.h"
#include "Player.h"
#include "Stage.h"
#include "Fruit.h"

PlayScene::PlayScene()
	:fruit(300,100)
{
}

PlayScene::~PlayScene()
{
}

void PlayScene::Update()
{

	stage.Update();

	if (CheckHitKey(KEY_INPUT_T)) {
		SceneManager::ChangeScene("TITLE");
	}
}

void PlayScene::Draw()
{
	stage.Draw();

	DrawString(0, 0, "PLAY SCENE", GetColor(255, 255, 255));
	DrawString(100, 400, "Push [T]Key To Title", GetColor(255, 255, 255));
}
