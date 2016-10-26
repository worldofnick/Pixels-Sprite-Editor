#ifndef POPUP_H
#define POPUP_H

#include <QDialog>

namespace Ui {
class Popup;
}

class Popup : public QDialog
{
    Q_OBJECT

public:
    explicit Popup(QWidget *parent = 0);
    ~Popup();

private:
    Ui::Popup *ui;
};

#endif // POPUP_H
