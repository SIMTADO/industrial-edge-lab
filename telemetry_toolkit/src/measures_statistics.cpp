#include "../include/measures_statistics.hpp"
#include <optional>
#include <print>

std::optional<double> getMax(const std::vector<double> &measures) noexcept {

    if(measures.empty()) {
        return std::nullopt;
    }

    double max{measures.front()}; // intialise max to the first item of the vector

    for(const double measure:measures){
        if (measure>max) 
            max=measure;
    }
    return max;
}

std::optional<double> getMin(const std::vector<double> &measures) noexcept {

    if(measures.empty()) {
        return std::nullopt;
    }

    double min{measures.front()}; // intialise min to the first item of the vector

    for(const double measure:measures){
        if (measure<min) 
            min=measure;
    }
    return min;
}

std::optional<double> getAverage(const std::vector<double> &measures) noexcept {

    if(measures.empty()) {
        return std::nullopt;
    }

    double sum{0.0};

    for(const double measure:measures){
        sum+=measure;
    }
    return sum/measures.size();
}