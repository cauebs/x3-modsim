#include "utils.h"

#include "../src/proportion.h"

using namespace statistics;

void test_proportion_test()
{
    // test calculated z statistic
    assert_almost_equal(proportion_statistic(0.1, 240, 0.06), 2.60931);
    assert_almost_equal(proportion_statistic(0.68, 100, 0.5), 3.6);
    assert_almost_equal(proportion_statistic(0.15, 400, 0.2), -2.5);
    assert_almost_equal(proportion_statistic(0.16, 225, 0.1), 3.);
    assert_almost_equal(proportion_statistic(0.44, 300, 0.49), -1.7324);

    // test p-value
    assert_almost_equal(proportion_p_value(-1.25, LESS_THAN), 0.10565);
    assert_almost_equal(proportion_p_value(1.79, DIFFERENT), 0.0734539);
    assert_almost_equal(proportion_p_value(0.75, GREATER_THAN), 0.226627);
    assert_almost_equal(proportion_p_value(-0.45, LESS_THAN), 0.326355);
    assert_almost_equal(proportion_p_value(2.236, DIFFERENT), 0.0253518);

    // test acceptance of alternative hypothesis
    assert(std::get<0>(proportion_test(0.44, 500, 0.45, 0.95, LESS_THAN)) == false);
    assert(std::get<0>(proportion_test(0.13, 500, 0.1, 0.95, DIFFERENT)) == true);
    assert(std::get<0>(proportion_test(0.16, 400, 0.2, 0.95, LESS_THAN)) == true);
    assert(std::get<0>(proportion_test(0.03, 500, 0.04, 0.9, DIFFERENT)) == false);
    assert(std::get<0>(proportion_test(0.36, 50, 0.3, 0.9, GREATER_THAN)) == false);
}

int main(void)
{
    set_tolerance(0.00001);
    test_proportion_test();
    std::cout << "All tests have passed!" << std::endl;
}
