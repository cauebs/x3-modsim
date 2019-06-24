#ifndef STATISTICS_PROPORTION_H
#define STATISTICS_PROPORTION_H

#include "statistics.h"
#include <tuple>

namespace statistics {
namespace proportion {

    /// Calculate the value of the test statistic in the z test for a proportion
    ///
    /// @param  sample_proportion is the proportion observed in the sample
    /// @param  sample_size is the number of elements in the sample
    /// @param  proportion is the population proportion of the null hypothesis
    /// @return The value of the test statistic (Z)
    double test_statistic(
        double sample_proportion,
        unsigned long sample_size,
        double proportion);

    /// Calculate the p-value for the test statistic in the z test for a proportion
    ///
    /// @param  z is the test statistic's value
    /// @param  comparison is the type of the alternative hypothesis
    /// @return The p-value for this hypothesis
    double p_value(double z, H1Comparison comparison);

    /// Calculate the critical value for the test statistic in the z test for a proportion
    ///
    /// @param  confidence_level is the fraction between 0 and 1 representing the confidence level (e.g.: 0.95)
    /// @param  comparison is the type of the alternative hypothesis
    /// @return The critical value for the test statistic for this hypothesis
    double critical_value(double confidence_level, H1Comparison comparison);

    /// Perform the significance z test and evaluate the hypothesis
    ///
    /// @param  sample_proportion is the proportion observed in the sample
    /// @param  sample_size is the number of elements in the sample
    /// @param  proportion is the population proportion of the null hypothesis
    /// @param  confidence_level is the fraction between 0 and 1 representing the confidence level (e.g.: 0.95)
    /// @param  comparison is the type of the alternative hypothesis
    /// @return A tuple containing a boolean that indicates whether the null hypothesis can be rejected and the associated p-value
    std::tuple<bool, double> significance_test(
        double sample_proportion,
        unsigned long sample_size,
        double proportion,
        double confidence_level,
        H1Comparison comparison);
}
}

#endif
