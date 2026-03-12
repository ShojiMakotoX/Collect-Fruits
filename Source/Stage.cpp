#include "Stage.h"
#include "DxLib.h"

Stage::Stage()
{
}

Stage::~Stage()
{
}

void Stage::Update()
{
    player.Update(*this);
}

void Stage::Draw() const
{


    //背景
    DrawBox(0, 0, WIDTH, HEIGHT, GetColor(30, 30, 30), TRUE);

    //左の穴
    DrawBox(0, 0, GROUND_LEFT, HEIGHT, GetColor(60, 60, 60), TRUE);

    //地面
    DrawBox(GROUND_LEFT, 0, GROUND_RIGHT, HEIGHT, GetColor(100, 180, 100), TRUE);
    DrawBox(GROUND_LEFT, 540, GROUND_RIGHT, HEIGHT, GetColor(141, 100, 73), TRUE);

    //右の穴
    DrawBox(GROUND_RIGHT, 0, WIDTH, HEIGHT, GetColor(60, 60, 60), TRUE);

    int footY = player.Bottom();

    //プレイヤーの影を取り入れてみる
    DrawBox(player.Left(), footY, player.Right(), footY + 10, GetColor(125, 125, 125), TRUE);

    //プレイヤー
    player.Draw();

}

bool Stage::IsOnGround(int playerX, int playerW) const
{
    return(playerX >= GROUND_LEFT) && (playerX + playerW <= GROUND_RIGHT);
}
