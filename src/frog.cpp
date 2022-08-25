#include "frog.h"
#include "car.h"
#include <QKeyEvent>

Frog::Frog()
    : QGraphicsPixmapItem(Game::PATH_TO_FROG_PIXMAP), m_isDead(false),
      m_moveUp(false), m_moveDown(false), m_moveLeft(false), m_moveRight(false)
{
    m_pixmap = pixmap();
    m_direction = Game::Direction::UP;
    setPixmap(m_pixmap.copy(int(m_direction)*Game::GRID_SIZE, 0, Game::GRID_SIZE, Game::GRID_SIZE ));

    m_deadFrogPixmap.load(Game::PATH_TO_DEAD_FROG_PIXMAP);

    setPosition(Game::WINDOW_WIDTH/2-1, Game::WINDOW_HEIGHT-1);
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
}

void Frog::setPosition(int grid_x, int grid_y)
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
    else if(grid_y >= Game::WINDOW_HEIGHT)
    {
        grid_y = Game::WINDOW_HEIGHT - 1;
    }
    m_gridPos.setX(grid_x);
    m_gridPos.setY(grid_y);

    int x = Game::convertGridPointToPixel(grid_x);
    int y = Game::convertGridPointToPixel(grid_y);
    setPos(x, y);
}

void Frog::setPosition(QPoint gridPoint)
{
    setPosition(gridPoint.x(), gridPoint.y());
}

void Frog::setDead()
{
    m_isDead = true;
    setPixmap(m_deadFrogPixmap.copy(int(m_direction)*Game::GRID_SIZE, 0, Game::GRID_SIZE, Game::GRID_SIZE ));
}

void Frog::checkCollisionWithCar()
{
    QList<QGraphicsItem*> collidedList = collidingItems();
    for(int idx = collidedList.size() - 1; idx >= 0; --idx)
    {
        Car* car = dynamic_cast<Car*>(collidedList[idx]);
        if(car)
        {
            setDead();
            return;
        }
    }
}

void Frog::updateFrog()
{
    if(m_isDead)
    {
        return;
    }
    if(m_moveUp)
    {
        setPosition(m_gridPos.x(), m_gridPos.y()-1);
        m_direction = Game::Direction::UP;
        setPixmap(m_pixmap.copy(int(m_direction)*Game::GRID_SIZE, 0, Game::GRID_SIZE, Game::GRID_SIZE ));
        m_moveUp = false;
    }
    else if(m_moveDown)
    {
        setPosition(m_gridPos.x(), m_gridPos.y()+1);
        m_direction = Game::Direction::DOWN;
        setPixmap(m_pixmap.copy(int(m_direction)*Game::GRID_SIZE, 0, Game::GRID_SIZE, Game::GRID_SIZE ));
        m_moveDown = false;
    }
    else if(m_moveLeft)
    {
        setPosition(m_gridPos.x()-1, m_gridPos.y());
        m_direction = Game::Direction::LEFT;
        setPixmap(m_pixmap.copy(int(m_direction)*Game::GRID_SIZE, 0, Game::GRID_SIZE, Game::GRID_SIZE ));
        m_moveLeft = false;
    }
    else if(m_moveRight)
    {
        setPosition(m_gridPos.x()+1, m_gridPos.y());
        m_direction = Game::Direction::RIGHT;
        setPixmap(m_pixmap.copy(int(m_direction)*Game::GRID_SIZE, 0, Game::GRID_SIZE, Game::GRID_SIZE ));
        m_moveRight = false;
    }
    checkCollisionWithCar();
}

void Frog::keyPressEvent(QKeyEvent *event)
{
    if(!event->isAutoRepeat())
    {
        switch (event->key()) {

        case Qt::Key_Up:
        {
            m_moveUp = true;
  }
            break;
        case Qt::Key_Right:
        {
            m_moveRight = true;
     }
            break;
        case Qt::Key_Left:
        {
            m_moveLeft = true;
      }
            break;
        case Qt::Key_Down:
        {
            m_moveDown = true;
    }
            break;


        }

    }
}
