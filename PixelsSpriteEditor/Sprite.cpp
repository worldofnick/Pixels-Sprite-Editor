#include "Sprite.h"

Sprite::Sprite(int w, int h, int s, std::string file)
{
    width = w;
    height = h;
    fps = s;
    filename = file;
}

Sprite::~Sprite()
{

}

void Sprite::addFrame()
{
    frames.push_back(new Frame());
}

Frame Sprite::getFrame(int index)
{
    return frames.at(index);
}

void Sprite::setFps(int speed)
{
    fps = speed;
}

Sprite::loadFile(std::string file)
{
    frames.clear();
    filename = file;

    // Open file
    // Read file header and initialize variables
    // Parse lines and create frames
    // Close file
}

Sprite::saveFile()
{
    // Open file
    // Save variables to header

    for(auto i = frames.begin(); i != frames.end; i++)
    {
        // Convert to image
        // Get RGBA from each pixel
        // Write frame to file
    }

    // Close file
}

Sprite::exportToGif(std::string file)
{
    // Call to GifExport class
}
