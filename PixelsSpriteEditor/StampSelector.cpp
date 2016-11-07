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
    ui->pokeballLabel->installEventFilter(this);
    ui->swordLabel->installEventFilter(this);
    ui->sunglassesLabel->installEventFilter(this);
    ui->sunLabel->installEventFilter(this);
    ui->cloudLabel->installEventFilter(this);
    ui->pikachuLabel->installEventFilter(this);
    ui->ashLabel->installEventFilter(this);
    ui->cowboyLabel->installEventFilter(this);
    ui->squirtleLabel->installEventFilter(this);

    whichStampSelected = 0;

    QPixmap mario;
    mario.load(":/stamps/Retro-Mario-icon.png");
    ui->marioLabel->setPixmap(mario);

    QPixmap pokeball;
    pokeball.load(":/stamps/pokeball.png");
    ui->pokeballLabel->setPixmap(pokeball);

    QPixmap sword;
    sword.load(":/stamps/sword.png");
    ui->swordLabel->setPixmap(sword);

    QPixmap sunglasses;
    sunglasses.load(":/stamps/sunglasses.png");
    ui->sunglassesLabel->setPixmap(sunglasses);

    QPixmap sun;
    sun.load(":/stamps/orange-sun.png");
    ui->sunLabel->setPixmap(sun);

    QPixmap cloud;
    cloud.load(":/stamps/cloud.png");
    ui->cloudLabel->setPixmap(cloud);

    QPixmap pikachuMap;
    pikachuMap.load(":/stamps/pikachu.png");
    ui->pikachuLabel->setPixmap(pikachuMap.scaled(90,90, Qt::KeepAspectRatio));

    QPixmap ashMap;
    ashMap.load(":/stamps/ash.png");
    ui->ashLabel->setPixmap(ashMap.scaled(90,90, Qt::KeepAspectRatio));

    QPixmap cowboyMap;
    cowboyMap.load(":/stamps/cowboy.png");
    ui->cowboyLabel->setPixmap(cowboyMap);

    QPixmap squirtleMap;
    squirtleMap.load(":/stamps/squirtle.png");
    ui->squirtleLabel->setPixmap(squirtleMap);

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
        else if (watched == ui->pokeballLabel){
            whichStampSelected = 3;
        }
        else if (watched == ui->swordLabel){
            whichStampSelected = 4;
        }
        else if (watched == ui->sunglassesLabel){
            whichStampSelected = 5;
        }
        else if (watched == ui->pikachuLabel){
            whichStampSelected = 6;
        }
        else if (watched == ui->ashLabel){
            whichStampSelected = 7;
        }
        else if (watched == ui->squirtleLabel){
            whichStampSelected = 8;
        }
        else if (watched == ui->cowboyLabel){
            whichStampSelected = 9;
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
