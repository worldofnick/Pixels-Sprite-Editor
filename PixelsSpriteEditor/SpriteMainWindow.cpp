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
    connect(&welcomeScreen, SIGNAL(okClicked(int,int,int)), this, SLOT(initialResolution(int,int,int)));
    welcomeScreen.exec();


    ui->setupUi(this);
    this->setWindowTitle("Pixels Sprite Editor");
    //this->setWindowFlags(Qt::FramelessWindowHint);

    // default to pen
    on_penTool_clicked();

    //penColor is recorded so that when a color picker is selected,
    //the beginning color will be the current penColor.
    penColor = qRgb(255, 198, 6);
    pen.setColor(penColor);
    pen.setWidth(10);
    clickedInsideWorkspace = false;     //TODO: keep or remove later
    scaleFactor = 1;
    mainWindowOriginalGeometry = this->saveGeometry();


    mousePressed = false;
    drawStarted = false;


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
    workspacePixMap = QPixmap(this->spriteWidth, this->spriteHeight);


    workspacePixMap.fill(this->backgroundColor);
    ui->workspaceLabel->setPixmap(workspacePixMap);

    mousePressed = false;

    shapeShouldNowBeDrawn = false;

    // Connections for undo/redo buttons
    connect(ui->undoButton, &QPushButton::clicked, this, &SpriteMainWindow::on_actionUndo_triggered);
    connect(ui->redoButton, &QPushButton::clicked, this, &SpriteMainWindow::on_actionRedo_triggered);

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
    currentFrame->makeFrameActive();


    connect(currentFrame, SIGNAL(clicked(Frame*)), this, SLOT(frameClicked(Frame*)));

    currentFrame->setPixmap(workspacePixMap.scaled(spriteWidth, spriteHeight, Qt::IgnoreAspectRatio, Qt::FastTransformation));

    //qDebug() << currentFrame->pixmap()->width();
    //qDebug() << currentFrame->pixmap()->height();

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

            if (brush == pencil || brush == eraser){
                drawPoint.setX(canvasX);
                drawPoint.setY(canvasY);
                //mousePressed = true;
            }
            else if (brush == line) {
                mLine.setP1(QPoint(canvasX, canvasY));
                mLine.setP2(QPoint(canvasX, canvasY));
            } else if (brush == rect || brush == ellipse) {
                mRect.setTopLeft(QPoint(canvasX, canvasY));
                mRect.setBottomRight(QPoint(canvasX, canvasY));
            }

            mousePressed = true;

            // Save this pixmap, cap at 20 frames
            if(undoStack.size() >= 20) {
                undoStack.pop_front();
            }
            undoStack.push_back(workspacePixMap);

            return true;
        }
        if(event->type() == QEvent::MouseMove) {
            QMouseEvent *mouseMoveEvent = static_cast<QMouseEvent*>(event);
            int canvasX = mouseMoveEvent->pos().x() - ((ui->workspaceLabel->width()/2) - (workspacePixMap.width()/2));
            int canvasY = mouseMoveEvent->pos().y() - ((ui->workspaceLabel->height()/2) - (workspacePixMap.height()/2));

            qDebug() << "mouse is being moved in workspace: (" << QString::number(canvasX) << ", " << QString::number(canvasY) << ")";

            if (brush == pencil || brush == eraser){
                drawPoint.setX(canvasX);
                drawPoint.setY(canvasY);
            }
            else if (brush == line){
                mLine.setP2(QPoint(canvasX, canvasY));
            } else if (brush == rect || brush == ellipse) {
                mRect.setBottomRight(QPoint(canvasX, canvasY));
            }
            updateWorkspace();
            return true;
        }
        if(event->type() == QEvent::MouseButtonRelease) {
            qDebug() << "mouse left click released inside workspace";

            mousePressed = false;

            if (brush == line || brush == rect || brush == ellipse){
                shapeShouldNowBeDrawn = true;
            }
            updateWorkspace();

            currentFrame->setPixmap(workspacePixMap.scaled(spriteWidth, spriteHeight, Qt::IgnoreAspectRatio, Qt::FastTransformation));

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
//void SpriteMainWindow::mouseMoveEvent(QMouseEvent *event) {
//    if(mousePressed) {
//        drawPoint.setX(event->pos().x() -242);
//        drawPoint.setY(event->pos().y() - 50);
//    }
//    updateWorkspace();

    // CRAP FOR QLABEL EVENTS. ONLY ADD FOR OTHER WIDGETS' EVENTS
//}

// Notify when the mouse ie released
void SpriteMainWindow::mouseReleaseEvent(QMouseEvent *event) {

    // CRAP FOR QLABEL EVENTS. ONLY ADD FOR OTHER WIDGETS' EVENTS
}

// Draws on the workspace's pixmap and reassigns it. All the tools will
// paint in this method. (Replacement for paintEvent() method).
void SpriteMainWindow::updateWorkspace() {
   if (brush == pencil || brush == eraser || shapeShouldNowBeDrawn){
    painter.begin(&workspacePixMap);
    painter.setCompositionMode(QPainter::CompositionMode_Source);


    painter.setPen(pen);

    if (brush == pencil || brush == eraser){
        painter.drawPoint(drawPoint);
    }
    else if (brush == line){
        //draw the line once mouse is actually released
        painter.drawLine(mLine);
        shapeShouldNowBeDrawn = false;
    } else if (brush == rect) {
        painter.drawRect(mRect);
        shapeShouldNowBeDrawn = false;
    }else if (brush == ellipse) {
        painter.drawEllipse(mRect);
        shapeShouldNowBeDrawn = false;
    }


     painter.end();

     ui->workspaceLabel->setPixmap(workspacePixMap);
    }
   //this is updating a temporary pixmap to the line before the mouse is released
   else if (brush == line || brush == rect || brush == ellipse){

           QPixmap temp = QPixmap(workspacePixMap);
           QPainter tempPainter(&temp);

           //alternate way based off of link on Slack; I don't know how to make it work
           //painter.begin(&workspacePixMap);
           // painter.drawPixmap(canvasX,canvasY, workspacePixMap);
           //painter.drawLine(mLine);
           //painter.end();

           tempPainter.setPen(pen);

           if(brush == line) {
               tempPainter.drawLine(mLine);
           } else if(brush == rect) {
               tempPainter.drawRect(mRect);
           } else if(brush == ellipse) {
               tempPainter.drawEllipse(mRect);
           }

           ui->workspaceLabel->setPixmap(temp);
   }


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
    brush = ellipse;
}

void SpriteMainWindow::on_rectangleTool_clicked()
{
    brush = rect;
}

void SpriteMainWindow::on_lineTool_clicked()
{
    pen.setColor(penColor);
    brush = line;


}

void SpriteMainWindow::on_eraserTool_clicked()
{
    //if(brush == eraser) {
    //on_penTool_clicked();
    //} else {
    pen.setColor(this->backgroundColor);    // TODO: change to user selected background
    brush = eraser;
}



void SpriteMainWindow::on_penTool_clicked()
{
    pen.setColor(penColor);
    brush = pencil;
    this->cursor().setShape(Qt::CrossCursor);
}

//Add a Frame
void SpriteMainWindow::on_addFrameButton_clicked()
{
    currentFrame->makeFrameUnactive();

    currentSprite.addFrame();
    ui->scrollAreaWidgetContents->layout()->addWidget(currentSprite.getFrames().last());

    currentFrame = currentSprite.getFrames().last();

    currentFrame->makeFrameActive();

    QPixmap map(spriteWidth, spriteHeight);
    map.fill(this->backgroundColor);
    currentFrame->setPixmap(map);

    workspacePixMap = currentFrame->pixmap()->scaled(this->spriteWidth, this->spriteHeight, Qt::IgnoreAspectRatio, Qt::FastTransformation);
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
        connect(&welcomeScreen, SIGNAL(okClicked(int,int,int)), this, SLOT(initialResolution(int,int,int)));
        welcomeScreen.exec();
        this->on_actionReset_triggered();
    }   
    //Clear the workspacePixMap
    workspacePixMap.fill(this->backgroundColor);
    ui->workspaceLabel->setPixmap(workspacePixMap);

    //Clear out the current Sprite
    Sprite newSprite(this->spriteWidth, this->spriteHeight, 0, "IDK");

    currentSprite = newSprite;

    //sets the current frame to the first frame
    currentFrame = currentSprite.getFrames().last();

    connect(currentFrame, SIGNAL(clicked(Frame*)), this, SLOT(frameClicked(Frame*)));
    currentFrame->setPixmap(workspacePixMap.scaled(spriteWidth, spriteHeight, Qt::IgnoreAspectRatio, Qt::FastTransformation));

    //Reset the frames display on the left
    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(currentFrame);
    ui->scrollAreaWidgetContents->setLayout(layout);
}

