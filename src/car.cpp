#include "car.h"

Car::Car(QObject *parent)
    : QObject{parent}, QGraphicsPixmapItem(QPixmap(Game::PATH_TO_CAR_PIXMAP))
{
    m_speed = 1.f;
    m_direction = Game::Direction::LEFT;

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
    }
    else if(x() > Game::RESOLUTION.width())
    {
        m_direction = Game::Direction::LEFT;
    }
    qDebug() << "pos" << pos();
}

void Car::setPosition(QPoint gridPoint)
{
    setPosition(gridPoint.x(), gridPoint.y());
}
