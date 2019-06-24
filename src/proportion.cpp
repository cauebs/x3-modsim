#include <boost/math/distributions/normal.hpp>

#include "proportion.h"
#include "statistics.h"
#include "utils.h"

namespace statistics {
namespace proportion {

    double test_statistic(
        double sample_proportion,
        unsigned long sample_size,
        double proportion)
    {
        auto z = (sample_proportion - proportion);
        z /= std::sqrt(proportion * (1 - proportion) / sample_size);
        return z;
    }

    double p_value(double z, H1Comparison comparison)
    {
        auto distribution = boost::math::normal{};
        if (comparison == DIFFERENT) {
            return 2 * (1 - boost::math::cdf(distribution, std::abs(z)));
        } else if (comparison == GREATER_THAN) {
            return 1 - boost::math::cdf(distribution, z);
        } else {
            return boost::math::cdf(distribution, z);
        }
    }

    double critical_value(double confidence_level, H1Comparison comparison)
    {
        auto critical_region = 1 - confidence_level;
        double z;

        if (comparison == DIFFERENT) {
            z = -normal_icdf(critical_region / 2, tolerance);
        } else if (comparison == GREATER_THAN) {
            z = normal_icdf(1 - critical_region, tolerance);
        } else {
            z = -normal_icdf(critical_region, tolerance);
        }

        return z;
    }

    std::tuple<bool, double> significance_test(
        double sample_proportion,
        unsigned long sample_size,
        double proportion,
        double confidence_level,
        H1Comparison comparison)
    {
        auto z_cal = test_statistic(sample_proportion, sample_size, proportion);
        auto p = p_value(z_cal, comparison);

        auto z_crit = critical_value(confidence_level, comparison);
        bool accept_alternative;

        if (comparison == DIFFERENT) {
            accept_alternative = (z_cal < -z_crit || z_cal > z_crit);
        } else if (comparison == GREATER_THAN) {
            accept_alternative = z_cal > z_crit;
        } else if (comparison == LESS_THAN) {
            accept_alternative = z_cal < -z_crit;
        }

        return std::make_tuple(accept_alternative, p);
    }
}
}
