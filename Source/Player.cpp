#include "Player.h"
#include "DxLib.h"
#include "Time.h"

Player::Player()
{
    Initlaize();
}

Player::~Player()
{
}

void Player::Initlaize()
{
    PlayerX = 380;
    PlayerY = 500;
    PlayerW = 40;
    PlayerH = 40;
    
    speed = 300.0f;

}

void Player::Update()
{
    if (CheckHitKey(KEY_INPUT_A))
    {
        moveX -= 1.0f;
    }
    if (CheckHitKey(KEY_INPUT_D))
    {
        moveX += 1.0f;
    }
    
    PlayerX += static_cast<int>(moveX * speed * Time::DeltaTime());

    if (PlayerX < 0)
    {
        PlayerX = 0;
    }

}

void Player::Draw()
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
