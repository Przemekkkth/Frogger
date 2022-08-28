#include "turtle.h"

const int Turtle::COUNT_OF_ANIM_FRAMES = 8;

Turtle::Turtle()
    : QGraphicsPixmapItem(Game::PATH_TO_TURTLE_PIXMAP), m_currentFrame(0)
{
    m_pixmap = pixmap();
    setPixmap(m_pixmap.copy(0,0, Game::GRID_SIZE, Game::GRID_SIZE));
    connect(&m_timer, &QTimer::timeout, this, &Turtle::updatePixmap);
    m_timer.start(500);
}

bool Turtle::isUnderWater()
{
    if(m_currentFrame == 3 || m_currentFrame == 4)
    {
        return true;
    }
    return false;
}

void Turtle::setTurtlePixmap(QPixmap pixmap)
{
    m_pixmap = pixmap;
    m_currentFrame = 0;
    setPixmap(m_pixmap.copy(0,0, Game::GRID_SIZE, Game::GRID_SIZE));
}

void Turtle::updatePixmap()
{
    m_currentFrame++;
    m_currentFrame %= COUNT_OF_ANIM_FRAMES;
    setPixmap(m_pixmap.copy(m_currentFrame*Game::GRID_SIZE, 0, Game::GRID_SIZE, Game::GRID_SIZE));
}
