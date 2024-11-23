#include <calculator.h>

#include <cmath>           // Для функции pow и константы INFINITY
#include <string>          // Для std::string
#include <sstream>         // Для std::ostringstream
#include <iomanip>         // Для std::fixed и std::setprecision
#include "calculator.h"



void Calculator::Set(Number n) {
    result_ = n;
}

Number Calculator::GetNumber() const {
    return result_;
}

void Calculator::Add(Number n) {
    result_ += n;
}

void Calculator::Sub(Number n) {
    result_ -= n;
}

void Calculator::Div(Number n) {
    if (n != 0) {
        result_ /= n;
    } else {
        if (std::signbit(n)) {
            if (result_ > 0) {
                result_ = -INFINITY;
            } else if (result_ < 0) {
                result_ = INFINITY;
            } else {
                result_ = std::numeric_limits<Number>::quiet_NaN();
            }
        } else {
            if (result_ > 0) {
                result_ = INFINITY;
            } else if (result_ < 0) {
                result_ = -INFINITY;
            } else {
                result_ = std::numeric_limits<Number>::quiet_NaN();
            }
        }
    }
}

void Calculator::Mul(Number n) {
    result_ *= n;
}

void Calculator::Pow(Number n) {

    if (result_ == 0 && n == 0) {
        result_ = 1;

    } else {
        result_ = std::pow(result_, n);

        if (std::isnan(result_)) {
            result_ = std::numeric_limits<Number>::quiet_NaN();
        }
    }
}
void Calculator::Save() {
    cashed_number_ = result_;
    has_memory_ = true;
}

void Calculator::Load() {
    if (has_memory_) {
        result_ = cashed_number_;
    }
}

bool Calculator::HasMem() const {
    return has_memory_;
}

std::string Calculator::GetNumberRepr() const {
    if (std::isnan(result_)) {
        return "nan";
    }
    if (std::isinf(result_)) {
        if (result_ > 0) {
            return "inf";
        } else {
            return "-inf";
        }
    }
    std::ostringstream oss;
    oss << std::fixed << std::showpoint << std::setprecision(6) << result_;
    return oss.str();
}
