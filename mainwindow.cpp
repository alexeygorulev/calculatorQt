#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::SetValue(char value) {
    QString active_number_label = ui->l_result->text();

    if (ui->l_formula->text().contains("=")) {
        ui->l_formula->setText("");
        calculator_.Set(0);
        active_number_ = 0;
    }

    if (value == '.') {
        if (active_number_label.contains('.') && !isResetResult) {
            return;
        } else if (active_number_label.isEmpty() || active_number_ == 0 ||
                   isResetResult) {
            active_number_label = "0.";
            ui->l_result->setText(active_number_label);
            isResetResult = false;
            return;
        } else {
            ui->l_result->setText(active_number_label + QString(QChar(value)));
            return;
        }
    }
    bool isDouble = false;
    if ((active_number_ == 0 && !active_number_label.contains('.')) ||
        isResetResult) {

        active_number_label = QString(QChar(value));
        isResetResult = false;
    } else {

        active_number_label += QString(QChar(value));
    }

    double number = active_number_label.toDouble(&isDouble);

    if (isDouble) {
        active_number_ = number;
        ui->l_result->setText(active_number_label);
    } else {
        active_number_ = 0.0;
    }
}

void MainWindow::SetOperationHelper(Operation operation) {
    input_number_ =
        FormatDouble(calculator_.GetNumber()) + operationToString(operation);
    current_operation_ = operation;
    ui->l_formula->setText(input_number_);
}

void MainWindow::SetOperator(Operation operation) {
    if (current_operation_ != Operation::NO_OPERATION) {
        SetOperationHelper(operation);
        return;
    }

    calculator_.Set(active_number_);
    SetOperationHelper(operation);

    ui->l_result->setText(FormatDouble(calculator_.GetNumber()));
    active_number_ = 0;
    isResetResult = true;
}

QString MainWindow::GetCurrentFormulaValue() { return input_number_; }

void MainWindow::on_pb_zero_clicked() { SetValue('0'); }

void MainWindow::on_pb_one_clicked() { SetValue('1'); }

void MainWindow::on_pb_two_clicked() { SetValue('2'); }

void MainWindow::on_pb_three_clicked() { SetValue('3'); }

void MainWindow::on_pb_four_clicked() { SetValue('4'); }

void MainWindow::on_pb_five_clicked() { SetValue('5'); }

void MainWindow::on_pb_six_clicked() { SetValue('6'); }

void MainWindow::on_pb_seven_clicked() { SetValue('7'); }

void MainWindow::on_pb_eight_clicked() { SetValue('8'); }

void MainWindow::on_pb_nine_clicked() { SetValue('9'); }

void MainWindow::on_pb_point_clicked() { SetValue('.'); }

void MainWindow::on_pb_backspace_clicked() {
    QString current_formula = ui->l_formula->text();
    QString current_active_value = ui->l_result->text();

    if (current_formula.contains("=")) {
        return;
    }

    if (!current_active_value.isEmpty()) {
        current_active_value.chop(1);
        ui->l_result->setText(current_active_value);
        active_number_ = current_active_value.toDouble();
    } else {
    }
}

void MainWindow::on_pb_clear_clicked() {
    active_number_ = 0;
    calculator_.Set(0);
    ui->l_formula->setText("");
    ui->l_result->setText("0");
    current_operation_ = Operation::NO_OPERATION;
}

void MainWindow::on_pb_plus_minus_clicked() {

    QString current_text = ui->l_result->text();
    double current_number = calculator_.GetNumber();

    if (std::isnan(current_number) || std::isinf(current_number)) {
        return;
    }


    if (current_text.startsWith("-")) {

        current_text.remove(0, 1);
    } else if (current_text != "0") {

        current_text = "-" + current_text;
    }

    ui->l_result->setText(current_text);

    bool isDouble = false;
    double number = current_text.toDouble(&isDouble);

    if (isDouble) {
        active_number_ = number;
        calculator_.Set(active_number_);
    } else {
        active_number_ = 0.0;
    }
}

void MainWindow::on_pb_memory_clean_clicked() {
    cashed_active_number_ = 0;
    ui->l_memory->setText("");
}

void MainWindow::on_pb_memory_output_clicked() {
    active_number_ = cashed_active_number_;
    calculator_.Set(active_number_);
    ui->l_result->setText(FormatDouble(active_number_));
}

void MainWindow::on_pb_memory_save_clicked() {
    cashed_active_number_ = active_number_;
    ui->l_memory->setText("M");
}

void MainWindow::on_pb_pow_clicked() { SetOperator(Operation::POWER); }

void MainWindow::on_pb_division_clicked() { SetOperator(Operation::DIVISION); }

void MainWindow::on_pb_multiplication_clicked() {
    SetOperator(Operation::MULTIPLICATION);
}

void MainWindow::on_pb_minus_clicked() { SetOperator(Operation::SUBTRACTION); }

void MainWindow::on_pb_plus_clicked() { SetOperator(Operation::ADDITION); }

void MainWindow::on_pb_result_clicked() {
    Number currentValue = ui->l_result->text().toDouble();
    switch (current_operation_) {
    case Operation::ADDITION:

        calculator_.Add(currentValue);
        break;
    case Operation::DIVISION:
        calculator_.Div(currentValue);
        break;
    case Operation::MULTIPLICATION:
        calculator_.Mul(currentValue);
        break;
    case Operation::NO_OPERATION:
        return;
    case Operation::POWER:
        calculator_.Pow(currentValue);
        break;
    case Operation::SUBTRACTION:
        calculator_.Sub(currentValue);
        break;
    default:
        return;
    }

    current_operation_ = Operation::NO_OPERATION;

    ui->l_formula->setText(input_number_ + " " + FormatDouble(currentValue) +
                           " = ");
    ui->l_result->setText(FormatDouble(calculator_.GetNumber()));
    active_number_ = calculator_.GetNumber();
    input_number_ = FormatDouble(calculator_.GetNumber());
}

QString MainWindow::FormatDouble(double number) {

    return QString::number(number);
}

void MainWindow::ResetFormulaLabel() {}

QString MainWindow::operationToString(Operation op) {

    switch (op) {
    case Operation::ADDITION:

        return " + ";
    case Operation::SUBTRACTION:
        return " - ";
    case Operation::MULTIPLICATION:
        return " * ";
    case Operation::DIVISION:
        return " ÷ ";
    case Operation::POWER:
        return " ^ ";
    default:
        return "";
    }
}
