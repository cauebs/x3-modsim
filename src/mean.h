#ifndef STATISTICS_MEAN_H
#define STATISTICS_MEAN_H

#include "statistics.h"
#include <tuple>

namespace statistics {
namespace mean {

    /// Calculate the value of the test statistic in the Student's t test for a mean
    ///
    /// @param  sample_mean is the mean observed in the sample
    /// @param  sample_std_dev is the standard deviation observed in the sample
    /// @param  sample_size is the number of elements in the sample
    /// @param  mean is the population mean of the null hypothesis
    /// @return The value of the test statistic (t)
    double test_statistic(
        double sample_mean,
        double sample_std_dev,
        unsigned long sample_size,
        double mean);

    /// Calculate the p-value for the test statistic in the Student's t test for a mean
    ///
    /// @param  t is the test statistic's value
    /// @param  degrees_of_freedom is the number of degrees of freedom (sample size - 1)
    /// @param  comparison is the type of the alternative hypothesis
    /// @return The p-value for this hypothesis
    double p_value(double t, double degrees_of_freedom, H1Comparison comparison);

    /// Calculate the critical value for the test statistic in the Student's t test for a mean
    ///
    /// @param  confidence_level is the fraction between 0 and 1 representing the confidence level (e.g.: 0.95)
    /// @param  degrees_of_freedom is the number of degrees of freedom (sample size - 1)
    /// @param  comparison is the type of the alternative hypothesis
    /// @return The critical value for the test statistic for this hypothesis
    double critical_value(
        double confidence_level,
        double degrees_of_freedom,
        H1Comparison comparison);

    /// Perform the significance Student's t test and evaluate the hypothesis
    ///
    /// @param  sample_mean is the mean observed in the sample
    /// @param  sample_std_dev is the standard deviation observed in the sample
    /// @param  sample_size is the number of elements in the sample
    /// @param  mean is the population mean of the null hypothesis
    /// @param  confidence_level is the fraction between 0 and 1 representing the confidence level (e.g.: 0.95)
    /// @param  comparison is the type of the alternative hypothesis
    /// @return A tuple containing a boolean that indicates whether the null hypothesis can be rejected and the associated p-value
    std::tuple<bool, double> significance_test(
        double sample_mean,
        double sample_std_dev,
        unsigned long sample_size,
        double mean,
        double confidence_level,
        H1Comparison comparison);
}
}

#endif
