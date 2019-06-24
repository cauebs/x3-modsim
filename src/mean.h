#ifndef STATISTICS_MEAN_H
#define STATISTICS_MEAN_H

#include "statistics.h"
#include <tuple>

namespace statistics {

/// Inverse cumulative distribution function for Student's t-distribution
double students_t_icdf(double p, double degrees_of_freedom, double tolerance);

double mean_statistic(
    double sample_mean,
    double sample_std_dev,
    unsigned long sample_size,
    double mean);

double mean_p_value(double t, double degrees_of_freedom, H1Comparison comparison);

double mean_critical_value(
    double confidence_level,
    double degrees_of_freedom,
    H1Comparison comparison);

std::tuple<bool, double> mean_test(
    double sample_mean,
    double sample_std_dev,
    unsigned long sample_size,
    double mean,
    double confidence_level,
    H1Comparison comparison);
}

#endif
