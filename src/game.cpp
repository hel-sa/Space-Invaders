#include "game.h"
#include "graphics.h"
#include "config.h"
#include "invader.h"
#include "bullet.h"
#include "bomb.h"


void Game::update()
{

	if (status == STATUS_START) {
		updateStartScreen();
	}
	else if (status == STATUS_PLAYING) {

		updateGameScreen();

	}
	else if (status == STATUS_OVER) {
		over++;
		updateGameOverScreen();
		if (over > 0) {
			if (highscore < score)
				highscore = score;
		}
	}
	else {
		over++;
		updateWinScreen();
		if (over > 0) {
			if (highscore < score)
				highscore += score;
		}
	}



}

void Game::draw()
{

	if (status == STATUS_START) {
		drawStartScreen();
	}
	else if (status == STATUS_PLAYING) {
		drawGameScreen();
	}
	else if (status == STATUS_OVER) {
		drawGameOverScreen();
	}
	else {
		drawWinScreen();
	}






}

void Game::updateStartScreen() {

	if (graphics::getKeyState(graphics::SCANCODE_S)) {
		status = STATUS_PLAYING;
		mode = 0;
	}

	if (graphics::getKeyState(graphics::SCANCODE_M)) {
		status = STATUS_PLAYING;
		mode = 1;
	}
}

void Game::updateGameScreen() {



	if (player)
		player->update();

	if (inv)
		inv->update();

	if (bullet)
		bullet->update();

	if (bomb)
		bomb->update();
}

void Game::updateGameOverScreen() {

	if (graphics::getKeyState(graphics::SCANCODE_S)) {

		status = STATUS_PLAYING;
		mode = 0;
		init();

	}

	if (graphics::getKeyState(graphics::SCANCODE_M)) {

		status = STATUS_PLAYING;
		mode = 1;
		init();

	}

}

void Game::updateWinScreen() {

	if (graphics::getKeyState(graphics::SCANCODE_S)) {

		status = STATUS_PLAYING;
		mode = 0;
		init();
	}
	if (graphics::getKeyState(graphics::SCANCODE_M)) {

		status = STATUS_PLAYING;
		mode = 1;
		init();

	}

}


void Game::drawStartScreen() {

	graphics::Brush br;
	br.fill_color[0] = 1.0f;
	br.fill_color[1] = 1.0;
	br.fill_color[2] = 1.0f;
	br.fill_opacity = 1.0f;
	br.outline_opacity = 0.0f;
	br.texture = std::string(ASSET_PATH) + "startback.png";
	br.outline_opacity = 0.0f;
	graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_WIDTH, br);


	br.texture = std::string(ASSET_PATH) + "logo.png";
	graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2 - 200, 550, 230, br);



	br.texture = std::string(ASSET_PATH) + "overback.png";
	graphics::drawRect(250, CANVAS_HEIGHT - 100, 550, 230, br);


	br.texture = std::string(ASSET_PATH) + "overback.png";
	graphics::drawRect(250 + 450, CANVAS_HEIGHT - 105, 550, 230, br);


	br.texture = std::string(ASSET_PATH) + "overback.png";
	graphics::drawRect(250 + 450 + 450, CANVAS_HEIGHT - 110, 550, 230, br);


	std::string p = " PRESS <S> FOR 1 PLAYER";
	graphics::drawText(CANVAS_WIDTH / 2 - 156, CANVAS_HEIGHT / 2 + 30, 30, p, br);

	std::string m = " PRESS <M> FOR MULTYPLAYER";
	graphics::drawText(CANVAS_WIDTH / 2 - 193, CANVAS_HEIGHT / 2 + 90, 30, m, br);

}

void Game::drawGameScreen() {

	graphics::Brush br;
	br.texture = std::string(ASSET_PATH) + "startback.png";
	br.outline_opacity = 0.0f;
	//draw background
	graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_WIDTH, br);

	br.fill_color[0] = 1.0f;
	br.fill_color[1] = 1.0f;
	br.fill_color[2] = 1.0f;

	//highscore
	graphics::drawText(CANVAS_WIDTH / 2 - 80, 40, 40, "HIGHSCORE", br);
	std::string s = std::to_string(highscore);
	graphics::drawText(CANVAS_WIDTH / 2 + 120, 40, 40, s, br);

	//score
	graphics::drawText(10, 40, 40, "Score", br);

	//level
	graphics::drawText(10, 80, 40, "Level", br);

	//draw protectors
	graphics::Brush pr;
	pr.fill_color[0] = 0.6235294118f;
	pr.fill_color[1] = 0.9607843137f;
	pr.fill_color[2] = 0.1529411765f;
	pr.fill_opacity = 1.0f;
	pr.outline_opacity = 0.0f;
	pr.texture = std::string(ASSET_PATH) + "protector.png";
	if (level == 0) {
		graphics::drawRect(CANVAS_WIDTH - (CANVAS_WIDTH / 3) * 2 - 110, 625, 110, 80, pr);
		graphics::drawRect(CANVAS_WIDTH / 2, 625, 110, 80, pr);
		graphics::drawRect(CANVAS_WIDTH - CANVAS_WIDTH / 3 + 110, 625, 110, 80, pr);
	}
	else if (level == 1) {
		graphics::drawRect(CANVAS_WIDTH / 2, 625, 110, 80, pr);
		graphics::drawRect(CANVAS_WIDTH - CANVAS_WIDTH / 3 + 110, 625, 110, 80, pr);
	}
	else if (level == 2) {
		graphics::drawRect(CANVAS_WIDTH / 2, 625, 110, 80, pr);
	}
	else {

	}

	//draw player 
	if (player)
		player->draw();

	if (inv)
		inv->draw();

	if (bullet)
		bullet->draw();

	if (bomb)
		bomb->draw();

}

