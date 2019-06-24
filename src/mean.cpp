#include <boost/math/distributions/students_t.hpp>

#include "mean.h"
#include "statistics.h"
#include "utils.h"

namespace statistics {
namespace mean {

    double test_statistic(
        double sample_mean,
        double sample_std_dev,
        unsigned long sample_size,
        double mean)
    {
        auto t = (sample_mean - mean);
        t /= sample_std_dev / std::sqrt(sample_size);
        return t;
    }

    double p_value(double t, double degrees_of_freedom, H1Comparison comparison)
    {
        auto distribution = boost::math::students_t{ degrees_of_freedom };
        if (comparison == DIFFERENT) {
            return 2 * (1 - boost::math::cdf(distribution, std::abs(t)));
        } else if (comparison == GREATER_THAN) {
            return 1 - boost::math::cdf(distribution, t);
        } else {
            return boost::math::cdf(distribution, t);
        }
    }

    double critical_value(
        double confidence_level,
        double degrees_of_freedom,
        H1Comparison comparison)
    {
        auto critical_region = 1 - confidence_level;
        double t;

        if (comparison == DIFFERENT) {
            t = -students_t_icdf(critical_region / 2, degrees_of_freedom, tolerance);
        } else if (comparison == GREATER_THAN) {
            t = students_t_icdf(1 - critical_region, degrees_of_freedom, tolerance);
        } else {
            t = -students_t_icdf(critical_region, degrees_of_freedom, tolerance);
        }

        return t;
    }

    std::tuple<bool, double> significance_test(
        double sample_mean,
        double sample_std_dev,
        unsigned long sample_size,
        double mean,
        double confidence_level,
        H1Comparison comparison)
    {
        auto t_cal = test_statistic(sample_mean, sample_std_dev, sample_size, mean);
        auto degrees_of_freedom = (double)sample_size - 1;
        auto p = p_value(t_cal, degrees_of_freedom, comparison);

        auto t_crit = critical_value(confidence_level, degrees_of_freedom, comparison);
        bool accept_alternative;

        if (comparison == DIFFERENT) {
            accept_alternative = (t_cal < -t_crit || t_cal > t_crit);
        } else if (comparison == GREATER_THAN) {
            accept_alternative = t_cal > t_crit;
        } else if (comparison == LESS_THAN) {
            accept_alternative = t_cal < -t_crit;
        }

        return std::make_tuple(accept_alternative, p);
    }
}
}
