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
    //”wŒi
    DrawBox(0, 0, WIDTH, HEIGHT, GetColor(30, 30, 30), TRUE);

    //¶‚ÌŒŠ
    DrawBox(0, 0, GROUND_LEFT, HEIGHT, GetColor(60, 60, 60), TRUE);

    //’n–Ê
    DrawBox(GROUND_LEFT, 0, GROUND_RIGHT, HEIGHT, GetColor(100, 180, 100), TRUE);


    //‰E‚ÌŒŠ
    DrawBox(GROUND_RIGHT, 0, WIDTH, HEIGHT, GetColor(60, 60, 60), TRUE);

    player.Draw();

}

bool Stage::IsOnGround(int playerX, int playerW) const
{
    return(playerX >= GROUND_LEFT) && (playerX + playerW <= GROUND_RIGHT);
}
