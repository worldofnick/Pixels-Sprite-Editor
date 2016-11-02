#include <QColorDialog>
#include <QPushButton>
#include <QFileDialog>
#include <QMessageBox>
#include <QPixmap>
#include "SpriteMainWindow.h"
#include "ui_SpriteMainWindow.h"
#include "GetResolutionDialog.h"
#include <QTransform>
#include <iostream>
#include <QPoint>
#include <QDebug>
#include "SpriteMainWindow.h"
#include "ui_SpriteMainWindow.h"
#include "GetResolutionDialog.h"

SpriteMainWindow::SpriteMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SpriteMainWindow)
{
    GetResolutionDialog welcomeScreen;
    connect(&welcomeScreen, SIGNAL(okClicked(int,int)), this, SLOT(initialResolution(int,int)));
    welcomeScreen.exec();


    ui->setupUi(this);
    this->setWindowTitle("Pixels Sprite Editor");
    //this->setWindowFlags(Qt::FramelessWindowHint);

    // default to pen
    brush = pencil;

    //penColor is recorded so that when a color picker is selected,
    //the beginning color will be the current penColor.
    penColor = qRgb(255, 198, 6);
    pen.setColor(penColor);
    pen.setWidth(10);
    clickedInsideWorkspace = false;     //TODO: keep or remove later
    scaleFactor = 1;
    mainWindowOriginalGeometry = this->saveGeometry();

    filename = "";
    isModified = false;

    // Assign buttons to the button group (with ids). These
    // ID's can be used to indentify which button was pressed.

    toolsButtonsGroup= new QButtonGroup(this);
    toolsButtonsGroup->addButton(ui->penTool, 0);
    toolsButtonsGroup->addButton(ui->eraserTool, 1);
    toolsButtonsGroup->addButton(ui->lineTool, 2);
    toolsButtonsGroup->addButton(ui->rectangleTool, 3);
    toolsButtonsGroup->addButton(ui->ellipseTool, 4);
    toolsButtonsGroup->addButton(ui->stampTool, 5);
    toolsButtonsGroup->addButton(ui->undoButton, 6);
    toolsButtonsGroup->addButton(ui->redoButton, 7);
    toolsButtonsGroup->addButton(ui->flipVerticalButton, 8);
    toolsButtonsGroup->addButton(ui->flipHorizontalButton, 9);
    toolsButtonsGroup->addButton(ui->rotateCounterClockButton, 10);
    toolsButtonsGroup->addButton(ui->rotateClockwiseButton, 11);
    toolsButtonsGroup->addButton(ui->unassignedButton_3, 12);
    toolsButtonsGroup->addButton(ui->unassignedButton_4, 13);
    toolsButtonsGroup->addButton(ui->unassignedButton_5, 14);
    toolsButtonsGroup->addButton(ui->unassignedButton_6, 15);

    brushSizeButtonsGroup = new QButtonGroup(this);
    brushSizeButtonsGroup->addButton(ui->brushSize1Button, 0);
    brushSizeButtonsGroup->addButton(ui->brushSize2Button, 1);
    brushSizeButtonsGroup->addButton(ui->brushSize3Button, 2);
    brushSizeButtonsGroup->addButton(ui->brushSize4Button, 3);

    // Set pixmap's resolution, color and set it to the workspace.
    workspacePixMap = QPixmap(400, 300);

    workspacePixMap.fill(Qt::white);
    ui->workspaceLabel->setPixmap(workspacePixMap);

    mousePressed = false;

    // Install SpriteMainWindow as an event handler for the workspaceLabel
    ui->workspaceLabel->installEventFilter(this);

    //create the sprite
    Sprite temp(spriteWidth, spriteHeight, 0, tr("MySprite"));
    currentSprite = temp;

    connect(&currentSprite, SIGNAL(frameClicked(Frame*)), this, SLOT(frameClicked(Frame*)));

    QVBoxLayout* layout = new QVBoxLayout;
    //Frame* something = &currentSprite.getFrame(0);
    layout->addWidget(currentSprite.getFrames().last());
    ui->scrollAreaWidgetContents->setLayout(layout);
    // Frame* something = new Frame();
    //ui->scrollAreaWidgetContents->layout()->




    //sets the current frame to the first frame
    currentFrame = currentSprite.getFrames().last();

    connect(currentFrame, SIGNAL(clicked(Frame*)), this, SLOT(frameClicked(Frame*)));

    currentFrame->setPixmap(workspacePixMap.scaled(172, 100, Qt::IgnoreAspectRatio, Qt::FastTransformation));

    ui->previewLabelMap->setPixmap(*currentSprite.getFrame(0).pixmap());

    // Setup and start the preview timer
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(on_timer_update()));
    timer->start(ui->fpsSlider->value());
}

