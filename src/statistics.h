#ifndef STATISTICS_H
#define STATISTICS_H

#include <tuple>

namespace statistics {

extern double tolerance;

/// Set the global tolerance value
///
/// @param  new_tolerance is the new value for the global tolerance and should be a very small number
void set_tolerance(double new_tolerance);

enum H1Comparison {
    DIFFERENT,
    GREATER_THAN,
    LESS_THAN,
};

/// Apply the inverse cumulative distribution function for the normal distribution
///
/// Finds a numerical aproximation via a binary search.
/// Boost's `quantile` function could be used instead for greater precision and efficiency.
///
/// @param  p is the cumulative probability (the area under the curve for the probability density function)
/// @param  tolerance is a small value to be used when comparing two floating point numbers
/// @return The z value associated with the given probability
double normal_icdf(double p, double tolerance);

/// Apply the inverse cumulative distribution function for Student's t-distribution
///
/// Finds a numerical aproximation via a binary search.
/// Boost's `quantile` function could be used instead for greater precision and efficiency.
///
/// @param  p is the cumulative probability (the area under the curve for the probability density function)
/// @param  degrees_of_freedom is the number of degrees of freedom that parameterize the distribution
/// @param  tolerance is a small value to be used when comparing two floating point numbers
/// @return The t value associated with the given probability
double students_t_icdf(double p, double degrees_of_freedom, double tolerance);
}

#endif
