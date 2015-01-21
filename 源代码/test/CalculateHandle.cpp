#include"CalculateHandle.h"

//记录属性的结构体

int  currentPosition=0;  //分析到的指针
int num=0;
struct mytype{    //记录数据信息
    int datatype;   //数据类型
    QString datacontent; //数据内容
    mytype * next;
    mytype * previous;
    int position;
    mytype(const int &,const QString &);

};



mytype::mytype( const int &a,const QString &b)
{
    this->datatype=a;
    this->datacontent=b;
    this->next=NULL;
    this->previous=NULL;
    this->position=num++;
}


struct blacket{

    blacket * previous;   //指向上一括号
    mytype  * medium;   //指向当前括号
    blacket * next;  //指向下一个括号
    blacket(blacket *p, mytype *m);

};
blacket::blacket(blacket *p, mytype *m)
{
    this->previous=p;
    this->medium=m;
    this->next=NULL;
}
bool hasError=false;

int   wholeLength=0;
QChar CurrentLetter;      // 当前字符
mytype  *start=NULL;
mytype  *current=start;
blacket  *startLeftBlacket=NULL;
blacket  *currentLeftBlacket=startLeftBlacket;
blacket  *startRightBlacket=NULL;
blacket  *currentRightBlacket=startRightBlacket;
mytype *handleLeft=NULL;
mytype *handleRight=NULL;
 bool fitSuccess=true;
float result=0;


void error(char *error_message)
{
    printf("错误:%s\n",error_message);
    hasError=true;
}

bool isBaseFunctionSymbol(QChar f) //判断是否为基础运算符
{
    if(f=='+'||f=='-'||f=='/'||f=='*'||f=='^')
    {
        return true;
    }
    else{
        return false;

    }
}

//判断是否为括号
bool isBlacket(QChar c)
{
    if(c=='('||c==')')
    {
        return true;
    }
    else {
        return false;
    }
}

//判断是否为小数点
bool isDecimalPoint(QChar c)
{
    if(c=='.')
    {
        return true;
    }
    else
    {
        return false;
    }
}
//判断是否为字母
bool isLetter(QChar c)
{
    if(c=='S'||c=='I'||c=='N'||c=='C'||c=='O'||c=='T'||c=='A')
    {
        return true;
    }
    else return false;
}

bool isSingleNumber(QChar s)  //判断是否为数字
{
    if(s>='0'&&s<='9')
    {
        return true;
    }
    else return false;
}

float myAdd(float & a,float &b)   //加法
{
    return a+b;
}
float myMul(float &a,float &b)  //乘法
{
    return a*b;
}
float myDiv(float &a,float &b)  //除法
{
    if(b==0)
    {
        error("除数不能为0");
        return 0 ;
    }
    else
    {
        return (float)a/b;
    }
}

float mySub(float &a,float &b)
{
    return a-b;
}

//将左括号结成链
void insertIntoLeftBlacketList(mytype *c)
{
    if(startLeftBlacket==NULL)
     {

        startLeftBlacket = new blacket(NULL,c);
        currentLeftBlacket=startLeftBlacket;


     }
    else{
        blacket *p = currentLeftBlacket;
        currentLeftBlacket->next=new blacket(currentLeftBlacket,c);
        currentLeftBlacket=currentLeftBlacket->next;
        currentLeftBlacket->previous = p;

    }
}


//将右括号结成链
void insertIntoRightBlacketList(mytype *c)
{
    if(startRightBlacket==NULL)
     {
        startRightBlacket = new blacket(NULL,c);
        currentRightBlacket=startRightBlacket;
     }
    else
    {
        blacket *p = currentRightBlacket;
        currentRightBlacket->next=new blacket(currentRightBlacket,c);
        currentRightBlacket=currentRightBlacket->next;
        currentRightBlacket->previous = p;
    }

    if(startLeftBlacket==NULL)
    {

        hasError=true;

    }
    else {
    calculate();
    }
}

//把符号填进表
void  insertIntoRecordList(const int &type,const QString &temp)
{
    if(start==NULL)
    {

        start=new mytype(type,temp);
        current=start;



    }
    else{

        mytype * p=current;
        current->next=new mytype(type,temp);
        current=current->next;
        current->previous=p;

    }

   fitSuccess=true;
}

