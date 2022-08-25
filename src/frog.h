#ifndef FROG_H
#define FROG_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include "game.h"

class Frog : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Frog();
    void setPosition(int grid_x, int grid_y);
    void setPosition(QPoint gridPoint);
    void setDead();
    void checkCollisionWithCar();
    void updateFrog();
signals:

private:

    QPoint m_gridPos;
    QPixmap m_pixmap;
    QPixmap m_deadFrogPixmap;
    Game::Direction m_direction;
    bool m_isDead;
    bool m_moveUp, m_moveDown, m_moveLeft, m_moveRight;
protected:
    virtual void keyPressEvent(QKeyEvent *event) override;
};

#endif // FROG_H
