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

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
};

#endif // FRAME_H
