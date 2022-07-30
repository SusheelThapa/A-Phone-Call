
#include "tone.hpp"

Tone::Tone()
{
    this->tone_audio = nullptr;
    this->audio_path = " ";
}

Tone::Tone(std::string audio_path)
{
    this->setTonePath(audio_path);
}

void Tone::setTonePath(std::string audio_path)
{
    this->audio_path = audio_path;
    this->tone_audio = Mix_LoadWAV(this->audio_path.c_str());

    /*Checking if the audio is loaded or not*/
    if (this->tone_audio == nullptr)
    {
        std::cout << "Audio file cannot be loaded\n";
    }
}

void Tone::play()
{
    if (this->getTonePath() == " ")
    {
        std::cout << "Audio Path isn't set\n";
        return;
    }

    // Audio is playing
    Mix_PlayChannel(-1, this->tone_audio, 0);
}

std::string Tone::getTonePath()
{
    return this->audio_path;
}