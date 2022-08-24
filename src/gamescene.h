#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsScene>
#include <QTimer>
#include <QElapsedTimer>
#include "game.h"
#include "frog.h"
#include "level.h"
#include "car.h"

class GameScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit GameScene(QObject *parent = nullptr);

signals:

private slots:
    void loop();
private:
    Game m_game;
    Frog *m_frog;
    Car *m_car;
    Level m_level;
    float m_loopTime, m_deltaTime;
    const float m_loopSpeed;
    QTimer m_timer;
    QElapsedTimer m_elapsedTimer;
};

#endif // GAMESCENE_H
