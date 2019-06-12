#include <algorithm>
#include <cmath>
#include <iostream>
#include <stdexcept>

#include <boost/math/distributions/normal.hpp>

#include "statistics.h"
#include "utils.h"

namespace statistics {

double icdf(double t, double precision)
{
    auto s = boost::math::normal{};

    auto cdf = [s](double y) {
        return boost::math::cdf(s, y);
    };

    return utils::numerical_inverse(cdf, t, 0., 3., precision);
}

bool proportion_test(
    double sample_proportion,
    unsigned long sample_size,
    double proportion,
    double confidence_level,
    H1Comparison comparison,
    double precision)
{
    auto z_cal = (sample_proportion - proportion);
    z_cal /= std::sqrt(proportion * (1 - proportion) / sample_size);

    if (comparison == DIFFERENT) {
        auto z_crit = icdf(0.5 + confidence_level / 2, precision);
        return (z_cal < -z_crit || z_cal > z_crit);

    } else if (comparison == GREATER_THAN) {
        auto z_crit = icdf(1 - confidence_level, precision);
        return z_cal > z_crit;

    } else if (comparison == LESS_THAN) {
        auto z_crit = icdf(confidence_level, precision);
        return z_cal < -z_crit;
    }
}

} // namespace statistics
