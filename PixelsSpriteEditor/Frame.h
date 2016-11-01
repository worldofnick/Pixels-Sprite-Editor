#ifndef FRAME_H
#define FRAME_H

#include <QLabel>
#include <QPainter>


class Frame : public QLabel
{
    Q_OBJECT
private:
    bool isVisible;
    int height;
    int width;
    //QPixmap pix;

public:
    Frame(int width = 32, int height = 32);
    //void setSize(int, int);
    ~Frame();

    // QWidget interface
protected:
    void mousePressEvent(QMouseEvent *event);

    // QWidget interface
public:
    QSize sizeHint() const;

signals:
    void clicked(Frame*);
};

#endif // FRAME_H
