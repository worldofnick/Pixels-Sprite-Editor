#include "Frame.h"
#include <QPixmap>

//Constructs a single Frame (derived from QLabel), which has a QPixmap associated with it of the passed resolution.
Frame::Frame()
{

    height = 32;
    width = 32;

    this->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);

    QPixmap temp(width, height);
    temp.fill(Qt::cyan);
    this->setScaledContents(true);
    this->setPixmap(temp);


    this->setGeometry(0, 0, 80, 80);
}

//Destructs the current Frame.
Frame::~Frame(){
    ;
}


QSize Frame::sizeHint() const{
    return QSize(80,80);
}


void Frame::mousePressEvent(QMouseEvent *event){

    //Right now we are just setting a frame to the color white when clicked...
    QPixmap temp(width, height);
    temp.fill(Qt::white);
    this->setPixmap(temp);

}

