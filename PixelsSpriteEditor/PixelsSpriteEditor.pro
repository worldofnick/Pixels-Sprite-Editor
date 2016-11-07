#-------------------------------------------------
#
# Project created by QtCreator 2016-10-24T11:37:21
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PixelsSpriteEditor
TEMPLATE = app

ICON = assets/icon3.icns
RC_ICONS = assets/icon3.ico

SOURCES += main.cpp\
        SpriteMainWindow.cpp \
    PopupWindow.cpp \
    Frame.cpp \
    Sprite.cpp \
    GetResolutionDialog.cpp \
    StampSelector.cpp \
    Preview.cpp

HEADERS  += SpriteMainWindow.h \
    PopupWindow.h \
    Frame.h \
    Sprite.h \
    GetResolutionDialog.h \
    StampSelector.h \
    Preview.h \
    gif.h

FORMS    += SpriteMainWindow.ui \
    PopupWindow.ui \
    GetResolutionDialog.ui \
    StampSelector.ui \
    Preview.ui

RESOURCES += \
    assets/ui_assets.qrc

DISTFILES +=
