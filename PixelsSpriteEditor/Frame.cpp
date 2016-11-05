#include <QPixmap>
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
}

//Destructs the current Frame.
Frame::~Frame(){
    ;
}


void Frame::makeFrameActive(){

    this->setFrameStyle(QFrame::Panel | QFrame::Plain);
    this->setLineWidth(2);
    this->setMidLineWidth(0);

}


void Frame::makeFrameUnactive(){

    this->setFrameStyle(QFrame::StyledPanel | QFrame::Plain);
    this->setLineWidth(1);
    this->setMidLineWidth(0);

}


QSize Frame::sizeHint() const{
    return this->FRAME_VIEW_DIMENSION;
}


void Frame::mousePressEvent(QMouseEvent *event){
    emit clicked(this);
}

