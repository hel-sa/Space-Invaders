#pragma once
#include "player.h"
#include "invader.h"
#include "vector"
#include "bullet.h"
#include "bomb.h"
#include <iostream>

class Game
{



	Player* player = nullptr;
	bool player_initialized = false;
	Player* player1 = nullptr;
	Invader* inv = nullptr;
	bool inv_initialized = false;
	Bullet* bullet = nullptr;
	bool bullet_initialized = false;
	Bomb* bomb = nullptr;
	bool bomb_initialized = false;


public:
	typedef enum { STATUS_START, STATUS_PLAYING, STATUS_OVER, STATUS_WIN }  status_t;

	status_t status = STATUS_START;

	void updateStartScreen();
	void updateGameScreen();
	void updateGameOverScreen();
	void updateWinScreen();
	void drawStartScreen();
	void drawGameScreen();
	void drawGameOverScreen();
	void drawWinScreen();



	float inv_position_x = 50.0f;
	float inv_position_y = 50.0f;
	float inv_speed = 0.5f;


	int score = 0;
	int count = 0;
	int vic = 0;
	int loose = 0;
	int level = 0;
	int mode = 0;//0 for solo,1 for multy
	int over = 0;
	int highscore = 0;

	float bomb_speed = 5.0f;
	float bomb_y = 5.0f;
	float bomb_timer = 400;
	bool bomb_alive = false;
	int bomb_r_temp;

	bool right = true;
	std::vector<Invader*>B; //big
	std::vector<Invader*>M; //medium
	std::vector<Invader*>S; //small

	void update();
	void draw();
	void init();
	Game();
	~Game();
};