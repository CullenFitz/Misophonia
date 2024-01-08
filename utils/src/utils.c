#include "utils.h"

void initializeWavHeader(WavHeader *header) {
    // Initialize all fields to appropriate initial values
    strcpy(header->chunkId, "RIFF");
    header->chunkSize = 0; // Actual value needs to be set later based on audio data size
    strcpy(header->format, "WAVE");
    strcpy(header->subchunk1Id, "fmt ");
    header->subchunk1Size = 16; // Assuming PCM format
    header->audioFormat = 1; // PCM format
    header->numChannels = 2; // Stereo
    header->sampleRate = 44100; // Sample rate in Hz
    header->byteRate = header->sampleRate * header->numChannels * (header->bitsPerSample / 8);
    header->blockAlign = header->numChannels * (header->bitsPerSample / 8);
    header->bitsPerSample = 16; // 16 bits per sample
    strcpy(header->subchunk2Id, "data");
    header->subchunk2Size = 0; // Actual value needs to be set later based on audio data size
}

void filterWavFile(const char* fileName){

    FILE* inputFile = fopen(fileName, "rb");
    if(!inputFile){
        perror("Error opening input file");
        return;
    }

    WavHeader header;
    initializeWavHeader(&header);

    // Read the wav header
    fread(&header, sizeof(WavHeader), 1, inputFile);

    // Calculate size of audio data
    fseek(inputFile, 0, SEEK_END);
    long fileSize = ftell(inputFile);
    size_t bufferSize = fileSize - sizeof(WavHeader);

    // Now read the rest of the audio data
    fseek(inputFile, 0, SEEK_SET);
    fseek(inputFile, sizeof(WavHeader), SEEK_SET);  // skip over the header
    uint16_t* buffer = (uint16_t *)malloc(bufferSize);
    if(!buffer){
        perror("Error allocating memory for buffer");
        fclose(inputFile);
        return;
    }
    fread(buffer, bufferSize, 1, inputFile);
    fclose(inputFile);

    // Filter data
    

    // Write new wav
    FILE *outputFile = fopen("../audio_output/output.wav", "wb");
    if (!outputFile) {
        perror("Error opening output file");
        free(buffer);
        return;
    }

    fwrite(&header, sizeof(header), 1, outputFile);
    fwrite(buffer, bufferSize, 1, outputFile);

    return;

}

void applyFFT(const double *inputBuffer, int bufferSize, int frameSize, int hopSize){

}