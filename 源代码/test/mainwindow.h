#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<qfont.h>
#include <QMainWindow>
#include<qpushbutton.h>
#include"mybutton.h"
#include"BaseNumber.h"
#include<qlineedit.h>
#include"showpic.h"
#include"my_paint.h"
#include"compute_net.h"
#include"back.h"
#include<QInputDialog>
#include<QMessageBox>
namespace Ui {

class Back;
class MainWindow;

}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:


    explicit MainWindow(QWidget *parent = 0);
    void addNumbers();       //添加数字
    void addBaseFunction(); //添加四种简单运算符
    void addSymbol();       //添加符号进去
    void addTrigonometric(); //添加三角函数
    void addSreen();        //显示屏
    void addSureCancel();   // 确认取消
    void boundButtonScreen();  //绑定屏幕按按钮事件
    void attachScreen();

    ~MainWindow();


private:
    Ui::MainWindow *ui;
    BaseNumber* numbers[10];  //存放所有数字

    MyButton* FunctionAdd;   //加号
    MyButton* FunctionSub;   //减号
    MyButton* FunctionMul;   //乘号
    MyButton* FunctionDiv;   //除法
    MyButton* FunctionPow;   //幂方

    MyButton* LeftBlacket;   //左括号
    MyButton* RightBlacket;  //右括号
    MyButton* DecimalPoint;  //小数点

    MyButton* FunctionSin;   //正弦
    MyButton* FunctionTan;   //正切
    MyButton* FunctionCos;   //余弦


    MyButton* Sure;  // 确认键
    MyButton* Cancel; //取消

    MyButton* MyButtons[23];

    MyButton *sender;  //信号发送


    My_paint *paintarea; // 绘图画板
    showpic * showArea;
    compute_net * compute;


    QLineEdit* CalculatorSreen; //显示器




public slots:




private slots:
    void on_rec_clicked();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
};

#endif // MAINWINDOW_H




