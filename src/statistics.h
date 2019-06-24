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
}

#endif
