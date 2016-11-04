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

    Frame* f = new Frame(width,height);

    frames.append(f);
}

Sprite::Sprite(){
    width = 32;
    height = 32;
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
    Frame* f = new Frame(width, height);

    frames.append(f);
    connect(f, SIGNAL(clicked(Frame*)), this, SLOT(frameSelected(Frame*)));
    qDebug() << frames.length();
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
    int i = 0;
    int j = 0;
    int fnumber = 0;
    QImage spriteImage;

    addFrame();
    // Open file
    // Read file header and initialize variables
    QFile fileLoad(filename);
    if(!fileLoad.open(QIODevice::ReadOnly)) {
        return;
    }

    QTextStream in(&fileLoad);
    // Parse lines and create frames
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList lineSegments = line.split(" ");
        if (lineSegments.size() == 1) {
            framesCount = lineSegments.at(0).toInt();
        }
        else if (lineSegments.size() == 2) {
            height = lineSegments.at(0).toInt();
            width = lineSegments.at(1).toInt();
        }
        else {
            j = 0;
            if(i < height){
                for(int k = 0; k < lineSegments.size(); k += 4) {
                    QColor temp;
                    temp.setRed(lineSegments.at(k).toInt());
                    temp.setGreen(lineSegments.at(k+1).toInt());
                    temp.setBlue(lineSegments.at(k+2).toInt());
                    temp.setAlpha(lineSegments.at(k+3).toInt());
                    spriteImage.setPixelColor(i, j++, temp);
                }
                i++;
            }
            else {
                // make a new frame
                frames.at(fnumber++)->pixmap()->fromImage(spriteImage);
                addFrame();
                i = 0;
                for(int k = 0; k < lineSegments.size(); k += 4) {
                    QColor temp;
                    temp.setRed(lineSegments.at(k).toInt());
                    temp.setGreen(lineSegments.at(k+1).toInt());
                    temp.setBlue(lineSegments.at(k+2).toInt());
                    temp.setAlpha(lineSegments.at(k+3).toInt());
                    spriteImage.setPixelColor(i, j++, temp);
                }
                i++;
            }
        }
    }
    // Close file
    fileLoad.close();
}

void Sprite::saveFile()
{
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

        QDataStream out(&fileSave);
        out << height << " ";
        out << width << '\n';
        out << frames.size() << '\n';


        for(int i = 0; i < frames.size(); i++)
        {
            // Convert to image
            QImage spriteImage = frames.at(i)->pixmap()->toImage();
            // Get RGBA from each pixel
            // Write frame to file
            qDebug() << spriteImage.size();

            for (int y = 0; y < spriteImage.height(); y++) {
                QRgb *line = (QRgb *) spriteImage.scanLine(y);
                for (int x = 0; x < spriteImage.width(); x++) {
                    // line[x] has an individual pixel
                    line[x] = QColor(255, 128, 0).rgb();
                }
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
    qDebug() << "frame is selected in Sprite.cpp";
}
