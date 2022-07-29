
#include "tone.hpp"

Tone::Tone()
{
    this->tone_audio = nullptr;
    this->audio_path = " ";
}

Tone::Tone(std::string audio_path)
{
    this->setAudioPath(audio_path);
}

void Tone::setAudioPath(std::string audio_path)
{
    this->audio_path = audio_path;
    this->tone_audio = Mix_LoadWAV(audio_path.c_str());

    /*Checking if the audio is loaded or not*/
    if (this->tone_audio == nullptr)
    {
        std::cout << "Audio file cannot be loaded\n";
    }
}

void Tone::play()
{
    if (this->getAudioPath() == " ")
    {
        std::cout << "Audio Path isn't set\n";
        return;
    }

    // Audio is playing
    Mix_PlayChannel(-1, this->tone_audio, 0);
}
