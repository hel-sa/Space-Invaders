#include "game.h"
#include "graphics.h"
#include "config.h"

void update(float ms)
{
	Game* game = reinterpret_cast<Game*>(graphics::getUserData());
	game->update();
}

void draw()
{
	Game* game = reinterpret_cast<Game*>(graphics::getUserData());
	game->draw();
}

int main()
{
	Game mygame;

	mygame.init();

	graphics::createWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Space_Invaders");

	graphics::setUserData(&mygame);



	graphics::setDrawFunction(draw);
	graphics::setUpdateFunction(update);

	graphics::setCanvasSize(CANVAS_WIDTH, CANVAS_HEIGHT);
	graphics::setCanvasScaleMode(graphics::CANVAS_SCALE_FIT);


	graphics::setFont("assets\\VPPixel-Simplified.otf");
	graphics::startMessageLoop();

	return 0;

}