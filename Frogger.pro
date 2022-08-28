greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    src/log.cpp \
    src/car.cpp \
    src/frog.cpp \
    src/gamescene.cpp \
    src/game.cpp \
    src/level.cpp \
    src/main.cpp \
    src/turtle.cpp \
    src/turtles.cpp \
    src/view.cpp

HEADERS += \
    src/log.h \
    src/car.h \
    src/frog.h \
    src/gamescene.h \
    src/game.h \
    src/level.h \
    src/turtle.h \
    src/turtles.h \
    src/view.h

RESOURCES += \
    resource.qrc
