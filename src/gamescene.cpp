#include "gamescene.h"

GameScene::GameScene(QObject *parent)
    : QGraphicsScene{parent}, m_level(this),
      m_loopTime(0.0f),
      m_deltaTime(0.0f), m_loopSpeed(int(1000.0f/Game::FPS))
{
    setSceneRect(0, 0, Game::RESOLUTION.width(), Game::RESOLUTION.height());
    setBackgroundBrush(QBrush(Qt::black));

    m_level.loadLevel();
    m_level.loadEntities();

    m_frog = new Frog();
    addItem(m_frog);



    connect(&m_timer, &QTimer::timeout, this, &GameScene::loop);
    m_timer.start(int(1000.0f)/Game::FPS);
    m_elapsedTimer.start();
}


void GameScene::loop()
{
    m_deltaTime = m_elapsedTimer.elapsed();
    m_elapsedTimer.restart();

    m_loopTime += m_deltaTime;
    if( m_loopTime > m_loopSpeed)
    {
        m_loopTime -= m_loopSpeed;
        for(int idx = Car::s_carsManager.size()-1; idx >= 0; --idx)
        {
            Car::s_carsManager.at(idx)->move();
        }
    }
}
