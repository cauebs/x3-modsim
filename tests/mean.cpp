#include "utils.h"

#include "../src/mean.h"

using namespace statistics;

void test_mean_test()
{
    // test calculated z statistic
    assert_almost_equal(mean_statistic(156, 30, 36, 150), 1.2);
    assert_almost_equal(mean_statistic(4, 2, 25, 5), -2.5);
    assert_almost_equal(mean_statistic(242, 12, 24, 250), -3.26599);
    assert_almost_equal(mean_statistic(2.8, 0.8, 16, 2.5), 1.5);
    assert_almost_equal(mean_statistic(156, 30, 33, 150), 1.14891);

    // test p-value
    assert_almost_equal(mean_p_value(1.952, 5, GREATER_THAN), 0.0541961);
    assert_almost_equal(mean_p_value(2.4, 15, DIFFERENT), 0.0298249);
    assert_almost_equal(mean_p_value(-2.83, 8, LESS_THAN), 0.0110751);
    assert_almost_equal(mean_p_value(2.411, 11, GREATER_THAN), 0.0172766);
    assert_almost_equal(mean_p_value(-1.79, 11, DIFFERENT), 0.100986);

    // test acceptance of alternative hypothesis
    assert(std::get<0>(mean_test(0.49, 0.04, 30, 0.5, 0.95, DIFFERENT)) == false);
    assert(std::get<0>(mean_test(4.25, 3, 30, 5, 0.95, LESS_THAN)) == false);
    assert(std::get<0>(mean_test(7.5, 1.6, 42, 8, 0.95, LESS_THAN)) == true);
    assert(std::get<0>(mean_test(127, 44, 30, 100, 0.9, GREATER_THAN)) == true);
    assert(std::get<0>(mean_test(156, 30, 33, 150, 0.95, GREATER_THAN)) == false);
}

int main(void)
{
    set_tolerance(0.00001);
    test_mean_test();
    std::cout << "All tests have passed!" << std::endl;
}
