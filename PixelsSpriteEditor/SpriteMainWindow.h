#ifndef SPRITEMAINWINDOW_H
#define SPRITEMAINWINDOW_H

#include <QMainWindow>
#include <QPen>
#include <QCloseEvent>
#include "PopupWindow.h"

namespace Ui {
class SpriteMainWindow;
}

class SpriteMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SpriteMainWindow(QWidget *parent = 0);
    ~SpriteMainWindow();

private slots:

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

    void on_actionStamp_triggered();

    void on_actionQuit_triggered();

    void on_actionSprite_Sheet_triggered();

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

    void on_actionRemove_All_triggered();

    void on_actionAbout_triggered();

    void on_actionWalkthrough_triggered();

    //Miscellaneous

    void rejected(PopupWindow*);

private:
    Ui::SpriteMainWindow *ui;
    QPen pen;
    QColor penColor;
    bool isModified;
    bool stillContinue;

protected:
    void closeEvent(QCloseEvent*);
};

#endif // SPRITEMAINWINDOW_H
