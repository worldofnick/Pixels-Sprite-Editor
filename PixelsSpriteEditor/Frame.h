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
    const QSize FRAME_VIEW_DIMENSION = QSize(150, 150);
    QPixmap* pix;

public:
    Frame(int width = 150, int height = 150);
    //void setSize(int, int);
    ~Frame();

    void makeFrameActive();

    void makeFrameUnactive();

    QSize sizeHint() const;
    void toggleVisibility(bool visible);
    bool getIsVisible();


    // QWidget interface
protected:
    void mousePressEvent(QMouseEvent *event);

    // QWidget interface

signals:
    void clicked(Frame*);
};

#endif // FRAME_H