SpriteMainWindow::~SpriteMainWindow()
{
    delete ui;
}

// Handles the events inside a QLabel. QLabel unlike QWidget cant emit signals
// for events like mouse click, etc. Thus, clicking and dragging anywhere on our
// SpriteMainWindow would draw on workspace (since it inherit from QWidget). But,
// this overidden method handles QLabel events, and if the event didnt occur in
// QLabel, then will pass it to the SpriteMainWindow.
//
// Can add more stuff (like for tools, etc). Much cleaner than creating a custom
// class and making it inherit from QLabel (and overide the mouse events).
bool SpriteMainWindow::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == ui->workspaceLabel) {
        clickedInsideWorkspace = true;
        if (event->type() == QEvent::MouseButtonPress) {
            QMouseEvent *mousePressEvent = static_cast<QMouseEvent*>(event);
            int canvasX = mousePressEvent->pos().x() - ((ui->workspaceLabel->width()/2) - (workspacePixMap.width()/2));
            int canvasY = mousePressEvent->pos().y() - ((ui->workspaceLabel->height()/2) - (workspacePixMap.height()/2));
            qDebug() << "Left mouse pressed in workspace: (" << QString::number(canvasX) << ", " << QString::number(canvasY) << ")";

            drawPoint.setX(canvasX);
            drawPoint.setY(canvasY);
            mousePressed = true;

            // Save this pixmap
            undoStack.push(workspacePixMap);

            return true;
        }
        if(event->type() == QEvent::MouseMove) {
            QMouseEvent *mouseMoveEvent = static_cast<QMouseEvent*>(event);
            int canvasX = mouseMoveEvent->pos().x() - ((ui->workspaceLabel->width()/2) - (workspacePixMap.width()/2));
            int canvasY = mouseMoveEvent->pos().y() - ((ui->workspaceLabel->height()/2) - (workspacePixMap.height()/2));

            qDebug() << "mouse is being moved in workspace: (" << QString::number(canvasX) << ", " << QString::number(canvasY) << ")";
            drawPoint.setX(canvasX);
            drawPoint.setY(canvasY);
            updateWorkspace();
            return true;
        }
        if(event->type() == QEvent::MouseButtonRelease) {
            qDebug() << "mouse left click released inside workspace";
            mousePressed = false;
            updateWorkspace();

            currentFrame->setPixmap(workspacePixMap.scaled(172, 100, Qt::IgnoreAspectRatio, Qt::FastTransformation));

            return true;
        }
        else {
            return false;
        }
    } else {
        // pass the event on to the parent class
        return QMainWindow::eventFilter(watched, event);
    }
}

// Nofity when the mouse is clicked
void SpriteMainWindow::mousePressEvent(QMouseEvent *event) {

    // CRAP FOR QLABEL EVENTS. ONLY ADD FOR OTHER WIDGETS' EVENTS
}

// Track mouse moving events
void SpriteMainWindow::mouseMoveEvent(QMouseEvent *event) {
    if(mousePressed) {
        drawPoint.setX(event->pos().x() -242);
        drawPoint.setY(event->pos().y() - 50);
    }
    updateWorkspace();

    // CRAP FOR QLABEL EVENTS. ONLY ADD FOR OTHER WIDGETS' EVENTS
}

// Notify when the mouse ie released
void SpriteMainWindow::mouseReleaseEvent(QMouseEvent *event) {
  
    // CRAP FOR QLABEL EVENTS. ONLY ADD FOR OTHER WIDGETS' EVENTS
}

