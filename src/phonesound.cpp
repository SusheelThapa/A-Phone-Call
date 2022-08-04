#include "phonesound.hpp"

PhoneSound::PhoneSound()
{
    /*Loading Dialpad tone*/
    dialpad_tone[0].setSoundPath("resources/audio/tone-zero.wav");
    dialpad_tone[1].setSoundPath("resources/audio/tone-one.wav");
    dialpad_tone[2].setSoundPath("resources/audio/tone-two.wav");
    dialpad_tone[3].setSoundPath("resources/audio/tone-three.wav");
    dialpad_tone[4].setSoundPath("resources/audio/tone-four.wav");
    dialpad_tone[5].setSoundPath("resources/audio/tone-five.wav");
    dialpad_tone[6].setSoundPath("resources/audio/tone-six.wav");
    dialpad_tone[7].setSoundPath("resources/audio/tone-seven.wav");
    dialpad_tone[8].setSoundPath("resources/audio/tone-eight.wav");
    dialpad_tone[9].setSoundPath("resources/audio/tone-nine.wav");

    /*Loading ringtone*/
    ringtone.setSoundPath("resources/audio/ringtone.wav");
    outgoing_tone.setSoundPath("resources/audio/outgoing-tone.wav");

    /*Load end call tone*/
    end_call_tone.setSoundPath("resources/audio/end_call_tone.wav");

    /*Load busy_audio*/
    busy_audio.setSoundPath("resources/audio/busy-tone.wav");
}

void PhoneSound::playDialpadTone(int dialpad_number)
{
    dialpad_tone[dialpad_number].play();
}

void PhoneSound::playRingtone()
{
    ringtone.play();
}

void PhoneSound::stopRingtone()
{
    ringtone.stop();
}
void PhoneSound::playOutgoingTone()
{
    outgoing_tone.play();
}

void PhoneSound::stopOutgoingTone()
{
    outgoing_tone.stop();
}

void PhoneSound::playEndCallTone()
{
    end_call_tone.play();
}

void PhoneSound::playBusyTone()
{
    busy_audio.play();
}

void PhoneSound::stopBusyTone()
{
    busy_audio.stop();
}
