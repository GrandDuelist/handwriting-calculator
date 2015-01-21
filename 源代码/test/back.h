#ifndef Back_H
#define Back_H

#include <QMainWindow>
#include "my_paint.h"
#include "showpic.h"
#include "compute_net.h"
#include"mainwindow.h"

namespace Ui {

class Back;
class MainWindow;

}

class Back:public QMainWindow
{
    Q_OBJECT
private:
    Ui::Back *ui;

public:
    explicit Back(QWidget *parent = 0);
    ~Back();
    My_paint* paintarea;
    showpic* showArea;

    My_paint* test;

    compute_net* compute;

    Ui::MainWindow *w;
    
private slots:
    void on_Okbutton_clicked();

    void on_cancelbutton_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();


};


#endif // Back_H


