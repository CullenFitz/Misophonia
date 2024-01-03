// main.c

#include <stdio.h>
#include <portaudio.h>
#include "low_pass_filter.h"

#define SAMPLE_RATE 44100
#define FRAMES_PER_BUFFER 256
#define CUTOFF_FREQUENCY 1000.0
#define FILTER_ORDER 3

typedef struct {
    LowPassFilter filter;
} PaUserData;

static int paCallback(const void* inputBuffer, void* outputBuffer,
                      unsigned long framesPerBuffer,
                      const PaStreamCallbackTimeInfo* timeInfo,
                      PaStreamCallbackFlags statusFlags,
                      void* userData) {
    PaUserData* data = (PaUserData*)userData;
    float* in = (float*)inputBuffer;
    float* out = (float*)outputBuffer;

    for (unsigned long i = 0; i < framesPerBuffer; ++i) {
        float inputSample = in[i];
        float outputSample = apply_filter(&(data->filter), inputSample);
        out[i] = outputSample;
    }

    return paContinue;
}

int main() {
    PaStream* stream;
    PaError err;
    PaUserData data;

    // Initialize the low-pass filter
    init_filter(&(data.filter), FILTER_ORDER, CUTOFF_FREQUENCY, SAMPLE_RATE);

    // Initialize PortAudio
    err = Pa_Initialize();
    if (err != paNoError) {
        fprintf(stderr, "PortAudio initialization failed: %s\n", Pa_GetErrorText(err));
        return 1;
    }

    // Open a stream for both input and output
    err = Pa_OpenDefaultStream(&stream, 1, 1, paFloat32, SAMPLE_RATE, FRAMES_PER_BUFFER, paCallback, &data);
    if (err != paNoError) {
        fprintf(stderr, "PortAudio stream opening failed: %s\n", Pa_GetErrorText(err));
        Pa_Terminate();
        return 1;
    }

    // Start the stream
    err = Pa_StartStream(stream);
    if (err != paNoError) {
        fprintf(stderr, "PortAudio stream starting failed: %s\n", Pa_GetErrorText(err));
        Pa_CloseStream(stream);
        Pa_Terminate();
        return 1;
    }

    printf("Press Enter to stop the program.\n");
    getchar();

    // Stop and close the stream
    err = Pa_StopStream(stream);
    if (err != paNoError) {
        fprintf(stderr, "PortAudio stream stopping failed: %s\n", Pa_GetErrorText(err));
    }

    err = Pa_CloseStream(stream);
    if (err != paNoError) {
        fprintf(stderr, "PortAudio stream closing failed: %s\n", Pa_GetErrorText(err));
    }

    // Terminate PortAudio
    Pa_Terminate();

    // Clean up the filter
    destroy_filter(&(data.filter));

    return 0;
}
