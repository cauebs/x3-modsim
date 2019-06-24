#ifndef UTILS_H
#define UTILS_H

#include <boost/math/special_functions/gamma.hpp>

namespace utils {

/// Find a numerical aproximation for the application of the inverse of a function via a binary search.
///
/// @param  f is the function whose inverse will be applied
/// @param  y is the value onto which the inverse will be applied
/// @param  begin is where the search interval should begin
/// @param  end is where the search interval should end
/// @param  tolerance is a small value to be used when comparing two floating point numbers
/// @return The value x for which f(x) = y
template <typename T, typename F>
T numerical_inverse(F f, T y, T begin, T end, T tolerance)
{
    while (std::abs(end - begin) > tolerance) {
        auto middle = (begin + end) / 2;

        if (f(middle) < y) {
            begin = middle;
        } else {
            end = middle;
        }
    }

    return end;
}

#endif
