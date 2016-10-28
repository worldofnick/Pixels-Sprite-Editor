#include "PopupWindow.h"
#include "ui_PopupWindow.h"
#include <QPushButton>
#include <iostream>

//Creates a general purpose PopupWindow.
PopupWindow::PopupWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PopupWindow)
{
    ui->setupUi(this);
}

//Destructs the current PopupWindow.
PopupWindow::~PopupWindow()
{
    delete ui;
}

//Sets the text of the current PopupWindow.
void PopupWindow::setText(const QString& text){
    ui->popupLabel->setText(text);
}
