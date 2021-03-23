#include "bullet.h"
#include "invader.h"
#include "graphics.h"
#include "game.h"
#include "player.h"
#include "bomb.h"


Bomb::Bomb(const Game& mygame)
	:GameObject(mygame)
{
}


void Bomb::update() {
	Game* game = (Game*)graphics::getUserData();

	//player movement
	if (graphics::getKeyState(graphics::SCANCODE_LEFT))
	{
		player_center_x -= speed * graphics::getDeltaTime() / 10.0f;

	}
	if (graphics::getKeyState(graphics::SCANCODE_RIGHT))
	{
		player_center_x += speed * graphics::getDeltaTime() / 10.0f;


	}

	if (game->mode == 1) {
		if (graphics::getKeyState(graphics::SCANCODE_A))
		{
			player_center_x1 -= speed * graphics::getDeltaTime() / 10.0f;
		}
		if (graphics::getKeyState(graphics::SCANCODE_D))
		{
			player_center_x1 += speed * graphics::getDeltaTime() / 10.0f;

		}
	}

	if ((game->count == 20 || game->count == 36 || game->count == 39) && (temp_sp == false)) {
		bomb_speed += 1.0f;
	}
	else {
		temp_sp = false;
	}

	//bomb movement;
	if (temp_pos_y + bomb_y < CANVAS_HEIGHT) {
		bomb_y += bomb_speed;
		bomb_alive = true;

	}


	//check if a bomb hit the player
	float distance;
	distance = sqrt(((player_center_x - temp_pos_x) * (player_center_x - temp_pos_x)) + ((player_center_y - temp_pos_y - bomb_y) * (player_center_y - temp_pos_y - bomb_y))) - 20;
	if (distance < 0) {
		std::string playerkilled = std::string(ASSET_PATH) + "explosion.wav";
		graphics::playSound(playerkilled, 0.3f, false);
		game->status = Game::STATUS_OVER;
		game->loose = 1;
	}
	//same for second player
	distance = sqrt(((player_center_x1 - temp_pos_x) * (player_center_x1 - temp_pos_x)) + ((player_center_y1 - temp_pos_y - bomb_y) * (player_center_y1 - temp_pos_y - bomb_y))) - 20;
	if (distance < 0) {
		std::string playerkilled = std::string(ASSET_PATH) + "explosion.wav";
		graphics::playSound(playerkilled, 0.3f, false);
		game->status = Game::STATUS_OVER;
		game->loose = 1;
	}

	//check if a bomb hit a protector

	distance = sqrt(((CANVAS_WIDTH - (CANVAS_WIDTH / 3) * 2 - 110 - temp_pos_x) * (CANVAS_WIDTH - (CANVAS_WIDTH / 3) * 2 - 110 - temp_pos_x)) + ((625 - temp_pos_y - bomb_y) * (625 - temp_pos_y - bomb_y))) - 50;
	if (distance < 0) {
		if (game->level == 0) {
			hit_p = 1;
			std::string protectorhit = std::string(ASSET_PATH) + "protectorhit.wav";
			graphics::playSound(protectorhit, 0.4f, false);
		}
	}

	distance = sqrt(((CANVAS_WIDTH / 2 - temp_pos_x) * (CANVAS_WIDTH / 2 - temp_pos_x)) + ((625 - temp_pos_y - bomb_y) * (625 - temp_pos_y - bomb_y))) - 50;
	if (distance < 0) {
		if (game->level == 0 || game->level == 1 || game->level == 2) {
			hit_p = 1;
			std::string protectorhit = std::string(ASSET_PATH) + "protectorhit.wav";
			graphics::playSound(protectorhit, 0.4f, false);
		}
	}

	distance = sqrt(((CANVAS_WIDTH - CANVAS_WIDTH / 3 + 110 - temp_pos_x) * (CANVAS_WIDTH - CANVAS_WIDTH / 3 + 110 - temp_pos_x)) + ((625 - temp_pos_y - bomb_y) * (625 - temp_pos_y - bomb_y))) - 50;
	if (distance < 0) {
		if (game->level == 0 || game->level == 1) {
			hit_p = 1;
			std::string protectorhit = std::string(ASSET_PATH) + "protectorhit.wav";
			graphics::playSound(protectorhit, 0.4f, false);
		}
	}


	//if bomb reach the limit reset
	if (temp_pos_y + bomb_y >= CANVAS_HEIGHT || hit_p == 1) {

		bomb_y = 5.0f;
		bomb_alive = false;
		hit_p = 0;
	}
	if ((game->count == 20 || game->count == 36 || game->count == 39) && (temp_sp == false))
		temp_sp = true;
}

void Bomb::draw() {
	Game* game = (Game*)graphics::getUserData();




	std::vector<Invader*>Possible_Bombs;

	for (int i = 0; i < 8; i++) {
		if (game->S[i]->getInvader_pos_x() != -1.0)
			Possible_Bombs.push_back(game->S[i]);
	}
	for (int i = 0; i < 16; i++) {
		if (game->M[i]->getInvader_pos_x() != -1.0)
			Possible_Bombs.push_back(game->M[i]);
	}
	for (int i = 0; i < 16; i++) {
		if (game->B[i]->getInvader_pos_x() != -1.0)
			Possible_Bombs.push_back(game->B[i]);
	}

	if (Possible_Bombs.size() > 0) {
		if (bomb_alive == false) {
			int r = rand() % Possible_Bombs.size();
			bomb_r_temp = r;
			temp_pos_x = Possible_Bombs[bomb_r_temp]->getInvader_center_x();
			temp_pos_y = Possible_Bombs[bomb_r_temp]->getInvader_center_y();
		}



		graphics::Brush br;
		graphics::setOrientation(0);
		br.fill_color[0] = 1.0f;
		br.fill_color[1] = 1.0f;
		br.fill_color[2] = 1.0f;
		br.fill_opacity = 1.0f;
		br.outline_opacity = 0.0f;
		br.texture = std::string(ASSET_PATH) + "thunder.png";

		graphics::drawRect(temp_pos_x, temp_pos_y + bomb_y, 20, 20, br);

	}
}

void Bomb::init() {

	bomb_speed = 10.0f;
	bomb_y = 5.0f;
	bomb_timer = 400;
	bomb_alive = false;
	bomb_r_temp = 0;
	temp_pos_x = 0.0;
	temp_pos_y = 0.0;
	player_center_y = 708;
	player_center_x = CANVAS_WIDTH / 2;
	player_center_y1 = 708;
	player_center_x1 = (CANVAS_WIDTH / 2) + 285;
	speed = 8.0f;
	hit_p = 0;
	temp_sp = false;

}