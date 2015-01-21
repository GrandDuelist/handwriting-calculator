#include "compute_net.h"
#include <QImage>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <QString>
#include <QColor>

using namespace std;

compute_net::compute_net()
{
 //   string file("./name.txt");
//   ifstream infile(file.c_str());
//    string str;
//    for(int count = 0;count<total_data;count++)
//    {
//        infile>>str;
//        this->name_index.push_back(str);
//    }

    this->initFilename();
    this->readToName();


}

QImage& compute_net::add_noise()
{
    int standard = 0;
    srand((unsigned)time(NULL));
    //QRgb white = qRgb(0,0,0);
    //QRgb black = qRgb(255,255,255);
    QColor white(Qt::white);
    QColor black(Qt::black);
    for(int width = 0;width < 40;width++)
    {
        for(int height = 0;height < 40;height++)
        {
            if(this->image.pixel(width,height) == white.rgb()) //如果像素点是白色，则有10%的可能性变为黑色
            {
                standard = rand() %100;
                if(standard < 10 && standard >= 0) //变为黑色
                {
                    this->image.setPixel(width,height,black.rgb());
                }
            }
            else //如果像素点是黑色,则有5%的几率变为白色
            {
                standard = rand() % 100;
                if(standard <= 10 && standard > 5)
                {
                    this->image.setPixel(width,height,white.rgb());
                }
            }
        }
    }
    return this->image;
}
void compute_net::set_image(QImage& image)
{
    this->image = image;
}

