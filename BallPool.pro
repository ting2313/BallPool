#-------------------------------------------------
#
# Project created by QtCreator 2017-05-12T20:09:05
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BallPool
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    scene.cpp \
    ball.cpp \
    ball_enemy.cpp \
    ball_on.cpp \
    cast_enemy.cpp \
    cast_user.cpp \
    score.cpp \
    record.cpp \
    magic.cpp \
    text.cpp

HEADERS  += mainwindow.h \
    scene.h \
    ball.h \
    ball_on.h \
    ball_enemy.h \
    cast_user.h \
    cast_enemy.h \
    score.h \
    record.h \
    magic.h \
    text.h

FORMS    += mainwindow.ui

RESOURCES += \
    resource.qrc
