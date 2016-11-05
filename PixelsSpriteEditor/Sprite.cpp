#include "Sprite.h"
#include <QDebug>
#include <QFile>
#include <QRgb>

Sprite::Sprite(int w, int h, int s, QString file)
{
    width = w;
    height = h;
    fps = s;
    filename = file;

    frames.append(new Frame());
}

Sprite::Sprite(){
    width = 128;
    height = 128;
    fps = 30;
    filename = "sprite1.ssp";
    frames.append(new Frame());

}

Sprite::Sprite(const Sprite &other){
    this->width = other.width;
    this->height = other.height;
    this->fps = other.fps;
    this->filename = other.filename;
    QVector<Frame*> temp;
    this->frames = temp;

    for (int i = 0; i < other.frames.length(); i++){
        this->frames.append(other.frames[i]);
    }
}

Sprite& Sprite::operator=(Sprite other){
    std::swap(this->width, other.width);
    std::swap(this->height, other.height);
    std::swap(this->fps, other.fps);
    std::swap(this->filename, other.filename);
    std::swap(this->frames, other.frames);

    return *this;
}

Sprite::~Sprite()
{
    //delete timer;
}

const QVector<Frame*> Sprite::getFrames(){
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
    QImage spriteImage(width, height, QImage::Format_RGB32);

    line = in.readLine();
    lineSeg = line.split(" ");
    framesCount = lineSeg.at(0).toInt();
    for(int i = 0; i < framesCount; i++) {
        addFrame();
        for(int j = 0; j < height; j++) {
            line = in.readLine();
            lineSeg = line.split(" ");
            for(int k = 0; k < lineSeg.size(); k+=4) {
                QColor colorVal;
                colorVal.setRed(lineSeg.at(k).toInt());
                colorVal.setGreen(lineSeg.at(k+1).toInt());
                colorVal.setBlue(lineSeg.at(k+2).toInt());
                colorVal.setAlpha(lineSeg.at(k+3).toInt());
                spriteImage.setPixelColor(j, i, colorVal);
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
    if(filename.isEmpty()){
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


        for(int i = 0; i < frames.size(); i++)
        {
            // Convert to image
            //Frames are scaled to 150x150 for display, so we need to scale it to the proper height when saving
            QImage spriteImage = frames.at(i)->pixmap()->toImage().scaled(this->width, this->height);

            // Get RGBA from each pixel
            // Write frame to file


            for (int y = 0; y < spriteImage.height(); y++) {
                QRgb *line = (QRgb *) spriteImage.scanLine(y);
                for (int x = 0; x < spriteImage.width(); x++) {
                    // line[x] has an individual pixel
                    // line[x] = QColor(255, 128, 0).rgb();
                    line += x;
                    QColor colorValue = *line;
                    out << colorValue.red() << " " << colorValue.green() << " " << colorValue.blue() << " " << colorValue.alpha() << " ";
                }
                out << '\n';
            }
        }

        // Close file
        fileSave.close();
    }
}

void Sprite::exportToGif(QString file)
{
    // Call to GifExport class
}

void Sprite::frameSelected(Frame* other){
    emit frameClicked(other);
}

void Sprite::setFilename(const QString &filename){
    this->filename = filename;
}
