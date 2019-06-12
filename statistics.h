#ifndef STATISTICS_H
#define STATISTICS_H

namespace statistics {

/// Inverse cumulative distribution function (for gaussian distribution)
double icdf(double t, double precision);

enum H1Comparison {
    DIFFERENT,
    GREATER_THAN,
    LESS_THAN,
};

bool mean_test(
    double sample_mean,
    double sample_std_dev,
    unsigned long sample_size,
    double mean,
    double confidence_level,
    H1Comparison comparison,
    double precision);

bool proportion_test(
    double sample_proportion,
    unsigned long sample_size,
    double proportion,
    double confidence_level,
    H1Comparison comparison,
    double precision);

bool variance_test(
    double sample_variance,
    unsigned long sample_size,
    double variance,
    double confidence_level,
    H1Comparison comparison,
    double precision);

} // namespace statistics

#endif
