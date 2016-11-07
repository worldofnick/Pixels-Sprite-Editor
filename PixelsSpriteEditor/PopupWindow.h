#ifndef POPUPWINDOW_H
#define POPUPWINDOW_H

#include <QDialog>
#include <QAbstractButton>

namespace Ui
{
class PopupWindow;
}

class PopupWindow : public QDialog
{
    Q_OBJECT

private:
    Ui::PopupWindow *ui;

public:
    explicit PopupWindow(QWidget *parent = 0);
    ~PopupWindow();

private slots:
    void okClicked();
};

#endif // POPUPWINDOW_H
