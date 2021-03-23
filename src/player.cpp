#include "player.h"
#include "graphics.h"
#include "game.h"


Player::Player(const Game& mygame)
	:GameObject(mygame)
{
}

void Player::update()
{
	Game* game = (Game*)graphics::getUserData();

	if (game->mode == 0) {
		if (graphics::getKeyState(graphics::SCANCODE_LEFT))
		{
			pos_x -= speed * graphics::getDeltaTime() / 10.0f;
		}
		if (graphics::getKeyState(graphics::SCANCODE_RIGHT))
		{
			pos_x += speed * graphics::getDeltaTime() / 10.0f;

		}
	}
	else {
		if (graphics::getKeyState(graphics::SCANCODE_LEFT))
		{
			pos_x -= speed * graphics::getDeltaTime() / 10.0f;
		}
		if (graphics::getKeyState(graphics::SCANCODE_RIGHT))
		{
			pos_x += speed * graphics::getDeltaTime() / 10.0f;

		}
		if (graphics::getKeyState(graphics::SCANCODE_A))
		{
			pos_x1 -= speed * graphics::getDeltaTime() / 10.0f;
		}
		if (graphics::getKeyState(graphics::SCANCODE_D))
		{
			pos_x1 += speed * graphics::getDeltaTime() / 10.0f;

		}
	}
}

void Player::draw()
{
	Game* game = (Game*)graphics::getUserData();
	graphics::Brush br;

	br.fill_color[0] = 0.93725490196f;
	br.fill_color[1] = 0.0862745098f;
	br.fill_color[2] = 0.11764705882f;
	br.fill_opacity = 1.0f;
	br.outline_opacity = 0.0f;
	br.texture = std::string(ASSET_PATH) + "ship2.png";

	if (game->mode == 0) {
		graphics::drawRect(pos_x, pos_y, player_width, player_height, br);
	}
	else {
		graphics::drawRect(pos_x, pos_y, player_width, player_height, br);
		graphics::drawRect(pos_x1, pos_y1, player_width, player_height, br);
	}
}

void Player::init()
{

	pos_x = CANVAS_WIDTH / 2;
	pos_y = 708;
	speed = 8.0f;
	pos_x1 = (CANVAS_WIDTH / 2) + 285;
	pos_y1 = 708;



}
