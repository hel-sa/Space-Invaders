#pragma once
#include <iostream>
#include "gameobject.h"
#include "config.h"
#include "player.h"
#include "invader.h"

class Bullet : public GameObject
{
public:
	Bullet(const class Game& mygame);

	//all var names that ends with 1 are for the sec player

	float bullet_center_y = 10;
	float player_center_y = 708;
	float player_center_x = CANVAS_WIDTH / 2;
	float player_center_x1 = (CANVAS_WIDTH / 2) + 285;
	float player_center_y1 = 708;
	float bullet_center_y1 = 10;

	float bullet_speed = 15.0f;
	float speed = 10.0;
	float temp_player_center_x = CANVAS_WIDTH / 2;
	float temp_player_center_x1 = (CANVAS_WIDTH / 2) + 285;
	int hit = 0;
	int hit1 = 0;
	int hit_p = 0;
	int hit_p1 = 0;
	int flag = 0;
	int flag1 = 0;
	int bulltimer = 0;
	float bullet_width = 5.0f;
	float bullet_height = 16.0f;



	void update() override;
	void draw() override;
	void init() override;
};