//Open a file
void SpriteMainWindow::on_actionOpen_triggered()
{
    /*//Check if the user wants to save any changes first, then open a new project.
    if(maybeSave()){
        QFileDialog dialog;
        QString filename = dialog.getOpenFileName();

    }*/
    QFileDialog dialog;
    currentSprite.loadFile(dialog.getOpenFileName());
}

//Save a file
void SpriteMainWindow::on_actionSave_triggered()
{
    QFileDialog dialog;
    isModified = false;
    currentSprite.saveFile(dialog.getSaveFileName(this, tr("Save File"), "/untitled.ssp", tr("Images (*.ssp)")));

    //This saves the pixmap to a png
    /*QFile file(filename);
    file.open(QIODevice::WriteOnly);
    QPixmap map = workspacePixMap.scaled(this->spriteWidth, this->spriteHeight, Qt::IgnoreAspectRatio, Qt::FastTransformation);
    map.save(&file, "PNG");*/
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
        // Save the current frame
        redoStack.push_back(workspacePixMap);
        workspacePixMap = undoStack.back();
        ui->workspaceLabel->setPixmap(workspacePixMap);
        currentFrame->setPixmap(workspacePixMap.scaled(spriteWidth, spriteHeight, Qt::IgnoreAspectRatio, Qt::FastTransformation));

        undoStack.pop_back();
    }
}

