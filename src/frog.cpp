#include "frog.h"

#include <QKeyEvent>

Frog::Frog()
    : QGraphicsPixmapItem(Game::PATH_TO_FROG_PIXMAP)
{
    m_pixmap = pixmap();
    m_direction = Game::Direction::UP;
    setPixmap(m_pixmap.copy(int(m_direction)*Game::GRID_SIZE, 0, Game::GRID_SIZE, Game::GRID_SIZE ));

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

void Frog::keyPressEvent(QKeyEvent *event)
{
    if(!event->isAutoRepeat())
    {
        switch (event->key()) {
        case Qt::Key_Up:
        {
            setPosition(m_gridPos.x(), m_gridPos.y()-1);
            m_direction = Game::Direction::UP;
        }
            break;
        case Qt::Key_Right:
        {
            setPosition(m_gridPos.x()+1, m_gridPos.y());
            m_direction = Game::Direction::RIGHT;
        }
            break;
        case Qt::Key_Left:
        {
            setPosition(m_gridPos.x()-1, m_gridPos.y());
            m_direction = Game::Direction::LEFT;
        }
            break;
        }
        setPixmap(m_pixmap.copy(int(m_direction)*Game::GRID_SIZE, 0, Game::GRID_SIZE, Game::GRID_SIZE ));
    }
}
