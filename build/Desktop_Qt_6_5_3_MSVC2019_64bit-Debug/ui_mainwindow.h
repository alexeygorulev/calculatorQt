/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QPushButton *pb_zero;
    QPushButton *pb_plus;
    QPushButton *pb_one;
    QPushButton *pb_result;
    QPushButton *pb_three;
    QPushButton *pb_pow;
    QPushButton *pb_minus;
    QPushButton *pb_multiplication;
    QPushButton *pb_seven;
    QPushButton *pb_nine;
    QPushButton *pb_memory_save;
    QPushButton *pb_two;
    QPushButton *pb_memory_clean;
    QPushButton *pb_memory_output;
    QPushButton *pb_eight;
    QHBoxLayout *horizontalLayout;
    QLabel *l_memory;
    QLabel *l_result;
    QPushButton *pb_backspace;
    QPushButton *pb_four;
    QPushButton *pb_plus_minus;
    QPushButton *pb_five;
    QPushButton *pb_six;
    QPushButton *pb_division;
    QLabel *l_formula;
    QPushButton *pb_point;
    QPushButton *pb_clear;
    QLabel *label_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(528, 618);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setHorizontalSpacing(20);
        pb_zero = new QPushButton(centralwidget);
        pb_zero->setObjectName("pb_zero");
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pb_zero->sizePolicy().hasHeightForWidth());
        pb_zero->setSizePolicy(sizePolicy);
        pb_zero->setMinimumSize(QSize(0, 40));

        gridLayout->addWidget(pb_zero, 7, 1, 1, 1);

        pb_plus = new QPushButton(centralwidget);
        pb_plus->setObjectName("pb_plus");
        sizePolicy.setHeightForWidth(pb_plus->sizePolicy().hasHeightForWidth());
        pb_plus->setSizePolicy(sizePolicy);
        pb_plus->setMinimumSize(QSize(0, 40));

        gridLayout->addWidget(pb_plus, 6, 4, 1, 1);

        pb_one = new QPushButton(centralwidget);
        pb_one->setObjectName("pb_one");
        sizePolicy.setHeightForWidth(pb_one->sizePolicy().hasHeightForWidth());
        pb_one->setSizePolicy(sizePolicy);
        pb_one->setMinimumSize(QSize(0, 40));

        gridLayout->addWidget(pb_one, 6, 0, 1, 1);

        pb_result = new QPushButton(centralwidget);
        pb_result->setObjectName("pb_result");
        sizePolicy.setHeightForWidth(pb_result->sizePolicy().hasHeightForWidth());
        pb_result->setSizePolicy(sizePolicy);
        pb_result->setMinimumSize(QSize(0, 40));

        gridLayout->addWidget(pb_result, 7, 4, 1, 1);

        pb_three = new QPushButton(centralwidget);
        pb_three->setObjectName("pb_three");
        sizePolicy.setHeightForWidth(pb_three->sizePolicy().hasHeightForWidth());
        pb_three->setSizePolicy(sizePolicy);
        pb_three->setMinimumSize(QSize(0, 40));

        gridLayout->addWidget(pb_three, 6, 2, 1, 1);

        pb_pow = new QPushButton(centralwidget);
        pb_pow->setObjectName("pb_pow");
        sizePolicy.setHeightForWidth(pb_pow->sizePolicy().hasHeightForWidth());
        pb_pow->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pb_pow, 2, 4, 1, 1);

        pb_minus = new QPushButton(centralwidget);
        pb_minus->setObjectName("pb_minus");
        sizePolicy.setHeightForWidth(pb_minus->sizePolicy().hasHeightForWidth());
        pb_minus->setSizePolicy(sizePolicy);
        pb_minus->setMinimumSize(QSize(0, 40));

        gridLayout->addWidget(pb_minus, 5, 4, 1, 1);

        pb_multiplication = new QPushButton(centralwidget);
        pb_multiplication->setObjectName("pb_multiplication");
        sizePolicy.setHeightForWidth(pb_multiplication->sizePolicy().hasHeightForWidth());
        pb_multiplication->setSizePolicy(sizePolicy);
        pb_multiplication->setMinimumSize(QSize(0, 40));

        gridLayout->addWidget(pb_multiplication, 4, 4, 1, 1);

        pb_seven = new QPushButton(centralwidget);
        pb_seven->setObjectName("pb_seven");
        sizePolicy.setHeightForWidth(pb_seven->sizePolicy().hasHeightForWidth());
        pb_seven->setSizePolicy(sizePolicy);
        pb_seven->setMinimumSize(QSize(0, 40));

        gridLayout->addWidget(pb_seven, 4, 0, 1, 1);

        pb_nine = new QPushButton(centralwidget);
        pb_nine->setObjectName("pb_nine");
        sizePolicy.setHeightForWidth(pb_nine->sizePolicy().hasHeightForWidth());
        pb_nine->setSizePolicy(sizePolicy);
        pb_nine->setMinimumSize(QSize(0, 40));

        gridLayout->addWidget(pb_nine, 4, 2, 1, 1);

        pb_memory_save = new QPushButton(centralwidget);
        pb_memory_save->setObjectName("pb_memory_save");
        sizePolicy.setHeightForWidth(pb_memory_save->sizePolicy().hasHeightForWidth());
        pb_memory_save->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pb_memory_save, 2, 2, 1, 1);

        pb_two = new QPushButton(centralwidget);
        pb_two->setObjectName("pb_two");
        sizePolicy.setHeightForWidth(pb_two->sizePolicy().hasHeightForWidth());
        pb_two->setSizePolicy(sizePolicy);
        pb_two->setMinimumSize(QSize(0, 40));

        gridLayout->addWidget(pb_two, 6, 1, 1, 1);

        pb_memory_clean = new QPushButton(centralwidget);
        pb_memory_clean->setObjectName("pb_memory_clean");
        sizePolicy.setHeightForWidth(pb_memory_clean->sizePolicy().hasHeightForWidth());
        pb_memory_clean->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pb_memory_clean, 2, 0, 1, 1);

        pb_memory_output = new QPushButton(centralwidget);
        pb_memory_output->setObjectName("pb_memory_output");
        sizePolicy.setHeightForWidth(pb_memory_output->sizePolicy().hasHeightForWidth());
        pb_memory_output->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pb_memory_output, 2, 1, 1, 1);

        pb_eight = new QPushButton(centralwidget);
        pb_eight->setObjectName("pb_eight");
        sizePolicy.setHeightForWidth(pb_eight->sizePolicy().hasHeightForWidth());
        pb_eight->setSizePolicy(sizePolicy);
        pb_eight->setMinimumSize(QSize(0, 40));

        gridLayout->addWidget(pb_eight, 4, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        l_memory = new QLabel(centralwidget);
        l_memory->setObjectName("l_memory");

        horizontalLayout->addWidget(l_memory);

        l_result = new QLabel(centralwidget);
        l_result->setObjectName("l_result");
        l_result->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(l_result);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 5);

        pb_backspace = new QPushButton(centralwidget);
        pb_backspace->setObjectName("pb_backspace");
        sizePolicy.setHeightForWidth(pb_backspace->sizePolicy().hasHeightForWidth());
        pb_backspace->setSizePolicy(sizePolicy);
        pb_backspace->setMinimumSize(QSize(0, 40));

        gridLayout->addWidget(pb_backspace, 7, 2, 1, 1);

        pb_four = new QPushButton(centralwidget);
        pb_four->setObjectName("pb_four");
        sizePolicy.setHeightForWidth(pb_four->sizePolicy().hasHeightForWidth());
        pb_four->setSizePolicy(sizePolicy);
        pb_four->setMinimumSize(QSize(0, 40));

        gridLayout->addWidget(pb_four, 5, 0, 1, 1);

        pb_plus_minus = new QPushButton(centralwidget);
        pb_plus_minus->setObjectName("pb_plus_minus");
        sizePolicy.setHeightForWidth(pb_plus_minus->sizePolicy().hasHeightForWidth());
        pb_plus_minus->setSizePolicy(sizePolicy);
        pb_plus_minus->setMinimumSize(QSize(0, 40));

        gridLayout->addWidget(pb_plus_minus, 3, 2, 1, 1);

        pb_five = new QPushButton(centralwidget);
        pb_five->setObjectName("pb_five");
        sizePolicy.setHeightForWidth(pb_five->sizePolicy().hasHeightForWidth());
        pb_five->setSizePolicy(sizePolicy);
        pb_five->setMinimumSize(QSize(0, 40));

        gridLayout->addWidget(pb_five, 5, 1, 1, 1);

        pb_six = new QPushButton(centralwidget);
        pb_six->setObjectName("pb_six");
        sizePolicy.setHeightForWidth(pb_six->sizePolicy().hasHeightForWidth());
        pb_six->setSizePolicy(sizePolicy);
        pb_six->setMinimumSize(QSize(0, 40));

        gridLayout->addWidget(pb_six, 5, 2, 1, 1);

        pb_division = new QPushButton(centralwidget);
        pb_division->setObjectName("pb_division");
        sizePolicy.setHeightForWidth(pb_division->sizePolicy().hasHeightForWidth());
        pb_division->setSizePolicy(sizePolicy);
        pb_division->setMinimumSize(QSize(0, 40));

        gridLayout->addWidget(pb_division, 3, 4, 1, 1);

        l_formula = new QLabel(centralwidget);
        l_formula->setObjectName("l_formula");
        l_formula->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(l_formula, 0, 0, 1, 5);

        pb_point = new QPushButton(centralwidget);
        pb_point->setObjectName("pb_point");
        sizePolicy.setHeightForWidth(pb_point->sizePolicy().hasHeightForWidth());
        pb_point->setSizePolicy(sizePolicy);
        pb_point->setMinimumSize(QSize(0, 40));

        gridLayout->addWidget(pb_point, 7, 0, 1, 1);

        pb_clear = new QPushButton(centralwidget);
        pb_clear->setObjectName("pb_clear");
        sizePolicy.setHeightForWidth(pb_clear->sizePolicy().hasHeightForWidth());
        pb_clear->setSizePolicy(sizePolicy);
        pb_clear->setMinimumSize(QSize(0, 40));

        gridLayout->addWidget(pb_clear, 3, 0, 1, 2);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);
        label_4->setMinimumSize(QSize(20, 0));
        label_4->setMaximumSize(QSize(20, 16777215));

        gridLayout->addWidget(label_4, 2, 3, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 528, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pb_zero->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pb_plus->setText(QCoreApplication::translate("MainWindow", "+	", nullptr));
        pb_one->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        pb_result->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        pb_three->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        pb_pow->setText(QCoreApplication::translate("MainWindow", "x\312\270", nullptr));
        pb_minus->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        pb_multiplication->setText(QCoreApplication::translate("MainWindow", "\303\227	", nullptr));
        pb_seven->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        pb_nine->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        pb_memory_save->setText(QCoreApplication::translate("MainWindow", "MS", nullptr));
        pb_two->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        pb_memory_clean->setText(QCoreApplication::translate("MainWindow", "MC", nullptr));
        pb_memory_output->setText(QCoreApplication::translate("MainWindow", "MR", nullptr));
        pb_eight->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        l_memory->setText(QCoreApplication::translate("MainWindow", "l_memory", nullptr));
        l_result->setText(QString());
        pb_backspace->setText(QCoreApplication::translate("MainWindow", "\342\214\253", nullptr));
        pb_four->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        pb_plus_minus->setText(QCoreApplication::translate("MainWindow", "\302\261", nullptr));
        pb_five->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        pb_six->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        pb_division->setText(QCoreApplication::translate("MainWindow", "\303\267", nullptr));
        l_formula->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pb_point->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        pb_clear->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
        label_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
