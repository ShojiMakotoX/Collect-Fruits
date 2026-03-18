#pragma once

class Stage;
class Player;

class Fruit
{
public:
	Fruit();
	Fruit(int x, int y);
	void Update(const Stage& stage);
	void Draw()const;

	bool IsCollected()const;
	bool CheckHit(const Player& player);

private:
	int x;
	int y;
	int radius = 10;
	float vy = 0.0f;

	bool collected = false;
};
