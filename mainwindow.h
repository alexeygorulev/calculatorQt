#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <calculator.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void SetValue(char value);
    void SetOperator(Operation operation);
    QString GetCurrentFormulaValue();
    QString FormatDouble(double number);
    void ResetFormulaLabel();
    QString operationToString(Operation op);
    void SetOperationHelper(Operation operation);
private slots:
    void on_pb_eight_clicked();

    void on_pb_zero_clicked();

    void on_pb_one_clicked();

    void on_pb_two_clicked();

    void on_pb_three_clicked();

    void on_pb_four_clicked();

    void on_pb_five_clicked();

    void on_pb_six_clicked();

    void on_pb_seven_clicked();

    void on_pb_nine_clicked();

    void on_pb_point_clicked();

    void on_pb_clear_clicked();

    void on_pb_plus_minus_clicked();

    void on_pb_memory_clean_clicked();

    void on_pb_memory_output_clicked();

    void on_pb_memory_save_clicked();

    void on_pb_pow_clicked();

    void on_pb_division_clicked();

    void on_pb_minus_clicked();

    void on_pb_plus_clicked();

    void on_pb_result_clicked();

    void on_pb_multiplication_clicked();

    void on_pb_backspace_clicked();

private:
    Ui::MainWindow *ui;
    Calculator calculator_;
    QString input_number_;
    Operation current_operation_{Operation::NO_OPERATION};
    double active_number_{0.0};
    double cashed_active_number_{0.0};
    double memory_cell_;
    bool memory_saved_;
    bool isResetResult;
};
#endif // MAINWINDOW_H
