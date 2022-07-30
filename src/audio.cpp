#include "audio.hpp"

Audio::Audio()
{
    this->audio = nullptr;
    this->audio_path = " ";
}

Audio::Audio(std::string)
{
    this->setAudioPath(audio_path);
}

void Audio::setAudioPath(std::string audio_path)
{
    this->audio_path = audio_path;
    this->audio = Mix_LoadMUS(this->audio_path.c_str());

    /*Checking if the audio is loaded or not*/
    if (this->audio == nullptr)
    {
        std::cout << "Audio file cannot be loaded\n";
        std::cout<< this->audio_path << "\n";
    }
}

void Audio::play()
{
    if (this->getAudioPath() == " ")
    {
        std::cout << "Audio Path isn't set\n";
        return;
    }

    // Audio is playing
    Mix_PlayMusic(audio, -1);
}

void Audio::stop()
{
    /*Stop the music*/
    Mix_HaltMusic();
}

std::string Audio::getAudioPath()
{
    return this->audio_path;
}