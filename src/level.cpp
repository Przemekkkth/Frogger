#include "level.h"
#include "game.h"
#include <QGraphicsPixmapItem>

Level::Level(QGraphicsScene *scene)
{
    m_scene = scene;
}

void Level::loadLevel()
{


    for(int i = 0; i < Game::WINDOW_WIDTH; ++i)
    {
        QGraphicsPixmapItem* tileItem = new QGraphicsPixmapItem(QPixmap(Game::PATH_TO_TILE_PIXMAP).copy(Game::Asphalt0p.x(), Game::Asphalt0p.y(), Game::GRID_SIZE, Game::GRID_SIZE));
        tileItem->setPos(Game::convertGridPointToPixel(i), Game::convertGridPointToPixel(Game::WINDOW_HEIGHT-7));
        m_scene->addItem(tileItem);
    }
    for(int i = 0; i < Game::WINDOW_WIDTH; ++i)
    {
        QGraphicsPixmapItem* tileItem = new QGraphicsPixmapItem(QPixmap(Game::PATH_TO_TILE_PIXMAP).copy(Game::Asphalt3p.x(), Game::Asphalt3p.y(), Game::GRID_SIZE, Game::GRID_SIZE));
        tileItem->setPos(Game::convertGridPointToPixel(i), Game::convertGridPointToPixel(Game::WINDOW_HEIGHT-6));
        m_scene->addItem(tileItem);
    }
    for(int i = 0; i < Game::WINDOW_WIDTH; ++i)
    {
        QGraphicsPixmapItem* tileItem = new QGraphicsPixmapItem(QPixmap(Game::PATH_TO_TILE_PIXMAP).copy(Game::Asphalt5p.x(), Game::Asphalt5p.y(), Game::GRID_SIZE, Game::GRID_SIZE));
        tileItem->setPos(Game::convertGridPointToPixel(i), Game::convertGridPointToPixel(Game::WINDOW_HEIGHT-5));
        m_scene->addItem(tileItem);
    }
    for(int i = 0; i < Game::WINDOW_WIDTH; ++i)
    {
        QGraphicsPixmapItem* tileItem = new QGraphicsPixmapItem(QPixmap(Game::PATH_TO_TILE_PIXMAP).copy(Game::Asphalt4p.x(), Game::Asphalt4p.y(), Game::GRID_SIZE, Game::GRID_SIZE));
        tileItem->setPos(Game::convertGridPointToPixel(i), Game::convertGridPointToPixel(Game::WINDOW_HEIGHT-4));
        m_scene->addItem(tileItem);
    }
    for(int i = 0; i < Game::WINDOW_WIDTH; ++i)
    {
        QGraphicsPixmapItem* tileItem = new QGraphicsPixmapItem(QPixmap(Game::PATH_TO_TILE_PIXMAP).copy(Game::Asphalt2p.x(), Game::Asphalt2p.y(), Game::GRID_SIZE, Game::GRID_SIZE));
        tileItem->setPos(Game::convertGridPointToPixel(i), Game::convertGridPointToPixel(Game::WINDOW_HEIGHT-3));
        m_scene->addItem(tileItem);
    }
    for(int i = 0; i < Game::WINDOW_WIDTH; ++i)
    {
        QGraphicsPixmapItem* tileItem = new QGraphicsPixmapItem(QPixmap(Game::PATH_TO_TILE_PIXMAP).copy(Game::Asphalt1p.x(), Game::Asphalt1p.y(), Game::GRID_SIZE, Game::GRID_SIZE));
        tileItem->setPos(Game::convertGridPointToPixel(i), Game::convertGridPointToPixel(Game::WINDOW_HEIGHT-2));
        m_scene->addItem(tileItem);
    }
    //Last row
    for(int i = 0; i < Game::WINDOW_WIDTH; ++i)
    {
        QGraphicsPixmapItem* tileItem = new QGraphicsPixmapItem(QPixmap(Game::PATH_TO_TILE_PIXMAP).copy(Game::Asphalt0p.x(), Game::Asphalt0p.y(), Game::GRID_SIZE, Game::GRID_SIZE));
        tileItem->setPos(Game::convertGridPointToPixel(i), Game::convertGridPointToPixel(Game::WINDOW_HEIGHT-1));
        m_scene->addItem(tileItem);
    }
}
