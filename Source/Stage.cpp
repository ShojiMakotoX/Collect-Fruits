#include "Stage.h"
#include "DxLib.h"
#include "Fruit.h"
#include "Player.h"
/// <summary>
/// M.Shoji
/// ゲームの全体を管理するのはここ
/// </summary>

Stage::Stage()
{
}

Stage::~Stage()
{
}

void Stage::Update()
{
    player.Update(*this);
    fruit.Update(*this);

    fruit.CheckHit(player);//果物回収
}

void Stage::Draw() const
{


    //背景
    DrawBox(0, 0, WIDTH, HEIGHT, GetColor(30, 30, 30), TRUE);

    //左の穴
    DrawBox(0, 0, GROUND_LEFT, HEIGHT, GetColor(60, 60, 60), TRUE);

    //地面
    DrawBox(GROUND_LEFT, 0, GROUND_RIGHT, HEIGHT, GetColor(100, 180, 100), TRUE);
    DrawBox(GROUND_LEFT, GROUND_Y, GROUND_RIGHT, HEIGHT, GetColor(140, 105, 70), TRUE);

    //右の穴
    DrawBox(GROUND_RIGHT, 0, WIDTH, HEIGHT, GetColor(60, 60, 60), TRUE);

    int footY = player.Bottom();

    //プレイヤーの影を取り入れてみる
    SetDrawBlendMode(DX_BLENDMODE_ALPHA, 120);
    DrawBox(player.Left(), footY, player.Right(), footY + 10, GetColor(90, 65, 45), TRUE);
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);


    fruit.Draw();
    //プレイヤー
    player.Draw();

}

bool Stage::IsOnGround(int playerX,int playerY, int playerW) const
{
    if (playerX <GROUND_LEFT || playerX + playerW> GROUND_RIGHT)
    {
        return false;
    }
    return playerY >= GROUND_Y;
   
}
