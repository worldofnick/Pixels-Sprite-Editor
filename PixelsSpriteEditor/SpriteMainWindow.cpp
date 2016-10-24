#include "SpriteMainWindow.h"
#include "ui_SpriteMainWindow.h"

SpriteMainWindow::SpriteMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SpriteMainWindow)
{
    ui->setupUi(this);
}

SpriteMainWindow::~SpriteMainWindow()
{
    delete ui;
}
