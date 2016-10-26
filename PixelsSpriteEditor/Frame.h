#ifndef FRAME_H
#define FRAME_H

#include <QLabel>


class Frame : public QLabel
{

public:
    Frame();
    //void setSize(int, int);
    ~Frame();

private:
    bool isVisible;
    int height;
    int width;
};

#endif // FRAME_H
