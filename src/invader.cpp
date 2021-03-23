#include "invader.h"
#include "graphics.h"
#include "game.h"


void Invader::setInvader_pos_x(float x) {
	invader_pos_x = x;
}
float Invader::getInvader_pos_x() {
	return invader_pos_x;
}
void Invader::setInvader_pos_y(float y) {
	invader_pos_y = y;
}
float Invader::getInvader_pos_y() {
	return invader_pos_y;
}

void Invader::setInvader_speed(float speed) {
	invader_speed = speed;
}
float Invader::getInvader_speed() {
	return invader_speed;
}
void Invader::setInvader_center(float c1, float c2) {
	invader_center_x = c1;
	invader_center_y = c2;
}
float Invader::getInvader_center_x() {
	return invader_center_x;
}
float Invader::getInvader_center_y() {
	return invader_center_y;
}
void Invader::setInvader_radius(float r) {
	invader_radius = r;
}
float Invader::getInvader_radius() {
	return invader_radius;
}

void Invader::setType(std::string t) {
	type = t;
	if (type == "BIG") {

		Invader::setBigDimensions(55.0, 35.0);
	}
	else if (type == "MEDIUM") {

		Invader::setMediumDimensions(45.0, 35.0);
	}
	else { //small

		Invader::setSmallDimensions(39.0, 30.0);
	}
}

void Invader::setPoints(int p) {
	points = p;
}
std::string Invader::getType() {
	return type;
}
int Invader::getPoints() {
	return points;
}

void Invader::setBigDimensions(float width, float height) {
	big_width = width;
	big_height = height;
}
void Invader::setMediumDimensions(float width, float height) {
	medium_width = width;
	medium_height = height;
}
void Invader::setSmallDimensions(float width, float height) {
	small_width = width;
	small_height = height;
}
float Invader::getSmallWidth() { return small_width; }
float Invader::getSmallHeight() { return small_height; }
float Invader::getMediumWidth() { return medium_width; }
float Invader::getMediumHeight() { return medium_height; }
float Invader::getBigWidth() { return big_width; }
float Invader::getBigHeight() { return big_height; }

Invader::Invader(const Game& mygame)
	:GameObject(mygame)
{

}
void Invader::init() {

	gap_x = 100;
	gap_y = 50;
	speed = 0.0f;
	temp = false;
	temp_sp = false;
	speed = 0.0f;
	invader_speed = 0.0f;
	points = 0;
	pic_t = 0;
}

void Invader::update() {
	Game* game = (Game*)graphics::getUserData();

	float max = -1.0;
	float min = 2000;
	for (int i = 0; i < 8; i++) {
		if (max < game->S[i]->getInvader_center_x())
			max = game->S[i]->getInvader_center_x();
		if (min > game->S[i]->getInvader_center_x())
			min = game->S[i]->getInvader_center_x();
	}
	for (int i = 0; i < 16; i++) {
		if (max < game->M[i]->getInvader_center_x())
			max = game->M[i]->getInvader_center_x();
		if (min > game->M[i]->getInvader_center_x())
			min = game->M[i]->getInvader_center_x();
	}
	for (int i = 0; i < 16; i++) {
		if (max < game->B[i]->getInvader_center_x())
			max = game->B[i]->getInvader_center_x();
		if (min > game->B[i]->getInvader_center_x())
			min = game->B[i]->getInvader_center_x();
	}


	if (max >= CANVAS_WIDTH - 50) {
		game->right = false;

	}
	else if (min <= 50) {
		game->right = true;
	}

	if ((game->count == 20 || game->count == 28 || game->count == 36 || game->count == 39) && (temp_sp == false)) {
		for (int i = 0; i < 8; i++)
			game->S[i]->setInvader_speed(game->S[i]->getInvader_speed() + 1.0f);
		for (int i = 0; i < 16; i++) {
			game->B[i]->setInvader_speed(game->B[i]->getInvader_speed() + 1.0f);
			game->M[i]->setInvader_speed(game->M[i]->getInvader_speed() + 1.0f);
		}
	}
	else {
		temp_sp = false;
	}

	if (game->right == true) {
		for (int i = 0; i < 8; i++) {
			if (game->S[i]->getInvader_pos_x() != -1.0) { // if an invader once got hit make sure he wont appear on screen again.
				float invader_move = game->S[i]->getInvader_pos_x() + game->S[i]->getInvader_speed();
				game->S[i]->setInvader_pos_x(invader_move);
			}
		}
		for (int i = 0; i < 16; i++) {
			if (game->B[i]->getInvader_pos_x() != -1.0) {
				float invader_move = game->B[i]->getInvader_pos_x() + game->B[i]->getInvader_speed();
				game->B[i]->setInvader_pos_x(invader_move);
			}
		}
		for (int i = 0; i < 16; i++) {
			if (game->M[i]->getInvader_pos_x() != -1.0) {
				float invader_move = game->M[i]->getInvader_pos_x() + game->M[i]->getInvader_speed();
				game->M[i]->setInvader_pos_x(invader_move);
			}
		}
	}
	else {
		for (int i = 0; i < 8; i++) {
			if (game->S[i]->getInvader_pos_x() != -1.0) {
				float invader_move = game->S[i]->getInvader_pos_x() - game->S[i]->getInvader_speed();
				game->S[i]->setInvader_pos_x(invader_move);
			}
		}
		for (int i = 0; i < 16; i++) {
			if (game->B[i]->getInvader_pos_x() != -1.0) {
				float invader_move = game->B[i]->getInvader_pos_x() - game->B[i]->getInvader_speed();
				game->B[i]->setInvader_pos_x(invader_move);
			}
		}
		for (int i = 0; i < 16; i++) {
			if (game->M[i]->getInvader_pos_x() != -1.0) {
				float invader_move = game->M[i]->getInvader_pos_x() - game->M[i]->getInvader_speed();
				game->M[i]->setInvader_pos_x(invader_move);
			}
		}
	}

	if ((game->count == 20 || game->count == 28 || game->count == 36 || game->count == 39) && (temp_sp == false))
		temp_sp = true;
}

