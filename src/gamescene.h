#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsScene>
#include "game.h"
#include "frog.h"
#include "level.h"

class GameScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit GameScene(QObject *parent = nullptr);

signals:

private:
    Game m_game;
    Frog *m_frog;
    Level m_level;
};

#endif // GAMESCENE_H
