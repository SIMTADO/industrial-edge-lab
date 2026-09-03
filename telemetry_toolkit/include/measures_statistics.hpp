#pragma once
#include <vector>
#include <optional>

[[nodiscard]] std::optional<double> getMax(const std::vector<double>& measures) noexcept;
[[nodiscard]] std::optional<double> getMin(const std::vector<double>& measures) noexcept;
[[nodiscard]] std::optional<double> getAverage(const std::vector<double>& measures) noexcept;