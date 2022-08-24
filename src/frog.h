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
signals:

private:
    QPoint m_gridPos;
    QPixmap m_pixmap;
    Game::Direction m_direction;
protected:
    virtual void keyPressEvent(QKeyEvent *event) override;
};

#endif // FROG_H
