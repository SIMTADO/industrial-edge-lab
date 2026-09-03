#include "../include/temperature_conversion.hpp"
#include <cassert>
#include <cmath>
#include <print>

namespace temperature_conversion {
    constexpr double EPSILON{1e-6}; // For double comparison, a small value to account for floating-point precision errors

    bool nearEqual(const double actual, const double expected) {
        return std::abs(actual - expected) < EPSILON;
    }

    void testCelsiusToFahrenheit(){
        assert(nearEqual(celsiusToFahrenheit(0.0), 32.0));
        assert(nearEqual(celsiusToFahrenheit(100.0), 212.0));
        assert(nearEqual(celsiusToFahrenheit(-40.0), -40.0));
    }

    void testFahrenheitToCelsius(){
        assert(nearEqual(fahrenheitToCelsius(32.0), 0.0));
        assert(nearEqual(fahrenheitToCelsius(212.0), 100.0));
        assert(nearEqual(fahrenheitToCelsius(-40.0), -40.0));
        // Failure test case to demonstrate assertion failure, uncomment the line below to see the failure
        // assert(nearEqual(fahrenheitToCelsius(100.0), 37.7778)); // This will fail, as 100°F is approximately 37.7778°C
    }

    void testRoundTrip(){
        constexpr double initialTemperature{23.5};

        const double fahrenheit{celsiusToFahrenheit(initialTemperature)};
        const double convertedBack{fahrenheitToCelsius(fahrenheit)};

        assert(nearEqual(convertedBack, initialTemperature));
    }

}

int main() {
    // Call all test functions
    using namespace temperature_conversion;
    testCelsiusToFahrenheit();  
    testFahrenheitToCelsius();
    testRoundTrip();

    std::println("All temperature conversion tests passed successfully.");

    return 0;
}