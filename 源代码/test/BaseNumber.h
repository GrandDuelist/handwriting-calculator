#ifndef BASENUMBER_H
#define BASENUMBER_H
#include"mybutton.h"
class BaseNumber:public MyButton{

public:
    explicit BaseNumber (QWidget *parent, const int &number,const int &x=0,const int &y=0);
    void setNumber(const int &number);
    int getNumber() const;
    ~BaseNumber();
private:
    int number;
};

#endif // BASENUMBER_H
