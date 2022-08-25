#include "car.h"

QList<Car*> Car::s_carsManager;

Car::Car(Game::CarType type)
    : QGraphicsPixmapItem(QPixmap(Game::PATH_TO_CAR_PIXMAP))
{
    m_speed = 1.f;
    m_direction = Game::Direction::LEFT;
    m_pixmap = pixmap();
    m_pixmap_r = QPixmap(Game::PATH_TO_CAR_R_PIXMAP);
    m_type = type;

    choosePixmap();

    s_carsManager.push_back(this);
    setZValue(int(Game::Layer::CAR));
}

Car::~Car()
{
    s_carsManager.removeOne(this);
}

void Car::choosePixmap()
{
    QPixmap newPixmap;
    if(m_direction == Game::Direction::LEFT)
    {
        newPixmap = m_pixmap;
    }
    else
    {
        newPixmap = m_pixmap_r;
    }

    switch(m_type)
    {
    case Game::CarType::RACER:
    {
        m_carSize = Game::GRID_SIZE;
        setPixmap(newPixmap.copy(0,0,m_carSize,m_carSize));
    }
        break;
    case Game::CarType::CAR:
    {
        m_carSize = Game::GRID_SIZE;
        setPixmap(newPixmap.copy(32,0,m_carSize,m_carSize));
    }
        break;
    case Game::CarType::BULLDOZER:
    {
        m_carSize = Game::GRID_SIZE;
        setPixmap(newPixmap.copy(64,0,m_carSize,m_carSize));
    }
        break;
    case Game::CarType::TIR:
    {
        m_carSize = 2*Game::GRID_SIZE;
        setPixmap(newPixmap.copy(96,0,m_carSize,m_carSize));
    }
    }
}

void Car::setPosition(int grid_x, int grid_y)
{
    if(grid_x <= 0)
    {
        grid_x = 0;
    }
    else if(grid_x >= Game::WINDOW_WIDTH)
    {
        grid_x = Game::WINDOW_WIDTH - 1;
    }
    if(grid_y <= 0)
    {
        grid_y = 0;
    }

    int x = Game::convertGridPointToPixel(grid_x);
    int y = Game::convertGridPointToPixel(grid_y);
    setPos(x, y);
}

void Car::move()
{
    if(m_direction == Game::Direction::LEFT)
    {
        moveBy(-m_speed, 0);
    }
    else if(m_direction == Game::Direction::RIGHT)
    {
        moveBy(m_speed, 0);
    }

    if(x() + boundingRect().width() < 0)
    {
        m_direction = Game::Direction::RIGHT;
        choosePixmap();
    }
    else if(x() > Game::RESOLUTION.width())
    {
        m_direction = Game::Direction::LEFT;
        choosePixmap();
    }
}

void Car::setRandomSpeed(int X)
{
    float r2 = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/X))+1;
    m_speed = r2;
}

void Car::setDirection(Game::Direction direction)
{
    if(m_direction == direction)
    {
        return;
    }
    m_direction = direction;
    choosePixmap();
}

void Car::setPosition(QPoint gridPoint)
{
    setPosition(gridPoint.x(), gridPoint.y());
}
