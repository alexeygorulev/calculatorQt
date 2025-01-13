#pragma once

#include "enums.h"
#include <QMainWindow>
#include <functional>
#include <optional>
#include <string>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void SetInputText(const std::string &text);
    void SetErrorText(const std::string &text);
    void SetFormulaText(const std::string &text);
    void SetMemText(const std::string &text);
    void SetExtraKey(const std::optional<std::string> &key);

    void SetDigitKeyCallback(const std::function<void(int key)> &callback);
    void SetProcessOperationKeyCallback(const std::function<void(Operation key)> &callback);
    void SetProcessControlKeyCallback(const std::function<void(ControlKey key)> &callback);
    void SetControllerCallback(const std::function<void(ControllerType controller)> &callback);

private slots:
    void HandleDigitKeyClick(int digit);
    void HandleControlKeyClick(ControlKey key);
    void HandleOperationKeyClick(Operation key);
    void on_cmb_controller_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui_;

    std::function<void(int)> digit_key_callback_;
    std::function<void(Operation)> operation_key_callback_;
    std::function<void(ControlKey)> control_key_callback_;
    std::function<void(ControllerType)> controller_callback_;
};
