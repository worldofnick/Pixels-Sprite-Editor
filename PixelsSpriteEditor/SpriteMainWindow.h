#ifndef SPRITEMAINWINDOW_H
#define SPRITEMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class SpriteMainWindow;
}

class SpriteMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SpriteMainWindow(QWidget *parent = 0);
    ~SpriteMainWindow();

private:
    Ui::SpriteMainWindow *ui;
};

#endif // SPRITEMAINWINDOW_H
