#pragma once
#include "gameobject.h"
#include "config.h"

class Player : public GameObject
{


public:
	float pos_x = CANVAS_WIDTH / 2;
	float pos_y = 708;
	float pos_x1 = CANVAS_WIDTH / 2 + 285;
	float pos_y1 = 708;
	float player_width = 47.0f;
	float player_height = 30.0f;
	float speed = 8.0f;


	Player(const class Game& mygame);
	void update() override;
	void draw() override;
	void init() override;
};