#include <QPushButton>
#include "PopupWindow.h"
#include "ui_PopupWindow.h"

//Creates a general purpose PopupWindow.
PopupWindow::PopupWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PopupWindow)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    connect(ui->okButton, SIGNAL(pressed()), this, SLOT(okClicked()));
}

//Destructs the current PopupWindow.
PopupWindow::~PopupWindow()
{
    delete ui;
}

//Closes PopupWindow when ok is clicked
void PopupWindow::okClicked()
{
    this->close();
}
