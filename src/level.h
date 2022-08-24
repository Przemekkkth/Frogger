#ifndef LEVEL_H
#define LEVEL_H

#include <QObject>
#include <QGraphicsScene>

class Level : public QObject
{
public:
    Level(QGraphicsScene* scene);
    void loadLevel();
private:
    QGraphicsScene *m_scene;
};

#endif // LEVEL_H
