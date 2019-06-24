#include "utils.h"

#include "../src/variance.h"

using namespace statistics;
using namespace statistics::variance;

void test_variance_test()
{
    // test calculated chi statistic
    assert_almost_equal(test_statistic(0.00003969, 100, 0.01), 0.392931);
    assert_almost_equal(test_statistic(18.3, 25, 25), 17.568);
    assert_almost_equal(test_statistic(0.304, 10, 1.3), 2.10462);
    assert_almost_equal(test_statistic(64, 30, 144), 12.8889);
    assert_almost_equal(test_statistic(144, 30, 196), 21.3061);
    assert_almost_equal(test_statistic(0.0153, 20, 0.01), 29.07);
    assert_almost_equal(test_statistic(3645.94 * 3645.94, 16, 4000 * 4000), 12.4621);

    // test p-value
    assert_almost_equal(p_value(2.10462, 9, DIFFERENT), 0.0205941);
    assert_almost_equal(p_value(29.07, 19, GREATER_THAN), 0.064892);
    assert_almost_equal(p_value(12.4621, 15, LESS_THAN), 0.356232);

    // test acceptance of alternative hypothesis
    assert(std::get<0>(significance_test(0.00003969, 100, 0.01, 0.95, DIFFERENT)) == true);
    assert(std::get<0>(significance_test(0.304, 10, 1.3, 0.95, DIFFERENT)) == true);
    assert(std::get<0>(significance_test(64, 30, 144, 0.95, DIFFERENT)) == true);
    assert(std::get<0>(significance_test(144, 30, 196, 0.99, DIFFERENT)) == false);
    assert(std::get<0>(significance_test(0.0153, 20, 0.01, 0.95, GREATER_THAN)) == false);
    assert(std::get<0>(significance_test(3645.94 * 3645.94, 16, 4000 * 4000, 0.95, LESS_THAN)) == false);
}

int main(void)
{
    set_tolerance(0.0001);
    test_variance_test();
    std::cout << "All tests have passed!" << std::endl;
}
