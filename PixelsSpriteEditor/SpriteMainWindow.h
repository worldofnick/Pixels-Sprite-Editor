#ifndef SPRITEMAINWINDOW_H
#define SPRITEMAINWINDOW_H

#include <QMainWindow>
#include <QPen>
#include <QCloseEvent>
#include <QTimer>
#include <QPainter>
#include <QButtonGroup>
#include <list>
#include <QPainterPath>
#include "qevent.h"
#include "Sprite.h"
#include "PopupWindow.h"
#include "Preview.h"
#include "StampSelector.h"
#include "PopupWindow.h"

namespace Ui {
class SpriteMainWindow;
}

class SpriteMainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::SpriteMainWindow *ui;
    QString filename;

    // Helper method that scales workspace pixmap
    void scaleWorkspaceSizeUp();
    void resetWorkspaceSizeToOriginal();
    void scaleWorkspaceSizeDown();
    void resetAllFrameSizes();
    void scalePen();

    int penWidthSelected;

    int numCustomStamps;

    // Exclusive grouping of the tools buttons. Only one are be toggle and remain active at a time.
    QButtonGroup* toolsButtonsGroup;
    QButtonGroup* brushSizeButtonsGroup;


    int timesScaled;
    QByteArray mainWindowOriginalGeometry;


    QColor backgroundColor;


    // Drawing resources
    QPen pen;
    QPoint drawPoint;
    QColor penColor;
    QPixmap workspacePixMap;
    QPainter painter;
    QLine mLine;
    QRect mRect;
    QPixmap selectedStamp;
    QPainterPath drawPath;


    bool stampIsActive;
    bool stampShouldBeDrawn;
    bool transparentGridIsVisible;
    bool drawStarted;
    bool shapeShouldNowBeDrawn;


    // Brush types, add more as we go
    enum Brushes { pencil, eraser, line, rect, ellipse, stamp };
    Brushes brush;


    // Lists for undo/redo
    std::list<QPixmap> undoStack;
    std::list<QPixmap> redoStack;


    // Flags
    bool isModified;
    bool mousePressed;
    bool maybeSave();
    bool clickedInsideWorkspace;

    // Helper methods
    void updateWorkspace();

    // Sprite
    Sprite currentSprite;


    // Preview window resources
    QTimer *timer;
    int it;
    int spriteWidth;
    int spriteHeight;

    //contains a pointer to the current frame selected
    Frame* currentFrame;

    //Preview Window
    Preview previewWindow;
    bool previewIsActive;

public:
    explicit SpriteMainWindow(QWidget *parent = 0);
    ~SpriteMainWindow();
    void call();

protected:
    bool eventFilter(QObject *watched, QEvent *event);      // Handles the QLabel events
    void closeEvent(QCloseEvent*);

signals:
    void sendRes(QRect geometry);

public slots:
    //Button Slots

    void on_colorPickButton_clicked();

    void on_stampTool_clicked();

    void on_ellipseTool_clicked();

    void on_rectangleTool_clicked();

    void on_lineTool_clicked();

    void on_eraserTool_clicked();

    void on_penTool_clicked();

    void on_addFrameButton_clicked();

    void on_fpsSlider_valueChanged(int value);



    //Menu Item Slots

    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionExport_as_gif_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_actionReset_triggered();

    void on_actionFlip_Horizontally_triggered();

    void on_actionFlip_Vertically_triggered();

    void on_actionRotate_Horizontally_triggered();

    void on_actionRotate_Counterclockwise_triggered();

    void on_actionShow_Hide_Frame_triggered();

    void on_actionDuplicate_triggered();

    void on_actionDelete_triggered();

    void on_actionAbout_triggered();

    // Timer slot
    void whenTimerUpdates();

    void on_brushSize1Button_clicked();
    void on_brushSize2Button_clicked();
    void on_brushSize3Button_clicked();
    void on_brushSize4Button_clicked();

    void initialResolution(int width, int backColor);

private slots:
    void on_action2x_Workspace_triggered();

    void frameClicked(Frame*);

    void on_rotateCounterClockButton_clicked();
    void on_rotateClockwiseButton_clicked();
    void on_flipVerticalButton_clicked();
    void on_flipHorizontalButton_clicked();

    void changeStamp(int id);

    void setFps(int fps);
    void on_actionZoom_Out_triggered();
    void on_actionReset_Size_triggered();
    void on_transparentGridButton_clicked();
    void on_actionToggle_Pen_Tip_triggered();
    void on_actionSolid_triggered();
    void on_actionDash_triggered();
    void on_actionDot_triggered();
};

#endif // SPRITEMAINWINDOW_H
