#include"mainwindow.h"
#include "ui_mainwindow.h"
#include<qfont.h>
#include<stdio.h>
#include<fstream>

#include"myBack.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

   ui->setupUi(this);

    this->addNumbers();  //加入数字
    this->addBaseFunction();  //加入基本运算
    this->addSymbol();   //加入括号和小数点
    this->addTrigonometric();   //加入三角函数
    this->addSreen();       //加入显示器
    this->addSureCancel();  //确定取消按钮
    this->attachScreen();
    this->compute=new compute_net();
    paintarea = new My_paint(ui->centralWidget);
    paintarea ->setGeometry(150,150,150,150);
    showArea = new showpic(ui->centralWidget);
    showArea->setGeometry(305,110,40,40);

     this->compute->readNet();

//    string filepath("./nihao.txt");
//    ofstream outfile(filepath.c_str());
//    outfile<<"nihao"<<endl;

    //this->boundButtonScreen();

    //b1->setFont(QFont("Times",18,QFont:Bold));

}


//添加+，-，×，/，^符号
void MainWindow::addBaseFunction()
{
    this->MyButtons[0]=this->FunctionAdd=new MyButton(this,"+",0,0);
    this->MyButtons[1]=this->FunctionSub=new MyButton(this,"-",1,0);
    this->MyButtons[2]=this->FunctionDiv=new MyButton(this,"/",2,0);
    this->MyButtons[3]=this->FunctionMul=new MyButton(this,"*",0,4);
    this->MyButtons[4]=this->FunctionPow=new MyButton(this,"^",3,1);

}



//添加数字进去
void MainWindow::addNumbers()
{
    //数字0
   this->MyButtons[5]= numbers[0]=new BaseNumber(this,0,1,4);

    //数字1～3
   this->MyButtons[6]= numbers[1]=new BaseNumber(this,1,0,3);
   this->MyButtons[7]= numbers[2]=new BaseNumber(this,2,1,3);
   this->MyButtons[8]=numbers[3]=new BaseNumber(this,3,2,3);

    //数字4～5
    this->MyButtons[9]=numbers[4]=new BaseNumber(this,4,0,2);
   this->MyButtons[10]= numbers[5]=new BaseNumber(this,5,1,2);
    this->MyButtons[11]=numbers[6]=new BaseNumber(this,6,2,2);

    //数字7～9
   this->MyButtons[12]= numbers[7]=new BaseNumber(this,7,0,1);
   this->MyButtons[13]= numbers[8]=new BaseNumber(this,8,1,1);
   this->MyButtons[14]= numbers[9]=new BaseNumber(this,9,2,1);
}


//加入小数点，左右括号
void MainWindow::addSymbol()
{
   this->MyButtons[15]=this->DecimalPoint=new MyButton(this,".",2,4);
   this->MyButtons[16]= this->LeftBlacket=new MyButton(this,"(",4,1);
   this->MyButtons[17]= this->RightBlacket=new MyButton(this,")",5,1);
}



//添加三角函数
void MainWindow::addTrigonometric()
{
    this->MyButtons[18]=this->FunctionSin=new MyButton(this,"SIN",3,0);
    this->MyButtons[19]= this->FunctionCos=new MyButton(this,"COS",4,0);
    this->MyButtons[20]=this->FunctionTan=new MyButton(this,"TAN",5,0);
}

//绑定显示屏
void MainWindow::attachScreen()
{

    for(int i=0;i<23;i++)
    {
        MyButtons[i]->setScreen(this->CalculatorSreen);

    }

}
//加入显示屏
void MainWindow::addSreen()
{
    this->CalculatorSreen=new QLineEdit();
    this->CalculatorSreen->setParent(this);
    this->CalculatorSreen->setGeometry(0,0,350,60);
    this->CalculatorSreen->setReadOnly(true);
    this->CalculatorSreen->setFont(QFont("Times",18,QFont::Bold));
}


//确定，取消
void MainWindow::addSureCancel()
{
    this->MyButtons[21]=this->Sure=new MyButton(this,"确认",6,0);
    this->MyButtons[22]=this->Cancel=new MyButton(this,"取消",6,1);

}

//通过信号绑定按钮和显示器
/*
void MainWindow::boundButtonScreen()
{

    for(int i=0;i<23;i++)
    {
        sender=MyButtons[i];
        connect(sender,SIGNAL(clicked()),this,SLOT(sreenReciever()));
    }

}

void MainWindow::screenReciever()
{
    QString message = this->MyButtons[i]->getContent();
    QString  content=this->CalculatorSreen->text();
    content.append(message);
    this->CalculatorSreen->setText(content);
}
*/
MainWindow::~MainWindow()
{
    delete ui;
    delete this->FunctionAdd;
    delete this->FunctionDiv;
    delete this->FunctionMul;
    delete this->FunctionSub;
    delete this->FunctionPow;

    delete this->FunctionSin;
    delete this->FunctionCos;
    delete this->FunctionTan;

    delete this->LeftBlacket;
    delete this->RightBlacket;
    delete this->DecimalPoint;

     delete CalculatorSreen;

    delete this->Sure;
    delete this->Cancel;

    for(int i=0;i<10;i++)
    {
        BaseNumber *temp=NULL;
        temp=numbers[i];
        if(temp!=NULL)
        {
            delete temp;     //释放所有代表数字的button
        }

    }
}

