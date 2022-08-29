#include "gamescene.h"
#include "log.h"
#include "turtles.h"

GameScene::GameScene(QObject *parent)
    : QGraphicsScene{parent}, m_level(this),
      m_loopTime(0.0f),
      m_deltaTime(0.0f), m_loopSpeed(int(1000.0f/Game::FPS))
{
    srand(time(0));
    setSceneRect(0, 0, Game::RESOLUTION.width(), Game::RESOLUTION.height());
    setBackgroundBrush(QBrush(Qt::black));

    m_level.loadLevel();
    m_level.loadCars();
    m_level.loadLogs();
    m_level.loadTurtles();

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

        bool isFragUnderWater = true;
        for(int idx = Log::s_logsManager.size()-1; idx >= 0; --idx)
        {
            Log::s_logsManager.at(idx)->move();
            if(Log::s_logsManager.at(idx)->checkFrog(m_frog) &&
                    m_frog->position().y() <= Game::MAX_WATER_Y && m_frog->position().y() >= Game::MIN_WATER_Y)
            {
                m_frog->move(Log::s_logsManager.at(idx)->speed());
                m_frog->setOnLog(true);
                isFragUnderWater = false;
            }
        }

        for(int idx = Turtles::s_turtlesManager.size()-1; idx >= 0; --idx)
        {
            Turtles::s_turtlesManager.at(idx)->move();
            if(Turtles::s_turtlesManager.at(idx)->checkFrog(m_frog) &&
                    m_frog->position().y() <= Game::MAX_WATER_Y && m_frog->position().y() >= Game::MIN_WATER_Y)
            {
                m_frog->move(Turtles::s_turtlesManager.at(idx)->speed());
                m_frog->setOnLog(true);
                isFragUnderWater = false;
            }
        }
        if( isFragUnderWater &&
                m_frog->position().y() <= Game::MAX_WATER_Y && m_frog->position().y() >= Game::MIN_WATER_Y)
        {
            m_frog->setDeadByWater();
            m_frog->setOnLog(false);
        }

        if( m_frog->position().y() == Game::SWAMP_Y)
        {
            m_frog->checkSwampPos();
        }

        m_frog->updateFrog();
    }
}