// Draws on the workspace's pixmap and reassigns it. All the tools will
// paint in this method. (Replacement for paintEvent() method).
void SpriteMainWindow::updateWorkspace() {
    painter.begin(&workspacePixMap);
    painter.setPen(pen);

    painter.drawPoint(drawPoint);
    ui->workspaceLabel->setPixmap(workspacePixMap);
    painter.end();

    isModified = true;
}

//void SpriteMainWindow::paintEvent(QPaintEvent *event) {

//}

//Slots

void SpriteMainWindow::on_colorPickButton_clicked()
{
    penColor = QColorDialog::getColor(penColor);
    pen.setColor(penColor);
    QString s = "#colorPickButton {background-color: rgb(";
    int rHover = penColor.red();
    int gHover = penColor.green();
    int bHover = penColor.blue();
    if(!(rHover < 40)) { rHover -= 40;}
    if(!(gHover < 40)) { gHover -= 40;}
    if(!(bHover < 40)) { bHover -= 40;}
    QString color = QString::number(penColor.red()).append(",").append(QString::number(penColor.green())).append(",").append(QString::number(penColor.blue()));
    QString hoverColor = QString::number(rHover).append(",").append(QString::number(gHover)).append(",").append(QString::number(bHover));

    s.append(color).append(");border: 6px solid rgb(252, 252, 252);border-radius: 50px;background-repeat: none;}#colorPickButton:hover{");
    s.append("background-color: rgb(").append(hoverColor).append(");border: 8px solid rgb(252, 252, 252);border-radius: 50px;}");
    ui->colorPickButton->setStyleSheet(s.toLatin1());
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
    if(brush == eraser) {
        on_penTool_clicked();
    } else {
        pen.setColor(Qt::white);
        brush = eraser;
    }

}

void SpriteMainWindow::on_penTool_clicked()
{
    pen.setColor(penColor);
    brush = pencil;
}

//Add a Frame
void SpriteMainWindow::on_addFrameButton_clicked()
{
    currentSprite.addFrame();
    ui->scrollAreaWidgetContents->layout()->addWidget(currentSprite.getFrames().last());

    currentFrame = currentSprite.getFrames().last();
    workspacePixMap = currentFrame->pixmap()->scaled(400,300, Qt::IgnoreAspectRatio, Qt::FastTransformation);
    ui->workspaceLabel->setPixmap(workspacePixMap);
}

void SpriteMainWindow::on_fpsSlider_valueChanged(int value)
{
    currentSprite.setFps(value);
    if(value == 0)
        timer->start(10);
    else
        timer->start(1000/currentSprite.getFps());
}

//Menu Item Slots

void SpriteMainWindow::on_actionNew_triggered()
{
    //Check if the user wants to save any changes first, then trigger the reset action.
    if(maybeSave()){
        GetResolutionDialog welcomeScreen;
        connect(&welcomeScreen, SIGNAL(okClicked(int,int)), this, SLOT(initialResolution(int,int)));
        welcomeScreen.exec();
        this->on_actionReset_triggered();
    }   
    //Clear the workspacePixMap
    workspacePixMap.fill(Qt::white);
    ui->workspaceLabel->setPixmap(workspacePixMap);

    //Clear out the current Sprite
    Sprite newSprite(this->spriteWidth, this->spriteHeight, 0, "IDK");

    currentSprite = newSprite;

    //sets the current frame to the first frame
    currentFrame = currentSprite.getFrames().last();

    connect(currentFrame, SIGNAL(clicked(Frame*)), this, SLOT(frameClicked(Frame*)));
    currentFrame->setPixmap(workspacePixMap.scaled(172, 100, Qt::IgnoreAspectRatio, Qt::FastTransformation));

    //Reset the frames display on the left
    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(currentFrame);
    ui->scrollAreaWidgetContents->setLayout(layout);
}

//Open a file
void SpriteMainWindow::on_actionOpen_triggered()
{
    //Check if the user wants to save any changes first, then open a new project.
    if(maybeSave()){
        QFileDialog dialog;
        QString filename = dialog.getOpenFileName();
    }
}

