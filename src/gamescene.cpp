#include "gamescene.h"

GameScene::GameScene(QObject *parent)
    : QGraphicsScene{parent}, m_level(this),
      m_loopTime(0.0f),
      m_deltaTime(0.0f), m_loopSpeed(int(1000.0f/Game::FPS))
{
    setSceneRect(0, 0, Game::RESOLUTION.width(), Game::RESOLUTION.height());
    setBackgroundBrush(QBrush(Qt::black));

    m_level.loadLevel();

    m_frog = new Frog();
    addItem(m_frog);

    m_car = new Car(Game::CarType::RACER);
    addItem(m_car);
    m_car->setPosition(8, Game::WINDOW_HEIGHT-2);

    m_car1 = new Car(Game::CarType::BULLDOZER);
    addItem(m_car1);
    m_car1->setPosition(5, Game::WINDOW_HEIGHT-3);


    m_car2 = new Car(Game::CarType::CAR);
    addItem(m_car2);
    m_car2->setPosition(14, Game::WINDOW_HEIGHT-4);


    m_car3 = new Car(Game::CarType::TIR);
    addItem(m_car3);
    m_car3->setPosition(10, Game::WINDOW_HEIGHT-5);


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
