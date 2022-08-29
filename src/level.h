#ifndef LEVEL_H
#define LEVEL_H

#include <QObject>
#include <QGraphicsScene>
#include "game.h"

class Level : public QObject
{
public:
    Level(QGraphicsScene* scene);
    void loadLevel();
    void loadCars();
    void loadLogs();
    void loadTurtles();
private:
    void makeCar(Game::CarType type, QPoint point, int speed, Game::Direction direction);
    void makeLog(int length, QPoint point, int speed, Game::Direction direction);
    QGraphicsScene *m_scene;
    int m_currentLevel;
};

#endif // LEVEL_H
