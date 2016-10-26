#include <QColorDialog>
#include <QPushButton>
#include <QFileDialog>
#include "SpriteMainWindow.h"
#include "ui_SpriteMainWindow.h"
#include <iostream>

SpriteMainWindow::SpriteMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SpriteMainWindow)
{
    ui->setupUi(this);

    //penColor is recorded so that when a color picker is selected,
    //the beginning color will be the current penColor.
    penColor = Qt:: blue;
    pen.setColor(penColor);

    isModified = true;
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

//Open a file
void SpriteMainWindow::on_actionOpen_triggered()
{

    QFileDialog dialog;
    QString filename = dialog.getOpenFileName();
    std::cout << filename.toStdString() << std::endl;
}

//Save a file
void SpriteMainWindow::on_actionSave_triggered()
{
    QFileDialog dialog;
    QString filename = dialog.getSaveFileName();
    std::cout << filename.toStdString() << std::endl;
}

//Slot for when the stamp tool button is clicked.
void SpriteMainWindow::on_actionStamp_triggered()
{

}

//Slot for when the quit menu itm is selected.
void SpriteMainWindow::on_actionQuit_triggered()
{
    stillContinue = true;
    if(isModified){
        PopupWindow saveWarningPopup;
        saveWarningPopup.setText("There are unsaved changes are you sure you want to continue?");
        saveWarningPopup.addCancelButton();
        saveWarningPopup.exec();
    }
    if(stillContinue){
        std::cout << "Success" << std::endl;
    }
}

//Slot for when the SpriteSheet menu item is selected.
void SpriteMainWindow::on_actionSprite_Sheet_triggered()
{

}

//Slot for when export as GIF is selected from the menu
void SpriteMainWindow::on_actionExport_as_gif_triggered()
{

}

//Slot for when undo is selected from the menu
void SpriteMainWindow::on_actionUndo_triggered()
{

}

//
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
    PopupWindow aboutPopup;
    aboutPopup.setText("This text will be replaced by a helpful about message.");
    aboutPopup.exec();
}


void SpriteMainWindow::on_actionWalkthrough_triggered()
{
    PopupWindow walkthroughPopup;
    walkthroughPopup.setText("This text will be replaced by a helpful walkthrough.");
    walkthroughPopup.exec();
}

void SpriteMainWindow::closeEvent(QCloseEvent *e){
    stillContinue = true;
    if(isModified){
        PopupWindow saveWarningPopup;
        saveWarningPopup.setText("There are unsaved changes are you sure you want to continue?");
        saveWarningPopup.addCancelButton();
        saveWarningPopup.exec();
    }
    if(stillContinue){
        std::cout << "Success" << std::endl;
    }
}

void SpriteMainWindow::rejected(PopupWindow *window){
    stillContinue = false;
    window->close();
}
