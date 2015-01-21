#include "mybutton.h"
bool hasShowResult=false;
//重构button
MyButton::MyButton(QWidget *parent,const QString &text,const int &x,const int &y):
    QPushButton(parent)
{

    if(text!="取消")
        {
 this->setPosition(x,y);
}else{
        this->setGeometry(300,95,MyButton::BUTTONWIDTH,MyButton::BUTTONHEIGHT/2);
    }
    if(text=="确认"||text=="取消")
        {
        this->resize(MyButton::BUTTONWIDTH,MyButton::BUTTONHEIGHT/2);

    }else
    {
         this->resize(MyButton::BUTTONWIDTH,MyButton::BUTTONHEIGHT);
    }

    this->setText(text);
  //  this->setGeometry(100,100,200,200);

    this->content=text;
     connect(this,SIGNAL(clicked()),this,SLOT(handleButton()));

}

void MyButton::setScreen(QLineEdit *screen)

{
    this->screen=screen;

}
QString MyButton::getContent() const
{
     return this->content;
}
//坐标重构
void MyButton::setPosition(const int &x,const int &y)
{
    int positionX=x*MyButton::BUTTONWIDTH;
    int positionY=y*MyButton::BUTTONHEIGHT+MyButton::INITHEIGHT;
    this->setGeometry(positionX,positionY,MyButton::BUTTONWIDTH,MyButton::BUTTONHEIGHT);


}
//事件相应函数
void MyButton::handleButton()
{

    if(this->content!="确认"&&this->content!="取消")
    {
    QString CurrentInput = this->screen->text();
  //  message=this->content;
    CurrentInput.append(this->content);
    this->screen->setText(CurrentInput);
    }else if(this->content=="确认"&&!hasShowResult)
    {
       hasShowResult=true;
        QString CurrentInput=this->screen->text();
        //QString a= RecNumber(CurrentInput);
       // float currentFloat = CurrentInput.toFloat();
       // cout<<"float: "<<currentFloat<<endl;
        QString handleInput="("+CurrentInput+")";
          cout<<"RESULT "<<handleInput.toStdString()<<endl;
       QString result=CurrentInput.append(HandleExpression(handleInput));

       this->screen->setText(result);
        // QString a=RecFunction(CurrentInput);
        //this->screen->setText(a+"ni");
       // float test = pow(2,3.4);
       // float test= sin(1);
      // cout<<"test="<<test<<endl;
        returnStore();

       // hasError=false;
      // cout<<a.toAscii()<<endl;

    }else if(this->content=="取消")
    {
        hasShowResult=false;
        this->screen->setText("");
    }

}
MyButton::~MyButton()
{
}
