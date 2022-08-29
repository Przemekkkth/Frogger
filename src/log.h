#ifndef LOG_H
#define LOG_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include "game.h"
#include "frog.h" 

class Log : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Log(int type = 0);
    ~Log();
    void setPosition(int grid_x, int grid_y);
    static QList<Log*> s_logsManager;
    void move();

    bool checkFrog(const Frog* frog);
    float speed() const;
    void setDirection(Game::Direction direction);
    void setSpeed(int X=1);

signals:

private:
    Game::Direction m_direction;
    float m_speed;
};

#endif // LOG_H
