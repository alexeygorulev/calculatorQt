#pragma once
#include <numeric>
#include <compare>
#include <iostream>
#include <istream>

class Rational {
public:
    Rational(): numerator_(0), denominator_(1) {
        };

     Rational(const int numerator): numerator_(numerator), denominator_(1) {
        Reduction();
    }

 Rational(const Rational&) = default;

    Rational(const int numerator, const int denominator_): numerator_(numerator), denominator_(denominator_) {
        Reduction();
    }

    [[nodiscard]] int GetNumerator() const { return numerator_; }
    [[nodiscard]] int GetDenominator() const { return denominator_; }

    [[nodiscard]] Rational Inv() const {
        return {denominator_, numerator_};
    }

    friend std::istream &operator>>(std::istream &is, Rational &r);

    friend std::ostream &operator<<(std::ostream &os, const Rational &r);

    void Reduction() {
        if (denominator_ < 0) {
            numerator_ = -numerator_;
            denominator_ = -denominator_;
        }
        const int divisor = std::gcd(numerator_, denominator_);
        numerator_ /= divisor;
        denominator_ /= divisor;
    }


    Rational operator+(const Rational &r) const {
        const int new_numerator = numerator_ * r.denominator_ + denominator_ * r.numerator_;
        const int new_denominator = denominator_ * r.denominator_;
        Rational result(new_numerator, new_denominator);
        result.Reduction();
        return result;
    }

    Rational operator-(const Rational &r) const {
        int new_numerator = numerator_ * r.denominator_ - denominator_ * r.numerator_;
        int new_denominator = denominator_ * r.denominator_;
        Rational result(new_numerator, new_denominator);
        result.Reduction();
        return result;
    }


    Rational operator*(const Rational &r) const {
        int new_numerator = numerator_ * r.numerator_;
        int new_denominator = denominator_ * r.denominator_;
        Rational result(new_numerator, new_denominator);
        result.Reduction();
        return result;
    }

    Rational operator/(const Rational &r) const {
        int new_numerator = numerator_ * r.denominator_;
        int new_denominator = denominator_ * r.numerator_;
        Rational result(new_numerator, new_denominator);
        result.Reduction();
        return result;
    }

    Rational &operator+=(const Rational &r) {
        numerator_ = numerator_ * r.denominator_ + denominator_ * r.numerator_;
        denominator_ = denominator_ * r.denominator_;
        Reduction();
        return *this;
    }

    Rational &operator-=(const Rational &r) {
        numerator_ = numerator_ * r.denominator_ - denominator_ * r.numerator_;
        denominator_ = denominator_ * r.denominator_;
        Reduction();
        return *this;
    }

    Rational &operator*=(const Rational &r) {
        numerator_ *= r.numerator_;
        denominator_ *= r.denominator_;
        Reduction();
        return *this;
    }

    Rational &operator/=(const Rational &r) {
        numerator_ *= r.denominator_;
        denominator_ *= r.numerator_;
        Reduction();
        return *this;
    }

    Rational operator-() const {
        return {-numerator_, denominator_};
    }

    Rational operator+() const {
        return {numerator_, denominator_};
    }

    Rational &operator=(const Rational &r) {
        numerator_ = r.numerator_;
        denominator_ = r.denominator_;
        Reduction();
        return *this;
    };

    bool operator==(const Rational &r) const = default;

private:
    int numerator_ = 0;
    int denominator_ = 1;
};

inline std::istream &operator>>(std::istream &is, Rational &r) {
    int n, d;
    char div;

    if (!(is >> n)) {
        return is;
    }

    if (!(is >> std::ws >> div)) {
        r = Rational(n, 1);
        is.clear();
        return is;
    }

    if (div != '/') {
        r = Rational(n, 1);
        is.unget();
        return is;
    }

    if (!(is >> d) || (d == 0)) {
        is.setstate(std::ios::failbit);
        return is;
    }

    r = Rational(n, d);

    return is;
}

inline std::ostream &operator<<(std::ostream &os, const Rational &r) {
    if (r.GetDenominator() == 1) {
        os << r.GetNumerator();
    } else {
        os << r.GetNumerator() << " / " << r.GetDenominator();
    }
    return os;
}

inline auto operator<=>(const Rational &lhs, const Rational &rhs) {
    return lhs.GetNumerator() * rhs.GetDenominator() <=> lhs.GetDenominator() * rhs.GetNumerator();
}
