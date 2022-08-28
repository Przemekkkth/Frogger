#include "game.h"

const QString Game::PATH_TO_FROG_PIXMAP      = ":/res/frog.png";
const QString Game::PATH_TO_DEAD_FROG_PIXMAP = ":/res/frog_dead.png";
const QString Game::PATH_TO_TILE_PIXMAP      = ":/res/tiles.png";
const QString Game::PATH_TO_CAR_PIXMAP       = ":/res/car.png";
const QString Game::PATH_TO_CAR_R_PIXMAP     = ":/res/cars_r.png";
const QString Game::PATH_TO_LOG_PIXMAP       = ":/res/logs.png";
const QString Game::PATH_TO_MELTING_FROG_PIXMAP = ":/res/melting_frog.png";
const QString Game::PATH_TO_TURTLE_PIXMAP = ":/res/turtle.png";

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
