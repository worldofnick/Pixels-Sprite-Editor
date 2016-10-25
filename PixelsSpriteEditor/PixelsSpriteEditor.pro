#-------------------------------------------------
#
# Project created by QtCreator 2016-10-24T11:37:21
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PixelsSpriteEditor
TEMPLATE = app


SOURCES += main.cpp\
        SpriteMainWindow.cpp \
    AboutDialog.cpp

HEADERS  += SpriteMainWindow.h \
    AboutDialog.h

FORMS    += SpriteMainWindow.ui \
    AboutDialog.ui
