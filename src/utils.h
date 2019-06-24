#ifndef UTILS_H
#define UTILS_H

#include <boost/math/special_functions/gamma.hpp>

namespace utils {

/// Aproximate inverse function application using a binary search
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

template <typename T>
double chi_squared_pdf(T x, T k)
{
    if (x == 0) {
        return 0;
    }

    auto y = std::pow(x, k / 2 - 1) * std::exp(-x / 2);
    y /= std::pow(2, k / 2) * boost::math::tgamma(k / 2);
    return y;
}
}

#endif