//Slot for when the redo button is selected the menu.
void SpriteMainWindow::on_actionRedo_triggered()
{
    if(!redoStack.empty()) {
        workspacePixMap = redoStack.back();
        ui->workspaceLabel->setPixmap(workspacePixMap);
        undoStack.push_back(redoStack.back());
        redoStack.pop_back();
        currentFrame->setPixmap(workspacePixMap.scaled(spriteWidth, spriteHeight, Qt::IgnoreAspectRatio, Qt::FastTransformation));
    }
}

//Slot for when the reset option is selected from the menu.
void SpriteMainWindow::on_actionReset_triggered()
{
    workspacePixMap = QPixmap(this->spriteWidth, this->spriteHeight);
    workspacePixMap.fill(this->backgroundColor);
    ui->workspaceLabel->setPixmap(workspacePixMap);
    currentFrame->setPixmap(workspacePixMap.scaled(spriteWidth, spriteHeight, Qt::IgnoreAspectRatio, Qt::FastTransformation));
}

//Slot for when the Flip Horizontally option is selected from the menu.
void SpriteMainWindow::on_actionFlip_Horizontally_triggered()
{
    QImage image = workspacePixMap.toImage().mirrored(true, false);
    workspacePixMap = QPixmap::fromImage(image);
    ui->workspaceLabel->setPixmap(workspacePixMap);
    currentFrame->setPixmap(workspacePixMap.scaled(spriteWidth, spriteHeight, Qt::IgnoreAspectRatio, Qt::FastTransformation));
}

//Slot for when the flip Vertically option is selected from the menu.
void SpriteMainWindow::on_actionFlip_Vertically_triggered()
{
    QImage image = workspacePixMap.toImage().mirrored(false, true);
    workspacePixMap = QPixmap::fromImage(image);
    ui->workspaceLabel->setPixmap(workspacePixMap);
    currentFrame->setPixmap(workspacePixMap.scaled(spriteWidth, spriteHeight, Qt::IgnoreAspectRatio, Qt::FastTransformation));
}

//Slot for when the rotate Horizontally option is selected from the menu.
void SpriteMainWindow::on_actionRotate_Horizontally_triggered()
{
    QTransform tran;
    tran.rotate(90);
    QImage img = workspacePixMap.toImage();
    img = img.transformed(tran);

    workspacePixMap = QPixmap::fromImage(img).scaled(this->spriteWidth,this->spriteHeight, Qt::IgnoreAspectRatio, Qt::FastTransformation);
    ui->workspaceLabel->setPixmap(workspacePixMap);
    currentFrame->setPixmap(workspacePixMap.scaled(spriteWidth, spriteHeight, Qt::IgnoreAspectRatio, Qt::FastTransformation));

}

