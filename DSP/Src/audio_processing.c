/*
 * audio_processing.c
 *
 *  Created on: Jan 2, 2024
 *      Author: cullen fitzgerald
 */

#include "audio_processing.h"
#include <stdio.h>


#define FIR_FILTER_SIZE	16

/*
 * Read in data from the audio sample. Store this in the audio buffer
 */

void readWavFile(const char* filename, int16_t* audioBuffer, size_t bufferSize){
	FILE* file = fopen(filename, "rb");

	if(file == NULL){
		return;
	}

	fseek(file, 44, SEEK_SET); /* First 44 bytes of WAV are header. Skip these */

	fread(audioBuffer, sizeof(int16_t), bufferSize, file);

	fclose(file);
}

void writeWavFile(const char* filename, const int16_t* audioData, size_t dataSize) {
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        // Handle file opening error
        return;
    }

    // Write WAV header (assuming PCM format, 44.1 kHz, 16-bit)
    // You might need to adjust these values based on your actual data
    fprintf(file, "RIFF");
    fwrite(&dataSize, sizeof(uint32_t), 1, file);  // File size excluding header
    fprintf(file, "WAVEfmt ");
    uint32_t formatSize = 16;
    fwrite(&formatSize, sizeof(uint32_t), 1, file);
    uint16_t audioFormat = 1;  // PCM format
    uint16_t numChannels = 1;  // Mono
    uint32_t sampleRate = 44100;
    uint32_t byteRate = sampleRate * sizeof(int16_t) * numChannels;
    uint16_t blockAlign = sizeof(int16_t) * numChannels;
    uint16_t bitsPerSample = 16;  // 16-bit
    fwrite(&audioFormat, sizeof(uint16_t), 1, file);
    fwrite(&numChannels, sizeof(uint16_t), 1, file);
    fwrite(&sampleRate, sizeof(uint32_t), 1, file);
    fwrite(&byteRate, sizeof(uint32_t), 1, file);
    fwrite(&blockAlign, sizeof(uint16_t), 1, file);
    fwrite(&bitsPerSample, sizeof(uint16_t), 1, file);
    fprintf(file, "data");
    fwrite(&dataSize, sizeof(uint32_t), 1, file);  // Data size

    // Write audio data
    fwrite(audioData, sizeof(int16_t), dataSize, file);

    fclose(file);
}


/*
 * Function to apply a Finite Impulse Response filter
 */

void applyLowPassFIRFilter(const int16_t* input, int16_t* output, size_t dataSize){

	float firCoefficients[FIR_FILTER_SIZE] = {
	    0.05, 0.1, 0.15, 0.2, 0.25, 0.3, 0.25, 0.2,
	    0.15, 0.1, 0.05, 0, 0, 0, 0, 0
	};

	for (size_t i = 0; i < dataSize; ++i) {
	        output[i] = 0;

	        // Apply filter coefficients
	        for (size_t j = 0; j < FIR_FILTER_SIZE; ++j) {
	            if (i >= j) {
	                output[i] += input[i - j] * firCoefficients[j];
	            }
	        }
	    }
}

/*
 * Read data from audio file and apply filter
 */

void processAudioFile(const char* filename, size_t bufferSize){
	// Allocate buffers for audio data
	int16_t audioBuffer[bufferSize];
	int16_t filteredAudio[bufferSize];

	// Read audio data from the file
	readWavFile(filename, audioBuffer, bufferSize);

	// Apply low-pass filter
	applyLowPassFIRFilter(audioBuffer, filteredAudio, bufferSize);

	// Write filtered audio data to a new WAV file
	writeWavFile("filtered_output.wav", filteredAudio, bufferSize);
}

/*
 * Calculate buffer size of input wav file
 */
size_t calculateBufferSize(uint32_t samplingRate, uint16_t bitDepth, uint16_t numChannels, uint32_t durationSeconds) {
    return (size_t)(samplingRate * bitDepth / 8 * numChannels * durationSeconds);
}




