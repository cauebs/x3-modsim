#ifndef STATISTICS_MEAN_H
#define STATISTICS_MEAN_H

#include "statistics.h"
#include <tuple>

namespace statistics {
namespace mean {
    double test_statistic(
        double sample_mean,
        double sample_std_dev,
        unsigned long sample_size,
        double mean);

    double p_value(double t, double degrees_of_freedom, H1Comparison comparison);

    double critical_value(
        double confidence_level,
        double degrees_of_freedom,
        H1Comparison comparison);

    std::tuple<bool, double> significance_test(
        double sample_mean,
        double sample_std_dev,
        unsigned long sample_size,
        double mean,
        double confidence_level,
        H1Comparison comparison);
}
}

#endif
