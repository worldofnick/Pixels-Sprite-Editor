#include <QDebug>
#include <QColorDialog>
#include <QPushButton>
#include <QFileDialog>
#include <QMessageBox>
#include <QPixmap>
#include <QTransform>
#include <QPoint>
#include <QScrollBar>
#include "GetResolutionDialog.h"
#include "SpriteMainWindow.h"
#include "ui_SpriteMainWindow.h"

//Constructs a new SpriteMainWindow, and initializes all member variables
SpriteMainWindow::SpriteMainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::SpriteMainWindow)
{
    GetResolutionDialog welcomeScreen;
    connect(&welcomeScreen, SIGNAL(okClicked(int,int)), this, SLOT(initialResolution(int,int)));
    welcomeScreen.exec();


    ui->setupUi(this);
    this->setWindowTitle("Pixels Sprite Editor");

    // default to pen
    on_penTool_clicked();

    //penColor is recorded so that when a color picker is selected,
    //the beginning color will be the current penColor.
    penColor = qRgb(255, 198, 6);
    pen.setColor(penColor);
    penWidthSelected = 1;
    transparentGridIsVisible = true;

    pen.setWidth(penWidthSelected);
    pen.setCapStyle(Qt::FlatCap);
    pen.setJoinStyle(Qt::RoundJoin);

    clickedInsideWorkspace = false;
    timesScaled = 0;
    mainWindowOriginalGeometry = this->saveGeometry();


    //Initialize flags
    mousePressed = false;
    drawStarted = false;
    isModified = false;
    shapeShouldNowBeDrawn = false;

    filename = "";


    // Assign buttons to the button group (with ids). These
    // ID's can be used to indentify which button was pressed.
    toolsButtonsGroup= new QButtonGroup(this);
    toolsButtonsGroup->addButton(ui->penTool, 0);
    toolsButtonsGroup->addButton(ui->eraserTool, 1);
    toolsButtonsGroup->addButton(ui->lineTool, 2);
    toolsButtonsGroup->addButton(ui->rectangleTool, 3);
    toolsButtonsGroup->addButton(ui->ellipseTool, 4);
    toolsButtonsGroup->addButton(ui->stampTool, 5);

    brushSizeButtonsGroup = new QButtonGroup(this);
    brushSizeButtonsGroup->addButton(ui->brushSize1Button, 0);
    brushSizeButtonsGroup->addButton(ui->brushSize2Button, 1);
    brushSizeButtonsGroup->addButton(ui->brushSize3Button, 2);
    brushSizeButtonsGroup->addButton(ui->brushSize4Button, 3);

    // Set pixmap's resolution, color and set it to the workspace.
    workspacePixMap = QPixmap(this->spriteWidth, this->spriteHeight);
    workspacePixMap.fill(this->backgroundColor);
    ui->workspaceLabel->setPixmap(workspacePixMap);


    // Connections for undo,redo,zooming buttons
    connect(ui->undoButton, &QPushButton::clicked, this, &SpriteMainWindow::on_actionUndo_triggered);
    connect(ui->redoButton, &QPushButton::clicked, this, &SpriteMainWindow::on_actionRedo_triggered);
    connect(ui->zoomInButton, &QPushButton::clicked, this, &SpriteMainWindow::on_action2x_Workspace_triggered);
    connect(ui->zoomOutButton, &QPushButton::clicked, this, &SpriteMainWindow::on_actionZoom_Out_triggered);
    connect(ui->oneToOneButton, &QPushButton::clicked, this, &SpriteMainWindow::on_actionReset_Size_triggered);

    // Install SpriteMainWindow as an event handler for the workspaceLabel
    ui->workspaceLabel->installEventFilter(this);
    ui->previewLabelMap->installEventFilter(this);

    //create the sprite
    Sprite temp(spriteWidth, spriteHeight, 0, tr("MySprite"));
    currentSprite = temp;
    connect(&currentSprite, SIGNAL(frameClicked(Frame*)), this, SLOT(frameClicked(Frame*)));

    //Initialize the frame viewer panel on the left of the main window.
    QVBoxLayout* layout = new QVBoxLayout;
    Frame* s =currentSprite.getFrames().last();
    s->setMinimumSize(160,160);
    s->setMaximumSize(160,160);
    s->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    s->setScaledContents(true);
    layout->addWidget(s);
    ui->scrollAreaWidgetContents->setLayout(layout);

    //sets the current frame to the first frame
    currentFrame = currentSprite.getFrames().last();
    currentFrame->makeFrameActive();
    connect(currentFrame, SIGNAL(clicked(Frame*)), this, SLOT(frameClicked(Frame*)));
    currentFrame->setPixmap(workspacePixMap.copy());


    QPixmap tempPixmap = *currentSprite.getFrame(0).pixmap();
    ui->previewLabelMap->setPixmap(tempPixmap.copy());


    // Setup and start the preview timer
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(whenTimerUpdates()));
    timer->start(ui->fpsSlider->value());


    //Connect the previewWindow in order to change the fps
    connect(&(this->previewWindow), SIGNAL(fpsChanged(int)), this, SLOT(setFps(int)));
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
    if (qobject_cast<QLabel*>(watched)==ui->previewLabelMap && event->type() == QEvent::MouseButtonPress){

        previewWindow.setPixmap(workspacePixMap);
        previewWindow.setFps(currentSprite.getFps());
        previewWindow.exec();
        return true;
    }
    if (watched == ui->workspaceLabel) {

        clickedInsideWorkspace = true;

        if (event->type() == QEvent::MouseButtonPress) {

            //Get the mouse position from the event
            QMouseEvent *mousePressEvent = static_cast<QMouseEvent*>(event);
            int canvasX = mousePressEvent->pos().x() - ((ui->workspaceLabel->width()/2) - (workspacePixMap.width()/2));
            int canvasY = mousePressEvent->pos().y() - ((ui->workspaceLabel->height()/2) - (workspacePixMap.height()/2));

            if (brush == pencil || brush == eraser || brush == stamp) {
                drawPoint.setX(canvasX);
                drawPoint.setY(canvasY);

                drawPath.moveTo(drawPoint);
            }
            else if (brush == line) {
                mLine.setP1(QPoint(canvasX, canvasY));
                mLine.setP2(QPoint(canvasX, canvasY));
            }
            else if (brush == rect || brush == ellipse) {
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

            //Get the mouse position from the event.
            QMouseEvent *mouseMoveEvent = static_cast<QMouseEvent*>(event);
            int canvasX = mouseMoveEvent->pos().x() - ((ui->workspaceLabel->width()/2) - (workspacePixMap.width()/2));
            int canvasY = mouseMoveEvent->pos().y() - ((ui->workspaceLabel->height()/2) - (workspacePixMap.height()/2));

            if (brush == pencil || brush == eraser || brush == stamp){
                drawPoint.setX(canvasX);
                drawPoint.setY(canvasY);
                drawPath.lineTo(drawPoint);
            }
            else if (brush == line){
                mLine.setP2(QPoint(canvasX, canvasY));
            }
            else if (brush == rect || brush == ellipse) {
                mRect.setBottomRight(QPoint(canvasX, canvasY));
            }
            updateWorkspace();
            return true;
        }
        if(event->type() == QEvent::MouseButtonRelease) {
            mousePressed = false;

            if (brush == pencil){
                //Now that we are using drawPath rather than drawPoint, it is necessary to draw the point on release
                //so that if the user clicks fast it will still draw that particular point.
                painter.begin(&workspacePixMap);
                painter.setCompositionMode(QPainter::CompositionMode_Source);
                painter.setPen(pen);
                painter.drawPoint(drawPoint);
                painter.end();

            }

            if (brush == line || brush == rect || brush == ellipse || brush == stamp){
                shapeShouldNowBeDrawn = true;
            }
            updateWorkspace();

            //Reset the drawPath member variable
            drawPath = QPainterPath();

            currentFrame->setPixmap(workspacePixMap.copy());

            return true;
        }
        else {
            return false;
        }
    }
    else {
        // pass the event on to the parent class
        return QMainWindow::eventFilter(watched, event);
    }
}


