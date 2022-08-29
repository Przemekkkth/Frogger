#ifndef FROG_H
#define FROG_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QTimer>
#include <QSoundEffect>
#include "game.h"

class Frog : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Frog();
    void setPosition(int grid_x, int grid_y);
    void setPosition(QPoint gridPoint);
    QPoint position() const;
    void setDeadByCar();
    void setDeadByWater();
    void setLife();
    void checkCollisionWithCar();
    void updateFrog();
    void move(float speed);
    void setOnLog(bool val);
    bool onLog() const;
    bool isDead() const;
    void checkSwampPos();
signals:

private slots:
    void updateMeltFrogPixmap();
private:

    QPoint m_gridPos;
    QPixmap m_pixmap;
    QPixmap m_deadFrogPixmap;
    QPixmap m_meltFrogPixmap;
    Game::Direction m_direction;
    bool m_isDead;
    bool m_moveUp, m_moveDown, m_moveLeft, m_moveRight;
    bool m_onLog;
    int m_currentMeltFrogFrame;
    QTimer m_meltFrogTimer;
    QSoundEffect m_frogExtra_SFX, m_frogPlunk_SFX, m_frogSquash_SFX;
protected:
    virtual void keyPressEvent(QKeyEvent *event) override;
};

#endif // FROG_H
