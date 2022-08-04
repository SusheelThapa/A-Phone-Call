#include "audio_recording.hpp"

#include <iostream>
#include <fstream>

void AudioRecording::startRecordingAudio()
{
    system("arecord resources/audio/test.wav -c 2 -f S16_LE -r 96000 -d 10 &");
}
void AudioRecording::stopRecordingAudio()
{
    /*This one will be written in future*/
}