// Draws on the workspace's pixmap and reassigns it. All the tools will
// paint in this method. (Replacement for paintEvent() method).
void SpriteMainWindow::updateWorkspace()
{
    if (brush == pencil || brush == eraser || shapeShouldNowBeDrawn){
        painter.begin(&workspacePixMap);
        painter.setCompositionMode(QPainter::CompositionMode_Source);
        painter.setRenderHints(QPainter::Antialiasing, QPainter::SmoothPixmapTransform);

        painter.setPen(pen);

        if (brush == pencil || brush == eraser){
            painter.drawPath(drawPath);
        }
        else if (brush == line){
            //draw the line once mouse is actually released
            painter.drawLine(mLine);
            shapeShouldNowBeDrawn = false;
        }
        else if (brush == rect) {
            painter.drawRect(mRect);
            shapeShouldNowBeDrawn = false;
        }
        else if (brush == ellipse) {
            painter.drawEllipse(mRect);
            shapeShouldNowBeDrawn = false;
        }
        else if (brush == stamp){
            painter.drawPixmap(drawPoint, selectedStamp);
            shapeShouldNowBeDrawn = false;
        }


        painter.end();

        ui->workspaceLabel->setPixmap(workspacePixMap);
    }

    //This is updating a temporary pixmap to the line before the mouse is released
    else if (brush == line || brush == rect || brush == ellipse || brush == stamp){

        QPixmap temp = QPixmap(workspacePixMap);
        QPainter tempPainter(&temp);

        tempPainter.setPen(pen);
        tempPainter.setRenderHints(QPainter::Antialiasing, QPainter::SmoothPixmapTransform);

        if(brush == line) {
            tempPainter.drawLine(mLine);
        }
        else if(brush == rect) {
            tempPainter.drawRect(mRect);
        }
        else if(brush == ellipse) {
            tempPainter.drawEllipse(mRect);
        }
        else if(brush == stamp){
            tempPainter.drawPixmap(drawPoint, selectedStamp);
        }

        ui->workspaceLabel->setPixmap(temp);
    }
    isModified = true;
}

