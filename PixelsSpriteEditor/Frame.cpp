#include <QPixmap>
#include <QPainter>
#include <QDebug>
#include "Frame.h"

//Constructs a single Frame (derived from QLabel), which has a QPixmap associated with it of the passed resolution.
Frame::Frame(int width, int height)
{

    this->width = width;
    this->height = height;

    this->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    this->setAlignment(Qt::AlignTop);

    QPixmap temp(width, height);
    temp.fill(Qt::white);
    this->setScaledContents(true);
    this->setPixmap(temp);//.scaled(this->FRAME_VIEW_DIMENSION));

    //this->setGeometry(0, 0, 150, 150);

    this->isVisible = true;
    pix = new QPixmap(*this->pixmap());
}

//Destructs the current Frame.
Frame::~Frame(){
    ;
}


void Frame::makeFrameActive(){
    if(!this->isVisible) {
        this->setStyleSheet("background-color: rgb(232,0,71,50); border: 3px solid rgb(232,0,71); border-radius: 5px;");
    }
    else {
        this->setStyleSheet("border: 2px solid rgb(180,180,180, 50); border-radius: 0px;");
    }
}


void Frame::makeFrameUnactive() {

    if(!this->isVisible) {
        this->setStyleSheet("background-color: rgb(232,0,71,50); border: 3px solid rgb(232,0,71); border-radius: 5px;");
    }else {
        this->setStyleSheet("border: 0px;");
    }
}


QSize Frame::sizeHint() const{
    return this->FRAME_VIEW_DIMENSION;
}


void Frame::mousePressEvent(QMouseEvent *event){
    emit clicked(this);
}

void Frame::toggleVisibility(bool visible){
    this->isVisible = visible;

    //Add a red border around the frame if it is hidden, else remove the border
    if(this->isVisible){
        this->setStyleSheet("border: 2px solid rgb(180,180,180, 50); border-radius: 0px;");
    }
    else{
        this->setStyleSheet("background-color: rgb(232,0,71,50); border: 3px solid rgb(232,0,71); border-radius: 5px;");
    }
}

bool Frame::getIsVisible(){
    return this->isVisible;
}
