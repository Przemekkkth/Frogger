#ifndef TURTLES_H
#define TURTLES_H

#include <QObject>
#include <QGraphicsItemGroup>
#include "game.h"
#include "turtle.h"
#include "frog.h"

class Turtles : public QObject, public QGraphicsItemGroup
{
    Q_OBJECT
public:
    explicit Turtles(int count = 2);
    ~Turtles();
    void setPosition(int grid_x, int grid_y);
    void move();
    float speed() const;
    void setDirection(Game::Direction direction);
    bool checkFrog(const Frog* frog);
    void setRandomSpeed(int X=1);
    static QList<Turtles*> s_turtlesManager;
signals:


private:
    QList<Turtle*> m_turtles;
    float m_speed;
    Game::Direction m_direction;
};

#endif // TURTLES_H
