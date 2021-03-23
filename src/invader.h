#pragma once
#include <iostream>
#include "gameobject.h"
#include "config.h"

class Invader : public GameObject
{
	int points = 0;
	int pic_t = 0;
	std::string picture = "";
	std::string type = "";

	float pos_x = 0.0f;
	float pos_y = 0.0f;
	float speed = 0.0f;
	int gap_x = 100;
	int gap_y = 50;
	bool temp = false;
	bool temp_sp = false;

	float width = 0.0f;
	float height = 0.0f;

	float invader_pos_x = 0.0f;
	float invader_pos_y = 0.0f;
	float invader_center_x = 0.0f;
	float invader_center_y = 0.0f;
	float invader_radius = 0.0f;
	float invader_speed = 0.0f;

	float small_width = 0.0f;
	float small_height = 0.0f;
	float medium_width = 0.0f;
	float medium_height = 0.0f;
	float big_width = 0.0f;
	float big_height = 0.0f;

	std::string assets_C1 = std::string(ASSET_PATH) + +"InvaderC1.png";
	std::string assets_C2 = std::string(ASSET_PATH) + +"InvaderC2.png";

	std::string assets_B1 = std::string(ASSET_PATH) + +"InvaderB1.png";
	std::string assets_B2 = std::string(ASSET_PATH) + +"InvaderB2.png";

	std::string assets_A1 = std::string(ASSET_PATH) + +"InvaderA1.png";
	std::string assets_A2 = std::string(ASSET_PATH) + +"InvaderA2.png";

public:
	Invader(const class Game& mygame);
	void update() override;
	void draw() override;
	void init() override;
	void minidrawInv();

	void setType(std::string t);

	std::string getType();

	void setPoints(int points);

	int getPoints();

	void setInvader_pos_x(float x);

	float getInvader_pos_x();

	void setInvader_pos_y(float y);

	float getInvader_pos_y();

	void setInvader_speed(float speed);

	float getInvader_speed();

	void setInvader_center(float c1, float c2);

	float getInvader_center_x();

	float getInvader_center_y();


	void setInvader_radius(float r);

	float getInvader_radius();

	void setBigDimensions(float width, float height);

	void setMediumDimensions(float width, float height);

	void setSmallDimensions(float width, float height);

	float getSmallWidth();
	float getSmallHeight();
	float getMediumWidth();
	float getMediumHeight();
	float getBigWidth();
	float getBigHeight();



};