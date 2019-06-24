#include <boost/math/distributions/chi_squared.hpp>

#include "statistics.h"
#include "utils.h"
#include "variance.h"

namespace statistics {

double variance_statistic(
    double sample_variance,
    unsigned long sample_size,
    double variance)
{
    return (sample_size - 1) * sample_variance / variance;
}

double variance_p_value(double chi, double degrees_of_freedom, H1Comparison comparison)
{
    auto distribution = boost::math::chi_squared{ degrees_of_freedom };

    if (comparison == DIFFERENT) {
        return 2 * boost::math::cdf(distribution, chi);
    } else if (comparison == GREATER_THAN) {
        return 1 - boost::math::cdf(distribution, chi);
    } else {
        return boost::math::cdf(distribution, chi);
    }
}

std::tuple<double, double> variance_critical_value(
    double confidence_level,
    double degrees_of_freedom,
    H1Comparison comparison)
{
    auto distribution = boost::math::chi_squared{ degrees_of_freedom };
    auto critical_region = 1 - confidence_level;
    double chi_inf, chi_sup;

    if (comparison == DIFFERENT) {
        chi_inf = boost::math::quantile(distribution, critical_region / 2);
        chi_sup = boost::math::quantile(distribution, 1 - critical_region / 2);
    } else if (comparison == GREATER_THAN) {
        chi_inf = chi_sup = boost::math::quantile(distribution, 1 - critical_region);
    } else {
        chi_inf = chi_sup = boost::math::quantile(distribution, critical_region);
    }

    return std::make_tuple(chi_inf, chi_sup);
}

std::tuple<bool, double> variance_test(
    double sample_variance,
    unsigned long sample_size,
    double variance,
    double confidence_level,
    H1Comparison comparison)
{
    auto chi_cal = variance_statistic(sample_variance, sample_size, variance);
    auto degrees_of_freedom = (double)sample_size - 1;
    auto p_value = variance_p_value(chi_cal, degrees_of_freedom, comparison);

    auto crit = variance_critical_value(confidence_level, degrees_of_freedom, comparison);
    bool accept_alternative;

    if (comparison == DIFFERENT) {
        auto chi_crit_inf = std::get<0>(crit);
        auto chi_crit_sup = std::get<1>(crit);
        accept_alternative = (chi_cal < chi_crit_inf || chi_cal > chi_crit_sup);
    } else {
        auto chi_crit = std::get<0>(crit);

        if (comparison == GREATER_THAN) {
            accept_alternative = chi_cal > chi_crit;
        } else if (comparison == LESS_THAN) {
            accept_alternative = chi_cal < -chi_crit;
        }
    }

    return std::make_tuple(accept_alternative, p_value);
}
}
