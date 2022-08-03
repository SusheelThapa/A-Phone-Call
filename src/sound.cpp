#include "sound.hpp"

void AbstractSound::setSoundPath(std::string sound_path)
{
    this->sound_path = sound_path;
}

std::string AbstractSound::getSoundPath()
{
    return this->sound_path;
}