//Slots

//Slot for when the colorPick button is clicked in the main window.
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
    StampSelector window;
    connect(&window, SIGNAL(selectedStamp(int)), this, SLOT(changeStamp(int)));
    connect(this, SIGNAL(sendRes(QRect)), &window, SLOT(resolution(QRect)));
    call();
    window.exec();

    brush = stamp;
}

void SpriteMainWindow::call() {
    emit(sendRes(this->geometry()));
}

//Change the selected stamp
void SpriteMainWindow::changeStamp(int id)
{
    if(id == 0){
        selectedStamp.load(":/stamps/Retro-Mario-icon.png");
    }
    else if(id == 1){
        selectedStamp.load(":/stamps/orange-sun.png");
    }
    else if(id == 2){
        selectedStamp.load(":/stamps/cloud.png");
    }
    else if(id == 3){
        selectedStamp.load(":/stamps/pokeball.png");
    }
    else if(id == 4){
        selectedStamp.load(":/stamps/sword.png");
    }
    else if(id == 5){
        selectedStamp.load(":/stamps/sunglasses.png");
    }
    else if(id == 6){
        selectedStamp.load(":/stamps/pikachu.png");
    }
    else if(id == 7){
        selectedStamp.load(":/stamps/ash.png");
    }
    else if(id == 8){
        selectedStamp.load(":/stamps/squirtle.png");
    }
    else if(id == 9){
        selectedStamp.load(":/stamps/cowboy.png");
    }
}

//Slot for when the ellipse tool is selected.
void SpriteMainWindow::on_ellipseTool_clicked()
{
    pen.setColor(penColor);
    brush = ellipse;
}

//Slot for when the rectangle tool is selected.
void SpriteMainWindow::on_rectangleTool_clicked()
{
    pen.setColor(penColor);
    brush = rect;
}

//Slot for when the line tool is selected.
void SpriteMainWindow::on_lineTool_clicked()
{
    pen.setColor(penColor);
    brush = line;
}

//Slot for when the eraser tool is selected.
void SpriteMainWindow::on_eraserTool_clicked()
{
    pen.setColor(this->backgroundColor);
    brush = eraser;
}

//Slot for when the pen tool is selected.
void SpriteMainWindow::on_penTool_clicked()
{
    pen.setColor(penColor);
    brush = pencil;
    this->cursor().setShape(Qt::CrossCursor);
}

