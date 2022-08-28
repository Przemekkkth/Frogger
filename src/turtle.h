#ifndef TURTLE_H
#define TURTLE_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include "game.h"

class Turtle : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Turtle();
    bool isUnderWater();
signals:
private slots:
    void updatePixmap();

private:

    QPixmap m_pixmap;
    QTimer m_timer;
    int m_currentFrame;

    static const int COUNT_OF_ANIM_FRAMES;
};

#endif // TURTLE_H