void Invader::draw() {

	Game* game = (Game*)graphics::getUserData();
	pic_t++;

	if (game->right == true) { // move ->

		minidrawInv();

	}
	else if (game->right == false) { //move <-

		minidrawInv();

	}
}

void Invader::minidrawInv() {
	Game* game = (Game*)graphics::getUserData();

	if ((game->count == 8 || game->count == 16 || game->count == 24 || game->count == 28 || game->count == 32 || game->count == 36 || game->count == 38 || game->count == 39) && (temp == false)) {
		gap_y += 60;

	}
	else {
		temp = false;
	}

	int i;
	//int j;
	int temp_gap_y = gap_y;
	gap_x = 100;

	//Squid small invaders
	for (i = 0; i < 8; i++) {
		//float d;
		graphics::Brush br;
		br.fill_color[0] = 1.0f;
		br.fill_color[1] = 1.0f;
		br.fill_color[2] = 1.0f;
		br.fill_opacity = 1.0f;
		br.outline_opacity = 0.0f;
		if (pic_t == 15)
		{
			picture = "A1";
		}
		if (pic_t == 30)
		{
			picture = "A2";
			pic_t = 0;
		}
		if (picture == "A1")
		{
			br.texture = std::string(ASSET_PATH) + "InvaderA1.png";
		}
		if (picture == "A2")
		{
			br.texture = std::string(ASSET_PATH) + "InvaderA2.png";
		}


		game->S[i]->setType("SMALL");

		if (game->S[i]->getInvader_pos_x() != -1.0) {
			graphics::drawRect(game->S[i]->getInvader_pos_x() + gap_x, game->S[i]->getInvader_pos_y() + gap_y, game->S[i]->getSmallWidth(), game->S[i]->getSmallHeight(), br);
			game->S[i]->setInvader_center(game->S[i]->getInvader_pos_x() + gap_x, game->S[i]->getInvader_pos_y() + gap_y);
			game->S[i]->setInvader_radius(20);

		}

		gap_x += 65;
	}

	//Crab medium invaders
	gap_x = 100;
	gap_y += 60;


	for (i = 0; i < 16; i++) {
		if (i == 8) {
			gap_y += 60;
			gap_x = 100;
		}
		graphics::Brush br;
		br.fill_color[0] = 1.0f;
		br.fill_color[1] = 1.0f;
		br.fill_color[2] = 1.0f;
		br.fill_opacity = 1.0f;
		br.outline_opacity = 0.0f;
		if (pic_t == 15)
		{
			picture = "A1";
		}
		if (pic_t == 30)
		{
			picture = "A2";
			pic_t = 0;
		}
		if (picture == "A1")
		{
			br.texture = std::string(ASSET_PATH) + "InvaderB1.png";
		}
		if (picture == "A2")
		{
			br.texture = std::string(ASSET_PATH) + "InvaderB2.png";
		}

		game->M[i]->setType("MEDIUM");

		if (game->M[i]->getInvader_pos_x() != -1.0) {
			graphics::drawRect(game->M[i]->getInvader_pos_x() + gap_x, game->M[i]->getInvader_pos_y() + gap_y, game->M[i]->getMediumWidth(), game->M[i]->getMediumHeight(), br);
			game->M[i]->setInvader_center(game->M[i]->getInvader_pos_x() + gap_x, game->M[i]->getInvader_pos_y() + gap_y);
			game->M[i]->setInvader_radius(20);

		}


		gap_x += 65;
	}


	//Octapus big invaders
	gap_x = 100;
	gap_y += 60;

	for (i = 0; i < 16; i++) {
		if (i == 8) {
			gap_y += 60;
			gap_x = 100;
		}

		graphics::Brush br;
		br.fill_color[0] = 1.0f;
		br.fill_color[1] = 1.0f;
		br.fill_color[2] = 1.0f;
		br.fill_opacity = 1.0f;
		br.outline_opacity = 0.0f;
		if (pic_t == 15)
		{
			picture = "A1";
		}
		if (pic_t == 30)
		{
			picture = "A2";
			pic_t = 0;
		}
		if (picture == "A1")
		{
			br.texture = std::string(ASSET_PATH) + "InvaderC1.png";
		}
		if (picture == "A2")
		{
			br.texture = std::string(ASSET_PATH) + "InvaderC2.png";
		}

		game->B[i]->setType("BIG");

		if (game->B[i]->getInvader_pos_x() != -1.0) {
			graphics::drawRect(game->B[i]->getInvader_pos_x() + gap_x, game->B[i]->getInvader_pos_y() + gap_y, game->B[i]->getBigWidth(), game->B[i]->getBigHeight(), br);
			game->B[i]->setInvader_center(game->B[i]->getInvader_pos_x() + gap_x, game->B[i]->getInvader_pos_y() + gap_y);
			game->B[i]->setInvader_radius(20);

		}

		gap_x += 65;
	}
	if ((game->count == 8 || game->count == 16 || game->count == 24 || game->count == 28 || game->count == 32 || game->count == 36 || game->count == 38 || game->count == 39) && (temp == false))
		temp = true;
	gap_y = temp_gap_y;

}