//识别sin
QString RecSin(QString &expression)
{
    QChar next1;   //下一个字母
    QChar next2;   //下两个字母

    QString temp="";
    CurrentLetter=expression.at(currentPosition);



    if(isLetter(CurrentLetter))
    {
        next1=expression.at(currentPosition+1);
        next2=expression.at(currentPosition+2);

        if(currentPosition+3<wholeLength)
        {
            QChar next3=expression.at(currentPosition+3);
            if(isBaseFunctionSymbol(next3)&&next3!='-')
            {
                hasError=true;
                return "Error";
            }

        }
        if(CurrentLetter=='S'&&next1=='I'&&next2=='N')    //sin
        {
            temp="sin";
            insertIntoRecordList(4,temp);
            currentPosition+=3;
        }
    }


    return temp;

}

//识别cos
QString RecCos(QString &expression)
{
    QChar next1;   //下一个字母
    QChar next2;   //下两个字母

    QString temp="";
    CurrentLetter=expression.at(currentPosition);



    if(isLetter(CurrentLetter))
    {
        next1=expression.at(currentPosition+1);
        next2=expression.at(currentPosition+2);

        if(currentPosition+3<wholeLength)
        {
            QChar next3=expression.at(currentPosition+3);
            if(isBaseFunctionSymbol(next3)&&next3!='-')
            {
                hasError=true;
                return "Error";
            }

        }
        if(CurrentLetter=='C'&&next1=='O'&&next2=='S')    //sin
        {
            temp="cos";
            insertIntoRecordList(4,temp);
            currentPosition+=3;
        }
    }


    return temp;

}

//识别tan
QString RecTan(QString &expression)
{
    QChar next1;   //下一个字母
    QChar next2;   //下两个字母

    QString temp="";
    CurrentLetter=expression.at(currentPosition);



    if(isLetter(CurrentLetter))
    {
        next1=expression.at(currentPosition+1);
        next2=expression.at(currentPosition+2);

        if(currentPosition+3<wholeLength)
        {
            QChar next3=expression.at(currentPosition+3);
            if(isBaseFunctionSymbol(next3)&&next3!='-')
            {
                hasError=true;
                return "Error";
            }

        }
        if(CurrentLetter=='T'&&next1=='A'&&next2=='N')    //sin
        {
            temp="tan";
            insertIntoRecordList(4,temp);
            currentPosition+=3;
        }
    }


    return temp;

}
//识别右括号
QString RecRightBlacket(QString &expression)
{
    QChar next;
    QString temp="";

    CurrentLetter=expression.at(currentPosition);

    if(CurrentLetter==')')
    {
    if((currentPosition+1)<wholeLength)
    {
        next= expression.at((currentPosition+1));
        if(isSingleNumber(next)||isLetter(next))
        {
            hasError=true;
            return "Error";
        }
     }
    temp.append("no");
    insertIntoRecordList(6,temp);
    currentPosition++;
    insertIntoRightBlacketList(current);

    }

    return temp;
}

//识别左括号
QString RecLeftBlacket(QString &expression)
{
   QChar next;
   QString temp="";

   CurrentLetter=expression.at(currentPosition);

   if(CurrentLetter=='(')
   {
        if((currentPosition+1)<wholeLength)
   {
       next= expression.at((currentPosition+1));
       if((isBaseFunctionSymbol(next)&&next!='-')||next==')')
       {
           hasError=true;
           return "Error";
       }
}

        temp.append("no");
        insertIntoRecordList(5,temp);  //用5代表操作符种类

        currentPosition++;

         insertIntoLeftBlacketList(current);


   }
   return temp;
}


