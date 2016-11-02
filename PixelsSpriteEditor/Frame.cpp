#include <QPixmap>
#include "Frame.h"

//Constructs a single Frame (derived from QLabel), which has a QPixmap associated with it of the passed resolution.
Frame::Frame(int width, int height)
{

    this->width = width;
    this->height = height;

    //QDebug() << "width: " << this->width << " Height: " << this->height;

    this->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    this->setAlignment(Qt::AlignTop);

    QPixmap temp(width, height);
    temp.fill(Qt::white);
    this->setScaledContents(true);
    this->setPixmap(temp);


    this->setGeometry(0, 0, 32, 32);
}

//Destructs the current Frame.
Frame::~Frame(){
    ;
}


QSize Frame::sizeHint() const{
    return QSize(172,100);
}


void Frame::mousePressEvent(QMouseEvent *event){
    emit clicked(this);
}

