#ifndef UTILS_H
#define UTILS_H

namespace utils {

/// Aproximate inverse function application using a binary search
template <typename T, typename F>
T numerical_inverse(F f, T y, T begin, T end, T precision)
{
    while (std::abs(end - begin) > precision) {
        auto middle = (begin + end) / 2;

        if (f(middle) < y) {
            begin = middle;
        } else {
            end = middle;
        }
    }

    return end;
}

} // namespace utils

#endif
