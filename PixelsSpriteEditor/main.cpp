#include "SpriteMainWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SpriteMainWindow w;
    w.show();

    return a.exec();
}