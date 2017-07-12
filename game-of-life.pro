TEMPLATE = app
TARGET = game-of-life
QT = core gui
QT += widgets
SOURCES += \
    main.cpp \
    cell.cpp \
    grid_qt.cpp \
    mainwindow.cpp \
    grid.cpp

HEADERS += \
    cell.h \
    grid_qt.h \
    mainwindow.h \
    grid.h
