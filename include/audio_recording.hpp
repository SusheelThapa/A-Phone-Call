#pragma once

enum AudioRecordingStatus
{
    NONE,
    RECORDING,
    RECORDED,
};

class AudioRecording
{
public:
    void startRecordingAudio();

    void stopRecordingAudio();
};