void Game::drawGameOverScreen() {

	graphics::Brush br;
	br.fill_color[0] = 1.38f;
	br.fill_color[1] = 0.46;
	br.fill_color[2] = 2.26f;
	std::string s = "GAME OVER";
	graphics::drawText(CANVAS_WIDTH / 2 - 227, CANVAS_HEIGHT / 2 - 50, 100, s, br);

	graphics::Brush pr;
	pr.fill_color[0] = 1.0f;
	pr.fill_color[1] = 1.2;
	pr.fill_color[2] = 1.0f;
	std::string p = "TO PLAY AGAIN PRESS <S> FOR 1 PLAYER";
	graphics::drawText(CANVAS_WIDTH / 2 - 240, CANVAS_HEIGHT / 2 + 150, 30, p, br);

	std::string m = " PRESS <M> FOR MULTYPLAYER";
	graphics::drawText(CANVAS_WIDTH / 2 - 200, CANVAS_HEIGHT / 2 + 200, 30, m, br);

	if (loose == 1) {
		std::string loose = std::string(ASSET_PATH) + "loose.wav";
		graphics::playSound(loose, 0.6f, false);
	}
	loose = 0;
	level = 0;
}

void Game::drawWinScreen() {

	graphics::Brush br;
	br.fill_color[0] = 1.38f;
	br.fill_color[1] = 0.46;
	br.fill_color[2] = 2.26f;
	std::string s = "VICTORY";
	graphics::drawText(CANVAS_WIDTH / 2 - 200, CANVAS_HEIGHT / 2 - 50, 100, s, br);

	graphics::Brush pr;
	pr.fill_color[0] = 1.0f;
	pr.fill_color[1] = 1.2;
	pr.fill_color[2] = 1.0f;
	std::string p = "TO MOVE TO THE NEXT LEVEL PRESS S OR M(SOLO/MULTYPLAYER)";
	graphics::drawText(CANVAS_WIDTH / 2 - 450, CANVAS_HEIGHT / 2 + 150, 30, p, pr);

	if (vic == 1) {
		std::string victory = std::string(ASSET_PATH) + "win.wav";
		graphics::playSound(victory, 0.6f, false);
	}
	vic = 0;

	if (level == 4)
		level = 0;
}

void Game::init() {

	//status = STATUS_START;


	if (!player_initialized) {

		score = 0;
		player = new Player(*this);
		player_initialized = true;
	}
	if (!inv_initialized) {

		inv = new Invader(*this);
		inv_initialized = true;
	}
	if (!bullet_initialized) {

		bullet = new Bullet(*this);
		bullet_initialized = true;
	}
	if (!bomb_initialized) {

		bomb = new Bomb(*this);
		bomb_initialized = true;
	}

	player->init();
	inv->init();
	bullet->init();
	bomb->init();

	for (int i = 0; i < 16; i++) {
		Invader* inv = new Invader(*this);
		B.push_back(inv);
		(*B[i]).setInvader_pos_x(50.0f);
		(*B[i]).setInvader_pos_y(50.0f);
		(*B[i]).setInvader_speed(2.5f);
		(*B[i]).setPoints(30);

	}
	for (int i = 0; i < 16; i++) {
		Invader* inv = new Invader(*this);
		M.push_back(inv);
		(*M[i]).setInvader_pos_x(50.0f);
		(*M[i]).setInvader_pos_y(50.0f);
		(*M[i]).setInvader_speed(2.5f);
		(*M[i]).setPoints(50);

	}

	for (int i = 0; i < 8; i++) {
		Invader* inv = new Invader(*this);
		S.push_back(inv);
		(*S[i]).setInvader_pos_x(50.0f);
		(*S[i]).setInvader_pos_y(50.0f);
		(*S[i]).setInvader_speed(2.5f);
		(*S[i]).setPoints(80);

	}

	bomb_speed = 5.0f;
	bomb_y = 5.0f;
	bomb_timer = 400;
	bomb_alive = false;
	bomb_r_temp;
	score = 0;
	count = 0;

	right = true;
}



Game::Game()
{
}

Game::~Game()
{
	if (player) {
		delete player;
	}
}