#include "gamescene.h"

GameScene::GameScene(QObject *parent)
    : QGraphicsScene{parent}, m_level(this)
{
    setSceneRect(0, 0, Game::RESOLUTION.width(), Game::RESOLUTION.height());
    setBackgroundBrush(QBrush(Qt::black));

    m_level.loadLevel();

    m_frog = new Frog();
    addItem(m_frog);
}
