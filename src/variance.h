#ifndef STATISTICS_VARIANCE_H
#define STATISTICS_VARIANCE_H

#include "statistics.h"
#include <tuple>

namespace statistics {
namespace variance {

    /// Calculate the value of the test statistic in the Chi-squared test for a variance
    ///
    /// @param  sample_variance is the variance observed in the sample
    /// @param  sample_size is the number of elements in the sample
    /// @param  variance is the population variance of the null hypothesis
    /// @return The value of the test statistic (chi)
    double test_statistic(
        double sample_variance,
        unsigned long sample_size,
        double variance);

    /// Calculate the p-value for the test statistic in the Chi-squared test for a variance
    ///
    /// @param  chi is the test statistic's value
    /// @param  degrees_of_freedom is the number of degrees of freedom (sample size - 1)
    /// @param  comparison is the type of the alternative hypothesis
    /// @return The p-value for this hypothesis
    double p_value(double chi, double degrees_of_freedom, H1Comparison comparison);

    /// Calculate the critical value for the test statistic in the Chi-squared test for a variance
    ///
    /// @param  confidence_level is the fraction between 0 and 1 representing the confidence level (e.g.: 0.95)
    /// @param  comparison is the type of the alternative hypothesis
    /// @return The critical value for the test statistic for this hypothesis
    double critical_value(double confidence_level, H1Comparison comparison);

    /// Perform the significance Chi-squared test and evaluate the hypothesis
    ///
    /// @param  sample_variance is the variance observed in the sample
    /// @param  sample_size is the number of elements in the sample
    /// @param  variance is the population variance of the null hypothesis
    /// @param  confidence_level is the fraction between 0 and 1 representing the confidence level (e.g.: 0.95)
    /// @param  comparison is the type of the alternative hypothesis
    /// @return A tuple containing a boolean that indicates whether the null hypothesis can be rejected and the associated p-value
    std::tuple<bool, double> significance_test(
        double sample_variance,
        unsigned long sample_size,
        double variance,
        double confidence_level,
        H1Comparison comparison);
}
}

#endif
