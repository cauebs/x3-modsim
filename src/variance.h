#ifndef STATISTICS_VARIANCE_H
#define STATISTICS_VARIANCE_H

#include "statistics.h"
#include <tuple>

namespace statistics {

double variance_statistic(
    double sample_variance,
    unsigned long sample_size,
    double variance);

double variance_p_value(double chi, double degrees_of_freedom, H1Comparison comparison);

double variance_critical_value(double confidence_level, H1Comparison comparison);

std::tuple<bool, double> variance_test(
    double sample_variance,
    unsigned long sample_size,
    double variance,
    double confidence_level,
    H1Comparison comparison);
}

#endif
