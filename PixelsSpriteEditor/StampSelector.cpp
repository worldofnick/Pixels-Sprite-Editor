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

void StampSelector::addStamp(const QString &filename){
    QLabel* newStamp = new QLabel();
    QPixmap map;

    qDebug() << "Entered addStamp";

    map.load(filename);

    map.save("/Users/tylerdailey/Desktop/test2.png", "PNG");

    qDebug() << "Loaded file";

    newStamp->setPixmap(map);

    qDebug() << "Created Stamp";

    newStamp->setStyleSheet("#newStamp { \n background-color: rgb(54,58,62,30); \n border-radius: 10px; \n background-repeat: none; \n"
                           " margin: 6px; \n } \n #newStamp:hover \n { \n background-color: rgb(54,58,62,50); \n border-radius: 10px;"
                           " \n border-top: -15px transparent; \n border-bottom: -15px transparent; \n border-right: -15px transparent;"
                           "\n border-left: -15px transparent; \n margin: 2px; \n }");

    qDebug() << "Passed stylesheet";

    newStamp->installEventFilter(this);

    ui->scrollAreaWidgetContents->layout()->addWidget(newStamp);
}
