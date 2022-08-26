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
    QPoint position() const;
    void setDead();
    void setLife();
    void checkCollisionWithCar();
    void updateFrog();
    void move(float speed);
    void setOnLog(bool val);
    bool onLog() const;
signals:

private:

    QPoint m_gridPos;
    QPixmap m_pixmap;
    QPixmap m_deadFrogPixmap;
    Game::Direction m_direction;
    bool m_isDead;
    bool m_moveUp, m_moveDown, m_moveLeft, m_moveRight;
    bool m_onLog;
protected:
    virtual void keyPressEvent(QKeyEvent *event) override;
};

#endif // FROG_H
