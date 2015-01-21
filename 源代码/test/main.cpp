#include <QtGui/QApplication>

#include<iostream>
#include<QTextCodec>
#include"CalculateHandle.h"

#include"myWindow.h"

int main(int argc, char *argv[])
{

    QTextCodec *codec = QTextCodec::codecForName("UTF-8");

    QTextCodec::setCodecForLocale(codec);

     QTextCodec::setCodecForCStrings(codec);

     QTextCodec::setCodecForTr(codec);
    QApplication a(argc, argv);
//    back = new Back();
//    w=new MainWindow();
//    w->back=(Ui::Back *)back;

    //w=new MainWindow();
   //back = new Back();
    MainWindow w;
    w.show();

//      back->show();

    return a.exec();
}
