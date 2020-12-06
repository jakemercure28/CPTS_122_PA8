#ifndef SOUND_H
#define SOUND_H

#include <SFML/Audio.hpp>
using namespace sf;

class sound_manager {

private:
    SoundBuffer buffer;
    Sound sound;
    string file;

public:
    sound_manager(string input_file)
    {
        file = input_file;
    }

    void init() 
    {
        buffer.loadFromFile(file);
        sound.setBuffer(buffer);
        sound.play();
    }
};
#endif