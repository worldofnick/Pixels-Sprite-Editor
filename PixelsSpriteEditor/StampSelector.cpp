#include <QVBoxLayout>
#include <QDesktopWidget>
#include <QGraphicsBlurEffect>
#include <QGraphicsDropShadowEffect>
#include <QDebug>
#include "StampSelector.h"
#include "ui_StampSelector.h"

StampSelector::StampSelector(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StampSelector)
{
    ui->setupUi(this);

    this->setAttribute(Qt::WA_TranslucentBackground);
    this->setWindowFlags(Qt::FramelessWindowHint);

    //    QGraphicsBlurEffect* blurEffect = new QGraphicsBlurEffect( );
    //    blurEffect->setBlurHints(QGraphicsBlurEffect::AnimationHint);
    //    blurEffect->setBlurRadius(1);
    //    this->setGraphicsEffect( blurEffect );


    ui->marioLabel->installEventFilter(this);
    ui->marioLabel_2->installEventFilter(this);
    ui->marioLabel_3->installEventFilter(this);
    ui->marioLabel_4->installEventFilter(this);
    ui->sunLabel->installEventFilter(this);
    ui->cloudLabel->installEventFilter(this);

    whichStampSelected = 0;

    QPixmap map;
    map.load(":/stamps/Retro-Mario-icon.png");
    ui->marioLabel->setPixmap(map.copy());
    ui->marioLabel_2->setPixmap(map.copy());
    ui->marioLabel_3->setPixmap(map.copy());
    ui->marioLabel_4->setPixmap(map.copy());


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
    if (event->type() == QEvent::MouseButtonPress){
        if(watched == ui->marioLabel) {
            whichStampSelected = 0;
        }
        else if (watched == ui->sunLabel){
            whichStampSelected = 1;
        }
        else if (watched == ui->cloudLabel){
            whichStampSelected = 2;
        }
        else if (watched == ui->marioLabel_2){
            whichStampSelected = 3;
        }
        else if (watched == ui->marioLabel_3){
            whichStampSelected = 4;
        }
        else if (watched == ui->marioLabel_4){
            whichStampSelected = 5;
        }
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

void StampSelector::resolution(QRect geometry) {
    //qDebug() << "res:" << geometry.x() << geometry.y() << geometry.width() << geometry.height();
    int x = geometry.x() + geometry.width() - 120;
    int y = geometry.y() - 10;
    //qDebug() << "x:" << x << "y: " << y;
    this->move(x, y);
}