//Add a Frame
void SpriteMainWindow::on_addFrameButton_clicked()
{
    // Resize previous zoomed frame before switching
    currentFrame->setPixmap(currentFrame->pixmap()->scaled(spriteWidth, spriteHeight));
    currentFrame->makeFrameUnactive();
    pen.setWidth(penWidthSelected);
    timesScaled = 0;

    currentSprite.addFrame();
    Frame* s =currentSprite.getFrames().last();
    s->setMinimumSize(160,160);
    s->setMaximumSize(160,160);
    s->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    s->setScaledContents(true);
    ui->scrollAreaWidgetContents->layout()->addWidget(s);


    currentFrame = currentSprite.getFrames().last();
    currentFrame->makeFrameActive();


    //Set the pixmap of the new frame
    QPixmap map(spriteWidth, spriteHeight);
    map.fill(this->backgroundColor);
    currentFrame->setPixmap(map);


    workspacePixMap = currentFrame->pixmap()->copy();
    ui->workspaceLabel->setPixmap(workspacePixMap);


    //sets the scrollbar to the bottom
    QScrollBar* verticalScrollBar = ui->framesScrollArea->verticalScrollBar();
    verticalScrollBar->setMaximum(verticalScrollBar->maximum() + 170);
    verticalScrollBar->setSliderPosition(verticalScrollBar->maximum());

}

//Slot for when the fps slider value changes.
//Sets the fps contained in the currentSprite, and also adjusts the speed of the timer.
void SpriteMainWindow::on_fpsSlider_valueChanged(int value)
{
    currentSprite.setFps(value);
    if(value == 0){
        timer->start(10);
    }
    else{
        timer->start(1000/currentSprite.getFps());
    }
}


//Menu Item Slots

//Slot for when File/New is selected from the menu bar.
void SpriteMainWindow::on_actionNew_triggered()
{
    //Check if the user wants to save any changes first, then trigger the reset action.
    if(maybeSave()){
        GetResolutionDialog welcomeScreen;
        connect(&welcomeScreen, SIGNAL(okClicked(int,int)), this, SLOT(initialResolution(int,int)));
        welcomeScreen.exec();
        //this->on_actionReset_triggered();


        //Clear the workspacePixMap
        workspacePixMap = QPixmap(this->spriteWidth, this->spriteHeight);
        workspacePixMap.fill(this->backgroundColor);
        ui->workspaceLabel->setPixmap(workspacePixMap);

        //Clear out the current Sprite
        Sprite newSprite(this->spriteWidth, this->spriteHeight, currentSprite.getFps(), "IDK");
        currentSprite = newSprite;

        //sets the current frame to the first frame
        currentFrame = currentSprite.getFrames().last();

        connect(currentFrame, SIGNAL(clicked(Frame*)), this, SLOT(frameClicked(Frame*)));
        currentFrame->setPixmap(workspacePixMap);
        currentFrame->makeFrameActive();


        //Deletes old layout and its children
        QLayoutItem* child;
        while((child = ui->scrollAreaWidgetContents->layout()->takeAt(0)) != 0){
            delete child->widget();
            delete child;
        }

        currentFrame->setMinimumSize(160,160);
        currentFrame->setMaximumSize(160,160);
        currentFrame->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        currentFrame->setScaledContents(true);
        ui->scrollAreaWidgetContents->layout()->addWidget(currentFrame);

    }

}

//Slot for when File/Open is selected from the menu bar. Opens a new Sprite in the current window,
//replacing any current contents.
void SpriteMainWindow::on_actionOpen_triggered()
{
    //creates a dialog and a popup appears asking for filename.
    QFileDialog dialog;
    QString nameOfFile= dialog.getOpenFileName(this, tr("Open File"), "", tr("Sprite (*.ssp)"));

    //if user canceled out of the dialog, return and do nothing.
    if (nameOfFile == ""){
        return;
    }

    //Check if the user wants to save any changes first, then open the project.
    maybeSave();

    //opening project
    currentSprite.loadFile(nameOfFile);

    //Deletes old layout and its children
    QLayoutItem* child;
    while((child = ui->scrollAreaWidgetContents->layout()->takeAt(0)) != 0){
        delete child->widget();
        delete child;
    }

    //Adds all the frames that are in the vector to the GUI layout
    for (int i = 0; i < currentSprite.getFrames().size(); i++){
        Frame* tmp = &currentSprite.getFrame(i);
        tmp->setMinimumSize(160,160);
        tmp->setMaximumSize(160,160);
        tmp->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        tmp->setScaledContents(true);
        tmp->makeFrameUnactive();
        ui->scrollAreaWidgetContents->layout()->addWidget(tmp);

    }

    currentFrame = (currentSprite.getFrames().first());

    //Clear the workspacePixMap
    workspacePixMap = currentFrame->pixmap()->copy();
    ui->workspaceLabel->setPixmap(workspacePixMap);

    ui->framesScrollArea->verticalScrollBar()->setSliderPosition(ui->framesScrollArea->verticalScrollBar()->minimum());

    currentFrame->makeFrameActive();
}

