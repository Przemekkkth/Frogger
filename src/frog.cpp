#include "frog.h"
#include "car.h"
#include <QKeyEvent>
#include <QGraphicsScene>

Frog::Frog()
    : QGraphicsPixmapItem(Game::PATH_TO_FROG_PIXMAP), m_isDead(false),
      m_moveUp(false), m_moveDown(false), m_moveLeft(false), m_moveRight(false),
      m_onLog(false), m_currentMeltFrogFrame(0)
{
    m_pixmap = pixmap();
    m_direction = Game::Direction::UP;
    setPixmap(m_pixmap.copy(int(m_direction)*Game::GRID_SIZE, 0, Game::GRID_SIZE, Game::GRID_SIZE ));

    m_deadFrogPixmap.load(Game::PATH_TO_DEAD_FROG_PIXMAP);
    m_meltFrogPixmap.load(Game::PATH_TO_MELTING_FROG_PIXMAP);

    setPosition(Game::WINDOW_WIDTH/2-1, Game::WINDOW_HEIGHT-1);
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
    setZValue(int(Game::Layer::FROG));

    connect(&m_meltFrogTimer, &QTimer::timeout, this, &Frog::updateMeltFrogPixmap);
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

QPoint Frog::position() const
{
    return m_gridPos;
}

void Frog::setDeadByCar()
{
    if(m_isDead)
    {
        return;
    }
    m_isDead = true;
    setPixmap(m_deadFrogPixmap.copy(int(m_direction)*Game::GRID_SIZE, 0, Game::GRID_SIZE, Game::GRID_SIZE ));
}

void Frog::setDeadByWater()
{
    if(m_isDead)
    {
        return;
    }
    m_isDead = true;
    setPixmap(m_meltFrogPixmap.copy(m_currentMeltFrogFrame*Game::GRID_SIZE,int(m_direction)*Game::GRID_SIZE, Game::GRID_SIZE, Game::GRID_SIZE ));
    m_meltFrogTimer.start(125);
}

void Frog::setLife()
{
    m_isDead = false;
    m_meltFrogTimer.stop();
    m_currentMeltFrogFrame = 0;
    m_direction = Game::Direction::UP;
    setPosition(Game::WINDOW_WIDTH/2-1, Game::WINDOW_HEIGHT-1);
    setPixmap(m_pixmap.copy(int(m_direction)*Game::GRID_SIZE, 0, Game::GRID_SIZE, Game::GRID_SIZE ));
}

void Frog::checkCollisionWithCar()
{
    QList<QGraphicsItem*> collidedList = collidingItems();
    for(int idx = collidedList.size() - 1; idx >= 0; --idx)
    {
        Car* car = dynamic_cast<Car*>(collidedList[idx]);
        if(car)
        {
            setDeadByCar();
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
        if(!m_onLog)
        {
            setPosition(m_gridPos.x(), m_gridPos.y()-1);
        }
        else
        {
            setPos(x(), y()-Game::GRID_SIZE);
            m_gridPos.setY(m_gridPos.y() - 1);
        }
        m_direction = Game::Direction::UP;
        setPixmap(m_pixmap.copy(int(m_direction)*Game::GRID_SIZE, 0, Game::GRID_SIZE, Game::GRID_SIZE ));
        m_moveUp = false;
    }
    else if(m_moveDown)
    {
        if(Game::convertPixelToGridPoint(y()) == Game::MAX_WATER_Y)
        {
            m_gridPos.setX(Game::convertPixelToGridPoint(x()));
            m_gridPos.setY(Game::convertPixelToGridPoint(y()));
            setPosition(m_gridPos.x(), m_gridPos.y()+1);
            setOnLog(false);
        }
        else
        {
            if(!m_onLog)
            {
                setPosition(m_gridPos.x(), m_gridPos.y()+1);
            }
            else
            {
                setPos(x(), y()+Game::GRID_SIZE);
                m_gridPos.setY(m_gridPos.y() + 1);
            }
        }


        m_direction = Game::Direction::DOWN;
        setPixmap(m_pixmap.copy(int(m_direction)*Game::GRID_SIZE, 0, Game::GRID_SIZE, Game::GRID_SIZE ));
        m_moveDown = false;
    }
    else if(m_moveLeft)
    {
        if(!m_onLog)
        {
            setPosition(m_gridPos.x()-1, m_gridPos.y());
        }
        else
        {
            setPos(x()-Game::GRID_SIZE, y());
        }
        m_direction = Game::Direction::LEFT;
        setPixmap(m_pixmap.copy(int(m_direction)*Game::GRID_SIZE, 0, Game::GRID_SIZE, Game::GRID_SIZE ));
        m_moveLeft = false;
    }
    else if(m_moveRight)
    {
        if(!m_onLog)
        {
            setPosition(m_gridPos.x()+1, m_gridPos.y());
        }
        else
        {
            setPos(x()+Game::GRID_SIZE, y());
        }

        m_direction = Game::Direction::RIGHT;
        setPixmap(m_pixmap.copy(int(m_direction)*Game::GRID_SIZE, 0, Game::GRID_SIZE, Game::GRID_SIZE ));
        m_moveRight = false;
    }
    checkCollisionWithCar();
}

void Frog::move(float speed)
{
    m_gridPos.setX(Game::convertPixelToGridPoint(pos().x()));
    moveBy(speed, 0);
    if(x() < 0)
    {
        setX(0);
    }
    else if(x() + boundingRect().width() > Game::RESOLUTION.width())
    {
        setX(Game::RESOLUTION.width() - boundingRect().width());
    }
}

void Frog::setOnLog(bool val)
{
    m_onLog = val;
}

bool Frog::onLog() const
{
    return m_onLog;
}

bool Frog::isDead() const
{
    return m_isDead;
}

void Frog::checkSwampPos()
{
    //  0
    if(!Game::SWAMP_POS[0] && (position().x() == 1 || position().x() == 2))
    {
        QGraphicsPixmapItem* p = new QGraphicsPixmapItem(Game::PATH_TO_WIN_FROG_PIXMAP);
        p->setPos(1.5*Game::GRID_SIZE, Game::GRID_SIZE);
        scene()->addItem(p);
        setPosition(Game::WINDOW_WIDTH/2-1, Game::WINDOW_HEIGHT-1);
        Game::SWAMP_POS[0] = true;
        return;
    }
    // 1
    if(!Game::SWAMP_POS[1] && (position().x() == 5 || position().x() == 6))
    {
        QGraphicsPixmapItem* p = new QGraphicsPixmapItem(Game::PATH_TO_WIN_FROG_PIXMAP);
        p->setPos(5*Game::GRID_SIZE+Game::GRID_SIZE/2, Game::GRID_SIZE);
        scene()->addItem(p);
        setPosition(Game::WINDOW_WIDTH/2-1, Game::WINDOW_HEIGHT-1);
        Game::SWAMP_POS[1] = true;
        return;
    }
    // 2
    if(!Game::SWAMP_POS[2] && (position().x() == 9 || position().x() == 10))
    {
        QGraphicsPixmapItem* p = new QGraphicsPixmapItem(Game::PATH_TO_WIN_FROG_PIXMAP);
        p->setPos(9*Game::GRID_SIZE+Game::GRID_SIZE/2, Game::GRID_SIZE);
        scene()->addItem(p);
        setPosition(Game::WINDOW_WIDTH/2-1, Game::WINDOW_HEIGHT-1);
        Game::SWAMP_POS[2] = true;
        return;
    }
    // 3
    if(!Game::SWAMP_POS[3] && (position().x() == 12))
    {
        QGraphicsPixmapItem* p = new QGraphicsPixmapItem(Game::PATH_TO_WIN_FROG_PIXMAP);
        p->setPos(12*Game::GRID_SIZE+Game::GRID_SIZE/2, Game::GRID_SIZE);
        scene()->addItem(p);
        setPosition(Game::WINDOW_WIDTH/2-1, Game::WINDOW_HEIGHT-1);
        Game::SWAMP_POS[3] = true;
        return;
    }

    setDeadByWater();
}

void Frog::updateMeltFrogPixmap()
{
    m_currentMeltFrogFrame++;
    if(m_currentMeltFrogFrame > 3)
    {
        m_currentMeltFrogFrame = 3;
    }
    setPixmap(m_meltFrogPixmap.copy(m_currentMeltFrogFrame*Game::GRID_SIZE,int(m_direction)*Game::GRID_SIZE, Game::GRID_SIZE, Game::GRID_SIZE ));
}

void Frog::keyPressEvent(QKeyEvent *event)
{
    if(!event->isAutoRepeat())
    {
        switch (event->key()) {

        case Qt::Key_Up:
        {
            if(!m_isDead)
            {
                m_moveUp = true;
            }
        }
            break;
        case Qt::Key_Right:
        {
            if(!m_isDead)
            {
                m_moveRight = true;
            }
        }
            break;
        case Qt::Key_Left:
        {
            if(!m_isDead)
            {
                m_moveLeft = true;
            }
        }
            break;
        case Qt::Key_Down:
        {
            if(!m_isDead)
            {
                m_moveDown = true;
            }
        }
            break;
        case Qt::Key_Enter:
        case Qt::Key_R:
        {
            if(m_isDead)
            {
                setLife();
            }
        }
            break;


        }

    }
}
