
#include "Client/tone.hpp"

void Tone::loadTone()
{
    this->tone_audio = Mix_LoadWAV(this->getSoundPath().c_str());

    /*Checking if the audio is loaded or not*/
    if (this->tone_audio == nullptr)
    {
        std::cout << "Audio file cannot be loaded\n";
    }
}

Tone::Tone(std::string audio_path)
{
    this->setSoundPath(audio_path);
    this->loadTone();
}
void Tone::setSoundPath(std::string sound_path)
{
    this->AbstractSound::setSoundPath(sound_path);
    this->loadTone();
}

Tone::~Tone()
{
    Mix_FreeChunk(tone_audio);
}

void Tone::play()
{
    if (this->getSoundPath() == " ")
    {
        std::cout << "Audio Path isn't set\n";
        return;
    }

    // Audio is playing
    Mix_PlayChannel(-1, this->tone_audio, 0);
}

void Tone::stop(){};
