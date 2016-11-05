#ifndef PREVIEW_H
#define PREVIEW_H

#include <QDialog>
#include <QPixmap>

namespace Ui {
class Preview;
}

class Preview : public QDialog
{
    Q_OBJECT

public:
    explicit Preview(QWidget *parent = 0);
    ~Preview();

    void setPixmap(const QPixmap& map);

    void setFps(int fps);

private slots:
    void on_zoomInButton_clicked();

    void on_zoomOutButton_clicked();

    void on_closeButton_clicked();

    void on_fpsSliderPreview_valueChanged(int value);

private:
    Ui::Preview *ui;

signals:
    void fpsChanged(int fps);
};

#endif // PREVIEW_H
