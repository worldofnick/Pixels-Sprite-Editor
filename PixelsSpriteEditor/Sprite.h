#ifndef SPRITE_H
#define SPRITE_H

#include <vector>

class Sprite
{
    Q_OBJECT

public:
    Sprite(int, int, int, std::string);
    ~Sprite();
    void setFps(int);
    void addFrame();
    Frame getFrame(int);

    void saveFile();
    void loadFile(std::string);
    void exportToGif(std::string);
private:
    std::vector<Frame> frames;
    std::string filename;
    int fps, width, height;
};

#endif // SPRITE_H
