#include <QApplication>
#include "SpriteMainWindow.h"

// Starts the "Pixels Sprite Editor" app.
//
// Team: Pixels
//
// Members: Snehashish Mishra, Tyler Dailey, Larry Nguyen
//          Alex Blackburn, Nate Roger, Nick Porter
//
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SpriteMainWindow w;
    w.show();

    return a.exec();
}