//识别运算符号
QString RecFunction(QString &expression)
{
    wholeLength=expression.length();
    QChar next;
    QString temp="";

    CurrentLetter=expression.at(currentPosition);

    if(isBaseFunctionSymbol(CurrentLetter))
    {
    if((currentPosition+1)<wholeLength)
    {
        next=expression.at(currentPosition+1);
        if(isBaseFunctionSymbol(CurrentLetter)&&(isBaseFunctionSymbol(next)||next==')'))
        {
            hasError=true;
            return "error";
        }
    }



        if(CurrentLetter=='+')
        {
            if(start==NULL)
            {
                temp="+";
                start=new mytype(1,temp);
                current=start;



            }
            else{

                mytype * p=current;
                temp="+";
                current->next=new mytype(1,temp);
                current=current->next;
                current->previous=p;

            }

        }else if(CurrentLetter=='-')
        {
            temp = "-";

                if(start==NULL)
                {
                    start=new mytype(1,temp);
                    current=start;



                }
                else{

                    mytype * p=current;
                    current->next=new mytype(1,temp);
                    current=current->next;
                    current->previous=p;


          }
        }else if(CurrentLetter=='*')
        {
            temp="*";

                    if(start==NULL)
                    {
                        start=new mytype(2,temp);
                        current=start;



                    }
                    else{

                        mytype * p=current;
                        current->next=new mytype(2,temp);
                        current=current->next;
                        current->previous=p;

                    }

        }
        else if(CurrentLetter=='/')
        {
            temp="/";

                if(start==NULL)
                {
                    start=new mytype(2,temp);
                    current=start;



                }
                else{

                    mytype * p=current;
                    current->next=new mytype(2,temp);
                    current=current->next;
                    current->previous=p;

                }



        }
        else if(CurrentLetter=='^')
            {
            temp="^";

            if(start==NULL)
            {
                start=new mytype(3,temp);
                current=start;



            }
            else{

                mytype * p=current;
                current->next=new mytype(3,temp);
                current=current->next;
                current->previous=p;

            }

      }
        currentPosition++;
        return temp;
}
    return temp;
}
//识别数字
QString RecNumber(QString &expression)
{
    wholeLength=expression.length();
    QChar next;
    QString temp="";
    bool hasDecimalPoint=false;
    QChar firstChar= expression.at(currentPosition);
    QChar secondChar=' ';
    QChar lastChar=' ';
    if(currentPosition-1>=0)
    {
        lastChar=expression.at(currentPosition-1);
    }
    if(currentPosition+1<wholeLength)
        {
        secondChar = expression.at(currentPosition+1);
    }
    else
        {
        secondChar = ' ';
    }
    if(((firstChar=='-'&&!isSingleNumber(lastChar))||isSingleNumber(firstChar)&&firstChar!='0')||(firstChar=='0'&&secondChar=='.')||(firstChar=='0'&&!isSingleNumber(secondChar)))
    {
    while(currentPosition<wholeLength&&!hasError)
    {
        CurrentLetter=expression.at(currentPosition);

        if((currentPosition+1)<wholeLength)
        {
            next=expression.at(currentPosition+1);
            if(next=='.'&&CurrentLetter=='.')
            {
                hasError=true;
                return "error";
            }
        }
        if(isSingleNumber(CurrentLetter))  //简单的数字记录下来
        {
            temp.append(CurrentLetter);
            currentPosition++;

        }else if(isDecimalPoint(CurrentLetter)&&!hasDecimalPoint)  //出现小数点记录下来
        {
            temp.append(CurrentLetter);
            currentPosition++;
            hasDecimalPoint=true;
        }else if(isDecimalPoint(CurrentLetter)&&hasDecimalPoint)
        {
            hasError=true;
            return "error";
        }
        else
        {


            QChar next =' ';

            if(currentPosition<wholeLength)
            {
                next=expression.at(currentPosition);
                if(next=='('||isLetter(next))
                {
                    hasError=true;
                    return "error";
                }
            }


            if(start==NULL)
            {
                start=new mytype(0,temp);
                current=start;



            }
            else{

                mytype * p=current;
                current->next=new mytype(0,temp);
                current=current->next;
                current->previous=p;

            }

            fitSuccess=true;
            return temp;
        }
    }

    QChar next =' ';

    if(currentPosition<wholeLength)
    {
        next=expression.at(currentPosition);
        if(next=='('||isLetter(next))
        {
            hasError=true;
            return "error";
        }
    }

    if(start==NULL)
    {

        start=new mytype(0,temp);
        current=start;
        current->previous=start;


    }
    else{

        mytype * p=current;
        current->next=new mytype(0,temp);
        current=current->next;
        current->previous=p;

    }
//    for(type *p=start;p!=NULL;p=p->next)
//    {
//        p=new type("digtal",temp);
//        current=p->next;

//    }
    }
    return temp;
}