void MainWindow::on_rec_clicked()
{
    QString r= this->CalculatorSreen->text();
    QChar preChar=' ';
    if(r.length()!=0)
    {
     preChar = r.at(r.length()-1);
    }
    string pre;
    pre.insert(pre.begin(),preChar.unicode());
    this->showArea->dispose_pic(this->paintarea->get_Iamge());
    QImage* image = this->showArea->get_image();
        this->compute->set_image(*image);
        int* temp_result = this->compute->recognise();


        char* result = new char[7];
        result[6] = '\0';
        for(int i =0;i<6;i++)
        {
            if(temp_result[i] == 1)
                result[i] = '1';
            else
                result[i] = '0';
        }
        delete[] temp_result;
        QString str(result);
        string str2(result);
        cout<<str2<<endl;
        if(str=="000000")
        {
            if(pre=="C")
            {
                str="O";
            }else {
            str="0";
            }
        }else if(str=="000001")
        {
            if(pre=="S")
            {
                str="I";
            }else{
            str="1";
            }
        }else if(str=="000010")
        {
            str="2";
        }else if(str=="000011")
        {
            str="3";
        }else if(str=="000100")
        {
            str="4";
        }else if(str=="000101")
        {
            if(pre=="O")
            {
                str="S";
            }
            else{
            str="5";
            }
        }else if(str=="000110")
        {
            str="6";
        }else if(str=="000111")
        {
            str="7";
        }else if(str=="001000")
        {
            str="8";
        }else if(str=="001001")
        {
            str="9";
        }else if(str=="101000")
        {
            str="(";
        }else if(str=="101001")
        {
            str=")";
        }else if(str=="101010")
        {
            str="^";
        }else if(str=="011100")
        {
            str="S";
        }else if(str=="010010")
        {
            if(pre=="S")
            {
            str="I";
            }else
            {
                str="1";
            }
        }else if(str=="010111")
        {
            str="N";
        }else if(str=="011101")
        {
            str="T";
        }else if(str=="001010")
        {
            str="A";
        }else if(str=="001100")
        {
            str="C";
        }else if(str=="000000")
        {
            if(pre=="C")
            {
                str="O";
            }

            else {
            str="0";
            }
        }else if(str=="100100")
        {
            str="+";
        }else if(str=="100101")
        {
            str="-";
        }else if(str=="100110")
        {
            str="*";
        }else if(str=="100111")
        {
            str="/";
        }else{
            str="0";
        }


        this->CalculatorSreen->setText(this->CalculatorSreen->text().append(str));
}

void MainWindow::on_pushButton_clicked()
{
    this->paintarea->clear();
}
void MainWindow::on_pushButton_2_clicked()
{
     this->hide();
    this->close();
    back  = new Back();
    back->show();


    back->move(500, 300);

    this->show();
   // delete this;
   // this->show();




}

void MainWindow::on_pushButton_4_clicked()
{
    QString str=this->CalculatorSreen->text();
    QString str2=str.mid(0,str.length()-1);
    this->CalculatorSreen->setText(str2);
}

void MainWindow::on_pushButton_3_clicked()
{
    vector<string> *myvector;
    string mycode;
    compute_net temp;
    bool isOK;
    bool inputRight=true;
    QString text = QInputDialog::getText(NULL, "智能记错",
                                                       "请输入正确数值",
                                                       QLineEdit::Normal,
                                                       "正确数值",
                                                       &isOK);
    if(isOK) {

        if(text=="0"){mycode="000000";myvector=temp.filename[0];}
        else if(text=="1"){mycode="000001";myvector=temp.filename[1];}
         else if(text=="2"){mycode="000010";myvector=temp.filename[2];}
         else if(text=="3"){mycode="000011";myvector=temp.filename[3];}
         else if(text=="4"){mycode="000100";myvector=temp.filename[4];}
         else if(text=="5"){mycode="000101";myvector=temp.filename[5];}
         else if(text=="6"){mycode="000110";myvector=temp.filename[6];}
         else if(text=="7"){mycode="000111";myvector=temp.filename[7];}
         else if(text=="8"){mycode="001000";myvector=temp.filename[8];}
         else if(text=="9"){mycode="001001";myvector=temp.filename[9];}
         else if(text=="A"){mycode="001010";myvector=temp.filename[10];}
         else if(text=="B"){mycode="001100";myvector=temp.filename[11];}
        else if(text=="I"){mycode="010010";myvector=temp.filename[12];}
         else if(text=="N"){mycode="010111";myvector=temp.filename[13];}
         else if(text=="S"){mycode="011100";myvector=temp.filename[14];}
         else if(text=="T"){mycode="011101";myvector=temp.filename[15];}
         else if(text=="("){mycode="101000";myvector=temp.filename[16];}
         else if(text==")"){mycode="101001";myvector=temp.filename[17];}
         else if(text=="*"){mycode="100110";myvector=temp.filename[18];}
        else if(text=="-"){mycode="100101";myvector=temp.filename[19];}
        else if(text=="+"){mycode="100100";myvector=temp.filename[20];}
        else if(text=="/"){mycode="100111";myvector=temp.filename[21];}
        else if(text=="^"){mycode="101010";myvector=temp.filename[22];}
        else {
            inputRight=false;
            QMessageBox::information(NULL, "记忆失败",
                                          "该字符不在输入列表",
                                          QMessageBox::Yes | QMessageBox::No,
                                          QMessageBox::Yes);


        }
        if(inputRight)
        {
            int count= myvector->size();
            string mycode2="_"+mycode;
           this->showArea->save_file(++count,mycode2);
           QMessageBox::information(NULL, "记忆成功",
                                               "你可在学习中点击startlearn重新学习",
                                               QMessageBox::Yes | QMessageBox::No,
                                               QMessageBox::Yes);
        }
    }



}
