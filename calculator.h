#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <string>
#include <QMainWindow>


using Number = double;

enum class Operation {
    NO_OPERATION,
    ADDITION,
    SUBTRACTION,
    MULTIPLICATION,
    DIVISION,
    POWER
};

class Calculator {
private:
    Number cashed_number_{0};
    Number result_{0};
    bool has_memory_ = false;
    Operation current_operation_{Operation::NO_OPERATION};

public:
    Calculator() = default;

    void Set(Number n);
    Number GetNumber() const;
    void Add(Number n);
    void Sub(Number n);
    void Div(Number n);
    void Mul(Number n);
    void Pow(Number n);
    void Save();
    void Load();
    bool HasMem() const;
    std::string GetNumberRepr() const;
    QString MultiplyStrings(const QString &num1, const QString &num2);
    QString Power(const QString &base, int exponent);
};

#endif // CALCULATOR_H
