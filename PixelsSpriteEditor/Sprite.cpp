#include "Sprite.h"

Sprite::Sprite(int w, int h, int s, QString file)
{
    width = w;
    height = h;
    fps = s;
    filename = file;
    frames.append(new Frame());
}

Sprite::~Sprite()
{

}

void Sprite::addFrame()
{
    frames.append(new Frame());
    //Emit a signal here to the Gui
}

Frame& Sprite::getFrame(int index)
{
    return *frames[index];
}

void Sprite::setFps(int speed)
{
    fps = speed;
}

void Sprite::loadFile(QString file)
{
    frames.clear();
    filename = file;

    // Open file
    // Read file header and initialize variables
    // Parse lines and create frames
    // Close file
}

void Sprite::saveFile()
{
    // Open file
    // Save variables to header

    for(auto i = frames.begin(); i != frames.end(); i++)
    {
        // Convert to image
        // Get RGBA from each pixel
        // Write frame to file
    }

    // Close file
}

void Sprite::exportToGif(QString file)
{
    // Call to GifExport class
}
