#ifndef SOUND_H
#define SOUND_H

#include <SFML/Audio.hpp>
#include <string>
using namespace sf;

class sound_manager {

private:
    SoundBuffer buffer;
    Sound sound;
    std::string file;

public:
    // baisc sound file setter
    sound_manager(std::string input_file)
    {
        file = input_file;
    }

    // initializes sound file to play
    void init() 
    {
        buffer.loadFromFile(file);
        sound.setBuffer(buffer);
        sound.play();
    }
};
#endif