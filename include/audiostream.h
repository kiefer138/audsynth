#ifndef AUDIOSTREAM_H
#define AUDIOSTREAM_H

#include <portaudio.h>

/**
 * Callback function for audio processing.
 *
 * This function is called by PortAudio when audio processing is needed.
 * It copies the input directly to the output, effectively creating a pass-through.
 *
 * @param inputBuffer The input audio data.
 * @param outputBuffer The output audio data.
 * @param framesPerBuffer The number of frames per buffer.
 * @param timeInfo Timing information for the callback.
 * @param statusFlags Status flags for the audio stream.
 * @param userData User-defined data.
 * @return 0 on success, non-zero on error.
 */
int audio_callback(const void *inputBuffer, void *outputBuffer,
                   unsigned long framesPerBuffer,
                   const PaStreamCallbackTimeInfo *timeInfo,
                   PaStreamCallbackFlags statusFlags,
                   void *userData);

/**
 * Starts the audio stream.
 *
 * This function initializes PortAudio, opens the default audio stream,
 * and starts the audio stream.
 *
 * @param stream A pointer to a PaStream pointer. This will be set to the opened stream.
 * @return paNoError on success, an error code on failure.
 */
int start_audiostream(PaStream **stream);

/**
 * Stops the audio stream.
 *
 * This function stops the audio stream, closes the stream, and terminates PortAudio.
 *
 * @param stream A pointer to a PaStream pointer. This should be set to the stream to stop.
 * @return paNoError on success, an error code on failure.
 */
int stop_audiostream(PaStream **stream);

#endif // AUDIOSTREAM_H