//释放两个指针之间的内存[p1,p2)
void returnStoreBetweenPointer(mytype *p1,mytype *p2)
{
    mytype *q;
    for(mytype *p=p1;p!=p2;)
    {
        q=p;
        p=p->next;
        delete q;


    }
}

//重新排序
void reOrder()
{
    num=0;
    mytype *p=NULL;
    for(p=start;p!=NULL;p=p->next)
    {
        p->position=num++;

    }


}

//求出当前表达式优先级最大的运算符[left,right)
mytype * getCurrentOperation(mytype * left,mytype *right)
{
    mytype *p=NULL;
    mytype *max=NULL;

    int maxType=-1;
    for(p=left;p!=right;p=p->next)
    {
        if(p->datatype>maxType)
        {

            max=p;
            maxType=max->datatype;

        }

    }
    return max;


}
//通过计算符号计算
float functionHandle(mytype *type)
{
    int datatype=type->datatype;

    QString minorType = type->datacontent;
    float minor=0;
    float leftdata=0;
    float rightdata=0;
    cout<<"begin"<<endl;
    cout<<type->previous->datacontent.toStdString();
    //cout<<type->previousdatacontent.toStdString();
    cout<<"end"<<endl;

    mytype *mergeLeft = type->previous->previous; //指向前两位
    mytype *mergeRight=type->next->next;//指向后两位
  //  cout<<"mergeLeft: "<<mergeLeft->position<<endl;
    switch(datatype)
    {
    case 0:
    {
        minor=minorType.toFloat();
        return minor;
        break;
    }
    case 1:
    {

        leftdata=type->previous->datacontent.toFloat();
        rightdata=type->next->datacontent.toFloat();
        cout<<"leftdata: "<<type->previous->datacontent.toStdString()<<"rightdata "+type->next->datacontent.toStdString()<<endl;
        if(minorType=="+")
        {
            minor=myAdd(leftdata,rightdata);
            cout<<"minor"<<minor<<endl;

        }
        else if(minorType=="-")
        {
            minor=mySub(leftdata,rightdata);
        }
        returnStoreBetweenPointer(type->previous,mergeRight);  //消掉算术表达式

        if(mergeLeft!=NULL)
        {
            QString temp=QString::number(minor);

            mergeLeft->next=new mytype(0,temp);
            mergeLeft->next->previous=mergeLeft;

            mergeLeft->next->next=mergeRight; //重新结成链
            if(mergeRight!=NULL)
            {
                mergeRight->previous=mergeLeft->next;
                 cout<<"fangzhihan:"<<mergeRight->previous->datacontent.toStdString()<<endl;

            }
            else {
                current=mergeLeft->next;
            }



        }else{

            QString temp=QString::number(minor);
            start=new mytype(0,temp);
            start->next=mergeRight;
            if(mergeRight!=NULL)
            {
                mergeRight->previous=start;

            }
            else {
                current=start;
            }


        }

        reOrder();   //重排


        return minor;
        break;
    }
    case 2:
    {
        leftdata=type->previous->datacontent.toFloat();
        rightdata=type->next->datacontent.toFloat();
        if(minorType=="*")
        {
            minor=myMul(leftdata,rightdata);
            cout<<"nihao"<<endl;
        }
        else if(minorType=="/")
        {
            minor=myDiv(leftdata,rightdata);
        }

        returnStoreBetweenPointer(type->previous,mergeRight);  //消掉算术表达式

        if(mergeLeft!=NULL)
        {
            QString temp=QString::number(minor);

            mergeLeft->next=new mytype(0,temp);
            mergeLeft->next->previous=mergeLeft;

            mergeLeft->next->next=mergeRight; //重新结成链
            if(mergeRight!=NULL)
            {
                mergeRight->previous=mergeLeft->next;


            }
            else {
                current=mergeLeft->next;
            }



        }else{

            QString temp=QString::number(minor);
            start=new mytype(0,temp);
            start->next=mergeRight;
            if(mergeRight!=NULL)
            {
                mergeRight->previous=start;

            }
            else {
                current=start;
            }


        }

        reOrder();   //重排
        return minor;

        break;
    }
    case 3:
    {
        leftdata=type->previous->datacontent.toFloat();
        rightdata=type->next->datacontent.toFloat();
         minor=pow(leftdata,rightdata);

         returnStoreBetweenPointer(type->previous,mergeRight);  //消掉算术表达式

         if(mergeLeft!=NULL)
         {
             QString temp=QString::number(minor);

             mergeLeft->next=new mytype(0,temp);
             mergeLeft->next->previous=mergeLeft;

             mergeLeft->next->next=mergeRight; //重新结成链
             if(mergeRight!=NULL)
             {
                 mergeRight->previous=mergeLeft->next;


             }
             else {
                 current=mergeLeft->next;
             }



         }else{

             QString temp=QString::number(minor);
             start=new mytype(0,temp);
             start->next=mergeRight;
             if(mergeRight!=NULL)
             {
                 mergeRight->previous=start;

             }
             else {
                 current=start;
             }


         }

         reOrder();   //重排


        return minor;
        break;
    }
    case 4:

    {
         rightdata=type->next->datacontent.toFloat();
         if(minorType=="sin")
         {
             minor=sin(rightdata);
         }
         else if(minorType=="cos")
         {
             minor=cos(rightdata);
         }
         else if(minorType=="tan")
        {
             minor=tan(rightdata);
         }

         mergeLeft=type->previous;
         returnStoreBetweenPointer(mergeLeft->next,mergeRight);

                 if(mergeLeft!=NULL)
                 {
                     QString temp=QString::number(minor);

                     mergeLeft->next=new mytype(0,temp);
                     mergeLeft->next->previous=mergeLeft;

                     mergeLeft->next->next=mergeRight; //重新结成链
                     if(mergeRight!=NULL)
                     {
                         mergeRight->previous=mergeLeft->next;


                     }
                     else {
                         current=mergeLeft->next;
                     }


                 }else{

                     QString temp=QString::number(minor);
                     start=new mytype(0,temp);
                     start->next=mergeRight;
                     if(mergeRight!=NULL)
                     {
                         mergeRight->previous=start;

                     }
                     else {
                         current=start;
                     }


                 }

                 reOrder();   //重排



         return minor;
         break;
    }

    }

}

