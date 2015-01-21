#ifndef COMPUTE_NET_H
#define COMPUTE_NET_H
#define total_data 23
#include <QImage>
#include <string>
#include <vector>
#include "network.h"
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<iostream>
using namespace std;
class compute_net //这个类进行图像的加噪声和获得输入数据
{
public:
    compute_net();
    ~compute_net();

    QImage& add_noise();
    void set_image(QImage& iamge);
    void compute_value();
    float* get_value();
    bool train(); //网络训练方法
    void save();//保存网络
    int* recognise();//识别字符
    void readNet();//读取网络
 //   void readToVector(); //
    float rate;

    int readToName();
    string getLastName(string fullname);  //通过全名找到后缀名，标示身份
    static const int typeNum=total_data;
    void initFilename();          //初始化容器
    vector<string >* filename[typeNum];

private:
    QImage image;
    float imput[100];
    int hope_value[6];//期望输出的值
    //string name_index[total_data];//一共130个测试样本
    vector<string> name_index;
    network nerual;
  //  vector<vector<string> > fileName;
};

#endif // COMPUTE_NET_H
