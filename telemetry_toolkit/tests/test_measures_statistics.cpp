#include "../include/measures_statistics.hpp"

#include <cassert>
#include <cmath>
#include <optional>
#include <print>
#include <vector>

namespace
{
constexpr double tolerance{1e-9};

bool nearEqual(const double actual, const double expected)
{
    return std::abs(actual - expected) < tolerance;
}

void expectValue(
    const std::optional<double>& actual,
    const double expected)
{
    // Vérifier l'optional avant de le déréférencer
    assert(actual.has_value());
    assert(nearEqual(*actual, expected));
}

void testEmptyMeasures()
{
    const std::vector<double> measures{};

    assert(!getMax(measures).has_value());
    assert(!getMin(measures).has_value());
    assert(!getAverage(measures).has_value());
}

void testSingleMeasure()
{
    const std::vector<double> measures{42.5};

    expectValue(getMax(measures), 42.5);
    expectValue(getMin(measures), 42.5);
    expectValue(getAverage(measures), 42.5);
}

void testPositiveMeasures()
{
    const std::vector<double> measures{
        12.5,
        15.0,
        9.8,
        20.1,
        18.3
    };

    expectValue(getMax(measures), 20.1);
    expectValue(getMin(measures), 9.8);
    expectValue(getAverage(measures), 15.14);
}

void testNegativeMeasures()
{
    const std::vector<double> measures{
        -12.5,
        -3.0,
        -40.0,
        -3.0
    };

    expectValue(getMax(measures), -3.0);
    expectValue(getMin(measures), -40.0);
    expectValue(getAverage(measures), -14.625);
}

void testMixedMeasures()
{
    const std::vector<double> measures{
        -10.0,
        0.0,
        10.0
    };

    expectValue(getMax(measures), 10.0);
    expectValue(getMin(measures), -10.0);
    expectValue(getAverage(measures), 0.0);
}

void testIdenticalMeasures()
{
    const std::vector<double> measures{
        5.0,
        5.0,
        5.0
    };

    expectValue(getMax(measures), 5.0);
    expectValue(getMin(measures), 5.0);
    expectValue(getAverage(measures), 5.0);
}
}

int main()
{
    testEmptyMeasures();
    testSingleMeasure();
    testPositiveMeasures();
    testNegativeMeasures();
    testMixedMeasures();
    testIdenticalMeasures();

    std::println("All measures statistics tests passed.");
    return 0;
}