//Slot for when File/Save is selected from the menu bar. Saves the current Sprite to a .ssp file
void SpriteMainWindow::on_actionSave_triggered()
{
    QFileDialog dialog;
    isModified = false;
    resetAllFrameSizes();

    currentSprite.saveFile(dialog.getSaveFileName(this, tr("Save File"), "/untitled.ssp", tr("Images (*.ssp)")));
}

//Slot for when export as GIF is selected from the menu.
void SpriteMainWindow::on_actionExport_as_gif_triggered()
{
    resetAllFrameSizes();
    QFileDialog dialog;
    isModified = false;
    currentSprite.exportToGif(dialog.getSaveFileName(this, tr("Save File"), "/untitled.gif", tr("Images (*.gif)")));
}

//Slot for when undo is selected from the menu.
void SpriteMainWindow::on_actionUndo_triggered()
{
    if(!undoStack.empty()) {
        // Save the current frame
        redoStack.push_back(workspacePixMap);
        workspacePixMap = undoStack.back();
        ui->workspaceLabel->setPixmap(workspacePixMap);
        //currentFrame->setPixmap(workspacePixMap.scaled(spriteWidth, spriteHeight));
        currentFrame->setPixmap(workspacePixMap.copy());

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
        //currentFrame->setPixmap(workspacePixMap.scaled(spriteWidth, spriteHeight));
        currentFrame->setPixmap(workspacePixMap.copy());
    }
}

//Slot for when the reset option is selected from the menu.
void SpriteMainWindow::on_actionReset_triggered()
{
    workspacePixMap = QPixmap(this->spriteWidth, this->spriteHeight);
    workspacePixMap.fill(this->backgroundColor);
    ui->workspaceLabel->setPixmap(workspacePixMap);
    currentFrame->setPixmap(workspacePixMap.copy());
    pen.setWidth(penWidthSelected);
    timesScaled = 0;
    scalePen();
}

//Slot for when the Flip Horizontally option is selected from the menu.
void SpriteMainWindow::on_actionFlip_Horizontally_triggered()
{
    QImage image = workspacePixMap.toImage().mirrored(true, false);
    workspacePixMap = QPixmap::fromImage(image);
    ui->workspaceLabel->setPixmap(workspacePixMap);
    currentFrame->setPixmap(workspacePixMap.copy());
}

//Slot for when the flip Vertically option is selected from the menu.
void SpriteMainWindow::on_actionFlip_Vertically_triggered()
{
    QImage image = workspacePixMap.toImage().mirrored(false, true);
    workspacePixMap = QPixmap::fromImage(image);
    ui->workspaceLabel->setPixmap(workspacePixMap);
    currentFrame->setPixmap(workspacePixMap.copy());
}

//Slot for when the rotate Horizontally option is selected from the menu.
void SpriteMainWindow::on_actionRotate_Horizontally_triggered()
{
    QTransform tran;
    tran.rotate(90);
    QImage img = workspacePixMap.toImage();
    img = img.transformed(tran);

    workspacePixMap = QPixmap::fromImage(img).copy();
    ui->workspaceLabel->setPixmap(workspacePixMap);
    currentFrame->setPixmap(workspacePixMap.copy());

}

//Slot for when the rotate Counterclockwise option is selected from the menu.
void SpriteMainWindow::on_actionRotate_Counterclockwise_triggered()
{
    QTransform tran;
    tran.rotate(-90);
    QImage img = workspacePixMap.toImage();
    img = img.transformed(tran);

    workspacePixMap = QPixmap::fromImage(img).copy();
    ui->workspaceLabel->setPixmap(workspacePixMap);
    currentFrame->setPixmap(workspacePixMap.copy());
}

//Slot for when the Show/Hide option is selected from the menu.
void SpriteMainWindow::on_actionShow_Hide_Frame_triggered()
{
    // Resize previous zoomed frame
    currentFrame->setPixmap(currentFrame->pixmap()->scaled(spriteWidth, spriteHeight));

    if(currentFrame->getIsVisible()){
        currentFrame->toggleVisibility(false);
    }
    else{
        currentFrame->toggleVisibility(true);
    }
}