void compute_net::compute_value()//每16个像素点为一组，计算黑色像素点占16个像素点的比例
{
    QColor white(Qt::white);

    //QRgb black = qRgb(255,255,255);
    int count = 0;
    int index = 0;//0~99
    int total = 16;
    for(int width = 0; width < 40;width = width +4)
    {
        for(int height = 0;height < 40;height = height + 4)
        {
            for(int i = width;i < width +4;i++)
            {
                for(int j =height;j<height+4;j++)
                {
                    if(this->image.pixel(i,j) != white.rgb())
                        count++;
                }
            }
            this->imput[index++] = (float)count/(float)total;
            count = 0;
        }
    }

}
float* compute_net::get_value() //获取到输入的数值
{
    return this->imput;
}
bool compute_net::train()
{
    float right_rate = 0.0;//设定正确率大于90%

    int correct_time = 0;//正确的次数

    int train_time = 30000;//设定训练次数为4000次

    this->nerual.initial_Net();//首先初始化网络

    int count = 0;   //作为一遍训练的标杆

    vector<int> time_index;

    vector<int>::iterator iter;

    vector<string> temp_name_index[total_data];
    vector<string>::iterator it;
    for(int i = 0;i<total_data;i++)
    {
        for(it=filename[i]->begin();it!=filename[i]->end();it++)
        {

        temp_name_index[i].push_back(*it);
        }
    }

    int pic_index = 0;


    int index = 0;

    srand((unsigned)time(NULL));

    string filepath;

    //for循环开始训练

    for(int i = 0; i<train_time;i++)
    {
        if(count == total_data)
        {
            time_index.clear();
            count = 0;
        }


        index = rand()%total_data;
        while((iter = find(time_index.begin(),time_index.end(),index)) !=
              time_index.end())//表示已经存在index
        {
            index = rand()%total_data;
        }
        time_index.push_back(index);
        pic_index = index;

        vector<string> temp_vector = temp_name_index[pic_index];
        index = temp_vector.size();

        index = rand()%index;//在这一串中找到一个随机数





        filepath = "./pic_data/" + temp_vector[index] + ".png";


        //从vector<string>中删除这个元素
        vector<string>::iterator ie;
        ie = temp_name_index[pic_index].begin();
        //找到迭代器的位置
        while(*ie != temp_vector[index])
        {
             ie++;
        }
        if(temp_name_index[pic_index].size() == 1)
        {
            temp_name_index[pic_index].erase(ie);
            //然后重新赋值
            for(it=filename[pic_index]->begin();it!=filename[pic_index]->end();it++)
            {
            temp_name_index[pic_index].push_back(*it);
            }
        }
        else
        {
            temp_name_index[pic_index].erase(ie);
        }

        QString file(filepath.c_str());
        QImage image;
        image.load(file);//装载图片
        this->image = image;
        //首先取出正确的预期值
        string str = temp_vector[index];
        //string str = this->name_index[index];

        int k;
        for(k = 0;k<str.length();k++)
        {
            if(str[k] == '_')
                break;
        }
        k= k+1;
        str = str.substr(k);
        for(int j =0;j<str.length();j++)
        {
            if(str[j] == '0')
                this->hope_value[j] = 0;
            else
                this->hope_value[j] = 1;
        }
        //完毕
        //开始训练网络
        //加噪声

        /////////////////////////////////////
        //this->add_noise();
        ////////////////////////////////////
        this->compute_value();

        this->nerual.learn_once(this->get_value());

        float* m_result = this->nerual.getResult();
        int temp_result[6];
        for(int i = 0;i<6;i++)
        {
            if(m_result[i] > 0.5)
                temp_result[i] = 1;
            else
                temp_result[i] = 0;
        }
        //开始比较结果，网络计算的结果已经保存在temp_result中
        bool flag = true;//作为输出结果与预期结果是否相等的标志
        for(int j = 0;j<6;j++)
        {
            if(temp_result[j] != this->hope_value[j])//如果和预期结果不符合，就将flag设为false并break
            {
                flag = false;
                break;
            }
        }
        if(flag == false)//如果不相等
        {
            //纠正网络
             this->nerual.correctNet(this->hope_value);
             //count ++;
        }

        ////////////////////////////////////////////////////////////////
        //this->nerual.correctNet(this->hope_value);
        //上面两行代码表示训练一次

        count++;


    }

    //开始测试网络的正确率


    //识别200次
    int total_test;
    correct_time = 0;
    for(total_test = 0;total_test<200;total_test++)
    {
         index = rand()%total_data;

         vector<string> name_index = *this->filename[index];

         index = rand()%name_index.size();
         string str = name_index[index];

         //string str = this->name_index[index];
         filepath = "./pic_data/" + str + ".png";

         QString file(filepath.c_str());
         QImage image;
         image.load(file);//装载图片
         this->image = image;
         //首先取出正确的预期值
         //string str = this->name_index[index];
         int k;
         for(k = 0;k<str.length();k++)
         {
             if(str[k] == '_')
                 break;
         }
         k= k+1;
         str = str.substr(k);
         for(int j =0;j<str.length();j++)
         {
             if(str[j] == '0')
                 this->hope_value[j] = 0;
             else
                 this->hope_value[j] = 1;
         }
         this->compute_value();

         this->nerual.learn_once(this->get_value());  //

         int temp_result[6];//处理网络预测的结果，注意，大于0.5的看做1，小于0.5的看做是0
         float* result = this->nerual.getResult();
         for(int i = 0;i<6;i++)
         {
             if(result[i] > 0.5)
                 temp_result[i] = 1;
             else
                 temp_result[i] = 0;
         }
         //开始比较结果，网络计算的记过已经保存在temp_result中
         bool flag = true;//作为输出结果与预期结果是否相等的标志
         for(int j = 0;j<6;j++)
         {
             if(temp_result[j] != this->hope_value[j])//如果和预期结果不符合，就将flag设为false并break
             {
                 flag = false;
                 break;
             }
         }
         if(flag)//如果相等
         {
             correct_time ++;//正确次数+1
         }
    }
    right_rate = (float)correct_time / (float)total_test;
    this->rate = right_rate;
    if(right_rate > 0.9)
        return true;
    else
        return false;
}
void compute_net::save()
{
    this->nerual.save_Net();
}
int* compute_net::recognise()
{
    this->compute_value();

    this->nerual.learn_once(this->get_value());

    float* m_result = this->nerual.getResult();
    int* temp_result = new int[6];
    for(int i = 0;i<6;i++)
    {
        if(m_result[i] > 0.5)
            temp_result[i] = 1;
        else
            temp_result[i] = 0;
    }
    return temp_result;
    /*
    char* result = new char[7];
    result[6] = '/0';
    for(int i =0;i<6;i++)
    {
        if(temp_result[i] == 1)
            result[i] = '1';
        else
            result[i] = '0';
    }
    return
    */
}
void compute_net::readNet()
{
    this->nerual.readNet();
}

