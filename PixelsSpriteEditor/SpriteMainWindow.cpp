#include <QColorDialog>
#include "SpriteMainWindow.h"
#include "ui_SpriteMainWindow.h"

SpriteMainWindow::SpriteMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SpriteMainWindow)
{
    ui->setupUi(this);

    //penColor is recorded so that when a color picker is selected,
    //the beginning color will be the current penColor.
    penColor = Qt:: blue;
    pen.setColor(penColor);
}

SpriteMainWindow::~SpriteMainWindow()
{
    delete ui;
}


//Slots*********************************************

void SpriteMainWindow::on_colorPickButton_clicked()
{
    pen.setColor(QColorDialog::getColor(penColor));
}

void SpriteMainWindow::on_stampTool_clicked()
{

}

void SpriteMainWindow::on_ellipseTool_clicked()
{

}

void SpriteMainWindow::on_rectangleTool_clicked()
{

}

void SpriteMainWindow::on_lineTool_clicked()
{

}

void SpriteMainWindow::on_eraserTool_clicked()
{

}

void SpriteMainWindow::on_penTool_clicked()
{

}

void SpriteMainWindow::on_addFrameButton_clicked()
{

}

void SpriteMainWindow::on_fpsSlider_valueChanged(int value)
{

}
