#ifndef FRAME_H
#define FRAME_H

#include <QLabel>
#include <QPainter>


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
    bool mousePressed;
    QPainter painter;

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
};

#endif // FRAME_H
