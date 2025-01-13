#pragma once

#include "pow.h"
#include "rational.h"
#include <cmath>
#include <limits>
#include <optional>
#include <string>
#include <type_traits>

using Error = std::string;

template <typename T>
class Calculator {
public:
    std::optional<Error> Add(const T &value) {
        result_ += value;
        return std::nullopt;
    }

    std::optional<Error> Sub(const T &value) {
        result_ -= value;
        return std::nullopt;
    }

    std::optional<Error> Div(const T &value) {
        if constexpr (std::is_floating_point_v<T>) {
            if (value == 0) {
                result_ = HandleFloatingPointDivisionByZero(value);
            } else {
                result_ /= value;
            }
            return std::nullopt;
        } else if constexpr (std::is_same_v<T, Rational>) {
            if (value == Rational(0)) {
                return Error{"Division by zero"};
            }
            result_ /= value;
            return std::nullopt;
        } else {
            if (value == 0) {
                return Error{"Division by zero"};
            }
            result_ /= value;
            return std::nullopt;
        }
    }

    std::optional<Error> Mul(const T &value) {
        result_ *= value;
        return std::nullopt;
    }

    std::optional<Error> Pow(const T &exponent) {
        if (result_ == 0 && exponent == 0) {
            return Error{"Zero power to zero"};
        }

        if constexpr (std::is_floating_point_v<T>) {
            result_ = std::pow(result_, exponent);
        } else if constexpr (std::is_same_v<T, Rational>) {
            if (exponent.GetDenominator() != 1) {
                return Error{"Fractional power is not supported"};
            }
            result_ = PowExternal(result_, exponent);
        } else if constexpr (std::is_integral_v<T>) {
            if (exponent < 0) {
                return Error{"Integer negative power"};
            }
            result_ = IntegerPow(result_, exponent);
        } else {
            return Error{"Unsupported type for exponentiation"};
        }

        return std::nullopt;
    }

    void Set(const T &value) {
        result_ = value;
    }

    bool HasMemory() const {
        return mem_.has_value();
    }

    T GetNumber() const {
        return result_;
    }

    void Save() {
        mem_ = result_;
    }

    void Load() {
        if (mem_.has_value()) {
            result_ = mem_.value();
        }
    }

    bool GetHasMem() { return mem_.has_value(); };

private:
    T HandleFloatingPointDivisionByZero(const T &value) const {
        if (std::signbit(value)) {
            return result_ > 0 ? -std::numeric_limits<T>::infinity() :
                       result_ < 0 ? std::numeric_limits<T>::infinity() :
                       std::numeric_limits<T>::quiet_NaN();
        } else {
            return result_ > 0 ? std::numeric_limits<T>::infinity() :
                       result_ < 0 ? -std::numeric_limits<T>::infinity() :
                       std::numeric_limits<T>::quiet_NaN();
        }
    }

    std::optional<T> mem_;
    T result_ = {};
};