//Slot for when the Frame/Duplicate option is selected from the menu bar.
//Duplicates the current frame.
void SpriteMainWindow::on_actionDuplicate_triggered()
{
    // Resize previous zoomed frame before switching
    currentFrame->setPixmap(currentFrame->pixmap()->scaled(spriteWidth, spriteHeight));
    pen.setWidth(penWidthSelected);
    timesScaled = 0;

    Frame* f = new Frame();
    QPixmap map = currentFrame->pixmap()->scaled(spriteWidth,spriteHeight).copy();
    f->setPixmap(map);

    currentFrame->setPixmap(currentFrame->pixmap()->scaled(spriteWidth, spriteHeight));
    currentFrame->makeFrameUnactive();

    currentSprite.appendFrame(f);

    currentFrame = currentSprite.getFrames().last();

    Frame* s =currentSprite.getFrames().last();
    s->setMinimumSize(160,160);
    s->setMaximumSize(160,160);
    s->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    s->setScaledContents(true);
    ui->scrollAreaWidgetContents->layout()->addWidget(s);

    currentFrame->makeFrameActive();

    workspacePixMap = map;
    ui->workspaceLabel->setPixmap(workspacePixMap);

    //sets the scrollbar to the bottom
    QScrollBar* verticalScrollBar = ui->framesScrollArea->verticalScrollBar();
    verticalScrollBar->setMaximum(verticalScrollBar->maximum() + 170);
    verticalScrollBar->setSliderPosition(verticalScrollBar->maximum());
}

//Slot for when the delete option is selected from the menu. Removes the currently selected frame.
void SpriteMainWindow::on_actionDelete_triggered()
{
    //Find the position of the frame to be deleted from the currentSprite's frames vector
    QVector<Frame*> frames = this->currentSprite.getFrames();
    if(frames.length() > 1){
        int frameID = -1;
        for(int i = 0; i < frames.length(); i++){
            if(frames.at(i) == currentFrame){
                frameID = i;
                break;
            }
        }

        //Enter this only if the frame was successfully removed from the currentSprite.
        if(currentSprite.removeFrame(currentFrame)){

            if (frameID != 0){
                currentFrame = this->currentSprite.getFrames().at(frameID - 1);
            }
            else{
                currentFrame = this->currentSprite.getFrames().first();
            }

            QLayoutItem* child = ui->scrollAreaWidgetContents->layout()->takeAt(frameID);
            delete child->widget();
            delete child;

            workspacePixMap = currentFrame->pixmap()->copy();
            ui->workspaceLabel->setPixmap(workspacePixMap);
            currentFrame->makeFrameActive();
        }
    }
    else{
        QMessageBox::StandardButton warning;
        warning = QMessageBox::warning(this, "Warning", "Must have atleast one frame!", QMessageBox::Ok);
    }
}

//Slot for when the about option is selected from the menu.
void SpriteMainWindow::on_actionAbout_triggered()
{
    PopupWindow aboutPopup;
    aboutPopup.exec();
}

//Override the closeEvent for the window so that a warning popup may be displayed if there are unsaved changes.
void SpriteMainWindow::closeEvent(QCloseEvent *e)
{
    if (maybeSave()) {
        e->accept();
    }
    else {
        e->ignore();
    }
}

//Called when the window wants to close, to determine if there are any necessary changes to save.
bool SpriteMainWindow::maybeSave()
{
    if (isModified) {
        isModified = false;
        resetAllFrameSizes();
        QMessageBox::StandardButton warning;
        warning = QMessageBox::warning(this, tr("Warning"), tr("The sprite has been modified.\n Do you want to save your changes?"),
                                       QMessageBox::Save | QMessageBox::Discard
                                       | QMessageBox::Cancel);
        if (warning == QMessageBox::Save) {
            //Call the Save method here
            on_actionSave_triggered();
            return true;
        }
        else if (warning == QMessageBox::Cancel) {
            isModified = true;
            return false;
        }
    }
    return true;
}

void SpriteMainWindow::scalePen() {
    if(timesScaled < 0 ) {
        for(int i = 0; i < -timesScaled; i++) {
            if(pen.width() > 0) {
                pen.setWidth(pen.width() / 2);
            }
        }
    }
    else {
        for(int i = 0; i < timesScaled; i++) {
            pen.setWidth(pen.width()*2);
        }
    }
}

