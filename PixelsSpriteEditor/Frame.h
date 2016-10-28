#ifndef FRAME_H
#define FRAME_H

#include <QLabel>
#include <QPainter>


class Frame : public QLabel
{
private:
    bool isVisible;
    int height;
    int width;
    //QPixmap pix;

public:
    Frame();
    //void setSize(int, int);
    ~Frame();

    // QWidget interface
protected:
    void mousePressEvent(QMouseEvent *event);

    // QWidget interface
public:
    QSize sizeHint() const;
};

#endif // FRAME_H
