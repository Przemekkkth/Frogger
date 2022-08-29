#include "game.h"

const QString Game::PATH_TO_FROG_PIXMAP         = ":/res/sprite/frog.png";
const QString Game::PATH_TO_DEAD_FROG_PIXMAP    = ":/res/sprite/frog_dead.png";
const QString Game::PATH_TO_TILE_PIXMAP         = ":/res/sprite/tiles.png";
const QString Game::PATH_TO_CAR_PIXMAP          = ":/res/sprite/car.png";
const QString Game::PATH_TO_CAR_R_PIXMAP        = ":/res/sprite/cars_r.png";
const QString Game::PATH_TO_LOG_PIXMAP          = ":/res/sprite/logs.png";
const QString Game::PATH_TO_MELTING_FROG_PIXMAP = ":/res/sprite/melting_frog.png";
const QString Game::PATH_TO_TURTLE_PIXMAP       = ":/res/sprite/turtle.png";
const QString Game::PATH_TO_TURTLE_R_PIXMAP     = ":/res/sprite/turtle_r.png";
const QString Game::PATH_TO_WIN_FROG_PIXMAP     = ":/res/sprite/frog_win.png";

QList<bool> Game::SWAMP_POS = {false, false, false, false};

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
