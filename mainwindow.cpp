#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    defaultValues();
    memory = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_P0_clicked()
{
    addToScreen("0");
}

void MainWindow::on_P1_clicked()
{
    addToScreen("1");
}

void MainWindow::on_P2_clicked()
{
    addToScreen("2");
}

void MainWindow::on_P3_clicked()
{
    addToScreen("3");
}

void MainWindow::on_P4_clicked()
{
    addToScreen("4");
}

void MainWindow::on_P5_clicked()
{
    addToScreen("5");
}

void MainWindow::on_P6_clicked()
{
    addToScreen("6");
}

void MainWindow::on_P7_clicked()
{
    addToScreen("7");
}

void MainWindow::on_P8_clicked()
{
    addToScreen("8");
}

void MainWindow::on_P9_clicked()
{
    addToScreen("9");
}

void MainWindow::on_P_Point_clicked()
{
    if(isPoint) return;
    isPoint = true;
    addToScreen(".");
    //ui->EScreen->setText(ui->EScreen->text().append("."));
}

void MainWindow::on_P_Equal_clicked()
{
    result();
}

void MainWindow::on_P_Plus_clicked()
{
    optionClicked();
    option = plus;
}

void MainWindow::on_P_Minus_clicked()
{
    optionClicked();
    option = minus;
}

void MainWindow::on_P_Divide_clicked()
{
    optionClicked();
    option = divide;
}

void MainWindow::on_P_Multiply_clicked()
{
    optionClicked();
    option = multiply;
}

void MainWindow::on_P_Exponent_clicked()
{
    optionClicked();
    option = exponent;
}

void MainWindow::on_P_Root_clicked()
{
    firstNumber = ui->EScreen->text().toDouble();

    if(firstNumber >= 0){
        QString equaling =  QString::number(sqrt(firstNumber), 'f', 10);
        showResult(equaling);
    }
    else
        ui->EScreen->setText("NUMBER < 0");
    ScreenClear = true;
}

void MainWindow::on_P_Backspace_clicked()
{
    QString back = ui->EScreen->text();
    if(back.at(back.length()-1) == ".") isPoint = false;

    if(back == "NUMBER = 0" || back == "NUMBER < 0" || back == "BIG NUMBER")
            return;

    back.remove(back.length()-1, 1);
    if(back.length() == 0)  ui->EScreen->setText("0");
    else                    ui->EScreen->setText(back);
}

void MainWindow::on_P_RM_clicked()
{
    ui->EScreen->setText(QString::number(memory));
}

void MainWindow::on_P_M_clicked()
{
    memory = ui->EScreen->text().toDouble();
}

void MainWindow::on_P_C_clicked()
{
    defaultValues();

    ui->EScreen->setText("0");
}

void MainWindow::addToScreen(QString text)
{
    QString oldText = ui->EScreen->text();

    if(ScreenClear)
    {
        oldText.clear();
        ScreenClear = false;
    }

    if(oldText.length() == 10 && isPoint == false)  return;
    if(oldText.length() == 11 && isPoint == true)   return;
    if(oldText.length() == 10 && text == ".") {
        isPoint = false;
        return;
    }
    if(oldText == "0")  oldText.clear();    

    oldText.append(text);
    ui->EScreen->setText(oldText);
}

void MainWindow::defaultValues()
{
    firstNumber = 0;
    secondNumber = 0;
    option = this->noOperation;
    isPoint = false;
    isFirstNumber = false;
    isSecondNumber = false;
    ScreenClear = false;
}

void MainWindow::optionClicked()
{
    result();

    if(!isFirstNumber)
    {
        firstNumber = ui->EScreen->text().toDouble();
        isFirstNumber = true;
        ScreenClear = true;
        isPoint = false;
    }
}

void MainWindow::result()
{
    if(!isFirstNumber) return;
    secondNumber = ui->EScreen->text().toDouble();
    double tmp = 0;
    bool divisionByZero = false;

    switch(option)
    {
    case plus:
        tmp = firstNumber + secondNumber;
        break;
    case minus:
        tmp = firstNumber - secondNumber;
        break;
    case multiply:
        tmp = firstNumber * secondNumber;
        break;
    case divide:
        if(secondNumber > 0 || secondNumber < 0)
            tmp = firstNumber / secondNumber;
        else
            divisionByZero = true;
        break;
    case exponent:
        tmp = pow(firstNumber, secondNumber);
        break;
    default:
        break;
    }

    QString equaling =  QString::number(tmp, 'f', 10);
    if(divisionByZero)      ui->EScreen->setText("NUMBER = 0");
    else if(tmp >= 10e9)    ui->EScreen->setText("BIG NUMBER");
    else                    showResult(equaling);

    ScreenClear = true;
    firstNumber = 0;
    secondNumber = 0;
    isFirstNumber = false;
    isSecondNumber = false;
    isPoint = false;
}

void MainWindow::showResult(QString val)
{
    if(val.length() > 11)
        val.remove(11, val.length()-11);
    while(val.at(val.length()-1) == "0" || val.at(val.length()-1) == ".")
        val.remove(val.length()-1,1);
    ui->EScreen->setText(val);
}

void MainWindow::keyReleaseEvent(QKeyEvent *e)
{
    switch (e->key())
    {
        case Qt::Key_0:
            on_P0_clicked();
            e->accept();
            break;
        case Qt::Key_1:
            on_P1_clicked();
            e->accept();
            break;
        case Qt::Key_2:
            on_P2_clicked();
            e->accept();
            break;
        case Qt::Key_3:
            on_P3_clicked();
            e->accept();
            break;
        case Qt::Key_4:
            on_P4_clicked();
            e->accept();
            break;
        case Qt::Key_5:
            on_P5_clicked();
            e->accept();
            break;
        case Qt::Key_6:
            on_P6_clicked();
            e->accept();
            break;
        case Qt::Key_7:
            on_P7_clicked();
            e->accept();
            break;
        case Qt::Key_8:
            on_P8_clicked();
            e->accept();
            break;
        case Qt::Key_9:
            on_P9_clicked();
            e->accept();
            break;
        case Qt::Key_Comma:
            on_P_Point_clicked();
            e->accept();
            break;
        case Qt::Key_Backspace:
            on_P_Backspace_clicked();
            e->accept();
            break;
        case Qt::Key_Plus:
            on_P_Plus_clicked();
            e->accept();
            break;
        case Qt::Key_Minus:
            on_P_Minus_clicked();
            e->accept();
            break;
        case Qt::Key_Asterisk:
            on_P_Multiply_clicked();
            e->accept();
            break;
        case Qt::Key_Slash:
            on_P_Divide_clicked();
            e->accept();
            break;
        case Qt::Key_Enter:
            on_P_Equal_clicked();
            e->accept();
            break;
        case Qt::Key_C:
            on_P_C_clicked();
            e->accept();
            break;
        case Qt::Key_M:
            on_P_M_clicked();
            e->accept();
            break;
        case Qt::Key_R:
            on_P_RM_clicked();
            e->accept();
            break;
        case Qt::Key_E:
            on_P_Exponent_clicked();
            break;
        default:
            e->ignore();
            break;
    }
}