//计算两括号之间的公式
float calculateBetweenBlacket(mytype *left,mytype *right)
{

    if(left->position>right->position)
    {
        hasError=true;
        return 0;
    }


    mytype * currentOperation=NULL;
    float result =0;

    while(left->position<(right->position-2))
    {

        cout<<"left->position:"<<left->position<<endl;
        cout<<"right->postion:"<<right->position<<endl;
//        if(left->position==(right->position-2))
//        {
//            if(left->previous!=NULL)
//            {
//                My
//                left=left->next;
//                left->previous->previous->next=left;
//                left->previous=

//            }
//            else
//            {
//                start=left

//            }

//            if(right->next!=NULL)
//            {

//            }


//        }
        for(mytype *p=start;p!=NULL;p=p->next)
       {
            cout<< "step "<<p->datacontent.toStdString()<<endl;
        }
        if(left->next!=NULL)
        {
            cout<<left->next->datacontent.toStdString()<<endl;
        }

        cout<<"left->position:"<<left->position<<endl;
        //找出此区间的最大优先级运算符
        currentOperation=getCurrentOperation(left->next,right);
        cout<<"currentOperation"<<currentOperation->position<<endl;
        result=functionHandle(currentOperation);

    }




    return result;


}

//判断运算式括号是否相等
bool blacketIsEqual()
{
    int a,b;

    blacket *p=NULL;
    for(a=0,p=startLeftBlacket;p!=NULL;p=p->next,a++);
    for(b=0,p=startRightBlacket;p!=NULL;p=p->next,b++);
    cout<<"a="<<a<<" b="<<b<<endl;
    return a==b;
}
//得到当前运算的左括号
blacket * getHandleLeftBlacket()
{
    return currentLeftBlacket;
}
//得到当前运算的右括号
blacket * getHandleRightBlacket()
{
    return startRightBlacket;
}

