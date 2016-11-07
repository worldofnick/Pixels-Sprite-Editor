#include <QDebug>
#include <QMessageBox>
#include "GetResolutionDialog.h"
#include "ui_GetResolutionDialog.h"

GetResolutionDialog::GetResolutionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GetResolutionDialog)
{
    ui->setupUi(this);
    connect(ui->okButton, SIGNAL(pressed()), this, SLOT(resolution()));
    this->setWindowFlags(Qt::FramelessWindowHint);

    resButtonsGroup = new QButtonGroup(this);
    resButtonsGroup->addButton(ui->blackBackgroundButton, 2);
    resButtonsGroup->addButton(ui->whiteBackgroundButton, 1);
    resButtonsGroup->addButton(ui->transparentBackgroundButton, 0);
}

GetResolutionDialog::~GetResolutionDialog()
{
    delete ui;
}

void GetResolutionDialog::resolution()
{
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
    if(resButtonsGroup->checkedButton() == ui->whiteBackgroundButton) {
        backColor = 1;
    }
    else if(resButtonsGroup->checkedButton() == ui->blackBackgroundButton) {
        backColor = 2;
    }
    emit okClicked(width, backColor);
    this->close();
}

void GetResolutionDialog::closeEvent(QCloseEvent *)
{
    int width = ui->widthInputBox->text().toInt();
    int height = width;
    //int height = ui->heightInputBox->text().toInt();


    //TODO: make it more user friendly
    if(width <= 0) {
        QMessageBox::StandardButton warning;
        warning = QMessageBox::warning(this, "Invalid size", "Invalid size: Defaulting to 128x128", QMessageBox::Ok);
    }

    if(width <= 0) {
        width = 128;
        height = 128;
    }
    //Get Selected Color
    int backColor = 0;
    if(resButtonsGroup->checkedButton() == ui->whiteBackgroundButton) {
        backColor = 1;
    }
    else if(resButtonsGroup->checkedButton() == ui->blackBackgroundButton) {
        backColor = 2;
    }
    emit okClicked(width, backColor);
}

void GetResolutionDialog::on_widthInputBox_textChanged(const QString &arg1)
{
    ui->heightInputBox->setText(arg1);
}
