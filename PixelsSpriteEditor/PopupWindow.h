#ifndef POPUPWINDOW_H
#define POPUPWINDOW_H

#include <QDialog>
#include <QAbstractButton>

namespace Ui {
class PopupWindow;
}

class PopupWindow : public QDialog
{
    Q_OBJECT

public:
    explicit PopupWindow(QWidget *parent = 0);
    ~PopupWindow();
    void setText(const QString&);
    void setTitle(const QString&);

private:
    Ui::PopupWindow *ui;

private slots:
    void okClicked();
};

#endif // POPUPWINDOW_H
