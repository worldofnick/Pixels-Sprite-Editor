#include "Preview.h"
#include "ui_Preview.h"

Preview::Preview(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Preview)
{
    ui->setupUi(this);
}

Preview::~Preview()
{
    delete ui;
}

void Preview::setPixmap(const QPixmap &map){
    ui->previewLabel->setPixmap(map);
}

void Preview::on_zoomInButton_clicked()
{
    int width = ui->previewLabel->pixmap()->width()*2;
    int height = ui->previewLabel->pixmap()->height()*2;

    ui->previewLabel->setPixmap(ui->previewLabel->pixmap()->scaled(width, height));
}

void Preview::on_zoomOutButton_clicked()
{
    int width = ui->previewLabel->pixmap()->width()/2;
    int height = ui->previewLabel->pixmap()->height()/2;

    if(width >= 32){
        ui->previewLabel->setPixmap(ui->previewLabel->pixmap()->scaled(width, height));
    }
}

void Preview::on_closeButton_clicked()
{
    this->close();
}
