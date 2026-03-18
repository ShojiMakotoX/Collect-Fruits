#pragma once
#include "Player.h"

class Stage
{
public:
	Stage();
	~Stage();

	void Update();
	void Draw() const;

	bool IsOnGround(int playerX,int playerY, int playerW)const;

	//ステージサイズ
	static constexpr int WIDTH = 1300;
	static constexpr int HEIGHT = 800;

	//地面・穴の構造
	static constexpr int HOLE_WIDTH = 250;//穴の幅
	static constexpr int GROUND_LEFT = HOLE_WIDTH;
	static constexpr int GROUND_RIGHT = WIDTH - HOLE_WIDTH;
	static constexpr int GROUND_Y = 540;//地面の高さ

	int GetLeft() const { return GROUND_LEFT; }
	int GetRight() const { return GROUND_RIGHT; }
	int GetGroundY() const { return GROUND_Y; }

private:
	Player player;

};
