#include "Frame.h"
#include <QPixmap>

//Constructs a single Frame (derived from QLabel), which has a QPixmap associated with it of the passed resolution.
Frame::Frame()
{
    height = 32;
    width = 32;
    this->setPixmap(QPixmap(width, height));
}

//Destructs the current Frame.
Frame::~Frame(){

}



