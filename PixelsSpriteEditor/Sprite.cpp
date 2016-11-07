#include <QDebug>
#include <QFile>
#include <QRgb>
#include "gif.h"
#include "Sprite.h"

Sprite::Sprite(int w, int h, int s, QString file)
{
    width = w;
    height = h;
    fps = s;
    filename = file;

    frames.append(new Frame());
}

Sprite::Sprite()
{
    width = 128;
    height = 128;
    fps = 30;
    filename = "sprite1.ssp";
    frames.append(new Frame());
}

Sprite::Sprite(const Sprite &other)
{
    this->width = other.width;
    this->height = other.height;
    this->fps = other.fps;
    this->filename = other.filename;
    QVector<Frame*> temp;
    this->frames = temp;

    for (int i = 0; i < other.frames.length(); i++) {
        this->frames.append(other.frames[i]);
    }
}

Sprite& Sprite::operator=(Sprite other)
{
    std::swap(this->width, other.width);
    std::swap(this->height, other.height);
    std::swap(this->fps, other.fps);
    std::swap(this->filename, other.filename);
    std::swap(this->frames, other.frames);

    return *this;
}

Sprite::~Sprite()
{
    frames.clear();
}

const QVector<Frame*> Sprite::getFrames()
{
    return this->frames;
}

void Sprite::addFrame()
{
    Frame* f = new Frame(this->width, this->height);

    frames.append(f);
    connect(f, SIGNAL(clicked(Frame*)), this, SLOT(frameSelected(Frame*)));
}

Frame& Sprite::getFrame(int index)
{
    return *(frames.at(index));
}

void Sprite::setFps(int speed)
{
    fps = speed;
}

int Sprite::getFps()
{
    return fps;
}

void Sprite::loadFile(QString file)
{
    frames.clear();
    filename = file;
    int framesCount;
    // Open file
    // Read file header and initialize variables
    QFile fileLoad(filename);
    if(!fileLoad.open(QIODevice::ReadOnly)) {
        return;
    }

    QTextStream in(&fileLoad);
    // Parse lines and create frames
    QString line = in.readLine();
    QStringList lineSeg = line.split(" ");
    height = lineSeg.at(0).toInt();
    width = lineSeg.at(1).toInt();
    QImage spriteImage(width, height, QImage::Format_ARGB32);

    line = in.readLine();
    lineSeg = line.split(" ");
    framesCount = lineSeg.at(0).toInt();
    for(int i = 0; i < framesCount; i++) {
        addFrame();

        for(int y = 0; y < height; y++) {
            int x = 0;
            line = in.readLine();
            lineSeg = line.split(" ");
            for(int k = 0; k < lineSeg.size(); k+=4) {
                QColor colorVal;
                colorVal.setRed(lineSeg.at(k).toInt());
                colorVal.setGreen(lineSeg.at(k+1).toInt());
                colorVal.setBlue(lineSeg.at(k+2).toInt());
                colorVal.setAlpha(lineSeg.at(k+3).toInt());
                spriteImage.setPixelColor(x, y, colorVal);
                x++;
            }
        }
        frames.last()->setPixmap(QPixmap::fromImage(spriteImage, 0));
    }
    // Close file
    fileLoad.close();
}

void Sprite::saveFile(QString file)
{

    filename = file;
    // Open file
    // Save variables to header
    if(filename.isEmpty()) {
        return;
    }
    else {
        QFile fileSave(filename);
        if(!fileSave.open(QIODevice::WriteOnly)) {
            return;
        }

        QTextStream out(&fileSave);
        out << height << " ";
        out << width << "\n";
        int fs = frames.size();
        out << fs << "\n";

        for(int i = 0; i < frames.size(); i++) {
            // Convert to image
            //Frames are scaled to 150x150 for display, so we need to scale it to the proper height when saving
            QImage spriteImage = frames.at(i)->pixmap()->toImage().scaled(this->width, this->height);

            // Get RGBA from each pixel
            // Write frame to file

            for ( int y = 0; y < spriteImage.height(); ++y) {
                for ( int x = 0; x < spriteImage.width(); ++x) {
                    QColor clrCurrent(spriteImage.pixelColor(x, y));
                    out << clrCurrent.red() << " " << clrCurrent.green() << " " << clrCurrent.blue() << " " << clrCurrent.alpha();
                    if(x != spriteImage.width()-1) {
                        out << " ";
                    }
                }
                out << "\n";
            }
        }
        // Close file
        fileSave.close();
    }
}

void Sprite::exportToGif(QString file)
{

    GifWriter *g = new GifWriter();
    QByteArray ba = file.toLatin1();
    //const char* buffer = ba.data();
    const char* buffer = ba;
    int size = width * height * 4;
    uint8_t *fr = new uint8_t[size];
    int gfps = fps;
    if(gfps == 0)
        gfps = 1;
    GifBegin(g, buffer, width, height, 100/gfps, 8, true);
    for(int i = 0; i < frames.count(); i++) {

        if(frames.at(i)->getIsVisible()) {
            QImage spriteImage = frames.at(i)->pixmap()->toImage();
            int index = 0;
            for (int y = 0; y < spriteImage.height(); y++) {
                for (int x = 0; x < spriteImage.width(); x++) {
                    QColor colorValue(spriteImage.pixelColor(x, y));
                    *(fr+index) = (uint8_t)colorValue.red(); index++;
                    *(fr+index) = (uint8_t)colorValue.green(); index++;
                    *(fr+index) = (uint8_t)colorValue.blue(); index++;
                    *(fr+index) = (uint8_t)colorValue.alpha(); index++;
                }
            }
            const uint8_t* cfr = const_cast<const uint8_t*>(fr);
            GifWriteFrame(g, cfr, width, height, 100/gfps, 8, true);
        }

    }
    GifEnd(g);
}

void Sprite::frameSelected(Frame* other)
{
    emit frameClicked(other);
}

void Sprite::setFilename(const QString &filename)
{
    this->filename = filename;
}

void Sprite::appendFrame(Frame *frame)
{
    frames.append(frame);
    connect(frame, SIGNAL(clicked(Frame*)), this, SLOT(frameSelected(Frame*)));
}

//Returns true if the remove was successful
bool Sprite::removeFrame(Frame *frame)
{
    return this->frames.removeOne(frame);
}

void Sprite::insertFrame(int index, Frame *frame)
{
    this->frames.insert(index, frame);
    connect(frame, SIGNAL(clicked(Frame*)), this, SLOT(frameSelected(Frame*)));
}