//Set the smallest brush size
void SpriteMainWindow::on_brushSize1Button_clicked()
{
    penWidthSelected = 1;
    pen.setWidth(penWidthSelected);
    scalePen();
}

//Set the second smallest brush size
void SpriteMainWindow::on_brushSize2Button_clicked()
{
    penWidthSelected = 10;
    pen.setWidth(penWidthSelected);
    scalePen();
}

//Set the medium brush size
void SpriteMainWindow::on_brushSize3Button_clicked()
{
    penWidthSelected = 30;
    pen.setWidth(penWidthSelected);
    scalePen();
}

//Set the largest brush size
void SpriteMainWindow::on_brushSize4Button_clicked()
{
    penWidthSelected = this->spriteWidth / 4;
    pen.setWidth(penWidthSelected);
    scalePen();
}

//Zoom into the workspace
void SpriteMainWindow::on_action2x_Workspace_triggered()
{
    scaleWorkspaceSizeUp();
    update();
}

//Zoom out of the workspace
void SpriteMainWindow::on_actionZoom_Out_triggered()
{
    scaleWorkspaceSizeDown();
    update();
}

//Reset the workspace zoom level
void SpriteMainWindow::on_actionReset_Size_triggered()
{
    resetWorkspaceSizeToOriginal();
    update();
}

//Scale the workspace up
void SpriteMainWindow::scaleWorkspaceSizeUp()
{
    timesScaled++;
    int wspWidth, wspHeight;

    wspWidth = workspacePixMap.width() * 2;
    wspHeight = workspacePixMap.height() * 2;
    pen.setWidth(penWidthSelected);
    scalePen();
    workspacePixMap = workspacePixMap.copy().scaled(wspWidth, wspHeight);
    ui->workspaceLabel->setPixmap(workspacePixMap);
}

//Scale the workspace down
void SpriteMainWindow::scaleWorkspaceSizeDown()
{
    timesScaled--;

    int wspWidth, wspHeight;
    wspWidth = workspacePixMap.width() / 2;
    wspHeight = workspacePixMap.height() / 2;
    pen.setWidth(penWidthSelected);
    scalePen();
    workspacePixMap = workspacePixMap.copy().scaled(wspWidth, wspHeight);
    ui->workspaceLabel->setPixmap(workspacePixMap);
}

//Rescale the workspace to the original level
void SpriteMainWindow::resetWorkspaceSizeToOriginal()
{
    timesScaled = 0;
    pen.setWidth(penWidthSelected);
    workspacePixMap = currentFrame->pixmap()->copy().scaled(this->spriteWidth, this->spriteHeight);
    ui->workspaceLabel->setPixmap(workspacePixMap);
}

//Called after the intial popup, asking for the settings of the current session, closes.
void SpriteMainWindow::initialResolution(int width, int backColor)
{

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

    this->spriteWidth = width;
    this->spriteHeight = width;
}

//Slot for when a frame is clicked.
void SpriteMainWindow::frameClicked(Frame* other)
{
    // Resize previous zoomed frame before switching
    if(other != currentFrame) {
        currentFrame->setPixmap(currentFrame->pixmap()->scaled(spriteWidth, spriteHeight));
    }

    currentFrame->makeFrameUnactive();
    currentFrame = other;
    currentFrame->makeFrameActive();

    workspacePixMap = currentFrame->pixmap()->copy();
    ui->workspaceLabel->setPixmap(workspacePixMap);

    //If the frame you clicked on is partially cut off because it is at the top or bottom of the scroll area,
    //then the scroll area moves so you see it.
    ui->framesScrollArea->ensureWidgetVisible(currentFrame, 0, 0);

}

//Rotates the selected frame 90 degrees counterclockwise
void SpriteMainWindow::on_rotateCounterClockButton_clicked()
{
    QTransform tran;
    tran.rotate(-90);
    QImage img = workspacePixMap.toImage();
    img = img.transformed(tran);

    workspacePixMap = QPixmap::fromImage(img).copy();
    ui->workspaceLabel->setPixmap(workspacePixMap);
    currentFrame->setPixmap(workspacePixMap.copy());
}

