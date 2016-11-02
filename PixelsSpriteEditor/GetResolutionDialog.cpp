#include "GetResolutionDialog.h"
#include "ui_GetResolutionDialog.h"

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
    emit okClicked(width, height);
    this->close();
}

void GetResolutionDialog::closeEvent(QCloseEvent *){
    int width = ui->widthInputBox->text().toInt();
    int height = ui->heightInputBox->text().toInt();
    emit okClicked(width, height);
}
