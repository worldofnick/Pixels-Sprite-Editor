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

// Override the paintEvent to allow pointing
void Frame::paintEvent(QPaintEvent *event){

    painter.begin(this);
    // When the mouse is pressed
    if(mousePressed) {

    }

    painter.end();
}

// Track mouse moving events
void Frame::mouseMoveEvent(QMouseEvent *event) {

    //As mouse is moving set the second point again and again
    // and update continuously
    if(event->type() == QEvent::MouseMove){

    }
    update();
}

// Notify when the mouse ie released
void Frame::mouseReleaseEvent(QMouseEvent *event) {
    mousePressed = false;
    update();
}

// Nofity when the mouse is clicked
void Frame::mousePressEvent(QMouseEvent *event) {
    mousePressed = true;
}