//Rotates the selected frame 90 degrees clockwise
void SpriteMainWindow::on_rotateClockwiseButton_clicked()
{
    QTransform tran;
    tran.rotate(90);
    QImage img = workspacePixMap.toImage();
    img = img.transformed(tran);

    workspacePixMap = QPixmap::fromImage(img).copy();
    ui->workspaceLabel->setPixmap(workspacePixMap);
    currentFrame->setPixmap(workspacePixMap.copy());
}

//Mirrors the current frame across a horizontal axis (flips it vertically).
void SpriteMainWindow::on_flipVerticalButton_clicked()
{
    QImage image = workspacePixMap.toImage().mirrored(false, true);
    workspacePixMap = QPixmap::fromImage(image);
    ui->workspaceLabel->setPixmap(workspacePixMap);

    currentFrame->setPixmap(workspacePixMap.copy());
}

//Mirrors the current frame across a vertical axis (flips it horizontally).
void SpriteMainWindow::on_flipHorizontalButton_clicked()
{
    QImage image = workspacePixMap.toImage().mirrored(true, false);
    workspacePixMap = QPixmap::fromImage(image);
    ui->workspaceLabel->setPixmap(workspacePixMap);

    //currentFrame->setPixmap(workspacePixMap.scaled(spriteWidth, spriteHeight));
    currentFrame->setPixmap(workspacePixMap.copy());
}

//Called when the timer updates
void SpriteMainWindow::whenTimerUpdates()
{
    if(currentSprite.getFps() > 0){
        it++;
    }
    if(it >= currentSprite.getFrames().size()){
        it = 0;
    }

    //counts how many non visible frames there are
    int numOfNotVisible = 0;

    //if the current frame is not visible, iterate until there is one visible.
    while (!currentSprite.getFrame(it).getIsVisible()){

        numOfNotVisible++;
        it++;

        if(it >= currentSprite.getFrames().size()){
            it = 0;
        }

        //If all of the frames are not visible, return
        if (numOfNotVisible >= currentSprite.getFrames().size() ){
            return;
        }
    }


    ui->previewLabelMap->setPixmap((currentSprite.getFrame(it).pixmap()->scaled(spriteWidth, spriteHeight)).copy());
    previewWindow.setPixmap((currentSprite.getFrame(it).pixmap()->scaled(spriteWidth, spriteHeight)).copy());
}

//Sets the fps of the slider in the UI, and also sets the fps of the current Sprite.
void SpriteMainWindow::setFps(int fps)
{
    ui->fpsSlider->setValue(fps);
    currentSprite.setFps(fps);
}

//Resets the sizes of all of the frames in the currentSprite.
void SpriteMainWindow::resetAllFrameSizes()
{
    QVector<Frame*> frames = currentSprite.getFrames();
    for(int i = 0; i < frames.size(); i++) {
        frames[i]->setPixmap(frames[i]->pixmap()->scaled(spriteWidth, spriteHeight));
    }
}

//Toggles the transparent grid behind the workspace
void SpriteMainWindow::on_transparentGridButton_clicked()
{
    if(transparentGridIsVisible) {
        ui->workspaceLabel->setStyleSheet("#workspaceLabel { background-color: rgb(29,29,29); border: none;}");
        ui->previewLabelMap->setStyleSheet(" background-color: rgb(29,29,29); border: none;");
        transparentGridIsVisible = false;
    }
    else {
        ui->workspaceLabel->setStyleSheet("#workspaceLabel { background-color: rgb(29,29,29); "
                                          "background-image: url(:transparent pattern 3.png);border: none;}");
        ui->previewLabelMap->setStyleSheet(" background-color: rgb(29,29,29); "
                                          "background-image: url(:transparent pattern 3.png);border: none;");
        transparentGridIsVisible = true;
    }
}

// Toggles pen tip between round or flat.
void SpriteMainWindow::on_actionToggle_Pen_Tip_triggered()
{
    if(pen.capStyle() == Qt::FlatCap) {
        pen.setCapStyle(Qt::RoundCap);
    }
    else {
        pen.setCapStyle(Qt::FlatCap);
    }
}

void SpriteMainWindow::on_actionSolid_triggered()
{
    pen.setStyle(Qt::SolidLine);
}

void SpriteMainWindow::on_actionDash_triggered()
{
    pen.setStyle(Qt::DashLine);
}

void SpriteMainWindow::on_actionDot_triggered()
{
    pen.setStyle(Qt::DotLine);
}