//Slot for when the rotate Counterclockwise option is selected from the menu.
void SpriteMainWindow::on_actionRotate_Counterclockwise_triggered()
{
    QTransform tran;
    tran.rotate(-90);
    QImage img = workspacePixMap.toImage();
    img = img.transformed(tran);

    workspacePixMap = QPixmap::fromImage(img).scaled(this->spriteWidth,this->spriteHeight, Qt::IgnoreAspectRatio, Qt::FastTransformation);
    ui->workspaceLabel->setPixmap(workspacePixMap);
    currentFrame->setPixmap(workspacePixMap.scaled(spriteWidth, spriteHeight, Qt::IgnoreAspectRatio, Qt::FastTransformation));
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


void SpriteMainWindow::initialResolution(int width, int height, int backColor){
    //See which color the user selected for the background
    if(backColor == 0){
        //Set Transparent Background
        this->backgroundColor = QColor(255,255,255,6);
    }
    else if(backColor == 1){
        //Set White Background
        this->backgroundColor = QColor(255,255,255);
    }
    else{
        //Set Black Background
        this->backgroundColor = QColor(0,0,0);
    }


    if(width < 32){
        this->spriteWidth = 32;
    }
    if(height < 32){
        this->spriteHeight = 32;
    }

    if(width != height) {
        if(width >= height) {
            this->spriteWidth = width;
            this->spriteHeight = width;
        }
        else {
            this->spriteWidth = height;
            this->spriteHeight = height;
        }
    }
    else {
        this->spriteWidth = width;
        this->spriteHeight = width;
    }

    // TODO: scale the image to worksapce
}

void SpriteMainWindow::frameClicked(Frame* other){
    qDebug() << "frame is clicked MainWindow";
    currentFrame->makeFrameUnactive();
    currentFrame = other;
    currentFrame->makeFrameActive();

    workspacePixMap = currentFrame->pixmap()->scaled(this->spriteWidth,this->spriteHeight, Qt::IgnoreAspectRatio, Qt::FastTransformation);
    ui->workspaceLabel->setPixmap(workspacePixMap);
}

void SpriteMainWindow::on_rotateCounterClockButton_clicked()
{
    QTransform tran;
    tran.rotate(-90);
    QImage img = workspacePixMap.toImage();
    img = img.transformed(tran);

    workspacePixMap = QPixmap::fromImage(img).scaled(this->spriteWidth,this->spriteHeight, Qt::IgnoreAspectRatio, Qt::FastTransformation);
    ui->workspaceLabel->setPixmap(workspacePixMap);
    currentFrame->setPixmap(workspacePixMap.scaled(spriteWidth, spriteHeight, Qt::IgnoreAspectRatio, Qt::FastTransformation));
}


void SpriteMainWindow::on_rotateClockwiseButton_clicked()
{
    QTransform tran;
    tran.rotate(90);
    QImage img = workspacePixMap.toImage();
    img = img.transformed(tran);

    workspacePixMap = QPixmap::fromImage(img).scaled(this->spriteWidth,this->spriteHeight, Qt::IgnoreAspectRatio, Qt::FastTransformation);
    ui->workspaceLabel->setPixmap(workspacePixMap);
    currentFrame->setPixmap(workspacePixMap.scaled(spriteWidth, spriteHeight, Qt::IgnoreAspectRatio, Qt::FastTransformation));
}

void SpriteMainWindow::on_flipVerticalButton_clicked()
{
    QImage image = workspacePixMap.toImage().mirrored(false, true);
    workspacePixMap = QPixmap::fromImage(image);
    ui->workspaceLabel->setPixmap(workspacePixMap);

    currentFrame->setPixmap(workspacePixMap.scaled(spriteWidth, spriteHeight, Qt::IgnoreAspectRatio, Qt::FastTransformation));
}

void SpriteMainWindow::on_flipHorizontalButton_clicked()
{
    QImage image = workspacePixMap.toImage().mirrored(true, false);
    workspacePixMap = QPixmap::fromImage(image);
    ui->workspaceLabel->setPixmap(workspacePixMap);

    currentFrame->setPixmap(workspacePixMap.scaled(spriteWidth, spriteHeight, Qt::IgnoreAspectRatio, Qt::FastTransformation));
}

void SpriteMainWindow::on_timer_update()
{
    if(currentSprite.getFps() > 0)
        it++;
    if(it >= currentSprite.getFrames().size())
        it = 0;

    ui->previewLabelMap->setPixmap((currentSprite.getFrame(it).pixmap())->scaled(172, 100, Qt::IgnoreAspectRatio, Qt::FastTransformation));
}