//Save a file
void SpriteMainWindow::on_actionSave_triggered()
{
    //This saves the pixmap to a png

    QFileDialog dialog;
    filename = dialog.getSaveFileName(this, tr("Save File"), "/untitled.png", tr("Images (*.png)"));
    isModified = false;


    QFile file(filename);
    file.open(QIODevice::WriteOnly);
    QPixmap map = workspacePixMap.scaled(this->spriteWidth, this->spriteHeight, Qt::IgnoreAspectRatio, Qt::FastTransformation);
    map.save(&file, "PNG");
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
    if(!undoStack.empty()) {
        ui->workspaceLabel->setPixmap(undoStack.top());
        redoStack.push(undoStack.top());
        undoStack.pop();
    }
}

//Slot for when the redo button is selected the menu.
void SpriteMainWindow::on_actionRedo_triggered()
{
    if(!redoStack.empty()) {
        ui->workspaceLabel->setPixmap(redoStack.top());
        undoStack.push(redoStack.top());
        redoStack.pop();
    }
}

//Slot for when the reset option is selected from the menu.
void SpriteMainWindow::on_actionReset_triggered()
{
    workspacePixMap = QPixmap(400, 300);
    workspacePixMap.fill(Qt::white);
    ui->workspaceLabel->setPixmap(workspacePixMap);
    currentFrame->setPixmap(workspacePixMap.scaled(172, 100, Qt::IgnoreAspectRatio, Qt::FastTransformation));

}

//Slot for when the Flip Horizontally option is selected from the menu.
void SpriteMainWindow::on_actionFlip_Horizontally_triggered()
{
    QImage image = workspacePixMap.toImage().mirrored(true, false);
    workspacePixMap = QPixmap::fromImage(image);
    ui->workspaceLabel->setPixmap(workspacePixMap);

    currentFrame->setPixmap(workspacePixMap.scaled(172, 100, Qt::IgnoreAspectRatio, Qt::FastTransformation));
}

//Slot for when the flip Vertically option is selected from the menu.
void SpriteMainWindow::on_actionFlip_Vertically_triggered()
{
    QImage image = workspacePixMap.toImage().mirrored(false, true);
    workspacePixMap = QPixmap::fromImage(image);
    ui->workspaceLabel->setPixmap(workspacePixMap);

    currentFrame->setPixmap(workspacePixMap.scaled(172, 100, Qt::IgnoreAspectRatio, Qt::FastTransformation));
}

//Slot for when the rotate Horizontally option is selected from the menu.
void SpriteMainWindow::on_actionRotate_Horizontally_triggered()
{
    QTransform tran;
    tran.rotate(90);
    QImage img = workspacePixMap.toImage();
    img = img.transformed(tran);

    workspacePixMap = QPixmap::fromImage(img).scaled(400,300, Qt::IgnoreAspectRatio, Qt::FastTransformation);
    ui->workspaceLabel->setPixmap(workspacePixMap);
    currentFrame->setPixmap(workspacePixMap.scaled(172, 100, Qt::IgnoreAspectRatio, Qt::FastTransformation));

}

//Slot for when the rotate Counterclockwise option is selected from the menu.
void SpriteMainWindow::on_actionRotate_Counterclockwise_triggered()
{
    QTransform tran;
    tran.rotate(-90);
    QImage img = workspacePixMap.toImage();
    img = img.transformed(tran);

    workspacePixMap = QPixmap::fromImage(img).scaled(400,300, Qt::IgnoreAspectRatio, Qt::FastTransformation);
    ui->workspaceLabel->setPixmap(workspacePixMap);
    currentFrame->setPixmap(workspacePixMap.scaled(172, 100, Qt::IgnoreAspectRatio, Qt::FastTransformation));
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
    aboutPopup.setTitle("About Pixels Sprite Editor");
    aboutPopup.exec();
}

