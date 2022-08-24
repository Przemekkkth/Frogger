#ifndef CAR_H
#define CAR_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QList>
#include "game.h"

class Car : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Car(Game::CarType type);
    ~Car();
    void setPosition(QPoint gridPoint);
    void setPosition(int grid_X, int grid_y);
    void move();
    void setRandomSpeed(int X = 1);
    void setDirection(Game::Direction direction);

    static QList<Car*> s_carsManager;
signals:

private:
    float m_speed;
    Game::Direction m_direction;
    Game::CarType m_type;
    QPixmap m_pixmap;
    QPixmap m_pixmap_r;
    int m_carSize;
    void choosePixmap();
};

#endif // CAR_H
