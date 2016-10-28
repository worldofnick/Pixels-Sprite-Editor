#include "Frame.h"
#include <QPixmap>

//Constructs a single Frame (derived from QLabel), which has a QPixmap associated with it of the passed resolution.
Frame::Frame()
{
    height = 32;
    width = 32;
    pix = QPixmap(width, height);
    pix.fill(Qt::transparent);
    this->setPixmap(pix);

}

//Destructs the current Frame.
Frame::~Frame(){
    ;
}

// Override the paintEvent to allow pointing
//void Frame::paintEvent(QPaintEvent *event){

//    painter.begin(this);
//    // When the mouse is pressed
//    if(mousePressed) {

//    }

//    painter.end();
//}


