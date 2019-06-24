#ifndef STATISTICS_H
#define STATISTICS_H

#include <tuple>

namespace statistics {

extern double tolerance;

void set_tolerance(double new_tolerance);

enum H1Comparison {
    DIFFERENT,
    GREATER_THAN,
    LESS_THAN,
};

/// Inverse cumulative distribution function for Student's t-distribution
double students_t_icdf(double p, double degrees_of_freedom, double tolerance);

/// Inverse cumulative distribution function for normal distribution
double normal_icdf(double p, double tolerance);
}

#endif
