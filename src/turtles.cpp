#include "turtles.h"

QList<Turtles*> Turtles::s_turtlesManager;

Turtles::Turtles(int count)
    : m_speed(1.0f)
{
    m_direction = Game::Direction::LEFT;
    for(int i = 0; i < count; ++i)
    {
        Turtle* turtle = new Turtle();
        turtle->setPos(i*Game::GRID_SIZE, 0);
        addToGroup(turtle);
        m_turtles.push_back(turtle);
    }
    s_turtlesManager.push_back(this);
}

Turtles::~Turtles()
{
    s_turtlesManager.removeOne(this);
}

void Turtles::setPosition(int grid_x, int grid_y)
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

void Turtles::move()
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
    if(m_direction == Game::Direction::LEFT)
    {
        if(x() < 0 - boundingRect().width())
        {
            setPos(Game::convertGridPointToPixel(Game::WINDOW_WIDTH), y());
        }

    }
    else
    {
        if(x() - boundingRect().width() > Game::RESOLUTION.width())
        {
            setPos(-boundingRect().width(), y());
        }
    }
}

float Turtles::speed() const
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

void Turtles::setDirection(Game::Direction direction)
{
    if(m_direction == direction)
    {
        return;
    }
    m_direction = direction;
    if(m_direction == Game::Direction::LEFT)
    {
        for(Turtle* turtle : m_turtles)
        {
            turtle->setTurtlePixmap(QPixmap(Game::PATH_TO_TURTLE_PIXMAP));
        }
    }
    else
    {
        for(Turtle* turtle : m_turtles)
        {
            turtle->setTurtlePixmap(QPixmap(Game::PATH_TO_TURTLE_R_PIXMAP));
        }
    }
}

bool Turtles::checkFrog(const Frog *frog)
{
    if(frog->isDead())
    {
        return false;
    }
    if(x() <= frog->pos().x() && x() + boundingRect().width()  >= frog->pos().x() + frog->boundingRect().width() &&
       y() <= frog->pos().y() && y() + boundingRect().height() >= frog->pos().y() + frog->boundingRect().height() &&
            !m_turtles.at(0)->isUnderWater())
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Turtles::setRandomSpeed(int X)
{
    float r2 = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/X))+1;
    m_speed = r2;
}
