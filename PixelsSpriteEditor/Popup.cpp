#include "Popup.h"
#include "ui_AboutDialog.h"

Popup::Popup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Popup)
{
    ui->setupUi(this);
}

Popup::~Popup()
{
    delete ui;
}
