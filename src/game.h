#ifndef GAME_H
#define GAME_H
#include <QSize>
#include <QString>
#include <QPoint>

class Game
{
public:
    Game();

    constexpr static const int GRID_SIZE = 32;
    constexpr static const int WINDOW_WIDTH = 14;
    constexpr static const int WINDOW_HEIGHT = 16;
    constexpr static const QSize RESOLUTION = QSize(GRID_SIZE*WINDOW_WIDTH, GRID_SIZE*WINDOW_HEIGHT);
    constexpr static const int FPS = 60;
    constexpr static const int MAX_WATER_Y = 7;
    constexpr static const int MIN_WATER_Y = 2;


    static int convertPixelToGridPoint(int pixelVal);
    static int convertGridPointToPixel(int gridPointVal);

    enum class Direction{
        LEFT, UP, RIGHT, DOWN
    };

    static const QString PATH_TO_FROG_PIXMAP;
    static const QString PATH_TO_DEAD_FROG_PIXMAP;
    static const QString PATH_TO_TILE_PIXMAP;
    static const QString PATH_TO_CAR_PIXMAP;
    static const QString PATH_TO_CAR_R_PIXMAP;
    static const QString PATH_TO_LOG_PIXMAP;
    static const QString PATH_TO_MELTING_FROG_PIXMAP;
    static const QString PATH_TO_TURTLE_PIXMAP;

    constexpr static const QPoint Asphalt0p = QPoint(0,0);
    constexpr static const QPoint Asphalt1p = QPoint(32,0);
    constexpr static const QPoint Asphalt2p = QPoint(64,0);
    constexpr static const QPoint Asphalt3p = QPoint(96,0);
    constexpr static const QPoint Asphalt4p = QPoint(128,0);
    constexpr static const QPoint Asphalt5p = QPoint(160,0);

    constexpr static const QPoint Water0p = QPoint(0, 32);
    constexpr static const QPoint Grass0p = QPoint(32, 32);


    enum class CarType{
        RACER, BULLDOZER, CAR, TIR
    };

    enum class Layer{
        LOG = 1, FROG, CAR
    };
};

#endif // GAME_H
