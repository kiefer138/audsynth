#include <stdio.h>
#include <stdlib.h>
#include "../include/audiostream.h"

int audio_callback(const void *inputBuffer, void *outputBuffer,
                   unsigned long framesPerBuffer,
                   const PaStreamCallbackTimeInfo *timeInfo,
                   PaStreamCallbackFlags statusFlags,
                   void *userData)
{
    // Copy input directly to output
    float *out = (float *)outputBuffer;
    const float *in = (const float *)inputBuffer;
    unsigned long i;
    for (i = 0; i < framesPerBuffer; i++)
    {
        *out++ = *in++; // left channel
        *out++ = *in++; // right channel
    }
    return 0;
}

int start_audiostream(PaStream **stream)
{
    PaError err;

    err = Pa_Initialize();
    if (err != paNoError)
    {
        printf("PortAudio error: %s\n", Pa_GetErrorText(err));
        return err;
    }

    err = Pa_OpenDefaultStream(stream,
                               0,              // no input channels
                               2,              // stereo output
                               paFloat32,      // 32 bit floating point output
                               44100,          // sample rate
                               256,            // frames per buffer
                               audio_callback, // callback function
                               NULL);          // no callback data
    if (err != paNoError)
    {
        printf("PortAudio error: %s\n", Pa_GetErrorText(err));
        return err;
    }

    err = Pa_StartStream(*stream);
    if (err != paNoError)
    {
        printf("PortAudio error: %s\n", Pa_GetErrorText(err));
        return err;
    }

    return paNoError;
}

int stop_audiostream(PaStream **stream)
{
    PaError err;

    err = Pa_StopStream(*stream);
    if (err != paNoError)
    {
        printf("PortAudio error: %s\n", Pa_GetErrorText(err));
        return err;
    }

    err = Pa_CloseStream(*stream);
    if (err != paNoError)
    {
        printf("PortAudio error: %s\n", Pa_GetErrorText(err));
        return err;
    }

    // Set the stream pointer to NULL after closing the stream
    *stream = NULL;

    err = Pa_Terminate();
    if (err != paNoError)
    {
        printf("PortAudio error: %s\n", Pa_GetErrorText(err));
        return err;
    }

    return paNoError;
}
