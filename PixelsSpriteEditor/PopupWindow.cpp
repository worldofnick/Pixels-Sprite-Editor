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

//Add a cancel button to the bottom of the PopupWindow.
void PopupWindow::addCancelButton(){
    ui->buttonBox->addButton(QDialogButtonBox::Cancel);
    std::cout << "addedbutton" << std::endl;
}

//Override the reject slot for when the cancel button is clicked.
void PopupWindow::reject(){
    emit rejected();
}

