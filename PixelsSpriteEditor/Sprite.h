#ifndef SPRITE_H
#define SPRITE_H

#include <QVector>
#include <QFile>
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
    int getFps();
    void addFrame();
    Frame& getFrame(int);

    void saveFile(QString);
    void loadFile(QString);
    void exportToGif(QString);
    const QVector<Frame*> getFrames();
    void setFilename(const QString& filename);
    void appendFrame(Frame* frame);
    bool removeFrame(Frame* frame);
    void insertFrame(int index, Frame* frame);

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
