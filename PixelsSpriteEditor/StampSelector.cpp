#include <QVBoxLayout>
#include "StampSelector.h"
#include "ui_StampSelector.h"

StampSelector::StampSelector(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StampSelector)
{
    ui->setupUi(this);

    ui->marioLabel->installEventFilter(this);
    ui->sunLabel->installEventFilter(this);
    ui->cloudLabel->installEventFilter(this);

    QPixmap map;
    map.load(":/stamps/Retro-Mario-icon.png");
    ui->marioLabel->setPixmap(map);
    whichStampSelected = 0;

    QPixmap sun;
    sun.load(":/stamps/orange-sun.png");
    ui->sunLabel->setPixmap(sun);

    QPixmap cloud;
    cloud.load(":/stamps/cloud.png");
    ui->cloudLabel->setPixmap(cloud);
}

StampSelector::~StampSelector()
{
    delete ui;
}

bool StampSelector::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == ui->marioLabel && event->type() == QEvent::MouseButtonPress){
        whichStampSelected = 0;
        this->close();
        return true;
    }
    else if (watched == ui->sunLabel && event->type() == QEvent::MouseButtonPress){
        whichStampSelected = 1;
        this->close();
        return true;
    }
    else if (watched == ui->cloudLabel && event->type() == QEvent::MouseButtonPress){
        whichStampSelected = 2;
        this->close();
        return true;
    }
    else {
        // pass the event on to the parent class
        return QDialog::eventFilter(watched, event);
    }
}

void StampSelector::closeEvent(QCloseEvent *){

    //TODO: can initialize whichStampselected to -1 in case user clicked cancel. Or
    // keep the current behavior (mario as defult)
    emit(selectedStamp(whichStampSelected));
}

//void StampSelector::on_selectButton_clicked()
//{
//    this->close();
//}
