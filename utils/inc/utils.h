#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <fftw3.h>

#define SAMPLE_RATE 44100
#define FFT_SIZE 1024
#define TARGET_FREQUENCY 10000
#define THRESHOLD 0.1

typedef struct {
    char     chunkId[5];
    uint32_t chunkSize;
    char     format[5];
    char     subchunk1Id[5];
    uint32_t subchunk1Size;
    uint16_t audioFormat;
    uint16_t numChannels;
    uint32_t sampleRate;
    uint32_t byteRate;
    uint16_t blockAlign;
    uint16_t bitsPerSample;
    char     subchunk2Id[5];
    uint32_t subchunk2Size;
} WavHeader;

typedef struct {
    fftw_complex *fft_input;
    fftw_complex *fft_output;
    fftw_plan fft_plan;
} AudioData;

void filterWavFile(const char* filePath);

void initializeWavHeader(WavHeader *header);

void applyFFT(const double *inputBuffer, int bufferSize, int frameSize, int hopSize);

#endif /* UTILS_H */