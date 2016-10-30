#include "GetResolutionDialog.h"
#include "ui_GetResolutionDialog.h"

GetResolutionDialog::GetResolutionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GetResolutionDialog)
{
    ui->setupUi(this);
    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(resolution()));
}

GetResolutionDialog::~GetResolutionDialog()
{
    delete ui;
}

void GetResolutionDialog::resolution(){
    int width = ui->widthInputBox->text().toInt();
    int height = ui->heightInputBox->text().toInt();
    emit okClicked(width, height);
}

void GetResolutionDialog::closeEvent(QCloseEvent *){
    int width = ui->widthInputBox->text().toInt();
    int height = ui->heightInputBox->text().toInt();
    emit okClicked(width, height);
}
