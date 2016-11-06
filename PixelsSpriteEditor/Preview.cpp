#include "Preview.h"
#include "ui_Preview.h"

Preview::Preview(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Preview)
{
    ui->setupUi(this);

    //this->setAttribute(Qt::WA_TranslucentBackground);
    //this->setWindowFlags(Qt::FramelessWindowHint);
    ui->previewLabel->setScaledContents(false);
    this->resize(this->width(), this->heightForWidth(this->width()));
}

Preview::~Preview()
{
    delete ui;
}

void Preview::setPixmap(const QPixmap &map){
    //ui->previewLabel->setScaledContents(false);
    ui->previewLabel->setPixmap(map.copy());
//    if(ui->previewLabel->pixmap()->width() > 500 && ui->previewLabel->pixmap()->width() <= 1000) {
//        this->resize(ui->previewLabel->width(), ui->previewLabel->width()+100);
//    }
}

void Preview::on_zoomInButton_clicked()
{

    ui->previewLabel->setScaledContents(true);

    ui->previewLabel->setPixmap(ui->previewLabel->pixmap()->copy());
//    int width = ui->previewLabel->pixmap()->width()*2;
//    int height = ui->previewLabel->pixmap()->height()*2;

//    ui->previewLabel->setPixmap(ui->previewLabel->pixmap()->scaled(width, height));
}

void Preview::on_zoomOutButton_clicked()
{
    ui->previewLabel->setScaledContents(false);
    ui->previewLabel->setPixmap(ui->previewLabel->pixmap()->copy());
//    int width = ui->previewLabel->pixmap()->width()/2;
//    int height = ui->previewLabel->pixmap()->height()/2;

//    if(width >= 32){
//        ui->previewLabel->setPixmap(ui->previewLabel->pixmap()->scaled(width, height));
//    }
}

void Preview::on_closeButton_clicked()
{
    ui->previewLabel->setScaledContents(true);
    this->close();
}

void Preview::setFps(int fps){
    ui->fpsSliderPreview->setValue(fps);
}

void Preview::on_fpsSliderPreview_valueChanged(int value)
{
    emit fpsChanged(value);
}
