#ifndef SPRITE_H
#define SPRITE_H

#include <QVector>
#include "Frame.h"


class Sprite : public QWidget
{
    Q_OBJECT

public:
    Sprite(int, int, int, QString);
    ~Sprite();
    void setFps(int);
    void addFrame();
    Frame& getFrame(int);

    void saveFile();
    void loadFile(QString);
    void exportToGif(QString);
private:
    QVector<Frame*> frames;
    QString filename;
    int fps, width, height;
};

#endif // SPRITE_H
