#include "log.h"


QList<Log*> Log::s_logsManager;

Log::Log(int type)
    : QGraphicsPixmapItem(Game::PATH_TO_LOG_PIXMAP), m_speed(1)
{
    m_direction = Game::Direction::LEFT;
    if(type == 0)
    {
        setPixmap(pixmap().copy(0,0,Game::GRID_SIZE, Game::GRID_SIZE));
    }
    else if(type == 1)
    {
        setPixmap(pixmap().copy(0,Game::GRID_SIZE,2*Game::GRID_SIZE, Game::GRID_SIZE));
    }
    else
    {
        setPixmap(pixmap().copy(0,2*Game::GRID_SIZE,3*Game::GRID_SIZE, Game::GRID_SIZE));
    }
    setZValue(int(Game::Layer::LOG));
    s_logsManager.push_back(this);
}

Log::~Log()
{
    s_logsManager.removeOne(this);
}

void Log::setPosition(int grid_x, int grid_y)
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

void Log::move()
{
    if(m_direction == Game::Direction::LEFT)
    {
        moveBy(-m_speed, 0);
    }
    else
    {
        moveBy(m_speed, 0);
    }

////////////////////////////

    if(x() < 0 - boundingRect().width())
    {
        setPos(Game::convertGridPointToPixel(Game::WINDOW_WIDTH), y());
    }
    else if(x() - boundingRect().width() > Game::RESOLUTION.width())
    {
        setPos(-2*boundingRect().width(), y());
    }
}

bool Log::checkFrog(const Frog *frog)
{
    if(x() <= frog->pos().x() && x() + boundingRect().width()  >= frog->pos().x() + frog->boundingRect().width() &&
       y() <= frog->pos().y() && y() + boundingRect().height() >= frog->pos().y() + frog->boundingRect().height() )
    {
        qDebug() << "true";
        return true;
    }
    else
    {
        //qDebug() << "false";
        return false;
    }
}

float Log::speed() const
{
    if(m_direction == Game::Direction::LEFT)
    {
        return -m_speed;
    }
    else
    {
        return m_speed;
    }
}
