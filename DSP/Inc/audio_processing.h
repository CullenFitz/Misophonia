/*
 * audio_processing.h
 *
 *  Created on: Jan 2, 2024
 *      Author: cullen fitzgerald
 */

#ifndef AUDIO_PROCESSING_H_
#define AUDIO_PROCESSING_H_

#include <stddef.h>
#include <stdint.h>

/*
 * Read in data from the audio sample. Store this in the audio buffer
 */

void readWavFile(const char* filename, int16_t* audioBuffer, size_t bufferSize);


/*
 * Write the output to a wav file
 */

void writeWavFile(const char* filename, const int16_t* audioData, size_t dataSize);


/*
 * Function to apply a Finite Impulse Response filter
 */

void applyLowPassFIRFilter(const int16_t* input, int16_t* output, size_t dataSize);


/*
 * Read data from audio file and apply filter
 */

void processAudioFile(const char* filename, size_t bufferSize);


/*
 * Calculate buffer size of input wav file
 */

size_t calculateBufferSize(uint32_t samplingRate, uint16_t bitDepth, uint16_t numChannels, uint32_t durationSeconds);



#endif /* AUDIO_PROCESSING_H_ */
