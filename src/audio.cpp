#include "audio.hpp"

void Audio::loadAudio()
{
    this->audio = Mix_LoadMUS(this->getSoundPath().c_str());

    /*Checking if the audio is loaded or not*/
    if (this->audio == nullptr)
    {
        std::cout << "Audio file cannot be loaded\n";
        std::cout << this->getSoundPath() << "\n";
    }
}

Audio::Audio(std::string sound_path)
{
    this->setSoundPath(sound_path);
    this->loadAudio();
}

void Audio::setSoundPath(std::string sound_path)
{
    this->AbstractSound::setSoundPath(sound_path);
    this->loadAudio();
}

void Audio::play()
{
    if (this->getSoundPath() == " ")
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