void compute_net::initFilename()
{
    for(int i=0;i<compute_net::typeNum;i++)
    {
        this->filename[i]=new vector<string>();
    }
}

string compute_net::getLastName(string fullname)
{
    int k;
    for(k = 0;k<fullname.length();k++)
    {
        if(fullname[k] == '_')
            break;
    }
    k= k+1;
    return fullname.substr(k);

}

//把文件里面的数据读到ector中
int compute_net::readToName()
{
    char buf[256];
    char temp;
    int fd;


    fd=open("./name.txt",O_RDONLY);
    if(fd<0)
    {
        cout<<"get file error"<<endl;
        return 0;
    }else{


 int i = 0;

 while(read(fd, &temp, 1) > 0)
    {

     if(temp==' ')
     {

     }
     else {

      i=0;
    do
    {
           if(temp == '\n') break;
          buf[i++] = temp;
       if(read(fd, &temp, 1) < 0) break;


    }while(1);
      buf[i-1] ='\0';

     string fullname(buf);

     string lastName=this->getLastName(fullname);


          if(lastName=="000000")this->filename[0]->push_back(fullname);


          else if(lastName=="000001")this->filename[1]->push_back(fullname);
          else if(lastName=="000010")this->filename[2]->push_back(fullname);
          else if(lastName=="000011")this->filename[3]->push_back(fullname);
          else if(lastName=="000100")this->filename[4]->push_back(fullname);
          else if(lastName=="000101")this->filename[5]->push_back(fullname);
          else if(lastName=="000110")this->filename[6]->push_back(fullname);
          else if(lastName=="000111")this->filename[7]->push_back(fullname);
          else if(lastName=="001000")this->filename[8]->push_back(fullname);
          else if(lastName=="001001")this->filename[9]->push_back(fullname);
          else if(lastName=="001010")this->filename[10]->push_back(fullname);
          else if(lastName=="001100")this->filename[11]->push_back(fullname);
          else if(lastName=="010010")this->filename[12]->push_back(fullname);
          else if(lastName=="010111")this->filename[13]->push_back(fullname);
          else if(lastName=="011100")this->filename[14]->push_back(fullname);
          else if(lastName=="011101")this->filename[15]->push_back(fullname);
          else if(lastName=="101000")this->filename[16]->push_back(fullname);
          else if(lastName=="101001")this->filename[17]->push_back(fullname);
          else if(lastName=="100110")this->filename[18]->push_back(fullname);
          else if(lastName=="100101")this->filename[19]->push_back(fullname);
          else if(lastName=="100100")this->filename[20]->push_back(fullname);
          else if(lastName=="100111")this->filename[21]->push_back(fullname);
          else if(lastName=="101010")this->filename[22]->push_back(fullname);



     }


    }

}

//    for(int i=0;i<this->typeNum;i++)
//    {
//        vector<string>::iterator it;
//        cout<<i<<": "<<endl;
//        for(it=this->filename[i]->begin();it!=this->filename[i]->end();it++)
//        {
//            cout<<*it<<endl;


//        }

//    }
    return 0;
}
compute_net::~compute_net()
{

    for(int i=0;i<compute_net::typeNum;i++)
    {
        delete this->filename[i];
    }
}
