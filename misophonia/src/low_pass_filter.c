// lowpass_filter.c

#include "low_pass_filter.h"
#include <math.h>
#include <stdlib.h>

void init_filter(LowPassFilter* filter, int order, double cutoff_frequency, double sampling_rate) {
    filter->order = order;

    // Calculate filter coefficients
    filter->coefficients = (double*)malloc((order + 1) * sizeof(double));
    double rc = 1.0 / (2.0 * M_PI * cutoff_frequency); 
    double dt = 1.0 / sampling_rate;
    double alpha = rc / (rc + dt);

    for (int i = 0; i <= order; ++i) {
        filter->coefficients[i] = pow(alpha, i);
    }

    // Initialize buffer
    filter->buffer = (double*)malloc((order + 1) * sizeof(double));
    for (int i = 0; i <= order; ++i) {
        filter->buffer[i] = 0.0;
    }
    filter->buffer_index = 0;
}

double apply_filter(LowPassFilter* filter, double input_sample) {
    // Shift buffer and update with new sample
    for (int i = filter->order; i > 0; --i) {
        filter->buffer[i] = filter->buffer[i - 1];
    }
    filter->buffer[0] = input_sample;

    // Apply filter
    double output_sample = 0.0;
    for (int i = 0; i <= filter->order; ++i) {
        output_sample += filter->coefficients[i] * filter->buffer[i];
    }

    return output_sample;
}

void destroy_filter(LowPassFilter* filter) {
    free(filter->coefficients);
    free(filter->buffer);
    filter->order = 0;
    filter->buffer_index = 0;
}