//Slot for when the walkthrough option is selected from the menu.
void SpriteMainWindow::on_actionWalkthrough_triggered()
{
    PopupWindow walkthroughPopup;
    walkthroughPopup.setText("This text will be replaced by a helpful walkthrough.");
    walkthroughPopup.setTitle("Walkthrough");
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

//Change Brush Size Slots
void SpriteMainWindow::on_brushSize1Button_clicked()
{
    pen.setWidth(10);
}

void SpriteMainWindow::on_brushSize2Button_clicked()
{
    pen.setWidth(20);
}

void SpriteMainWindow::on_brushSize3Button_clicked()
{
    pen.setWidth(30);
}

void SpriteMainWindow::on_brushSize4Button_clicked()
{
    pen.setWidth(40);
}

void SpriteMainWindow::on_action2x_Workspace_triggered()
{
    scaleFactor++;
    int wspWidth = workspacePixMap.width() * scaleFactor;
    int wspHeight = workspacePixMap.height() * scaleFactor;

    workspacePixMap = workspacePixMap.scaled(wspWidth, wspHeight, Qt::IgnoreAspectRatio, Qt::FastTransformation);
    ui->workspaceLabel->setPixmap(workspacePixMap);

    if(scaleFactor != 1) {
        pen.setWidth(10 * scaleFactor);      //TODO: replace 10 by the current brush size.
    }

    update();

//    if(wspWidth > this->width()) {
//        this->resize(this->width() + wspWidth, this->height());
//        if(wspHeight > this->height()) {
//            this->resize(this->width(), this->height() + wspHeight);
//        }
//    }
//    update();

}


void SpriteMainWindow::initialResolution(int width, int height){
    //Enforce a range of 32-128.
    if(width < 32){
        width = 32;
    }
    else if(width > 200){
        width = 200;
    }

    if(height < 32){
        height = 32;
    }
    else if(height > 128){
        height = 128;
    }

    this->spriteWidth = width;
    this->spriteHeight = height;

//    spriteWidth = 172;
//    spriteHeight = 100;
}

void SpriteMainWindow::frameClicked(Frame* other){
    qDebug() << "frame is clicked MainWindow";
    currentFrame = other;
    workspacePixMap = currentFrame->pixmap()->scaled(400,300, Qt::IgnoreAspectRatio, Qt::FastTransformation);
    ui->workspaceLabel->setPixmap(workspacePixMap);
}

void SpriteMainWindow::on_rotateCounterClockButton_clicked()
{
    QTransform tran;
    tran.rotate(-90);
    QImage img = workspacePixMap.toImage();
    img = img.transformed(tran);

    workspacePixMap = QPixmap::fromImage(img).scaled(400,300, Qt::IgnoreAspectRatio, Qt::FastTransformation);
    ui->workspaceLabel->setPixmap(workspacePixMap);
    currentFrame->setPixmap(workspacePixMap.scaled(172, 100, Qt::IgnoreAspectRatio, Qt::FastTransformation));
}


void SpriteMainWindow::on_rotateClockwiseButton_clicked()
{
    QTransform tran;
    tran.rotate(90);
    QImage img = workspacePixMap.toImage();
    img = img.transformed(tran);

    workspacePixMap = QPixmap::fromImage(img).scaled(400,300, Qt::IgnoreAspectRatio, Qt::FastTransformation);
    ui->workspaceLabel->setPixmap(workspacePixMap);
    currentFrame->setPixmap(workspacePixMap.scaled(172, 100, Qt::IgnoreAspectRatio, Qt::FastTransformation));
}

void SpriteMainWindow::on_flipVerticalButton_clicked()
{
    QImage image = workspacePixMap.toImage().mirrored(false, true);
    workspacePixMap = QPixmap::fromImage(image);
    ui->workspaceLabel->setPixmap(workspacePixMap);

    currentFrame->setPixmap(workspacePixMap.scaled(172, 100, Qt::IgnoreAspectRatio, Qt::FastTransformation));
}

void SpriteMainWindow::on_flipHorizontalButton_clicked()
{
    QImage image = workspacePixMap.toImage().mirrored(true, false);
    workspacePixMap = QPixmap::fromImage(image);
    ui->workspaceLabel->setPixmap(workspacePixMap);

    currentFrame->setPixmap(workspacePixMap.scaled(172, 100, Qt::IgnoreAspectRatio, Qt::FastTransformation));
}

void SpriteMainWindow::on_timer_update()
{
    if(currentSprite.getFps() > 0)
        it++;
    if(it >= currentSprite.getFrames().size())
        it = 0;

    ui->previewLabelMap->setPixmap(*currentSprite.getFrame(it).pixmap());
}
