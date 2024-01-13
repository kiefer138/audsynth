#include <stdio.h>
#include "../include/audiostream.h"

int main()
{
    PaStream *stream = NULL;
    int err;

    // Start the audio stream
    printf("Starting audio stream...\n");
    err = start_audiostream(&stream);
    if (err != paNoError)
    {
        printf("Failed to start audio stream: %s\n", Pa_GetErrorText(err));
        return 1;
    }

    // Do something with the audio stream here...

    // Stop the audio stream
    printf("Stopping audio stream...\n");
    err = stop_audiostream(&stream);
    if (err != paNoError)
    {
        printf("Failed to stop audio stream: %s\n", Pa_GetErrorText(err));
        return 1;
    }

    printf("Audio stream stopped successfully.\n");
    return 0;
}
