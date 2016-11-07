#include <QVBoxLayout>
#include <QDesktopWidget>
#include "StampSelector.h"
#include "ui_StampSelector.h"

// Constructs a stamp selection object. It contains the in-built stamps.
// As soon as the user selects a stamp, this window closes.
StampSelector::StampSelector(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StampSelector)
{
    ui->setupUi(this);

    // Setup this window's flags and attributes
    this->setAttribute(Qt::WA_TranslucentBackground);
    this->setWindowFlags(Qt::FramelessWindowHint);

    // Install event filter on the QLabel containing the stamps.
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

    // By default, select the first stamp
    whichStampSelected = 0;

    // Load the images to the stamp QLabel's

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

// Destructor
StampSelector::~StampSelector()
{
    delete ui;
}

// An eventFilter which identifies a QEvent and associates it different actions.
// Used to detect events on a QLabel (like mouse press). If the event was not for a QLabel,
// returns the event to this object's parent class.
//
// Returns true if the event was for a QLabel, else returns the event to the parent class (for
// its event handler).
bool StampSelector::eventFilter(QObject *watched, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonPress){
        if(watched == ui->marioLabel) {
            whichStampSelected = 0;
        }
        else if (watched == ui->sunLabel) {
            whichStampSelected = 1;
        }
        else if (watched == ui->cloudLabel) {
            whichStampSelected = 2;
        }
        else if (watched == ui->pokeballLabel) {
            whichStampSelected = 3;
        }
        else if (watched == ui->swordLabel) {
            whichStampSelected = 4;
        }
        else if (watched == ui->sunglassesLabel) {
            whichStampSelected = 5;
        }
        else if (watched == ui->pikachuLabel) {
            whichStampSelected = 6;
        }
        else if (watched == ui->ashLabel) {
            whichStampSelected = 7;
        }
        else if (watched == ui->squirtleLabel) {
            whichStampSelected = 8;
        }
        else if (watched == ui->cowboyLabel) {
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

// Contains a close window event. Emits a signal identifying the
// selected stamp tool. If user didn't select anything,
// defaults to the first stamp.
void StampSelector::closeEvent(QCloseEvent *)
{
    emit(selectedStamp(whichStampSelected));
}

// Slot to set the resolution of the stamp.
void StampSelector::resolution(QRect geometry)
{
    int x = geometry.x() + geometry.width() - 120;
    int y = geometry.y() - 10;
    this->move(x, y);
}
