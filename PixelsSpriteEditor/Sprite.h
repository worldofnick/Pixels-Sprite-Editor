#ifndef SPRITE_H
#define SPRITE_H

#include <QVector>
#include "Frame.h"

class Sprite : public QWidget
{
    Q_OBJECT

public:
    Sprite(int, int, int, QString);
    Sprite();
    Sprite(const Sprite& other);
    Sprite& operator=(Sprite other);
    ~Sprite();
    void setFps(int);
    void addFrame();
    Frame& getFrame(int);

    void saveFile();
    void loadFile(QString);
    void exportToGif(QString);
    const QVector<Frame*> getFrames();

private:
    QVector<Frame*> frames;
    QString filename;
    int fps, width, height;

private slots:
    void frameSelected(Frame*);

signals:
    void frameClicked(Frame*);
};

#endif // SPRITE_H
