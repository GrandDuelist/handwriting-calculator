#include "BaseNumber.h"

BaseNumber::BaseNumber(QWidget *parent, const int &number,const int &x,const int &y):MyButton(parent,QString::number(number),x,y)
{
    this->setNumber(number);


}
void BaseNumber::setNumber(const int &number)
{
    this->number=number;
}
int BaseNumber::getNumber() const
{
    return this->number;
}
BaseNumber::~BaseNumber(){


}
