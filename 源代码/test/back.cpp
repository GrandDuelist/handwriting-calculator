#include "back.h"
#include "ui_back.h"
#include <string>
#include <sstream>

using namespace std;

Back::Back(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Back)
{
    ui->setupUi(this);
    paintarea = new My_paint(ui->centralWidget);
    paintarea->setGeometry(QRect(240,10,150,150));

    showArea = new showpic(ui->centralWidget);
    showArea->setGeometry(QRect(150,180,40,40));

    this->compute = new compute_net;

    //test = new My_paint(ui->centralWidget);
    //test->setGeometry(QRect(400,40,100,100));

}

Back::~Back()
{
    delete ui;
}

void Back::on_Okbutton_clicked()
{
    //ui->lineEdit->setText("hello world");
    this->paintarea->clear();
}

void Back::on_cancelbutton_clicked()
{
    this->showArea->dispose_pic(this->paintarea->get_Iamge());
    this->showArea->set_image(this->paintarea->get_Iamge());
//    QImage *myimage= new QImage("./pic_data/558_001000.png");
//    this->showArea->set_image(myimage);
}

void Back::on_pushButton_clicked()
{
 //   this->showArea->save_file();
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

void Back::on_pushButton_2_clicked()
{
    bool flag = this->compute->train();
    if(flag == true)
    {
        ui->lineEdit->setText("训练成功 ");
        stringstream stream ;
        stream << this->compute->rate;
        string result;
        stream >> result;
        ui->lineEdit->setText(result.c_str());
    }
    else
    {
        //ui->lineEdit->setText("训练失败 ");
        stringstream stream ;
        stream << this->compute->rate;
        string result;
        stream >> result;
        result = "训练失败 " + result;
        ui->lineEdit->setText(result.c_str());

    }
}

void Back::on_pushButton_3_clicked()
{
    this->compute->save();
}

void Back::on_pushButton_4_clicked()
{
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
    this->ui->lineEdit->setText(str);
}

void Back::on_pushButton_5_clicked()
{
    this->compute->readNet();
}


