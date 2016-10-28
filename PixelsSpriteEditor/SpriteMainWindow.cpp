#include <QColorDialog>
#include <QPushButton>
#include <QFileDialog>
#include <QMessageBox>
#include "SpriteMainWindow.h"
#include "ui_SpriteMainWindow.h"
#include <iostream>
#include <QPoint>

SpriteMainWindow::SpriteMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SpriteMainWindow)
{
    ui->setupUi(this);

    //penColor is recorded so that when a color picker is selected,
    //the beginning color will be the current penColor.
    penColor = Qt:: blue;
    pen.setColor(penColor);
    pen.setWidth(10);

    filename = "";
    isModified = true;

    // Set pixmap's resolution, color and set it to the workspace.
    workspacePixMap = QPixmap(536, 408);
    workspacePixMap.fill(Qt::white);
    ui->workspaceLabel->setPixmap(workspacePixMap);
    mousePressed = false;


    //create the sprite
    Sprite temp(32, 32, 0, tr("MySprite"));
    currentSprite = temp;
    QVBoxLayout* layout = new QVBoxLayout;
    //Frame* something = &currentSprite.getFrame(0);
    layout->addWidget(&currentSprite.getFrame(0));
    ui->scrollAreaWidgetContents->setLayout(layout);

   // Frame* something = new Frame();
    //ui->scrollAreaWidgetContents->layout()->

}

SpriteMainWindow::~SpriteMainWindow()
{
    delete ui;
}

// Nofity when the mouse is clicked
void SpriteMainWindow::mousePressEvent(QMouseEvent *event) {

    //Pen tool (add conditionals as per new tools)
    if(event->button() == Qt::LeftButton) {
        drawPoint.setX(event->pos().x() - 242);
        drawPoint.setY(event->pos().y() - 50);
        mousePressed = true;
    }

    //updateWorkspace();
}

// Track mouse moving events
void SpriteMainWindow::mouseMoveEvent(QMouseEvent *event) {

    //As mouse is moving set the second point again and again
    // and update continuously
    //if(event->type() == QEvent::MouseMove){

    //}
    //updateWorkspace();
    if(mousePressed) {
        drawPoint.setX(event->pos().x() -242);
        drawPoint.setY(event->pos().y() - 50);
    }
    updateWorkspace();

}

// Notify when the mouse ie released
void SpriteMainWindow::mouseReleaseEvent(QMouseEvent *event) {
    mousePressed = false;
    updateWorkspace();
}

// Draws on the workspace's pixmap and reassigns it. All the tools will
// paint in this method. (Replacement for paintEvent() method).
void SpriteMainWindow::updateWorkspace() {
    painter.begin(&workspacePixMap);
    painter.setPen(pen);
    painter.drawPoint(drawPoint);
    ui->workspaceLabel->setPixmap(workspacePixMap);
    painter.end();
}

//void SpriteMainWindow::paintEvent(QPaintEvent *event) {

//}

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

//Add a Frame
void SpriteMainWindow::on_addFrameButton_clicked()
{
    currentSprite.addFrame();
    ui->scrollAreaWidgetContents->layout()->addWidget(currentSprite.getFrames().last());
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
}

//Save a file
void SpriteMainWindow::on_actionSave_triggered()
{
    QFileDialog dialog;
    filename = dialog.getSaveFileName(NULL, "Save", filename, ".ssp");
}

//Slot for when the stamp tool button is clicked.
void SpriteMainWindow::on_actionStamp_triggered()
{

}

//Slot for when the SpriteSheet menu item is selected.
void SpriteMainWindow::on_actionSprite_Sheet_triggered()
{

}

//Slot for when export as GIF is selected from the menu.
void SpriteMainWindow::on_actionExport_as_gif_triggered()
{

}

//Slot for when undo is selected from the menu.
void SpriteMainWindow::on_actionUndo_triggered()
{

}

//Slot for when the redo button is selected the menu.
void SpriteMainWindow::on_actionRedo_triggered()
{

}

//Slot for when the reset option is selected from the menu.
void SpriteMainWindow::on_actionReset_triggered()
{

}

//Slot for when the Flip Horizontally option is selected from the menu.
void SpriteMainWindow::on_actionFlip_Horizontally_triggered()
{

}

//Slot for when the flip Vertically option is selected from the menu.
void SpriteMainWindow::on_actionFlip_Vertically_triggered()
{

}

//Slot for when the rotate Horizontally option is selected from the menu.
void SpriteMainWindow::on_actionRotate_Horizontally_triggered()
{

}

//Slot for when the rotate Counterclockwise option is selected from the menu.
void SpriteMainWindow::on_actionRotate_Counterclockwise_triggered()
{

}

//Slot for when the Show/Hide option is selected from the menu.
void SpriteMainWindow::on_actionShow_Hide_Frame_triggered()
{

}

//Slot for when the Duplicate option is selected from the menu.
void SpriteMainWindow::on_actionDuplicate_triggered()
{

}

//Slot for when the delete option is selected from the menu.
void SpriteMainWindow::on_actionDelete_triggered()
{

}

//Slot for when the remove all option is selected from the menu.
void SpriteMainWindow::on_actionRemove_All_triggered()
{

}

//Slot for when the about option is selected from the menu.
void SpriteMainWindow::on_actionAbout_triggered()
{
    PopupWindow aboutPopup;
    aboutPopup.setText("This text will be replaced by a helpful about message.");
    aboutPopup.exec();
}

//Slot for when the walkthrough option is selected from the menu.
void SpriteMainWindow::on_actionWalkthrough_triggered()
{
    PopupWindow walkthroughPopup;
    walkthroughPopup.setText("This text will be replaced by a helpful walkthrough.");
    walkthroughPopup.exec();
}

//Override the closeEvent for the window so that a warning popup may be displayed if there are unsaved changes.
void SpriteMainWindow::closeEvent(QCloseEvent *e){
    if (maybeSave()) {
        e->accept();
    } else {
        e->ignore();
    }
}

//Called when the window wants to close, to determine if there are any necessary changes to save.
bool SpriteMainWindow::maybeSave(){
    if (isModified) {
       isModified = false;
       QMessageBox::StandardButton ret;
       ret = QMessageBox::warning(this, tr("Warning"),
                          tr("The sprite has been modified.\n"
                             "Do you want to save your changes?"),
                          QMessageBox::Save | QMessageBox::Discard
                          | QMessageBox::Cancel);
        if (ret == QMessageBox::Save) {
            //Call the Save method here...
            on_actionSave_triggered();
            return true;
        } else if (ret == QMessageBox::Cancel) {
            isModified = true;
            return false;
        }
    }
    return true;
}
