#pragma once
#include "DxLib.h"

class Stage;

class Player
{
public:
	Player();
	~Player();

	void Initialize();
	void Update(const Stage& stage);
	void Draw() const;

	//“–‚½‚è”»’è—p‚Ì‚â‚Â
	int Left() const;
	int Top() const;
	int Right() const;
	int Bottom() const;

private:
	float PlayerX;
	float PlayerY;
	int PlayerW;
	int PlayerH;

	float moveX;
	float moveY;

	int PlayerColor = GetColor(255, 0, 0);

	float speed;
};
