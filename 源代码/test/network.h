#ifndef NETWORK_H
#define NETWORK_H
#define input_layer_total 100
#define output_layer_total 6
#define MAXTIME  65536
#define learn_rate 0.2


#include <iostream>
#include <vector>
using namespace std;


struct node
{
    //网络节点
    float* weight; //权值,指向一个float数组

    float threshold;//阈值,每个单元只有一个阈值

    float input_value;

    float output_value;

    float error;//误差

};
class network
{
public:
    network()
    {
        hidden_layer_total = 2;
        hidden_layer_node = 30;
        hidden = new node*[hidden_layer_total];
        for(int i = 0;i<hidden_layer_total;i++)
        {
            hidden[i] = new node[hidden_layer_node];
        }
        //为输入层每个结点建立权值数组
        for(int i = 0;i < input_layer_total;i++)
        {
            input[i].weight = new float[hidden_layer_node];
        }
        //为输出层每个结点建立权值数组,但去除最后一层隐藏层，因为输出层的数目不同
        for(int i = 0; i< hidden_layer_total-1;i++)
        {
            for(int k = 0;k<hidden_layer_node;k++)
            {
                hidden[i][k].weight = new float[hidden_layer_node];
            }
        }
        //为最后一层隐藏层建立权值数组

        for(int i =0;i<hidden_layer_node;i++)
        {
            hidden[hidden_layer_total-1][i].weight = new float[output_layer_total];
        }
    }
    ~network()
    {
        for(int i =0;i<hidden_layer_total;i++)
        {
            for(int k = 0;k<hidden_layer_node;k++)
            {
                delete []hidden[i][k].weight;
            }
        }
        for(int i =0; i<hidden_layer_total;i++)
        {
            delete []hidden[i];
        }
        delete []hidden;

        for(int i =0; i<input_layer_total;i++)
        {
            delete []input[i].weight;
        }
    }
    void initial_Net();//初始化网络
    void learn_once(float* source);//进行一次学习
    void correctNet(int* source);//紧接上面的方法，用于纠正网络误差,source是预期输出的结果
    void save_Net();//保存网络
    void readNet();//读取网络
    bool training();//训练网络
    float* getResult();//返回网络识别的结果


protected:

private:
    //const int input_layer_total = 100;

    //const int output_layer_total = 6;

    int hidden_layer_total;//隐藏层的层数

    int hidden_layer_node;//隐藏层每层的节点数目
    //const int MAXTIME = 65536;

    node input[100];//输入层
    node output[6];//输出层
    float result[6];//网络识别的结果存储在这个数组内
    node** hidden;
};

#endif // NETWORK_H
