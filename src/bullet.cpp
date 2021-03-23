#include "bullet.h"
#include "invader.h"
#include "graphics.h"
#include "game.h"
#include "player.h"
#include <iostream>


Bullet::Bullet(const Game& mygame)
	:GameObject(mygame)

{

}



void Bullet::update() {
	Game* game = (Game*)graphics::getUserData();
	float distance;


	if (graphics::getKeyState(graphics::SCANCODE_LEFT))
	{
		player_center_x -= speed * graphics::getDeltaTime() / 10.0f;
		if (flag == 0)
			temp_player_center_x = player_center_x; //bullet stays always on top of the player
	}
	if (graphics::getKeyState(graphics::SCANCODE_RIGHT))
	{
		player_center_x += speed * graphics::getDeltaTime() / 10.0f;
		if (flag == 0)
			temp_player_center_x = player_center_x; //bullet stays always on top of the player

	}

	if (game->mode == 1) {
		if (graphics::getKeyState(graphics::SCANCODE_A))
		{
			player_center_x1 -= speed * graphics::getDeltaTime() / 10.0f;
			if (flag1 == 0)
				temp_player_center_x1 = player_center_x1; //bullet stays always on top of the player
		}
		if (graphics::getKeyState(graphics::SCANCODE_D))
		{
			player_center_x1 += speed * graphics::getDeltaTime() / 10.0f;
			if (flag1 == 0)
				temp_player_center_x1 = player_center_x1; //bullet stays always on top of the player

		}
	}

	//bullet movement
	if (graphics::getKeyState(graphics::SCANCODE_SPACE))
	{
		flag = 1;
		std::string shoot = std::string(ASSET_PATH) + "shoot.wav";
		graphics::playSound(shoot, 0.05f, false);

	}

	if (game->mode == 1) {
		if (graphics::getKeyState(graphics::SCANCODE_W))
		{
			flag1 = 1;
			std::string shoot = std::string(ASSET_PATH) + "shoot.wav";
			graphics::playSound(shoot, 0.05f, false);

		}
	}

	//check if bullet hit a protector
	if (flag == 1) {
		distance = sqrt(((temp_player_center_x - (CANVAS_WIDTH - (CANVAS_WIDTH / 3) * 2 - 110)) * (temp_player_center_x - (CANVAS_WIDTH - (CANVAS_WIDTH / 3) * 2 - 110))) + ((player_center_y - bullet_center_y - 625) * (player_center_y - bullet_center_y - 625))) - 50;

		if (distance < 0) {
			if (game->level == 0) {
				hit_p = 1;
				std::string protectorhit = std::string(ASSET_PATH) + "protectorhit.wav";
				graphics::playSound(protectorhit, 0.4f, false);
			}
		}

		distance = sqrt(((temp_player_center_x - CANVAS_WIDTH / 2) * (temp_player_center_x - CANVAS_WIDTH / 2)) + ((player_center_y - bullet_center_y - 625) * (player_center_y - bullet_center_y - 625))) - 50;

		if (distance < 0) {
			if (game->level == 0 || game->level == 1 || game->level == 2) {
				hit_p = 1;
				std::string protectorhit = std::string(ASSET_PATH) + "protectorhit.wav";
				graphics::playSound(protectorhit, 0.4f, false);
			}
		}

		distance = sqrt(((temp_player_center_x - (CANVAS_WIDTH - CANVAS_WIDTH / 3 + 110)) * (temp_player_center_x - (CANVAS_WIDTH - CANVAS_WIDTH / 3 + 110))) + ((player_center_y - bullet_center_y - 625) * (player_center_y - bullet_center_y - 625))) - 50;
		if (distance < 0) {
			if (game->level == 0 || game->level == 1) {
				hit_p = 1;
				std::string protectorhit = std::string(ASSET_PATH) + "protectorhit.wav";
				graphics::playSound(protectorhit, 0.4f, false);
			}
		}
	}
	//same for second player
	if (flag1 == 1) {
		distance = sqrt(((temp_player_center_x1 - (CANVAS_WIDTH - (CANVAS_WIDTH / 3) * 2 - 110)) * (temp_player_center_x1 - (CANVAS_WIDTH - (CANVAS_WIDTH / 3) * 2 - 110))) + ((player_center_y1 - bullet_center_y1 - 625) * (player_center_y1 - bullet_center_y1 - 625))) - 50;

		if (distance < 0) {
			if (game->level == 0) {
				hit_p1 = 1;
				std::string protectorhit = std::string(ASSET_PATH) + "protectorhit.wav";
				graphics::playSound(protectorhit, 0.4f, false);
			}
		}

		distance = sqrt(((temp_player_center_x1 - CANVAS_WIDTH / 2) * (temp_player_center_x1 - CANVAS_WIDTH / 2)) + ((player_center_y1 - bullet_center_y1 - 625) * (player_center_y1 - bullet_center_y1 - 625))) - 50;

		if (distance < 0) {
			if (game->level == 0 || game->level == 1 || game->level == 2) {
				hit_p1 = 1;
				std::string protectorhit = std::string(ASSET_PATH) + "protectorhit.wav";
				graphics::playSound(protectorhit, 0.4f, false);
			}
		}

		distance = sqrt(((temp_player_center_x1 - (CANVAS_WIDTH - CANVAS_WIDTH / 3 + 110)) * (temp_player_center_x1 - (CANVAS_WIDTH - CANVAS_WIDTH / 3 + 110))) + ((player_center_y1 - bullet_center_y1 - 625) * (player_center_y1 - bullet_center_y1 - 625))) - 50;
		if (distance < 0) {
			if (game->level == 0 || game->level == 1) {
				hit_p1 = 1;
				std::string protectorhit = std::string(ASSET_PATH) + "protectorhit.wav";
				graphics::playSound(protectorhit, 0.4f, false);
			}
		}
	}

	//check if bullet hit invader
	if (flag == 1) {

		for (int i = 15; i >= 0; i--) {
			distance = 0;
			if (game->B[i]->getInvader_pos_x() != -1.0)
				distance = sqrt(((temp_player_center_x - game->B[i]->getInvader_center_x()) * (temp_player_center_x - game->B[i]->getInvader_center_x())) + ((player_center_y - bullet_center_y - game->B[i]->getInvader_center_y()) * (player_center_y - bullet_center_y - game->B[i]->getInvader_center_y()))) - game->B[i]->getInvader_radius() - 10;

			if (distance < 0) {
				game->B[i]->setInvader_pos_x(-1.0);
				hit = 1;
				flag = 0;
				game->count++;


				//Update score
				game->score += game->B[i]->getPoints();
				std::cout << game->score << std::endl;

				//play sound if invader got hit
				std::string invaderkilled = std::string(ASSET_PATH) + "invaderkilled.wav";
				graphics::playSound(invaderkilled, 0.2f, false);



				break;
			}
		}
		if (hit != 1) {
			for (int i = 15; i >= 0; i--) {
				distance = 0;
				if (game->M[i]->getInvader_pos_x() != -1.0)
					distance = sqrt(((temp_player_center_x - game->M[i]->getInvader_center_x()) * (temp_player_center_x - game->M[i]->getInvader_center_x())) + ((player_center_y - bullet_center_y - game->M[i]->getInvader_center_y()) * (player_center_y - bullet_center_y - game->M[i]->getInvader_center_y()))) - game->M[i]->getInvader_radius() - 15;
				if (distance < 0) {
					game->M[i]->setInvader_pos_x(-1.0);
					hit = 1;
					flag = 0;
					game->count++;


					//Update score
					game->score += game->M[i]->getPoints();
					std::cout << game->score << std::endl;

					std::string invaderkilled = std::string(ASSET_PATH) + "invaderkilled.wav";
					graphics::playSound(invaderkilled, 0.2f, false);


					break;
				}
			}
		}
		if (hit != 1) {
			for (int i = 0; i < 8; i++) {
				distance = 0;
				if (game->S[i]->getInvader_pos_x() != -1.0)
					distance = sqrt(((temp_player_center_x - game->S[i]->getInvader_center_x()) * (temp_player_center_x - game->S[i]->getInvader_center_x())) + ((player_center_y - bullet_center_y - game->S[i]->getInvader_center_y()) * (player_center_y - bullet_center_y - game->S[i]->getInvader_center_y()))) - game->S[i]->getInvader_radius() - 15;
				if (distance < 0) {
					game->S[i]->setInvader_pos_x(-1.0);
					hit = 1;
					flag = 0;
					game->count++;


					//Update score
					game->score += game->S[i]->getPoints();
					std::cout << game->score << std::endl;

					std::string invaderkilled = std::string(ASSET_PATH) + "invaderkilled.wav";
					graphics::playSound(invaderkilled, 0.2f, false);

					break;
				}
			}
		}
	}

	//same for second player
	if (flag1 == 1) {

		for (int i = 15; i >= 0; i--) {
			distance = 0;
			if (game->B[i]->getInvader_pos_x() != -1.0)
				distance = sqrt(((temp_player_center_x1 - game->B[i]->getInvader_center_x()) * (temp_player_center_x1 - game->B[i]->getInvader_center_x())) + ((player_center_y1 - bullet_center_y1 - game->B[i]->getInvader_center_y()) * (player_center_y1 - bullet_center_y1 - game->B[i]->getInvader_center_y()))) - game->B[i]->getInvader_radius() - 10;

			if (distance < 0) {
				game->B[i]->setInvader_pos_x(-1.0);
				hit1 = 1;
				flag1 = 0;
				game->count++;


				//Update score
				game->score += game->B[i]->getPoints();
				std::cout << game->score << std::endl;

				//play sound if invader got hit
				std::string invaderkilled = std::string(ASSET_PATH) + "invaderkilled.wav";
				graphics::playSound(invaderkilled, 0.2f, false);



				break;
			}
		}
		if (hit != 1) {
			for (int i = 15; i >= 0; i--) {
				distance = 0;
				if (game->M[i]->getInvader_pos_x() != -1.0)
					distance = sqrt(((temp_player_center_x1 - game->M[i]->getInvader_center_x()) * (temp_player_center_x1 - game->M[i]->getInvader_center_x())) + ((player_center_y1 - bullet_center_y1 - game->M[i]->getInvader_center_y()) * (player_center_y1 - bullet_center_y1 - game->M[i]->getInvader_center_y()))) - game->M[i]->getInvader_radius() - 15;
				if (distance < 0) {
					game->M[i]->setInvader_pos_x(-1.0);
					hit1 = 1;
					flag1 = 0;
					game->count++;


					//Update score
					game->score += game->M[i]->getPoints();
					std::cout << game->score << std::endl;

					std::string invaderkilled = std::string(ASSET_PATH) + "invaderkilled.wav";
					graphics::playSound(invaderkilled, 0.2f, false);


					break;
				}
			}
		}
		if (hit != 1) {
			for (int i = 0; i < 8; i++) {
				distance = 0;
				if (game->S[i]->getInvader_pos_x() != -1.0)
					distance = sqrt(((temp_player_center_x1 - game->S[i]->getInvader_center_x()) * (temp_player_center_x1 - game->S[i]->getInvader_center_x())) + ((player_center_y1 - bullet_center_y1 - game->S[i]->getInvader_center_y()) * (player_center_y1 - bullet_center_y1 - game->S[i]->getInvader_center_y()))) - game->S[i]->getInvader_radius() - 15;
				if (distance < 0) {
					game->S[i]->setInvader_pos_x(-1.0);
					hit1 = 1;
					flag1 = 0;
					game->count++;


					//Update score
					game->score += game->S[i]->getPoints();
					std::cout << game->score << std::endl;

					std::string invaderkilled = std::string(ASSET_PATH) + "invaderkilled.wav";
					graphics::playSound(invaderkilled, 0.2f, false);

					break;
				}
			}
		}
	}

	//Check if the player won
	if (game->score == 1920) {
		game->status = Game::STATUS_WIN;
		game->vic = 1;
		game->level++;
	}

	//movement of bullet
	if (flag == 1 && player_center_y - bullet_center_y > 0) {
		if (hit == 0 && hit_p == 0) {
			bullet_center_y += bullet_speed;
		}
	}
	//same for second player
	if (flag1 == 1 && player_center_y1 - bullet_center_y1 > 0) {
		if (hit1 == 0 && hit_p1 == 0) {
			bullet_center_y1 += bullet_speed;
		}
	}

	//if bullet out of boundry or hit invader or hit a protector reset 
	if (player_center_y - bullet_center_y <= 0 || hit == 1 || hit_p == 1) {
		bullet_center_y = 10;
		flag = 0;
		temp_player_center_x = player_center_x;
		hit = 0;
		hit_p = 0;

	}
	//same for second player
	if (player_center_y1 - bullet_center_y1 <= 0 || hit1 == 1 || hit_p1 == 1) {
		bullet_center_y1 = 10;
		flag1 = 0;
		temp_player_center_x1 = player_center_x1;
		hit1 = 0;
		hit_p1 = 0;

	}

}

