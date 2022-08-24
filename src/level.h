#ifndef LEVEL_H
#define LEVEL_H

#include <QObject>
#include <QGraphicsScene>

class Level : public QObject
{
public:
    Level(QGraphicsScene* scene);
    void loadLevel();
    void loadEntities();
private:
    QGraphicsScene *m_scene;
    int m_currentLevel;
};

#endif // LEVEL_H
