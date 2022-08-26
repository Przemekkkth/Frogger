#include "level.h"
#include "game.h"
#include "car.h"
#include "log.h"
#include <QGraphicsPixmapItem>

Level::Level(QGraphicsScene *scene)
    : m_scene(scene), m_currentLevel(0)
{

}

void Level::loadLevel()
{
    //0
    for(int i = 0; i < Game::WINDOW_WIDTH; ++i)
    {
        QGraphicsPixmapItem* tileItem = new QGraphicsPixmapItem(QPixmap(Game::PATH_TO_TILE_PIXMAP).copy(Game::Grass0p.x(), Game::Grass0p.y(), Game::GRID_SIZE, Game::GRID_SIZE));
        tileItem->setPos(Game::convertGridPointToPixel(i), Game::convertGridPointToPixel(0));
        m_scene->addItem(tileItem);
    }
    //1
        QGraphicsPixmapItem* tileItem1 = new QGraphicsPixmapItem(QPixmap(Game::PATH_TO_TILE_PIXMAP).copy(Game::Grass0p.x(), Game::Grass0p.y(), Game::GRID_SIZE, Game::GRID_SIZE));
        tileItem1->setPos(Game::convertGridPointToPixel(0), Game::convertGridPointToPixel(1));
        m_scene->addItem(tileItem1);

        QGraphicsPixmapItem* tileItem2 = new QGraphicsPixmapItem(QPixmap(Game::PATH_TO_TILE_PIXMAP).copy(Game::Water0p.x(), Game::Water0p.y(), Game::GRID_SIZE, Game::GRID_SIZE));
        tileItem2->setPos(Game::convertGridPointToPixel(1), Game::convertGridPointToPixel(1));
        m_scene->addItem(tileItem2);

        QGraphicsPixmapItem* tileItem3 = new QGraphicsPixmapItem(QPixmap(Game::PATH_TO_TILE_PIXMAP).copy(Game::Water0p.x(), Game::Water0p.y(), Game::GRID_SIZE, Game::GRID_SIZE));
        tileItem3->setPos(Game::convertGridPointToPixel(2), Game::convertGridPointToPixel(1));
        m_scene->addItem(tileItem3);

        QGraphicsPixmapItem* tileItem4 = new QGraphicsPixmapItem(QPixmap(Game::PATH_TO_TILE_PIXMAP).copy(Game::Grass0p.x(), Game::Grass0p.y(), Game::GRID_SIZE, Game::GRID_SIZE));
        tileItem4->setPos(Game::convertGridPointToPixel(3), Game::convertGridPointToPixel(1));
        m_scene->addItem(tileItem4);

        QGraphicsPixmapItem* tileItem5 = new QGraphicsPixmapItem(QPixmap(Game::PATH_TO_TILE_PIXMAP).copy(Game::Grass0p.x(), Game::Grass0p.y(), Game::GRID_SIZE, Game::GRID_SIZE));
        tileItem5->setPos(Game::convertGridPointToPixel(4), Game::convertGridPointToPixel(1));
        m_scene->addItem(tileItem5);

        QGraphicsPixmapItem* tileItem6 = new QGraphicsPixmapItem(QPixmap(Game::PATH_TO_TILE_PIXMAP).copy(Game::Water0p.x(), Game::Water0p.y(), Game::GRID_SIZE, Game::GRID_SIZE));
        tileItem6->setPos(Game::convertGridPointToPixel(5), Game::convertGridPointToPixel(1));
        m_scene->addItem(tileItem6);

        QGraphicsPixmapItem* tileItem7 = new QGraphicsPixmapItem(QPixmap(Game::PATH_TO_TILE_PIXMAP).copy(Game::Water0p.x(), Game::Water0p.y(), Game::GRID_SIZE, Game::GRID_SIZE));
        tileItem7->setPos(Game::convertGridPointToPixel(6), Game::convertGridPointToPixel(1));
        m_scene->addItem(tileItem7);

        QGraphicsPixmapItem* tileItem8 = new QGraphicsPixmapItem(QPixmap(Game::PATH_TO_TILE_PIXMAP).copy(Game::Grass0p.x(), Game::Grass0p.y(), Game::GRID_SIZE, Game::GRID_SIZE));
        tileItem8->setPos(Game::convertGridPointToPixel(7), Game::convertGridPointToPixel(1));
        m_scene->addItem(tileItem8);

        QGraphicsPixmapItem* tileItem9 = new QGraphicsPixmapItem(QPixmap(Game::PATH_TO_TILE_PIXMAP).copy(Game::Grass0p.x(), Game::Grass0p.y(), Game::GRID_SIZE, Game::GRID_SIZE));
        tileItem9->setPos(Game::convertGridPointToPixel(8), Game::convertGridPointToPixel(1));
        m_scene->addItem(tileItem9);

        QGraphicsPixmapItem* tileItem10 = new QGraphicsPixmapItem(QPixmap(Game::PATH_TO_TILE_PIXMAP).copy(Game::Water0p.x(), Game::Water0p.y(), Game::GRID_SIZE, Game::GRID_SIZE));
        tileItem10->setPos(Game::convertGridPointToPixel(9), Game::convertGridPointToPixel(1));
        m_scene->addItem(tileItem10);

        QGraphicsPixmapItem* tileItem11 = new QGraphicsPixmapItem(QPixmap(Game::PATH_TO_TILE_PIXMAP).copy(Game::Water0p.x(), Game::Water0p.y(), Game::GRID_SIZE, Game::GRID_SIZE));
        tileItem11->setPos(Game::convertGridPointToPixel(10), Game::convertGridPointToPixel(1));
        m_scene->addItem(tileItem11);

        QGraphicsPixmapItem* tileItem12 = new QGraphicsPixmapItem(QPixmap(Game::PATH_TO_TILE_PIXMAP).copy(Game::Grass0p.x(), Game::Grass0p.y(), Game::GRID_SIZE, Game::GRID_SIZE));
        tileItem12->setPos(Game::convertGridPointToPixel(11), Game::convertGridPointToPixel(1));
        m_scene->addItem(tileItem12);

        QGraphicsPixmapItem* tileItem13 = new QGraphicsPixmapItem(QPixmap(Game::PATH_TO_TILE_PIXMAP).copy(Game::Water0p.x(), Game::Water0p.y(), Game::GRID_SIZE, Game::GRID_SIZE));
        tileItem13->setPos(Game::convertGridPointToPixel(12), Game::convertGridPointToPixel(1));
        m_scene->addItem(tileItem13);

        QGraphicsPixmapItem* tileItem14 = new QGraphicsPixmapItem(QPixmap(Game::PATH_TO_TILE_PIXMAP).copy(Game::Grass0p.x(), Game::Grass0p.y(), Game::GRID_SIZE, Game::GRID_SIZE));
        tileItem14->setPos(Game::convertGridPointToPixel(13), Game::convertGridPointToPixel(1));
        m_scene->addItem(tileItem14);
    //2
    for(int i = 0; i < Game::WINDOW_WIDTH; ++i)
    {
        QGraphicsPixmapItem* tileItem = new QGraphicsPixmapItem(QPixmap(Game::PATH_TO_TILE_PIXMAP).copy(Game::Water0p.x(), Game::Water0p.y(), Game::GRID_SIZE, Game::GRID_SIZE));
        tileItem->setPos(Game::convertGridPointToPixel(i), Game::convertGridPointToPixel(Game::WINDOW_HEIGHT-14));
        m_scene->addItem(tileItem);
    }
    for(int i = 0; i < Game::WINDOW_WIDTH; ++i)
    {
        QGraphicsPixmapItem* tileItem = new QGraphicsPixmapItem(QPixmap(Game::PATH_TO_TILE_PIXMAP).copy(Game::Water0p.x(), Game::Water0p.y(), Game::GRID_SIZE, Game::GRID_SIZE));
        tileItem->setPos(Game::convertGridPointToPixel(i), Game::convertGridPointToPixel(Game::WINDOW_HEIGHT-13));
        m_scene->addItem(tileItem);
    }
    for(int i = 0; i < Game::WINDOW_WIDTH; ++i)
    {
        QGraphicsPixmapItem* tileItem = new QGraphicsPixmapItem(QPixmap(Game::PATH_TO_TILE_PIXMAP).copy(Game::Water0p.x(), Game::Water0p.y(), Game::GRID_SIZE, Game::GRID_SIZE));
        tileItem->setPos(Game::convertGridPointToPixel(i), Game::convertGridPointToPixel(Game::WINDOW_HEIGHT-12));
        m_scene->addItem(tileItem);
    }
    for(int i = 0; i < Game::WINDOW_WIDTH; ++i)
    {
        QGraphicsPixmapItem* tileItem = new QGraphicsPixmapItem(QPixmap(Game::PATH_TO_TILE_PIXMAP).copy(Game::Water0p.x(), Game::Water0p.y(), Game::GRID_SIZE, Game::GRID_SIZE));
        tileItem->setPos(Game::convertGridPointToPixel(i), Game::convertGridPointToPixel(Game::WINDOW_HEIGHT-12));
        m_scene->addItem(tileItem);
    }
    for(int i = 0; i < Game::WINDOW_WIDTH; ++i)
    {
        QGraphicsPixmapItem* tileItem = new QGraphicsPixmapItem(QPixmap(Game::PATH_TO_TILE_PIXMAP).copy(Game::Water0p.x(), Game::Water0p.y(), Game::GRID_SIZE, Game::GRID_SIZE));
        tileItem->setPos(Game::convertGridPointToPixel(i), Game::convertGridPointToPixel(Game::WINDOW_HEIGHT-11));
        m_scene->addItem(tileItem);
    }
    for(int i = 0; i < Game::WINDOW_WIDTH; ++i)
    {
        QGraphicsPixmapItem* tileItem = new QGraphicsPixmapItem(QPixmap(Game::PATH_TO_TILE_PIXMAP).copy(Game::Water0p.x(), Game::Water0p.y(), Game::GRID_SIZE, Game::GRID_SIZE));
        tileItem->setPos(Game::convertGridPointToPixel(i), Game::convertGridPointToPixel(Game::WINDOW_HEIGHT-10));
        m_scene->addItem(tileItem);
    }
    for(int i = 0; i < Game::WINDOW_WIDTH; ++i)
    {
        QGraphicsPixmapItem* tileItem = new QGraphicsPixmapItem(QPixmap(Game::PATH_TO_TILE_PIXMAP).copy(Game::Water0p.x(), Game::Water0p.y(), Game::GRID_SIZE, Game::GRID_SIZE));
        tileItem->setPos(Game::convertGridPointToPixel(i), Game::convertGridPointToPixel(Game::WINDOW_HEIGHT-9));
        m_scene->addItem(tileItem);
    }
    for(int i = 0; i < Game::WINDOW_WIDTH; ++i)
    {
        QGraphicsPixmapItem* tileItem = new QGraphicsPixmapItem(QPixmap(Game::PATH_TO_TILE_PIXMAP).copy(Game::Asphalt0p.x(), Game::Asphalt0p.y(), Game::GRID_SIZE, Game::GRID_SIZE));
        tileItem->setPos(Game::convertGridPointToPixel(i), Game::convertGridPointToPixel(Game::WINDOW_HEIGHT-8));
        m_scene->addItem(tileItem);
    }
    for(int i = 0; i < Game::WINDOW_WIDTH; ++i)
    {
        QGraphicsPixmapItem* tileItem = new QGraphicsPixmapItem(QPixmap(Game::PATH_TO_TILE_PIXMAP).copy(Game::Asphalt3p.x(), Game::Asphalt3p.y(), Game::GRID_SIZE, Game::GRID_SIZE));
        tileItem->setPos(Game::convertGridPointToPixel(i), Game::convertGridPointToPixel(Game::WINDOW_HEIGHT-7));
        m_scene->addItem(tileItem);
    }
    for(int i = 0; i < Game::WINDOW_WIDTH; ++i)
    {
        QGraphicsPixmapItem* tileItem = new QGraphicsPixmapItem(QPixmap(Game::PATH_TO_TILE_PIXMAP).copy(Game::Asphalt2p.x(), Game::Asphalt2p.y(), Game::GRID_SIZE, Game::GRID_SIZE));
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

void Level::loadCars()
{
    if(m_currentLevel == 0)
    {
        Car* car = new Car(Game::CarType::RACER);
        m_scene->addItem(car);
        car->setPosition(8, Game::WINDOW_HEIGHT-2);
        car->setRandomSpeed(1);
        car->setDirection(Game::Direction::LEFT);

        Car* car1 = new Car(Game::CarType::BULLDOZER);
        m_scene->addItem(car1);
        car1->setPosition(5, Game::WINDOW_HEIGHT-3);
        car1->setRandomSpeed(1);
        car1->setDirection(Game::Direction::LEFT);

        Car* car2 = new Car(Game::CarType::CAR);
        m_scene->addItem(car2);
        car2->setPosition(10, Game::WINDOW_HEIGHT-4);
        car2->setRandomSpeed(1);
        car2->setDirection(Game::Direction::RIGHT);

        Car* car3 = new Car(Game::CarType::TIR);
        m_scene->addItem(car3);
        car3->setPosition(10, Game::WINDOW_HEIGHT-5);
        car3->setRandomSpeed(1);
        car3->setDirection(Game::Direction::LEFT);
    }
}

void Level::loadLogs()
{
    if(m_currentLevel == 0)
    {
        Log* log = new Log(3);
        log->setPosition(8,7);
        log->setDirection(Game::Direction::RIGHT);
        m_scene->addItem(log);

        Log* log1 = new Log(3);
        log1->setPosition(12,7);
        log1->setDirection(Game::Direction::RIGHT);
        m_scene->addItem(log1);

        Log* log2 = new Log(2);
        log2->setPosition(8,6);
        m_scene->addItem(log2);

        Log* log3 = new Log(2);
        log3->setPosition(8, 5);
        m_scene->addItem(log3);

        Log* log4 = new Log(2);
        log4->setPosition(8, 4);
        m_scene->addItem(log4);

        Log* log5 = new Log(2);
        log5->setPosition(8, 3);
        m_scene->addItem(log5);

        Log* log6 = new Log(2);
        log6->setPosition(8, 2);
        m_scene->addItem(log6);
    }
}
