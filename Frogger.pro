greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    src/frog.cpp \
    src/gamescene.cpp \
    src/game.cpp \
    src/level.cpp \
    src/main.cpp \
    src/view.cpp

HEADERS += \
    src/frog.h \
    src/gamescene.h \
    src/game.h \
    src/level.h \
    src/view.h

RESOURCES += \
    resource.qrc
