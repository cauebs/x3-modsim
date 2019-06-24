#include <boost/math/distributions/normal.hpp>
#include <boost/math/distributions/students_t.hpp>
#include <boost/math/distributions/chi_squared.hpp>

#include "statistics.h"
#include "utils.h"

namespace statistics {

double tolerance = 0.0001;

void set_tolerance(double new_tolerance)
{
    tolerance = new_tolerance;
}

double normal_icdf(double p, double tolerance)
{
    auto distribution = boost::math::normal{};

    // cumulative distribution function
    auto cdf = [distribution](double y) {
        return boost::math::cdf(distribution, y);
    };

    return utils::numerical_inverse(cdf, p, -5., 5., tolerance);
}

double students_t_icdf(double p, double degrees_of_freedom, double tolerance)
{
    auto distribution = boost::math::students_t{ degrees_of_freedom };

    // cumulative distribution function
    auto cdf = [distribution](double y) {
        return boost::math::cdf(distribution, y);
    };

    return utils::numerical_inverse(cdf, p, -5., 5., tolerance);
}
}
