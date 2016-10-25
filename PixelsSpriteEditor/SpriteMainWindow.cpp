#include <QColorDialog>
#include "SpriteMainWindow.h"
#include "ui_SpriteMainWindow.h"
#include "AboutDialog.h"

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


//Slots

void SpriteMainWindow::on_colorPickButton_clicked()
{
    penColor = QColorDialog::getColor(penColor);
    pen.setColor(penColor);
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

//Menu Item Slots

void SpriteMainWindow::on_actionNew_triggered()
{

}

void SpriteMainWindow::on_actionOpen_triggered()
{

}

void SpriteMainWindow::on_actionSave_triggered()
{

}

void SpriteMainWindow::on_actionStamp_triggered()
{

}

void SpriteMainWindow::on_actionQuit_triggered()
{

}

void SpriteMainWindow::on_actionSprite_Sheet_triggered()
{

}


void SpriteMainWindow::on_actionExport_as_gif_triggered()
{

}

void SpriteMainWindow::on_actionUndo_triggered()
{

}

void SpriteMainWindow::on_actionRedo_triggered()
{

}

void SpriteMainWindow::on_actionReset_triggered()
{

}

void SpriteMainWindow::on_actionFlip_Horizontally_triggered()
{

}

void SpriteMainWindow::on_actionFlip_Vertically_triggered()
{

}

void SpriteMainWindow::on_actionRotate_Horizontally_triggered()
{

}

void SpriteMainWindow::on_actionRotate_Counterclockwise_triggered()
{

}

void SpriteMainWindow::on_actionShow_Hide_Frame_triggered()
{

}

void SpriteMainWindow::on_actionDuplicate_triggered()
{

}

void SpriteMainWindow::on_actionDelete_triggered()
{

}

void SpriteMainWindow::on_actionRemove_All_triggered()
{

}

void SpriteMainWindow::on_actionAbout_triggered()
{
    AboutDialog dialogWindow;
    dialogWindow.show();
}

void SpriteMainWindow::on_actionWalkthrough_triggered()
{

}
