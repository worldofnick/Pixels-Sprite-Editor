#ifndef SPRITEMAINWINDOW_H
#define SPRITEMAINWINDOW_H

#include <QMainWindow>
#include <QPen>

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
    void on_colorPickButton_clicked();

    void on_stampTool_clicked();

    void on_ellipseTool_clicked();

    void on_rectangleTool_clicked();

    void on_lineTool_clicked();

    void on_eraserTool_clicked();

    void on_penTool_clicked();

    void on_addFrameButton_clicked();

    void on_fpsSlider_valueChanged(int value);

private:
    Ui::SpriteMainWindow *ui;
    QPen pen;
    QColor penColor;
};

#endif // SPRITEMAINWINDOW_H