//合并括号
QString mergeBlacket(blacket * left, blacket * right)
{
    mytype *l=left->medium;
    mytype *r=right->medium;

    if(l->previous!=NULL)
    {
    l->previous->next=l->next;
    }
    else
    {
        start=l->next;
    }
    l->next->previous=l->previous;
    delete l;


    r->previous->next=r->next;
    if(r->next!=NULL)
    {
        r->next->previous=r->previous;
    }
    else
    {
       current= r->previous;
    }
    delete r;


    //left->previous->next=left->next;
   // left->next->previous=left->previous;

    currentLeftBlacket=left->previous;
    if(currentLeftBlacket==NULL)
    {
        startLeftBlacket=NULL;
    }
    delete left;

  //right->previous->next=right->next;
   // right->next->previous=right->previous;
    if(right->next==NULL)
    {
    startRightBlacket=right->next;
    }else{
        startLeftBlacket=NULL;
    }

    delete right;

   reOrder();

    return "success";

}/*
//根据类型串来计算
float calculate()
{


    float result=0;
    blacket *left=NULL;
    blacket *right =NULL;
    if(blacketIsEqual())
    {
        left=getHandleLeftBlacket();
        right=getHandleRightBlacket();
        while(left!=NULL)
        {


            result=calculateBetweenBlacket(left->medium,right->medium);


            cout<<"nihao"<<endl;
             mergeBlacket(left,right);
            left=getHandleLeftBlacket();
            right=getHandleRightBlacket();
        }
   //   return calculateWithoutBlacket(start,current);
  //  return calculateBetweenBlacket(startLeftBlacket->medium,startRightBlacket->medium);
    //return calculateBetweenBlacket()
    }
    return result;
}*/

float calculate()
{



    blacket *left=NULL;
     blacket *right=NULL;
        left=getHandleLeftBlacket();
        right=getHandleRightBlacket();



            result=calculateBetweenBlacket(left->medium,right->medium);


            cout<<"nihao"<<endl;
             mergeBlacket(left,right);

   //   return calculateWithoutBlacket(start,current);
  //  return calculateBetweenBlacket(startLeftBlacket->medium,startRightBlacket->medium);
    //return calculateBetweenBlacket()

    return result;
}
//处理输入字符串
QString HandleExpression(QString &expression)
{
    bool hasFinished=false;  //是否完成


    wholeLength=expression.length();

//    //预处理 总运算前面加括号
//    QString temp="no";
//    insertIntoRecordList(5,temp);  //用5代表操作符种类
//    insertIntoLeftBlacketList(current);

    //词法分析
    while(currentPosition<wholeLength&&!hasFinished&&!hasError)
    {
        if(hasError)
        {
            return "";
        }

       fitSuccess=false;   //初始匹配失败，开始进入匹配去
       RecRightBlacket(expression);
       RecNumber(expression);
       RecFunction(expression);
       RecSin(expression);
       RecTan(expression);
       RecCos(expression);
       RecLeftBlacket(expression);


       cout<<"fitSuccess= "<<fitSuccess<<endl;
       if(!fitSuccess) hasError=true;
       if(currentPosition==wholeLength) hasFinished=true;

    }

//   //结尾处理
//     currentPosition=0;
//     insertIntoRecordList(6,temp);  //用5代表操作符种类
//     insertIntoRightBlacketList(current);
   //语法语义分析，计算

    if(startLeftBlacket!=NULL)
    {
        hasError=true;
    }
    if(!hasError)
    {

          cout<<"result: "<<result<<endl;


         return "="+QString::number(result);
}
    return "=";

}

//内存回收函数
void returnStore()
{
     //cout<<start->datatype<<endl;
//      blacket *l=NULL;
//      for(blacket *p=startRightBlacket;p!=NULL;)
//      {

//          l=p;
//          p=p->next;
//          cout<<"r "<<(l->medium->datatype)<<endl;
//          delete l;

//      }

//    for(blacket *p=startLeftBlacket;p!=NULL;)
//    {

//        l=p;
//        p=p->next;
//        cout<<"l "<<(l->medium->datatype)<<endl;
//        delete l;

//    }
    num=0;
     mytype *q=NULL;
    for(mytype * p=start;p!=NULL;)
    {

        q=p;
        p=p->next;
        cout<<"position: "<<q->position<<endl;
        cout<<q->datatype<<endl;
        delete q;
    }


    hasError=false;
    currentPosition=0;
    current=start=NULL;
    currentLeftBlacket=startLeftBlacket=currentRightBlacket=startRightBlacket=NULL;
    num=0;

}
