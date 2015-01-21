#ifndef CALCULATEHANDLE_H
#define CALCULATEHANDLE_H
#include<qstring.h>
#include<string.h>
#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;


void error(char *error_message);
bool isBaseFunctionSymbol(char f) ;//判断是否为基础运算符
bool isSingleNumber(char s); //判断是否为数字
float add(float & a,float &b);   //加法
float div(float &a,float &b);  //除法
float sub(float &a,float &b);
float calculate();
QString RecNumber(QString &expression); //识别数字
QString RecFunction(QString &expression);//识别基础运算符
QString RecSin(QString &expression);   //识别三角函数
QString RecCos(QString &expression);
QString RecTan(QString &expression);

//识别右括号
QString RecRightBlacket(QString &expression);
//识别左括号
QString RecLeftBlacket(QString &expression);





void returnStore();           //回收内存
QString HandleExpression(QString &);  //处理输入的表达式
void reOrder();//对指针中的内容重新排序



#endif // CALCULATEHANDLE_H
