#include <cassert>
#include <iostream>
#include <sstream>
#include <stdexcept>

#include "../src/statistics.h"

template <typename T>
void assert_almost_equal(T a, T b)
{
    if (std::abs(a - b) > statistics::tolerance) {
        auto error_message = std::stringstream{};
        error_message << "Expected " << b << " but got " << a << '\n';
        throw std::logic_error(error_message.str());
    }
}
