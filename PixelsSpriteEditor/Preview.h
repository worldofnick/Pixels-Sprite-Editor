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

private slots:
    void on_zoomInButton_clicked();

    void on_zoomOutButton_clicked();

    void on_closeButton_clicked();

private:
    Ui::Preview *ui;
};

#endif // PREVIEW_H
