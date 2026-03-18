#include "Fruit.h"
#include "DxLib.h"
#include "Stage.h"
#include "Player.h"

/// <summary>
/// M.Shoji
/// 果物についての管理はここ
/// </summary>

Fruit::Fruit()
{
}

Fruit::Fruit(int x, int y)
    :x(x),y(y)
{
}

void Fruit::Update(const Stage& stage)
{
    if (collected)
    {
        return;
    }

    //最大落下速度
    const float MAX_FALL_SPEED = 10.0f;
    //重力を与える
    vy += 0.3f;

    if (vy > MAX_FALL_SPEED)
    {
        vy = MAX_FALL_SPEED;
    }

    y += vy;

    //地面に当たったら止める
    if (stage.IsOnGround(x - radius,y, radius * 2))
    {
        y = stage.GetGroundY() - radius;
        vy = 0;
    }
}

void Fruit::Draw() const
{
    if (collected)
    {
        return;
    }
    DrawCircle(x, y, radius, GetColor(255, 100, 100), TRUE);
}

bool Fruit::IsCollected() const
{
    return collected;
}

bool Fruit::CheckHit(const Player& player)
{
    if (collected)
    {
        return false;
    }

    //当たり判定（簡易版）
    if (x > player.Left() && x<player.Right() && y>player.Top() && y < player.Bottom())
    {
        collected = true;
        return true;
    }

    return false;
}
