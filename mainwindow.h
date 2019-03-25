#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <math.h>
#include <QKeyEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_P0_clicked();

    void on_P1_clicked();

    void on_P2_clicked();

    void on_P3_clicked();

    void on_P4_clicked();

    void on_P5_clicked();

    void on_P6_clicked();

    void on_P7_clicked();

    void on_P8_clicked();

    void on_P9_clicked();

    void on_P_Point_clicked();

    void on_P_Equal_clicked();

    void on_P_Plus_clicked();

    void on_P_Minus_clicked();

    void on_P_Divide_clicked();

    void on_P_Multiply_clicked();

    void on_P_Exponent_clicked();

    void on_P_Root_clicked();

    void on_P_Backspace_clicked();

    void on_P_RM_clicked();

    void on_P_M_clicked();

    void on_P_C_clicked();

private:
    Ui::MainWindow *ui;

    enum operation
    {
        plus,
        minus,
        divide,
        multiply,
        exponent,
        noOperation
    };

    double firstNumber;
    double secondNumber;
    bool isFirstNumber;
    bool isSecondNumber;
    int option;
    double memory;
    bool isPoint;
    bool ScreenClear;

    void addToScreen(QString text);

    void defaultValues();

    void optionClicked();

    void result();

    void showResult(QString val);

    void keyReleaseEvent(QKeyEvent *e);
};

#endif // MAINWINDOW_H