void Bullet::draw() {
	Game* game = (Game*)graphics::getUserData();


	graphics::Brush br;
	br.fill_color[0] = 0.93725490196f;
	br.fill_color[1] = 0.0862745098f;
	br.fill_color[2] = 0.11764705882f;
	br.fill_opacity = 1.0f;
	br.outline_opacity = 0.0f;
	br.texture = std::string(ASSET_PATH) + "bullett.png";

	graphics::drawRect(temp_player_center_x, player_center_y - bullet_center_y, bullet_width, bullet_height, br);
	if (game->mode == 1)
		graphics::drawRect(temp_player_center_x1, player_center_y1 - bullet_center_y1, bullet_width, bullet_height, br);

	//score
	graphics::resetPose();
	graphics::Brush sc;
	std::string s = std::to_string(game->score);
	graphics::drawText(150, 40, 40, s, sc);


	//level
	graphics::resetPose();
	std::string lev = std::to_string(game->level);
	graphics::drawText(150, 80, 40, lev, sc);

}

void Bullet::init() {

	bullet_center_y = 10;
	player_center_y = 708;
	bullet_center_y1 = 10;
	player_center_y1 = 708;
	bullet_speed = 15.0f;
	player_center_x = CANVAS_WIDTH / 2;
	temp_player_center_x = CANVAS_WIDTH / 2;
	player_center_x1 = CANVAS_WIDTH / 2 + 285;
	temp_player_center_x1 = CANVAS_WIDTH / 2 + 285;
	speed = 8.0;
	hit = 0;
	hit_p = 0;
	flag = 0;
	bulltimer = 0;

}