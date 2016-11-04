#include "GetResolutionDialog.h"
#include "ui_GetResolutionDialog.h"
#include <QDebug>
#include <QMessageBox>

GetResolutionDialog::GetResolutionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GetResolutionDialog)
{
    ui->setupUi(this);
    connect(ui->okButton, SIGNAL(pressed()), this, SLOT(resolution()));

    resButtonsGroup = new QButtonGroup(this);
    resButtonsGroup->addButton(ui->blackBackgroundButton, 2);
    resButtonsGroup->addButton(ui->whiteBackgroundButton, 1);
    resButtonsGroup->addButton(ui->transparentBackgroundButton, 0);
}

GetResolutionDialog::~GetResolutionDialog()
{
    delete ui;
}

void GetResolutionDialog::resolution(){
    int width = ui->widthInputBox->text().toInt();
    int height = ui->heightInputBox->text().toInt();

    if(width == 0){
        width = 128;
    }
    if(height == 0){
        height = 128;
    }

    //Get Selected Color
    int backColor = 0;
    if(resButtonsGroup->checkedButton() == ui->whiteBackgroundButton){
        backColor = 1;
    }
    else if(resButtonsGroup->checkedButton() == ui->blackBackgroundButton){
        backColor = 2;
    }
    emit okClicked(width, height, backColor);
    this->close();
}

void GetResolutionDialog::closeEvent(QCloseEvent *){
    int width = ui->widthInputBox->text().toInt();   
    int height = ui->heightInputBox->text().toInt();


    if(height <= 0 && width <= 0) {
        QMessageBox::StandardButton warning;
        warning = QMessageBox::warning(this, "Invalid size", "Defaulting to 128x128", QMessageBox::Ok);
    }

    if(width == 0){
        width = 128;
    }
    if(height == 0){
        height = 128;
    }

    //Get Selected Color
    int backColor = 0;
    if(resButtonsGroup->checkedButton() == ui->whiteBackgroundButton){
        backColor = 1;
    }
    else if(resButtonsGroup->checkedButton() == ui->blackBackgroundButton){
        backColor = 2;
    }
    emit okClicked(width, height, backColor);
}
