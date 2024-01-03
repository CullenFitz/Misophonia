// lowpass_filter.h

#ifndef LOW_PASS_FILTER_H
#define LOW_PASS_FILTER_H

typedef struct {
    double* coefficients;
    int order;
    double* buffer;
    int buffer_index;
} LowPassFilter;

void init_filter(LowPassFilter* filter, int order, double cutoff_frequency, double sampling_rate);
double apply_filter(LowPassFilter* filter, double input_sample);
void destroy_filter(LowPassFilter* filter);

#endif // LOWPASS_FILTER_H
