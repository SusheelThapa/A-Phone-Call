#pragma once

#include <string>

class AbstractSound
{
    std::string sound_path;

public:
    AbstractSound(){};

    void setSoundPath(std::string sound_path);

    std::string getSoundPath();

    virtual void play() = 0;
    virtual void stop() = 0;
};