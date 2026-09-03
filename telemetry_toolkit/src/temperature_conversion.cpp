/* Converting temperature from Celsuis/Fahreint*/
#include "../include/temperature_conversion.hpp"

double celsiusToFahrenheit(const double celsuis_temp) noexcept {
    return celsuis_temp*9.0/5.0+32;
}

double fahrenheitToCelsius(const double fahrenheit_temp) noexcept {
    return (fahrenheit_temp-32)*5.0/9.0;
}