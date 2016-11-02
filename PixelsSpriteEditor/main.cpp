#include <QApplication>
#include "SpriteMainWindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SpriteMainWindow w;
    w.show();

    return a.exec();
}
