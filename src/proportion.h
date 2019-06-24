#ifndef STATISTICS_PROPORTION_H
#define STATISTICS_PROPORTION_H

#include "statistics.h"
#include <tuple>

namespace statistics {

/// Inverse cumulative distribution function for normal distribution
double normal_icdf(double p, double tolerance);

double proportion_statistic(
    double sample_proportion,
    unsigned long sample_size,
    double proportion);

double proportion_p_value(double z, H1Comparison comparison);

double proportion_critical_value(double confidence_level, H1Comparison comparison);

std::tuple<bool, double> proportion_test(
    double sample_proportion,
    unsigned long sample_size,
    double proportion,
    double confidence_level,
    H1Comparison comparison);
}

#endif
