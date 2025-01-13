#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui_(new Ui::MainWindow) {
    ui_->setupUi(this);

    ui_->cmb_controller->addItem("double");
    ui_->cmb_controller->addItem("float");
    ui_->cmb_controller->addItem("uint8_t");
    ui_->cmb_controller->addItem("int");
    ui_->cmb_controller->addItem("int64_t");
    ui_->cmb_controller->addItem("size_t");
    ui_->cmb_controller->addItem("Rational");

    connect(ui_->pb_zero, &QPushButton::clicked, this, [this]() { HandleDigitKeyClick(0); });
    connect(ui_->pb_one, &QPushButton::clicked, this, [this]() { HandleDigitKeyClick(1); });
    connect(ui_->pb_two, &QPushButton::clicked, this, [this]() { HandleDigitKeyClick(2); });
    connect(ui_->pb_three, &QPushButton::clicked, this, [this]() { HandleDigitKeyClick(3); });
    connect(ui_->pb_four, &QPushButton::clicked, this, [this]() { HandleDigitKeyClick(4); });
    connect(ui_->pb_five, &QPushButton::clicked, this, [this]() { HandleDigitKeyClick(5); });
    connect(ui_->pb_six, &QPushButton::clicked, this, [this]() { HandleDigitKeyClick(6); });
    connect(ui_->pb_seven, &QPushButton::clicked, this, [this]() { HandleDigitKeyClick(7); });
    connect(ui_->pb_eight, &QPushButton::clicked, this, [this]() { HandleDigitKeyClick(8); });
    connect(ui_->pb_nine, &QPushButton::clicked, this, [this]() { HandleDigitKeyClick(9); });

    connect(ui_->tb_extra, &QPushButton::clicked, this, [this]() { control_key_callback_(ControlKey::EXTRA_KEY); });
    connect(ui_->pb_clear, &QPushButton::clicked, this, [this]() { control_key_callback_(ControlKey::CLEAR); });
    connect(ui_->pb_plus_minus, &QPushButton::clicked, this, [this]() { control_key_callback_(ControlKey::PLUS_MINUS); });
    connect(ui_->pb_memory_clean, &QPushButton::clicked, this, [this]() { control_key_callback_(ControlKey::MEM_CLEAR); });
    connect(ui_->pb_memory_output, &QPushButton::clicked, this, [this]() { control_key_callback_(ControlKey::MEM_LOAD); });
    connect(ui_->pb_memory_save, &QPushButton::clicked, this, [this]() { control_key_callback_(ControlKey::MEM_SAVE); });
    connect(ui_->pb_result, &QPushButton::clicked, this, [this]() { control_key_callback_(ControlKey::EQUALS); });
    connect(ui_->pb_backspace, &QPushButton::clicked, this, [this]() { control_key_callback_(ControlKey::BACKSPACE); });

    connect(ui_->pb_pow, &QPushButton::clicked, this, [this]() { operation_key_callback_(Operation::POWER); });
    connect(ui_->pb_division, &QPushButton::clicked, this, [this]() { operation_key_callback_(Operation::DIVISION); });
    connect(ui_->pb_minus, &QPushButton::clicked, this, [this]() { operation_key_callback_(Operation::SUBTRACTION); });
    connect(ui_->pb_plus, &QPushButton::clicked, this, [this]() { operation_key_callback_(Operation::ADDITION); });
    connect(ui_->pb_multiplication, &QPushButton::clicked, this, [this]() { operation_key_callback_(Operation::MULTIPLICATION); });

    connect(ui_->cmb_controller, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, [this](int index) { controller_callback_(static_cast<ControllerType>(index)); });
}

MainWindow::~MainWindow() {
    delete ui_;
}
void MainWindow::SetDigitKeyCallback(const std::function<void(int key)> &callback) {
    digit_key_callback_ = callback;
}

void MainWindow::SetProcessOperationKeyCallback(const std::function<void(Operation key)> &callback) {
    operation_key_callback_ = callback;
}

void MainWindow::SetProcessControlKeyCallback(const std::function<void(ControlKey key)> &callback) {
    control_key_callback_ = callback;
}

void MainWindow::SetControllerCallback(const std::function<void(ControllerType controller)> &callback) {
    controller_callback_ = callback;
}

void MainWindow::HandleDigitKeyClick(int digit) {
    if (digit_key_callback_) {
        digit_key_callback_(digit);
    }
}

void MainWindow::HandleControlKeyClick(ControlKey key) {
    if (control_key_callback_) {
        control_key_callback_(key);
    }
}

void MainWindow::HandleOperationKeyClick(Operation key) {
    if (operation_key_callback_) {
        operation_key_callback_(key);
    }
}

void MainWindow::on_cmb_controller_currentIndexChanged(int index) {
    if (controller_callback_) {
        controller_callback_(static_cast<ControllerType>(index));
    }
}

void MainWindow::SetInputText(const std::string &text) {
    ui_->l_result->setStyleSheet("");
    ui_->l_result->setText(QString::fromStdString(text));
}

void MainWindow::SetErrorText(const std::string &text) {
    ui_->l_result->setStyleSheet("color: red;");
    ui_->l_result->setText(QString::fromStdString(text));
}

void MainWindow::SetFormulaText(const std::string &text) {
    ui_->l_formula->setText(QString::fromStdString(text));
}

void MainWindow::SetMemText(const std::string &text) {
    ui_->l_memory->setText(QString::fromStdString(text));
}

void MainWindow::SetExtraKey(const std::optional<std::string> &key) {
    if (key.has_value()) {
        ui_->tb_extra->setText(QString::fromStdString(key.value()));
        ui_->tb_extra->show();
    } else {
        ui_->tb_extra->hide();
    }
}
