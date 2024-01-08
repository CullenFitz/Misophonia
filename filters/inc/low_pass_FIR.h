#ifndef LOW_PASS_FIR_H
#define LOW_PASS_FIR_H

#include <stdlib.h>

#define FILTER_SIZE     5

typedef struct{
    float buffer[FILTER_SIZE];
    size_t index;
}LowPassFIRFilter;

void initLowPassFIR(LowPassFIRFilter* filter);

float applyFilter(LowPassFIRFilter* filter, float newData);

#endif /* LOW_PASS_FIR_H */