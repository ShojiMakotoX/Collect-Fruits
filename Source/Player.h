#pragma once
#include "DxLib.h"

class Player
{
public:
	Player();
	~Player();

	void Initlaize();
	void Update();
	void Draw();

	//“–‚½‚è”»’è—p‚Ì‚â‚Â
	int Left() const;
	int Top() const;
	int Right() const;
	int Bottom() const;

private:
	int PlayerX;
	int PlayerY;
	int PlayerW;
	int PlayerH;

	float moveX;
	float moveY;

	int PlayerColor = GetColor(255, 0, 0);

	float speed;
};
