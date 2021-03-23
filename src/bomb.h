#pragma once
#pragma once
#include <iostream>
#include "gameobject.h"
#include "config.h"


class Bomb : public GameObject
{
public:
	Bomb(const class Game& mygame);

	float bomb_speed = 10.0f;
	float bomb_y = 5.0f;
	float bomb_timer = 400;
	bool bomb_alive = false;
	int bomb_r_temp = 0;
	float temp_pos_x = 0.0;
	float temp_pos_y = 0.0;
	float player_center_y = 708;
	float player_center_x = CANVAS_WIDTH / 2;
	float player_center_x1 = (CANVAS_WIDTH / 2) + 285;
	float player_center_y1 = 708;
	float speed = 8.0f;
	int hit_p = 0;
	bool temp_sp = false;

	void update() override;
	void draw() override;
	void init() override;
};