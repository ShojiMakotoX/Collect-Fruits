#include "Player.h"
#include "DxLib.h"
#include "Stage.h"
#include "../Library/Time.h"

Player::Player()
{
    Initialize();
}

Player::~Player()
{
}

void Player::Initialize()
{
    PlayerX = 400;
    PlayerY = 500;
    PlayerW = 40;
    PlayerH = 40;
    
    speed = 300.0f;

    StageLeft = 250;
    StageRight = 1050;

}

void Player::Update(const Stage& stage)
{
    moveX = 0.0f;

    if (CheckHitKey(KEY_INPUT_A))
    {
        moveX -= 1.0f;
    }
    if (CheckHitKey(KEY_INPUT_D))
    {
        moveX += 1.0f;
    }
    
    PlayerX += static_cast<int>(moveX * speed * Time::DeltaTime());

    if (PlayerX <StageLeft)
    {
        PlayerX = StageLeft;
    }
    if (PlayerX + PlayerW > StageRight)
    {
        PlayerX = 1050 - StageRight;
    }

}

void Player::Draw() const
{
    DrawBox(PlayerX, PlayerY, PlayerX + PlayerW, PlayerY + PlayerH, PlayerColor, TRUE);
}

int Player::Left() const
{
    return PlayerX;
}

int Player::Top() const
{
    return PlayerY;
}

int Player::Right() const
{
    return PlayerX + PlayerW;
}

int Player::Bottom() const
{
    return PlayerY + PlayerH;
}
