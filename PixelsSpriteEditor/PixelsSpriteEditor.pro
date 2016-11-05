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
    PopupWindow.cpp \
    Frame.cpp \
    Sprite.cpp \
    GetResolutionDialog.cpp \
    StampSelector.cpp

HEADERS  += SpriteMainWindow.h \
    PopupWindow.h \
    Frame.h \
    Sprite.h \
    GetResolutionDialog.h \
    StampSelector.h

FORMS    += SpriteMainWindow.ui \
    PopupWindow.ui \
    GetResolutionDialog.ui \
    StampSelector.ui

RESOURCES += \
    assets/ui_assets.qrc

DISTFILES +=
