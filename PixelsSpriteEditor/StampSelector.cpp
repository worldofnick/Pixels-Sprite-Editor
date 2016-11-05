#include <QVBoxLayout>
#include "StampSelector.h"
#include "ui_StampSelector.h"

StampSelector::StampSelector(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StampSelector)
{
    ui->setupUi(this);

    QPixmap map;
    map.load(":/stamps/Retro-Mario-icon.png");
    ui->label_2->setPixmap(map);

    QPixmap sun;
    sun.load(":/stamps/orange-sun.png");
    ui->label_3->setPixmap(sun);

    QPixmap cloud;
    cloud.load(":/stamps/cloud.png");
    ui->label_4->setPixmap(cloud);
}

StampSelector::~StampSelector()
{
    delete ui;
}

void StampSelector::closeEvent(QCloseEvent *){

    //emit 0 for mario, 1 for sun, 2 for cloud...
    if(ui->marioButton->isChecked()){
        emit selectedStamp(0);
    }
    else if(ui->sunButton->isChecked()){
        emit selectedStamp(1);
    }
    else{
        emit selectedStamp(2);
    }
}

void StampSelector::on_selectButton_clicked()
{
    this->close();
}
