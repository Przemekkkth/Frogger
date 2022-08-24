#include "game.h"

const QString Game::PATH_TO_FROG_PIXMAP = ":/res/frog.png";
const QString Game::PATH_TO_TILE_PIXMAP = ":/res/tiles.png";
const QString Game::PATH_TO_CAR_PIXMAP  = ":/res/car.png";

Game::Game()
{

}

int Game::convertPixelToGridPoint(int pixelVal)
{
    return int(pixelVal/GRID_SIZE);
}

int Game::convertGridPointToPixel(int gridPointVal)
{
    return gridPointVal*GRID_SIZE;
}
