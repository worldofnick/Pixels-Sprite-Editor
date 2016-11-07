/********************************************************************************
** Form generated from reading UI file 'SpriteMainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPRITEMAINWINDOW_H
#define UI_SPRITEMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SpriteMainWindow
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionStamp;
    QAction *actionQuit;
    QAction *actionSprite_Sheet;
    QAction *actionAnimated_GIF;
    QAction *actionExport_as_gif;
    QAction *actionUndo;
    QAction *actionRedo;
    QAction *actionReset;
    QAction *actionFlip_Horizontally;
    QAction *actionFlip_Vertically;
    QAction *actionRotate_Horizontally;
    QAction *actionRotate_Counterclockwise;
    QAction *actionShow_Hide_Frame;
    QAction *actionDuplicate;
    QAction *actionDelete;
    QAction *actionRemove_All;
    QAction *actionAbout;
    QAction *actionWalkthrough;
    QAction *action2x_Workspace;
    QWidget *centralWidget;
    QWidget *workspaceWidgetContainer;
    QGridLayout *gridLayout_5;
    QGridLayout *gridLayout;
    QFrame *framesContainer;
    QVBoxLayout *verticalLayout;
    QScrollArea *framesScrollArea;
    QWidget *scrollAreaWidgetContents;
    QPushButton *addFrameButton;
    QPushButton *duplicateFrameButton;
    QSpacerItem *verticalSpacer;
    QLabel *previewLabelMap;
    QSlider *fpsSlider;
    QLabel *workspaceLabel;
    QFrame *toolsContainer;
    QPushButton *penTool;
    QPushButton *eraserTool;
    QPushButton *lineTool;
    QPushButton *ellipseTool;
    QPushButton *stampTool;
    QPushButton *rotateCounterClockButton;
    QPushButton *rotateClockwiseButton;
    QPushButton *flipHorizontalButton;
    QPushButton *flipVerticalButton;
    QPushButton *undoButton;
    QPushButton *redoButton;
    QPushButton *unassignedButton_3;
    QPushButton *unassignedButton_4;
    QPushButton *brushSize1Button;
    QPushButton *brushSize2Button;
    QPushButton *brushSize3Button;
    QPushButton *brushSize4Button;
    QPushButton *colorPickButton;
    QPushButton *rectangleTool;
    QPushButton *unassignedButton_5;
    QPushButton *unassignedButton_6;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuSave_As;
    QMenu *menuEdit;
    QMenu *menuTools;
    QMenu *menuHelp;

    void setupUi(QMainWindow *SpriteMainWindow)
    {
        if (SpriteMainWindow->objectName().isEmpty())
            SpriteMainWindow->setObjectName(QStringLiteral("SpriteMainWindow"));
        SpriteMainWindow->resize(920, 600);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SpriteMainWindow->sizePolicy().hasHeightForWidth());
        SpriteMainWindow->setSizePolicy(sizePolicy);
        SpriteMainWindow->setMinimumSize(QSize(920, 600));
        SpriteMainWindow->setWindowOpacity(1);
        actionNew = new QAction(SpriteMainWindow);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        actionOpen = new QAction(SpriteMainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave = new QAction(SpriteMainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionStamp = new QAction(SpriteMainWindow);
        actionStamp->setObjectName(QStringLiteral("actionStamp"));
        actionQuit = new QAction(SpriteMainWindow);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        actionSprite_Sheet = new QAction(SpriteMainWindow);
        actionSprite_Sheet->setObjectName(QStringLiteral("actionSprite_Sheet"));
        actionAnimated_GIF = new QAction(SpriteMainWindow);
        actionAnimated_GIF->setObjectName(QStringLiteral("actionAnimated_GIF"));
        actionExport_as_gif = new QAction(SpriteMainWindow);
        actionExport_as_gif->setObjectName(QStringLiteral("actionExport_as_gif"));
        actionUndo = new QAction(SpriteMainWindow);
        actionUndo->setObjectName(QStringLiteral("actionUndo"));
        actionRedo = new QAction(SpriteMainWindow);
        actionRedo->setObjectName(QStringLiteral("actionRedo"));
        actionReset = new QAction(SpriteMainWindow);
        actionReset->setObjectName(QStringLiteral("actionReset"));
        actionFlip_Horizontally = new QAction(SpriteMainWindow);
        actionFlip_Horizontally->setObjectName(QStringLiteral("actionFlip_Horizontally"));
        actionFlip_Vertically = new QAction(SpriteMainWindow);
        actionFlip_Vertically->setObjectName(QStringLiteral("actionFlip_Vertically"));
        actionRotate_Horizontally = new QAction(SpriteMainWindow);
        actionRotate_Horizontally->setObjectName(QStringLiteral("actionRotate_Horizontally"));
        actionRotate_Counterclockwise = new QAction(SpriteMainWindow);
        actionRotate_Counterclockwise->setObjectName(QStringLiteral("actionRotate_Counterclockwise"));
        actionShow_Hide_Frame = new QAction(SpriteMainWindow);
        actionShow_Hide_Frame->setObjectName(QStringLiteral("actionShow_Hide_Frame"));
        actionDuplicate = new QAction(SpriteMainWindow);
        actionDuplicate->setObjectName(QStringLiteral("actionDuplicate"));
        actionDelete = new QAction(SpriteMainWindow);
        actionDelete->setObjectName(QStringLiteral("actionDelete"));
        actionRemove_All = new QAction(SpriteMainWindow);
        actionRemove_All->setObjectName(QStringLiteral("actionRemove_All"));
        actionAbout = new QAction(SpriteMainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionWalkthrough = new QAction(SpriteMainWindow);
        actionWalkthrough->setObjectName(QStringLiteral("actionWalkthrough"));
        action2x_Workspace = new QAction(SpriteMainWindow);
        action2x_Workspace->setObjectName(QStringLiteral("action2x_Workspace"));
        centralWidget = new QWidget(SpriteMainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        workspaceWidgetContainer = new QWidget(centralWidget);
        workspaceWidgetContainer->setObjectName(QStringLiteral("workspaceWidgetContainer"));
        workspaceWidgetContainer->setGeometry(QRect(784, 578, 16, 16));
        sizePolicy.setHeightForWidth(workspaceWidgetContainer->sizePolicy().hasHeightForWidth());
        workspaceWidgetContainer->setSizePolicy(sizePolicy);
        gridLayout_5 = new QGridLayout(workspaceWidgetContainer);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        framesContainer = new QFrame(centralWidget);
        framesContainer->setObjectName(QStringLiteral("framesContainer"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(framesContainer->sizePolicy().hasHeightForWidth());
        framesContainer->setSizePolicy(sizePolicy1);
        framesContainer->setMinimumSize(QSize(200, 200));
        framesContainer->setMaximumSize(QSize(200, 16777215));
        framesContainer->setFrameShape(QFrame::NoFrame);
        framesContainer->setFrameShadow(QFrame::Plain);
        framesContainer->setLineWidth(0);
        verticalLayout = new QVBoxLayout(framesContainer);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(10, 10, 10, 10);
        framesScrollArea = new QScrollArea(framesContainer);
        framesScrollArea->setObjectName(QStringLiteral("framesScrollArea"));
        sizePolicy.setHeightForWidth(framesScrollArea->sizePolicy().hasHeightForWidth());
        framesScrollArea->setSizePolicy(sizePolicy);
        framesScrollArea->setMaximumSize(QSize(500, 16777215));
        framesScrollArea->setFrameShape(QFrame::NoFrame);
        framesScrollArea->setFrameShadow(QFrame::Plain);
        framesScrollArea->setLineWidth(0);
        framesScrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        framesScrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        framesScrollArea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
        framesScrollArea->setWidgetResizable(true);
        framesScrollArea->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 164, 278));
        framesScrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(framesScrollArea);

        addFrameButton = new QPushButton(framesContainer);
        addFrameButton->setObjectName(QStringLiteral("addFrameButton"));
        addFrameButton->setStyleSheet(QLatin1String("#addFrameButton{\n"
"	border-radius: 4px;\n"
"	background-color: rgb(100, 100, 100);\n"
"}\n"
"\n"
"#addFrameButton:hover{	\n"
"	background-color: rgb(183, 183, 183);\n"
"}"));

        verticalLayout->addWidget(addFrameButton);

        duplicateFrameButton = new QPushButton(framesContainer);
        duplicateFrameButton->setObjectName(QStringLiteral("duplicateFrameButton"));
        duplicateFrameButton->setStyleSheet(QLatin1String("#duplicateFrameButton{\n"
"	border-radius: 4px;\n"
"	background-color: rgb(100, 100, 100);\n"
"	color: rgb(252, 255, 255);\n"
"}\n"
"\n"
"#duplicateFrameButton:hover{	\n"
"	background-color: rgb(183, 183, 183);\n"
"}"));

        verticalLayout->addWidget(duplicateFrameButton);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout->addItem(verticalSpacer);

        previewLabelMap = new QLabel(framesContainer);
        previewLabelMap->setObjectName(QStringLiteral("previewLabelMap"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(previewLabelMap->sizePolicy().hasHeightForWidth());
        previewLabelMap->setSizePolicy(sizePolicy2);
        previewLabelMap->setMinimumSize(QSize(150, 150));
        previewLabelMap->setMouseTracking(false);
        previewLabelMap->setStyleSheet(QLatin1String("background-color: rgb(29,29,29);\n"
"background-image: url(:transparent pattern 3.png);\n"
"border: none;"));
        previewLabelMap->setLineWidth(0);

        verticalLayout->addWidget(previewLabelMap);

        fpsSlider = new QSlider(framesContainer);
        fpsSlider->setObjectName(QStringLiteral("fpsSlider"));
        fpsSlider->setMaximum(32);
        fpsSlider->setOrientation(Qt::Horizontal);
        fpsSlider->setTickPosition(QSlider::TicksBelow);
        fpsSlider->setTickInterval(0);

        verticalLayout->addWidget(fpsSlider);


        gridLayout->addWidget(framesContainer, 0, 0, 2, 1);

        workspaceLabel = new QLabel(centralWidget);
        workspaceLabel->setObjectName(QStringLiteral("workspaceLabel"));
        sizePolicy.setHeightForWidth(workspaceLabel->sizePolicy().hasHeightForWidth());
        workspaceLabel->setSizePolicy(sizePolicy);
        workspaceLabel->setMinimumSize(QSize(600, 600));
        workspaceLabel->setCursor(QCursor(Qt::CrossCursor));
        workspaceLabel->setMouseTracking(false);
        workspaceLabel->setFocusPolicy(Qt::NoFocus);
        workspaceLabel->setStyleSheet(QLatin1String("background-color: rgb(29,29,29);\n"
"background-image: url(:transparent pattern 3.png);\n"
"border: none;\n"
"\n"
""));
        workspaceLabel->setFrameShape(QFrame::NoFrame);
        workspaceLabel->setLineWidth(0);
        workspaceLabel->setScaledContents(false);
        workspaceLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(workspaceLabel, 0, 1, 1, 1);

        toolsContainer = new QFrame(centralWidget);
        toolsContainer->setObjectName(QStringLiteral("toolsContainer"));
        sizePolicy1.setHeightForWidth(toolsContainer->sizePolicy().hasHeightForWidth());
        toolsContainer->setSizePolicy(sizePolicy1);
        toolsContainer->setMinimumSize(QSize(120, 600));
        toolsContainer->setMaximumSize(QSize(120, 16777215));
        toolsContainer->setStyleSheet(QLatin1String("background-color: qlineargradient(spread:pad, x1:0.482, y1:0.4375, x2:0.488, y2:0.994318, stop:0 rgba(35, 37, 37, 255), stop:1 rgba(51, 53, 53, 255));\n"
"color: rgb(239, 239, 239);"));
        toolsContainer->setFrameShape(QFrame::NoFrame);
        toolsContainer->setFrameShadow(QFrame::Plain);
        toolsContainer->setLineWidth(0);
        penTool = new QPushButton(toolsContainer);
        penTool->setObjectName(QStringLiteral("penTool"));
        penTool->setEnabled(true);
        penTool->setGeometry(QRect(8, 10, 50, 50));
        sizePolicy2.setHeightForWidth(penTool->sizePolicy().hasHeightForWidth());
        penTool->setSizePolicy(sizePolicy2);
        penTool->setMinimumSize(QSize(50, 50));
        penTool->setMaximumSize(QSize(50, 50));
        QPalette palette;
        QBrush brush(QColor(239, 239, 239, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QLinearGradient gradient(0.482, 0.4375, 0.488, 0.994318);
        gradient.setSpread(QGradient::PadSpread);
        gradient.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient.setColorAt(0, QColor(35, 37, 37, 255));
        gradient.setColorAt(1, QColor(51, 53, 53, 255));
        QBrush brush1(gradient);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QLinearGradient gradient1(0.482, 0.4375, 0.488, 0.994318);
        gradient1.setSpread(QGradient::PadSpread);
        gradient1.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient1.setColorAt(0, QColor(35, 37, 37, 255));
        gradient1.setColorAt(1, QColor(51, 53, 53, 255));
        QBrush brush2(gradient1);
        palette.setBrush(QPalette::Active, QPalette::Base, brush2);
        QLinearGradient gradient2(0.482, 0.4375, 0.488, 0.994318);
        gradient2.setSpread(QGradient::PadSpread);
        gradient2.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient2.setColorAt(0, QColor(35, 37, 37, 255));
        gradient2.setColorAt(1, QColor(51, 53, 53, 255));
        QBrush brush3(gradient2);
        palette.setBrush(QPalette::Active, QPalette::Window, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QLinearGradient gradient3(0.482, 0.4375, 0.488, 0.994318);
        gradient3.setSpread(QGradient::PadSpread);
        gradient3.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient3.setColorAt(0, QColor(35, 37, 37, 255));
        gradient3.setColorAt(1, QColor(51, 53, 53, 255));
        QBrush brush4(gradient3);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        QLinearGradient gradient4(0.482, 0.4375, 0.488, 0.994318);
        gradient4.setSpread(QGradient::PadSpread);
        gradient4.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient4.setColorAt(0, QColor(35, 37, 37, 255));
        gradient4.setColorAt(1, QColor(51, 53, 53, 255));
        QBrush brush5(gradient4);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush5);
        QLinearGradient gradient5(0.482, 0.4375, 0.488, 0.994318);
        gradient5.setSpread(QGradient::PadSpread);
        gradient5.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient5.setColorAt(0, QColor(35, 37, 37, 255));
        gradient5.setColorAt(1, QColor(51, 53, 53, 255));
        QBrush brush6(gradient5);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        QLinearGradient gradient6(0.482, 0.4375, 0.488, 0.994318);
        gradient6.setSpread(QGradient::PadSpread);
        gradient6.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient6.setColorAt(0, QColor(35, 37, 37, 255));
        gradient6.setColorAt(1, QColor(51, 53, 53, 255));
        QBrush brush7(gradient6);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        QLinearGradient gradient7(0.482, 0.4375, 0.488, 0.994318);
        gradient7.setSpread(QGradient::PadSpread);
        gradient7.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient7.setColorAt(0, QColor(35, 37, 37, 255));
        gradient7.setColorAt(1, QColor(51, 53, 53, 255));
        QBrush brush8(gradient7);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush8);
        QLinearGradient gradient8(0.482, 0.4375, 0.488, 0.994318);
        gradient8.setSpread(QGradient::PadSpread);
        gradient8.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient8.setColorAt(0, QColor(35, 37, 37, 255));
        gradient8.setColorAt(1, QColor(51, 53, 53, 255));
        QBrush brush9(gradient8);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush9);
        penTool->setPalette(palette);
        penTool->setStyleSheet(QStringLiteral(""));
        QIcon icon;
        icon.addFile(QStringLiteral(":/pen2.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon.addFile(QStringLiteral(":/pen1.png"), QSize(), QIcon::Normal, QIcon::On);
        penTool->setIcon(icon);
        penTool->setIconSize(QSize(23, 23));
        penTool->setCheckable(true);
        penTool->setChecked(true);
        penTool->setFlat(true);
        eraserTool = new QPushButton(toolsContainer);
        eraserTool->setObjectName(QStringLiteral("eraserTool"));
        eraserTool->setGeometry(QRect(62, 10, 50, 50));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(60);
        sizePolicy3.setVerticalStretch(60);
        sizePolicy3.setHeightForWidth(eraserTool->sizePolicy().hasHeightForWidth());
        eraserTool->setSizePolicy(sizePolicy3);
        eraserTool->setMinimumSize(QSize(50, 50));
        eraserTool->setMaximumSize(QSize(50, 50));
        eraserTool->setStyleSheet(QStringLiteral(""));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/eraser2.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon1.addFile(QStringLiteral(":/eraser1.png"), QSize(), QIcon::Normal, QIcon::On);
        eraserTool->setIcon(icon1);
        eraserTool->setIconSize(QSize(23, 23));
        eraserTool->setCheckable(true);
        eraserTool->setFlat(true);
        lineTool = new QPushButton(toolsContainer);
        lineTool->setObjectName(QStringLiteral("lineTool"));
        lineTool->setGeometry(QRect(8, 60, 50, 50));
        sizePolicy3.setHeightForWidth(lineTool->sizePolicy().hasHeightForWidth());
        lineTool->setSizePolicy(sizePolicy3);
        lineTool->setMinimumSize(QSize(50, 50));
        lineTool->setMaximumSize(QSize(50, 50));
        lineTool->setStyleSheet(QStringLiteral(""));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/line2.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon2.addFile(QStringLiteral(":/line1.png"), QSize(), QIcon::Normal, QIcon::On);
        lineTool->setIcon(icon2);
        lineTool->setIconSize(QSize(23, 23));
        lineTool->setCheckable(true);
        lineTool->setFlat(true);
        ellipseTool = new QPushButton(toolsContainer);
        ellipseTool->setObjectName(QStringLiteral("ellipseTool"));
        ellipseTool->setGeometry(QRect(8, 110, 50, 50));
        sizePolicy3.setHeightForWidth(ellipseTool->sizePolicy().hasHeightForWidth());
        ellipseTool->setSizePolicy(sizePolicy3);
        ellipseTool->setMinimumSize(QSize(50, 50));
        ellipseTool->setMaximumSize(QSize(50, 50));
        ellipseTool->setStyleSheet(QStringLiteral(""));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/ellipse2.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon3.addFile(QStringLiteral(":/ellipse1.png"), QSize(), QIcon::Normal, QIcon::On);
        ellipseTool->setIcon(icon3);
        ellipseTool->setIconSize(QSize(23, 22));
        ellipseTool->setCheckable(true);
        ellipseTool->setFlat(true);
        stampTool = new QPushButton(toolsContainer);
        stampTool->setObjectName(QStringLiteral("stampTool"));
        stampTool->setGeometry(QRect(62, 110, 50, 50));
        sizePolicy2.setHeightForWidth(stampTool->sizePolicy().hasHeightForWidth());
        stampTool->setSizePolicy(sizePolicy2);
        stampTool->setMinimumSize(QSize(50, 50));
        stampTool->setMaximumSize(QSize(50, 50));
        stampTool->setStyleSheet(QStringLiteral(""));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/stamp2.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon4.addFile(QStringLiteral(":/stamp1.png"), QSize(), QIcon::Normal, QIcon::On);
        stampTool->setIcon(icon4);
        stampTool->setIconSize(QSize(23, 23));
        stampTool->setCheckable(true);
        stampTool->setFlat(true);
        rotateCounterClockButton = new QPushButton(toolsContainer);
        rotateCounterClockButton->setObjectName(QStringLiteral("rotateCounterClockButton"));
        rotateCounterClockButton->setGeometry(QRect(8, 260, 50, 50));
        sizePolicy3.setHeightForWidth(rotateCounterClockButton->sizePolicy().hasHeightForWidth());
        rotateCounterClockButton->setSizePolicy(sizePolicy3);
        rotateCounterClockButton->setMinimumSize(QSize(50, 50));
        rotateCounterClockButton->setMaximumSize(QSize(50, 50));
        rotateCounterClockButton->setStyleSheet(QStringLiteral(""));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/ccw2.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon5.addFile(QStringLiteral(":/ccw1.png"), QSize(), QIcon::Normal, QIcon::On);
        rotateCounterClockButton->setIcon(icon5);
        rotateCounterClockButton->setIconSize(QSize(23, 23));
        rotateCounterClockButton->setCheckable(true);
        rotateCounterClockButton->setFlat(true);
        rotateClockwiseButton = new QPushButton(toolsContainer);
        rotateClockwiseButton->setObjectName(QStringLiteral("rotateClockwiseButton"));
        rotateClockwiseButton->setGeometry(QRect(62, 260, 50, 50));
        sizePolicy3.setHeightForWidth(rotateClockwiseButton->sizePolicy().hasHeightForWidth());
        rotateClockwiseButton->setSizePolicy(sizePolicy3);
        rotateClockwiseButton->setMinimumSize(QSize(50, 50));
        rotateClockwiseButton->setMaximumSize(QSize(50, 50));
        rotateClockwiseButton->setStyleSheet(QStringLiteral(""));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/cw2.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon6.addFile(QStringLiteral(":/cw1.png"), QSize(), QIcon::Normal, QIcon::On);
        rotateClockwiseButton->setIcon(icon6);
        rotateClockwiseButton->setIconSize(QSize(23, 23));
        rotateClockwiseButton->setCheckable(true);
        rotateClockwiseButton->setFlat(true);
        flipHorizontalButton = new QPushButton(toolsContainer);
        flipHorizontalButton->setObjectName(QStringLiteral("flipHorizontalButton"));
        flipHorizontalButton->setGeometry(QRect(62, 210, 50, 50));
        sizePolicy3.setHeightForWidth(flipHorizontalButton->sizePolicy().hasHeightForWidth());
        flipHorizontalButton->setSizePolicy(sizePolicy3);
        flipHorizontalButton->setMinimumSize(QSize(50, 50));
        flipHorizontalButton->setMaximumSize(QSize(50, 50));
        flipHorizontalButton->setStyleSheet(QStringLiteral(""));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/flipl2.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon7.addFile(QStringLiteral(":/flipl1.png"), QSize(), QIcon::Normal, QIcon::On);
        flipHorizontalButton->setIcon(icon7);
        flipHorizontalButton->setIconSize(QSize(23, 23));
        flipHorizontalButton->setCheckable(true);
        flipHorizontalButton->setFlat(true);
        flipVerticalButton = new QPushButton(toolsContainer);
        flipVerticalButton->setObjectName(QStringLiteral("flipVerticalButton"));
        flipVerticalButton->setGeometry(QRect(8, 210, 50, 50));
        sizePolicy3.setHeightForWidth(flipVerticalButton->sizePolicy().hasHeightForWidth());
        flipVerticalButton->setSizePolicy(sizePolicy3);
        flipVerticalButton->setMinimumSize(QSize(50, 50));
        flipVerticalButton->setMaximumSize(QSize(50, 50));
        flipVerticalButton->setStyleSheet(QStringLiteral(""));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/flipv2.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon8.addFile(QStringLiteral(":/flipv1.png"), QSize(), QIcon::Normal, QIcon::On);
        flipVerticalButton->setIcon(icon8);
        flipVerticalButton->setIconSize(QSize(23, 23));
        flipVerticalButton->setCheckable(true);
        flipVerticalButton->setFlat(true);
        undoButton = new QPushButton(toolsContainer);
        undoButton->setObjectName(QStringLiteral("undoButton"));
        undoButton->setGeometry(QRect(8, 160, 50, 50));
        sizePolicy3.setHeightForWidth(undoButton->sizePolicy().hasHeightForWidth());
        undoButton->setSizePolicy(sizePolicy3);
        undoButton->setMinimumSize(QSize(50, 50));
        undoButton->setMaximumSize(QSize(50, 50));
        undoButton->setStyleSheet(QStringLiteral(""));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/undo2.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon9.addFile(QStringLiteral(":/undo1.png"), QSize(), QIcon::Normal, QIcon::On);
        undoButton->setIcon(icon9);
        undoButton->setIconSize(QSize(23, 23));
        undoButton->setCheckable(true);
        undoButton->setFlat(true);
        redoButton = new QPushButton(toolsContainer);
        redoButton->setObjectName(QStringLiteral("redoButton"));
        redoButton->setGeometry(QRect(62, 160, 50, 50));
        sizePolicy3.setHeightForWidth(redoButton->sizePolicy().hasHeightForWidth());
        redoButton->setSizePolicy(sizePolicy3);
        redoButton->setMinimumSize(QSize(50, 50));
        redoButton->setMaximumSize(QSize(50, 50));
        redoButton->setStyleSheet(QStringLiteral(""));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/redo1.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon10.addFile(QStringLiteral(":/redo2.png"), QSize(), QIcon::Normal, QIcon::On);
        redoButton->setIcon(icon10);
        redoButton->setIconSize(QSize(23, 23));
        redoButton->setCheckable(true);
        redoButton->setFlat(true);
        unassignedButton_3 = new QPushButton(toolsContainer);
        unassignedButton_3->setObjectName(QStringLiteral("unassignedButton_3"));
        unassignedButton_3->setGeometry(QRect(8, 310, 50, 50));
        sizePolicy3.setHeightForWidth(unassignedButton_3->sizePolicy().hasHeightForWidth());
        unassignedButton_3->setSizePolicy(sizePolicy3);
        unassignedButton_3->setMinimumSize(QSize(50, 50));
        unassignedButton_3->setMaximumSize(QSize(50, 50));
        unassignedButton_3->setStyleSheet(QLatin1String("#unassignedButton_3 {\n"
"	border: 3px solid rgb(239, 239, 239);\n"
"	background-color: rgb(255, 147, 147);\n"
"	border-radius: 10px;\n"
"	color: rgb(76, 76, 76);\n"
"}\n"
"\n"
"#unassignedButton_3:hover\n"
"{\n"
"	background-color: rgb(179, 179, 179);\n"
"	border: 3px solid rgb(252, 252, 252);\n"
"	border-radius: 10px;\n"
"}\n"
"\n"
"#unassignedButton_3:checked\n"
"{\n"
"	background-color: rgb(179, 179, 179);\n"
"	border: 3px solid rgb(252, 252, 252);\n"
"	border-radius: 10px;\n"
"}\n"
"\n"
"#unassignedButton_3:unchecked {\n"
"	border: 3px solid rgb(239, 239, 239);\n"
"	background-color: rgb(255, 147, 147);\n"
"	border-radius: 10px;\n"
"	color: rgb(76, 76, 76);\n"
"}"));
        unassignedButton_3->setCheckable(true);
        unassignedButton_3->setFlat(true);
        unassignedButton_4 = new QPushButton(toolsContainer);
        unassignedButton_4->setObjectName(QStringLiteral("unassignedButton_4"));
        unassignedButton_4->setGeometry(QRect(62, 310, 50, 50));
        sizePolicy3.setHeightForWidth(unassignedButton_4->sizePolicy().hasHeightForWidth());
        unassignedButton_4->setSizePolicy(sizePolicy3);
        unassignedButton_4->setMinimumSize(QSize(50, 50));
        unassignedButton_4->setMaximumSize(QSize(50, 50));
        unassignedButton_4->setStyleSheet(QLatin1String("#unassignedButton_4 {\n"
"	border: 3px solid rgb(239, 239, 239);\n"
"	background-color: rgb(255, 147, 147);\n"
"	border-radius: 10px;\n"
"	color: rgb(76, 76, 76);\n"
"}\n"
"\n"
"#unassignedButton_4:hover\n"
"{\n"
"	background-color: rgb(179, 179, 179);\n"
"	border: 3px solid rgb(252, 252, 252);\n"
"	border-radius: 10px;\n"
"}\n"
"\n"
"#unassignedButton_4:checked\n"
"{\n"
"	background-color: rgb(179, 179, 179);\n"
"	border: 3px solid rgb(252, 252, 252);\n"
"	border-radius: 10px;\n"
"}\n"
"\n"
"#unassignedButton_4:unchecked {\n"
"	border: 3px solid rgb(239, 239, 239);\n"
"	background-color: rgb(255, 147, 147);\n"
"	border-radius: 10px;\n"
"	color: rgb(76, 76, 76);\n"
"}"));
        unassignedButton_4->setCheckable(true);
        unassignedButton_4->setFlat(true);
        brushSize1Button = new QPushButton(toolsContainer);
        brushSize1Button->setObjectName(QStringLiteral("brushSize1Button"));
        brushSize1Button->setGeometry(QRect(5, 430, 25, 25));
        sizePolicy2.setHeightForWidth(brushSize1Button->sizePolicy().hasHeightForWidth());
        brushSize1Button->setSizePolicy(sizePolicy2);
        brushSize1Button->setMinimumSize(QSize(25, 25));
        brushSize1Button->setMaximumSize(QSize(25, 25));
        brushSize1Button->setStyleSheet(QStringLiteral(""));
        brushSize1Button->setCheckable(true);
        brushSize1Button->setChecked(true);
        brushSize1Button->setFlat(true);
        brushSize2Button = new QPushButton(toolsContainer);
        brushSize2Button->setObjectName(QStringLiteral("brushSize2Button"));
        brushSize2Button->setGeometry(QRect(33, 430, 25, 25));
        sizePolicy2.setHeightForWidth(brushSize2Button->sizePolicy().hasHeightForWidth());
        brushSize2Button->setSizePolicy(sizePolicy2);
        brushSize2Button->setMinimumSize(QSize(25, 25));
        brushSize2Button->setMaximumSize(QSize(25, 25));
        brushSize2Button->setStyleSheet(QStringLiteral(""));
        brushSize2Button->setCheckable(true);
        brushSize2Button->setFlat(true);
        brushSize3Button = new QPushButton(toolsContainer);
        brushSize3Button->setObjectName(QStringLiteral("brushSize3Button"));
        brushSize3Button->setGeometry(QRect(62, 430, 25, 25));
        sizePolicy2.setHeightForWidth(brushSize3Button->sizePolicy().hasHeightForWidth());
        brushSize3Button->setSizePolicy(sizePolicy2);
        brushSize3Button->setMinimumSize(QSize(25, 25));
        brushSize3Button->setMaximumSize(QSize(25, 25));
        brushSize3Button->setStyleSheet(QStringLiteral(""));
        brushSize3Button->setCheckable(true);
        brushSize3Button->setFlat(true);
        brushSize4Button = new QPushButton(toolsContainer);
        brushSize4Button->setObjectName(QStringLiteral("brushSize4Button"));
        brushSize4Button->setGeometry(QRect(90, 430, 25, 25));
        sizePolicy2.setHeightForWidth(brushSize4Button->sizePolicy().hasHeightForWidth());
        brushSize4Button->setSizePolicy(sizePolicy2);
        brushSize4Button->setMinimumSize(QSize(25, 25));
        brushSize4Button->setMaximumSize(QSize(25, 25));
        brushSize4Button->setStyleSheet(QStringLiteral(""));
        brushSize4Button->setCheckable(true);
        brushSize4Button->setFlat(true);
        colorPickButton = new QPushButton(toolsContainer);
        colorPickButton->setObjectName(QStringLiteral("colorPickButton"));
        colorPickButton->setGeometry(QRect(10, 480, 100, 100));
        sizePolicy2.setHeightForWidth(colorPickButton->sizePolicy().hasHeightForWidth());
        colorPickButton->setSizePolicy(sizePolicy2);
        colorPickButton->setMinimumSize(QSize(100, 100));
        colorPickButton->setMaximumSize(QSize(100, 100));
        colorPickButton->setStyleSheet(QLatin1String("#colorPickButton {\n"
"background-color: rgb(254, 188, 12);\n"
"/*border-image: url(:RGB Circle 1.png);*/\n"
"/*background: none;*/\n"
"border: 6px solid rgb(252, 252, 252);\n"
"border-radius: 50px;\n"
"background-repeat: none;\n"
"}\n"
"#colorPickButton:hover\n"
"{\n"
"background-color: rgb(254, 210, 80);\n"
"/*background: none;*/\n"
"border: 8px solid rgb(252, 252, 252);\n"
"border-radius: 50px;\n"
"background-repeat: none;\n"
"/*border-image: url(:RGB Circle 2.png);*/\n"
"}"));
        colorPickButton->setFlat(false);
        rectangleTool = new QPushButton(toolsContainer);
        rectangleTool->setObjectName(QStringLiteral("rectangleTool"));
        rectangleTool->setGeometry(QRect(62, 60, 50, 50));
        sizePolicy3.setHeightForWidth(rectangleTool->sizePolicy().hasHeightForWidth());
        rectangleTool->setSizePolicy(sizePolicy3);
        rectangleTool->setMinimumSize(QSize(50, 50));
        rectangleTool->setMaximumSize(QSize(50, 50));
        rectangleTool->setStyleSheet(QStringLiteral(""));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/rect2.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon11.addFile(QStringLiteral(":/rect1.png"), QSize(), QIcon::Normal, QIcon::On);
        rectangleTool->setIcon(icon11);
        rectangleTool->setIconSize(QSize(23, 23));
        rectangleTool->setCheckable(true);
        rectangleTool->setFlat(true);
        unassignedButton_5 = new QPushButton(toolsContainer);
        unassignedButton_5->setObjectName(QStringLiteral("unassignedButton_5"));
        unassignedButton_5->setGeometry(QRect(8, 362, 50, 50));
        sizePolicy3.setHeightForWidth(unassignedButton_5->sizePolicy().hasHeightForWidth());
        unassignedButton_5->setSizePolicy(sizePolicy3);
        unassignedButton_5->setMinimumSize(QSize(50, 50));
        unassignedButton_5->setMaximumSize(QSize(50, 50));
        unassignedButton_5->setStyleSheet(QLatin1String("#unassignedButton_5 {\n"
"	border: 3px solid rgb(239, 239, 239);\n"
"	background-color: rgb(255, 147, 147);\n"
"	border-radius: 10px;\n"
"	color: rgb(76, 76, 76);\n"
"}\n"
"\n"
"#unassignedButton_5:hover\n"
"{\n"
"	background-color: rgb(179, 179, 179);\n"
"	border: 3px solid rgb(252, 252, 252);\n"
"	border-radius: 10px;\n"
"}\n"
"\n"
"#unassignedButton_5:checked\n"
"{\n"
"	background-color: rgb(179, 179, 179);\n"
"	border: 3px solid rgb(252, 252, 252);\n"
"	border-radius: 10px;\n"
"}\n"
"\n"
"#unassignedButton_5:unchecked {\n"
"	border: 3px solid rgb(239, 239, 239);\n"
"	background-color: rgb(255, 147, 147);\n"
"	border-radius: 10px;\n"
"	color: rgb(76, 76, 76);\n"
"}"));
        unassignedButton_5->setCheckable(true);
        unassignedButton_5->setFlat(true);
        unassignedButton_6 = new QPushButton(toolsContainer);
        unassignedButton_6->setObjectName(QStringLiteral("unassignedButton_6"));
        unassignedButton_6->setGeometry(QRect(62, 362, 50, 50));
        sizePolicy3.setHeightForWidth(unassignedButton_6->sizePolicy().hasHeightForWidth());
        unassignedButton_6->setSizePolicy(sizePolicy3);
        unassignedButton_6->setMinimumSize(QSize(50, 50));
        unassignedButton_6->setMaximumSize(QSize(50, 50));
        unassignedButton_6->setStyleSheet(QLatin1String("#unassignedButton_6 {\n"
"	border: 3px solid rgb(239, 239, 239);\n"
"	background-color: rgb(255, 147, 147);\n"
"	border-radius: 10px;\n"
"	color: rgb(76, 76, 76);\n"
"}\n"
"\n"
"#unassignedButton_6:hover\n"
"{\n"
"	background-color: rgb(179, 179, 179);\n"
"	border: 3px solid rgb(252, 252, 252);\n"
"	border-radius: 10px;\n"
"}\n"
"\n"
"#unassignedButton_6:checked\n"
"{\n"
"	background-color: rgb(179, 179, 179);\n"
"	border: 3px solid rgb(252, 252, 252);\n"
"	border-radius: 10px;\n"
"}\n"
"\n"
"#unassignedButton_6:unchecked {\n"
"	border: 3px solid rgb(239, 239, 239);\n"
"	background-color: rgb(255, 147, 147);\n"
"	border-radius: 10px;\n"
"	color: rgb(76, 76, 76);\n"
"}"));
        unassignedButton_6->setCheckable(true);
        unassignedButton_6->setFlat(true);
        eraserTool->raise();
        lineTool->raise();
        ellipseTool->raise();
        stampTool->raise();
        rotateCounterClockButton->raise();
        rotateClockwiseButton->raise();
        flipHorizontalButton->raise();
        flipVerticalButton->raise();
        undoButton->raise();
        redoButton->raise();
        unassignedButton_3->raise();
        unassignedButton_4->raise();
        brushSize1Button->raise();
        brushSize2Button->raise();
        brushSize3Button->raise();
        brushSize4Button->raise();
        colorPickButton->raise();
        rectangleTool->raise();
        penTool->raise();
        unassignedButton_5->raise();
        unassignedButton_6->raise();

        gridLayout->addWidget(toolsContainer, 0, 4, 1, 1);

        SpriteMainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SpriteMainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 920, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuSave_As = new QMenu(menuFile);
        menuSave_As->setObjectName(QStringLiteral("menuSave_As"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuTools = new QMenu(menuBar);
        menuTools->setObjectName(QStringLiteral("menuTools"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        SpriteMainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuTools->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(menuSave_As->menuAction());
        menuFile->addSeparator();
        menuFile->addAction(actionExport_as_gif);
        menuSave_As->addAction(actionStamp);
        menuSave_As->addAction(actionSprite_Sheet);
        menuEdit->addAction(actionUndo);
        menuEdit->addAction(actionRedo);
        menuEdit->addSeparator();
        menuEdit->addAction(actionReset);
        menuTools->addAction(actionFlip_Horizontally);
        menuTools->addAction(actionFlip_Vertically);
        menuTools->addSeparator();
        menuTools->addAction(actionRotate_Horizontally);
        menuTools->addAction(actionRotate_Counterclockwise);
        menuTools->addSeparator();
        menuTools->addAction(actionShow_Hide_Frame);
        menuTools->addAction(actionDuplicate);
        menuTools->addSeparator();
        menuTools->addAction(actionDelete);
        menuTools->addAction(actionRemove_All);
        menuTools->addSeparator();
        menuTools->addAction(action2x_Workspace);
        menuHelp->addAction(actionWalkthrough);
        menuHelp->addAction(actionAbout);

        retranslateUi(SpriteMainWindow);

        QMetaObject::connectSlotsByName(SpriteMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SpriteMainWindow)
    {
        SpriteMainWindow->setWindowTitle(QApplication::translate("SpriteMainWindow", "SpriteMainWindow", 0));
        actionNew->setText(QApplication::translate("SpriteMainWindow", "New", 0));
        actionNew->setShortcut(QApplication::translate("SpriteMainWindow", "Ctrl+N", 0));
        actionOpen->setText(QApplication::translate("SpriteMainWindow", "Open...", 0));
        actionOpen->setShortcut(QApplication::translate("SpriteMainWindow", "Ctrl+O", 0));
        actionSave->setText(QApplication::translate("SpriteMainWindow", "Save...", 0));
        actionSave->setShortcut(QApplication::translate("SpriteMainWindow", "Ctrl+S", 0));
        actionStamp->setText(QApplication::translate("SpriteMainWindow", "Stamp", 0));
        actionQuit->setText(QApplication::translate("SpriteMainWindow", "Quit", 0));
        actionSprite_Sheet->setText(QApplication::translate("SpriteMainWindow", "Sprite Sheet", 0));
        actionAnimated_GIF->setText(QApplication::translate("SpriteMainWindow", "Animated GIF", 0));
        actionExport_as_gif->setText(QApplication::translate("SpriteMainWindow", "Export as .gif", 0));
        actionUndo->setText(QApplication::translate("SpriteMainWindow", "Undo", 0));
        actionUndo->setShortcut(QApplication::translate("SpriteMainWindow", "Ctrl+Z", 0));
        actionRedo->setText(QApplication::translate("SpriteMainWindow", "Redo", 0));
        actionRedo->setShortcut(QApplication::translate("SpriteMainWindow", "Ctrl+Shift+Z", 0));
        actionReset->setText(QApplication::translate("SpriteMainWindow", "Reset Current Frame", 0));
        actionFlip_Horizontally->setText(QApplication::translate("SpriteMainWindow", "Flip Horizontally", 0));
        actionFlip_Vertically->setText(QApplication::translate("SpriteMainWindow", "Flip Vertically", 0));
        actionRotate_Horizontally->setText(QApplication::translate("SpriteMainWindow", "Rotate Clockwise", 0));
        actionRotate_Horizontally->setShortcut(QApplication::translate("SpriteMainWindow", "Ctrl+R", 0));
        actionRotate_Counterclockwise->setText(QApplication::translate("SpriteMainWindow", "Rotate Counterclockwise", 0));
        actionRotate_Counterclockwise->setShortcut(QApplication::translate("SpriteMainWindow", "Ctrl+L", 0));
        actionShow_Hide_Frame->setText(QApplication::translate("SpriteMainWindow", "Show/Hide", 0));
        actionDuplicate->setText(QApplication::translate("SpriteMainWindow", "Duplicate", 0));
        actionDuplicate->setShortcut(QApplication::translate("SpriteMainWindow", "Ctrl+D", 0));
        actionDelete->setText(QApplication::translate("SpriteMainWindow", "Remove", 0));
        actionDelete->setShortcut(QApplication::translate("SpriteMainWindow", "Ctrl+Backspace", 0));
        actionRemove_All->setText(QApplication::translate("SpriteMainWindow", "Remove All...", 0));
        actionRemove_All->setShortcut(QApplication::translate("SpriteMainWindow", "Ctrl+Shift+Backspace", 0));
        actionAbout->setText(QApplication::translate("SpriteMainWindow", "About", 0));
#ifndef QT_NO_TOOLTIP
        actionAbout->setToolTip(QApplication::translate("SpriteMainWindow", "<html><head/><body><p>This is the about menu option</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        actionWalkthrough->setText(QApplication::translate("SpriteMainWindow", "Walkthrough", 0));
        action2x_Workspace->setText(QApplication::translate("SpriteMainWindow", "2x Workspace", 0));
        action2x_Workspace->setShortcut(QApplication::translate("SpriteMainWindow", "Ctrl+=", 0));
        addFrameButton->setText(QApplication::translate("SpriteMainWindow", "+", 0));
        duplicateFrameButton->setText(QApplication::translate("SpriteMainWindow", "Duplicate Last Frame", 0));
#ifndef QT_NO_TOOLTIP
        previewLabelMap->setToolTip(QApplication::translate("SpriteMainWindow", "<html><head/><body><p>When you click on this, a new preview window will open. It has zoom controls</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        previewLabelMap->setText(QString());
#ifndef QT_NO_TOOLTIP
        workspaceLabel->setToolTip(QApplication::translate("SpriteMainWindow", "<html><head/><body><p>Will display the current selected frame. The size is dependent on the resolution of the image selected. Should scale without changing the resolution.</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        workspaceLabel->setText(QString());
        penTool->setText(QString());
        eraserTool->setText(QString());
        lineTool->setText(QString());
        ellipseTool->setText(QString());
        stampTool->setText(QString());
        rotateCounterClockButton->setText(QString());
        rotateClockwiseButton->setText(QString());
        flipHorizontalButton->setText(QString());
        flipVerticalButton->setText(QString());
        undoButton->setText(QString());
        redoButton->setText(QString());
        unassignedButton_3->setText(QApplication::translate("SpriteMainWindow", "-", 0));
        unassignedButton_4->setText(QApplication::translate("SpriteMainWindow", "-", 0));
#ifndef QT_NO_TOOLTIP
        brushSize1Button->setToolTip(QApplication::translate("SpriteMainWindow", "Brush size 1", 0));
#endif // QT_NO_TOOLTIP
        brushSize1Button->setText(QApplication::translate("SpriteMainWindow", "1", 0));
        brushSize1Button->setShortcut(QApplication::translate("SpriteMainWindow", "Ctrl+1", 0));
#ifndef QT_NO_TOOLTIP
        brushSize2Button->setToolTip(QApplication::translate("SpriteMainWindow", "Brush size 2", 0));
#endif // QT_NO_TOOLTIP
        brushSize2Button->setText(QApplication::translate("SpriteMainWindow", "2", 0));
        brushSize2Button->setShortcut(QApplication::translate("SpriteMainWindow", "Ctrl+2", 0));
#ifndef QT_NO_TOOLTIP
        brushSize3Button->setToolTip(QApplication::translate("SpriteMainWindow", "Brush size 3", 0));
#endif // QT_NO_TOOLTIP
        brushSize3Button->setText(QApplication::translate("SpriteMainWindow", "3", 0));
        brushSize3Button->setShortcut(QApplication::translate("SpriteMainWindow", "Ctrl+3", 0));
#ifndef QT_NO_TOOLTIP
        brushSize4Button->setToolTip(QApplication::translate("SpriteMainWindow", "Brush size 4", 0));
#endif // QT_NO_TOOLTIP
        brushSize4Button->setText(QApplication::translate("SpriteMainWindow", "4", 0));
        brushSize4Button->setShortcut(QApplication::translate("SpriteMainWindow", "Ctrl+4", 0));
        colorPickButton->setText(QString());
        colorPickButton->setShortcut(QApplication::translate("SpriteMainWindow", "Ctrl+P", 0));
        rectangleTool->setText(QString());
        unassignedButton_5->setText(QApplication::translate("SpriteMainWindow", "-", 0));
        unassignedButton_6->setText(QApplication::translate("SpriteMainWindow", "-", 0));
        menuFile->setTitle(QApplication::translate("SpriteMainWindow", "File", 0));
        menuSave_As->setTitle(QApplication::translate("SpriteMainWindow", "Save As...", 0));
        menuEdit->setTitle(QApplication::translate("SpriteMainWindow", "Edit", 0));
        menuTools->setTitle(QApplication::translate("SpriteMainWindow", "Frame", 0));
        menuHelp->setTitle(QApplication::translate("SpriteMainWindow", "Help", 0));
    } // retranslateUi

};

namespace Ui {
    class SpriteMainWindow: public Ui_SpriteMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPRITEMAINWINDOW_H
