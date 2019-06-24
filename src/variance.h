#ifndef STATISTICS_VARIANCE_H
#define STATISTICS_VARIANCE_H

#include "statistics.h"
#include <tuple>

namespace statistics {
namespace variance {

    double test_statistic(
        double sample_variance,
        unsigned long sample_size,
        double variance);

    double p_value(double chi, double degrees_of_freedom, H1Comparison comparison);

    double critical_value(double confidence_level, H1Comparison comparison);

    std::tuple<bool, double> significance_test(
        double sample_variance,
        unsigned long sample_size,
        double variance,
        double confidence_level,
        H1Comparison comparison);
}
}

#endif
