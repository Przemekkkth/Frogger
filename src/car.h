#ifndef CAR_H
#define CAR_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include "game.h"

class Car : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Car(QObject *parent = nullptr);
    void setPosition(QPoint gridPoint);
    void setPosition(int grid_X, int grid_y);
    void move();
signals:

private:
    float m_speed;
    Game::Direction m_direction;
};

#endif // CAR_H
