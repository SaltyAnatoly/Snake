QT += core
QT -= gui

TARGET = Snake
CONFIG += c++11
CONFIG += console
CONFIG -= app_bundle


TEMPLATE = app

SOURCES += main.cpp \
    field.cpp \
    visual.cpp \
    gameengine.cpp \
    snake.cpp

HEADERS += \
    enums.h \
    field.h \
    visual.h \
    gameengine.h \
    snake.h

