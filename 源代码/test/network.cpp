#include "network.h"


#include <time.h>
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <cmath>
using namespace std;

void network::initial_Net()
{
    //初始化输入层的权值
     //srand((unsigned)time(NULL));
     for(int i =0;i<input_layer_total;i++)
     {
         for(int k = 0;k<network::hidden_layer_node;k++)
         {
             network::input[i].weight[k] = rand() /(double)(RAND_MAX/2) - 1;
             //cout<<network::input[i].weight[k]<<endl;
         }
     }
     //初始化隐藏层的权值和阈值
     int count=0;
     for(int i =0;i<network::hidden_layer_total-1;i++)
     {
         for(int k =0;k<network::hidden_layer_node;k++)
         {
             //初始化阈值
             network::hidden[i][k].threshold = rand() /(double)(RAND_MAX/2) - 1;
             for(int j =0;j<network::hidden_layer_node;j++)
             {
                 network::hidden[i][k].weight[j] = rand() /(double)(RAND_MAX/2) - 1;
                 //cout<<network::hidden[i][k].weight[j]<<endl;
             }
             //cout<<count++<<endl;
         }
     }
     //进行最后一层隐藏层的权值初始化
     for(int i = 0;i<network::hidden_layer_node;i++)
     {
         //初始化阈值
         network::hidden[network::hidden_layer_total-1][i].threshold = rand() /(double)(RAND_MAX/2) - 1;
         for(int k = 0;k<output_layer_total;k++)
         {
             network::hidden[network::hidden_layer_total-1][i].weight[k] = rand() /(double)(RAND_MAX/2) - 1;
             //cout<<network::hidden[network::hidden_layer_total-1][i].weight[k]<<endl;
         }
         //cout<<count++<<endl;
     }
     //初始化输出层的阈值
     for(int i = 0;i<output_layer_total;i++)
     {
         network::output[i].threshold = rand() /(double)(RAND_MAX/2) - 1;
     }
}
void network::save_Net()
{
    //默认的数据文件的存放地址是当前工作目录
    string filepath("./data.txt");
    //ifstream infile(filepath.c_str());
    ofstream outfile(filepath.c_str());

    if(outfile)
    {
        outfile<<"隐藏层层数： ";
        outfile<<network::hidden_layer_total<<endl;
        //cout<<network::hidden_layer_total<<endl;
        outfile<<"单层隐藏层的节点数： ";
        outfile<<network::hidden_layer_node<<endl;
        outfile<<"权值数据:"<<endl;
        //保存输入层
        for(int i =0;i<input_layer_total;i++)
        {
            for(int k =0;k<network::hidden_layer_node;k++)
            {
                //cout<<network::input[i].weight[k]<<endl;
                outfile<<network::input[i].weight[k]<<endl;
                //cout<<network::input[i].weight[k]<<endl;
            }
        }

        //保存隐藏层
        for(int i =0;i<network::hidden_layer_total-1;i++)
        {
            for(int k =0;k<network::hidden_layer_node;k++)
            {
                for(int j =0;j<network::hidden_layer_node;j++)
                {
                    outfile<<network::hidden[i][k].weight[j]<<endl;
                }
            }
        }
        for(int i =0;i<network::hidden_layer_node;i++)
        {
            for(int k =0;k<output_layer_total;k++)
            {
                outfile<<network::hidden[network::hidden_layer_total-1][i].weight[k]<<endl;
            }
        }

        //保存阈值
        outfile<<"阈值数据： "<<endl;

        for(int i =0;i<network::hidden_layer_total;i++)
        {
            for(int k = 0;k<network::hidden_layer_node;k++)
            {
                outfile<<network::hidden[i][k].threshold<<endl;
            }
        }
        for(int i =0;i<output_layer_total;i++)
        {
            outfile<<network::output[i].threshold<<endl;
        }
        outfile.close();
    }
    /*string str;
    infile>>str;
    int value;
    float value1;
    infile>>value;
    cout<<value<<endl;
    infile>>str>>value;
    infile>>str;
    infile>>value1;
    cout<<value1<<endl;*/
}
void network::readNet()
{
    ////默认的数据文件的存放地址是当前工作目录
    string filepath("./data.txt");
    ifstream infile(filepath.c_str());
    string str;
    int test;
    float data;

    infile>>str>>test;
    if(test != network::hidden_layer_total)
    {
        cout<<"当前网络结构与输入文件格式不符"<<endl;
        return;
    }
    infile>>str>>test;
    if(test != network::hidden_layer_node)
    {
        cout<<"当前网络结构与输入文件格式不符"<<endl;
        return;
    }
    infile>>str;
    //读取输入层的权值
    for(int i =0;i<input_layer_total;i++)
    {
        for(int k =0;k<network::hidden_layer_node;k++)
        {
            //cout<<network::input[i].weight[k]<<endl;
            infile>>data;
            network::input[i].weight[k] = data;
            //outfile<<network::input[i].weight[k]<<endl;
            //cout<<network::input[i].weight[k]<<endl;
        }
    }

    //读取隐藏层的权值
    for(int i =0;i<network::hidden_layer_total-1;i++)
    {
        for(int k =0;k<network::hidden_layer_node;k++)
        {
            for(int j =0;j<network::hidden_layer_node;j++)
            {
                infile>>data;
                network::hidden[i][k].weight[j] = data;
                //outfile<<network::hidden[i][k].weight[j]<<endl;
            }
        }
    }
    for(int i =0;i<network::hidden_layer_node;i++)
    {
        for(int k =0;k<output_layer_total;k++)
        {
            infile>>data;
            network::hidden[network::hidden_layer_total-1][i].weight[k] = data;
            //outfile<<network::hidden[network::hidden_layer_total-1][i].weight[k]<<endl;
        }
    }

    //读取阈值
    infile>>str;
    for(int i =0;i<network::hidden_layer_total;i++)
    {
        for(int k = 0;k<network::hidden_layer_node;k++)
        {
            infile>>data;
            network::hidden[i][k].threshold = data;
            //outfile<<network::hidden[i][k].threshold<<endl;
        }
    }
    for(int i =0;i<output_layer_total;i++)
    {
        infile>>data;
        network::output[i].threshold = data;
        //outfile<<network::output[i].threshold<<endl;
    }
    infile.close();
}
void network::learn_once(float* source)
{
    //学习一次,source是一个float数组，长度为input_layer_total
    //向网络输入数据
    for(int i =0;i<input_layer_total;i++)
    {
        //输入层不对数据进行任何处理
        network::input[i].input_value = source[i];
        network::input[i].output_value = source[i];
    }
    //先单独计算输入层到隐藏层的传递
    float sum = 0.0;
    for(int i =0;i<network::hidden_layer_node;i++)
    {
        for(int k =0;k<input_layer_total;k++)
        {
            sum = sum + network::input[k].weight[i]*network::input[k].output_value;
        }
        sum = sum - network::hidden[0][i].threshold;//计算完成
        network::hidden[0][i].input_value = sum;
        sum = 0.0; //sum初始化
        //计算输出值
        network::hidden[0][i].output_value = 1.0/(1.0 + exp(-network::hidden[0][i].input_value));
    }

    //以下开始计算隐藏层的第一层到倒数第一层的计算传递
    sum = 0.0;
    for(int i =1;i < network::hidden_layer_total;i++)//i代表第几层
    {
        for(int k =0;k<network::hidden_layer_node;k++)//k代表计算一层中第几个结点的输入值
        {
            for(int j =0;j<network::hidden_layer_node;j++)
            {
                sum = sum + network::hidden[i-1][j].output_value * network::hidden[i-1][j].weight[k];
            }
            sum = sum - network::hidden[i][k].threshold;
            network::hidden[i][k].input_value = sum;
            sum = 0.0;
            network::hidden[i][k].output_value = 1.0/(1.0 + exp(-network::hidden[i][k].input_value));
        }
    }
    //计算隐藏层到输出层的计算传递
    sum = 0.0;
    for(int i =0;i<output_layer_total;i++)
    {
        for(int k =0; k<network::hidden_layer_node;k++)
        {
            sum = sum + network::hidden[network::hidden_layer_total-1][k].output_value *
                network::hidden[network::hidden_layer_total-1][k].weight[i];
        }
        sum = sum - network::output[i].threshold;
        network::output[i].input_value = sum;
        sum = 0.0;
        network::output[i].output_value = 1.0/(1.0 + exp(-network::output[i].input_value));
    }
    //将输出层的结果保存到result数组中
    for(int i =0; i< 6;i++)
    {
        network::result[i] = network::output[i].output_value;
    }
}
void network::correctNet(int* source)//数组中只有0和1两个数，但是在实际判别时以
    //0.5为标准，大于0.5当做1，小于0.5当做0
{
    //计算输出层每个单元的误差d
    for(int i = 0;i< output_layer_total;i++)
    {
        network::output[i].error = (source[i] - network::result[i])*network::output[i].output_value* //(y - c)*c*(1 - c)
            (1 - network::output[i].output_value);
    }
    //计算最后一层隐藏层的误差
    float sum = 0;
    for(int i =0;i<network::hidden_layer_node;i++)
    {
        for(int k =0;k<output_layer_total;k++)
        {
            //计算输出层每个结点的误差与最后一层隐藏层每个结点到对应输出层结点权值的乘积和
            sum = sum + network::output[k].error * network::hidden[network::hidden_layer_total-1][i].weight[k];
        }
        //计算完成
        network::hidden[network::hidden_layer_total-1][i].error = sum * network::hidden[network::hidden_layer_total-1][i].output_value
            * (1 - network::hidden[network::hidden_layer_total-1][i].output_value);//sum*output_value*(1 - output_value)
        sum = 0.0;
    }
    //继续向前计算误差
    sum = 0.0;
    for(int i = network::hidden_layer_total-1;i>0;i--)
    {
        for(int k =0;k<network::hidden_layer_node;k++)
        {
            for(int j =0;j<network::hidden_layer_node;j++)
            {
                sum = sum + network::hidden[i][j].error * network::hidden[i-1][k].weight[j];
            }
            network::hidden[i-1][k].error = sum * network::hidden[i-1][k].output_value * (1 - network::hidden[i-1][k].output_value);
            sum = 0.0;
        }
    }
    //计算完成
    //计算最后一层隐藏层到输出层的纠正权值和输出层的纠正阈值
    //先修正输出层的阈值
    for(int i =0;i<output_layer_total;i++)
    {
        network::output[i].threshold = network::output[i].threshold + learn_rate * network::output[i].error;
    }
    //修正最后一层隐藏层到输出层的修正权值
    for(int i =0;i<network::hidden_layer_node;i++)
    {
        for(int k = 0;k<output_layer_total;k++)
        {
            //V = V + rate * error * output_value
            network::hidden[network::hidden_layer_total-1][i].weight[k] = network::hidden[network::hidden_layer_total-1][i].weight[k] +
                learn_rate * network::hidden[network::hidden_layer_total-1][i].output_value * network::output[k].error;
        }
    }
    //继续向前计算
    //先计算阈值
    for(int i =0;i<network::hidden_layer_total;i++)
    {
        for(int k =0;k<network::hidden_layer_node;k++)
        {
            network::hidden[i][k].threshold = network::hidden[i][k].threshold + learn_rate * network::hidden[i][k].error;
        }
    }
    //开始修正权值，这里从输入层到中间层的权值开始，一直到倒数第二层的中间层与倒数第一层的中间层的权值完毕
    //注意这里不需要修改中间层到输出层的权值，因为在前面已经修改过
    //首先修正输入层到中间层的权值
    for(int i =0; i< input_layer_total;i++)
    {
       for(int k =0;k<network::hidden_layer_node;k++)
        {
            network::input[i].weight[k] = network::input[i].weight[k] + learn_rate * network::input[i].output_value *
                network::hidden[0][k].error;
        }
    }
    //修正中间层的权值，从第一层开始,不需要修改最后一层到输出层
    for(int i =0;i<network::hidden_layer_total-1;i++)
    {
        for(int k = 0;k<network::hidden_layer_node;k++)
        {
            for(int j =0;j<network::hidden_layer_node;j++)
            {
                //V = V + learn_rate * error * output_value
                network::hidden[i][k].weight[j] = network::hidden[i][k].weight[j] + learn_rate *
                    network::hidden[i][k].output_value * network::hidden[i+1][j].error;
            }
        }
    }
}
bool network::training()
{

    return true;

}
float* network::getResult()
{
    return this->result;
}
