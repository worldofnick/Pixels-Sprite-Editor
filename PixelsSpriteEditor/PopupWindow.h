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
    void addCancelButton();

private:
    Ui::PopupWindow *ui;

protected:
    void reject();

signals:
    void rejected();
};

#endif // POPUPWINDOW_H
