#ifndef STATISTICS_PROPORTION_H
#define STATISTICS_PROPORTION_H

#include "statistics.h"
#include <tuple>

namespace statistics {
namespace proportion {

    double test_statistic(
        double sample_proportion,
        unsigned long sample_size,
        double proportion);

    double p_value(double z, H1Comparison comparison);

    double critical_value(double confidence_level, H1Comparison comparison);

    std::tuple<bool, double> significance_test(
        double sample_proportion,
        unsigned long sample_size,
        double proportion,
        double confidence_level,
        H1Comparison comparison);
}
}

#endif
