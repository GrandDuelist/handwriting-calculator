#include "showpic.h"
#include <QImage>
#include <QPainter>
#include <string>
#include <sstream>
#include <QString>
#include <strstream>
#include <fstream>
using namespace std;

showpic::showpic(QWidget *parent) :
    QWidget(parent)
{
    setAutoFillBackground(true);
    setPalette(QPalette(Qt::white));
    is_Object = true;
    //image = new QImage(40,40,QImage::Format_RGB32);
    //image->fill(Qt::white);
}
void showpic::paintEvent(QPaintEvent *e)
{
    //update需要调用这个函数
    if(is_Object)//第一次调用
    {
        this->image = new QImage(40,40,QImage::Format_RGB32);
        this->image->fill(Qt::white);
        /*QPainter my_painter(this);
        my_painter.drawImage(QPoint(0,0),this->image);*/
        is_Object = false;
    }
    else
    {
        QPainter my_painter(this);
        my_painter.drawImage(QPoint(0,0),*(this->image));
    }
}


void showpic::dispose_pic(QImage *image)
{
    //遍历image中的所有像素点，首先高度切分，然后左右切分，比较两者，取最大的
    //作为正方形的边长，然后将图像缩小到40*40大小
    QColor tempory_color;
    QColor standard(0,0,0);
    bool flag = false;
    int width = 0;
    int heigth = 0;
    int top,bottom,left,right;
    int vertical_length,cross_length;

    //先从上往下找
    for(;heigth < showpic::HEIGHT;heigth++)
    {
        for(width = 0;width < showpic::WIDTH;width++)
        {
            if(image->pixel(width,heigth) == standard.rgb())
            {
                flag = true;
                break;
            }
        }
        if(flag)
            break;
    }
    flag = false;
    top = heigth;

    heigth = 0;
    width = 0;
    //从下往上找

    for(heigth = showpic::HEIGHT-1;heigth > -1;heigth--)
    {
        for(width = 0;width < showpic::WIDTH;width++)
        {
            if(image->pixel(width,heigth) == standard.rgb())
            {
                flag = true;
                break;
            }
        }
        if(flag)
            break;
    }
    flag = false;
    bottom = heigth;

    heigth = 0;
    width = 0;
    //从左向右找
    for(;width < showpic::WIDTH;width++)
    {
        for(heigth = 0;heigth < showpic::HEIGHT;heigth++)
        {
            if(image->pixel(width,heigth) == standard.rgb())
            {
                flag = true;
                break;
            }
        }
        if(flag)
            break;
    }
    flag = false;
    left = width;

    width = 0;
    heigth = 0;
    //从右向左找
    for(width = showpic::WIDTH-1;width > -1;width--)
    {
        for(heigth = 0;heigth < showpic::HEIGHT;heigth++)
        {
            if(image->pixel(width,heigth) == standard.rgb())
            {
                flag = true;
                break;
            }
        }
        if(flag)
            break;
    }
    flag = false;
    right = width;

    vertical_length = bottom - top;
    cross_length = right - left;

    //将图像裁剪出来
    QImage temp_Image = image->copy(left,top,cross_length,vertical_length);

    //裁剪出来后呢，再放进去（放到中间部分）
    //首先需要比较竖向上的距离和横向上的距离
    QImage* t_Image;
    if((bottom - top) > (right - left))
    {
        t_Image = new QImage(bottom-top,bottom-top,QImage::Format_RGB32);
        t_Image->fill(Qt::white);
        int from_width = ((bottom - top)-(right - left))/2;
        QPainter imagePainter;
        imagePainter.begin(t_Image);
        imagePainter.drawImage(QPoint(from_width,0),temp_Image);
        imagePainter.end();
        //将图像缩小
        *this->image = t_Image->scaled(40,40,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
        this->update();
    }
    else
    {
        t_Image = new QImage(right - left,right - left,QImage::Format_RGB32);
        t_Image->fill(Qt::white);
        int from_height = ((right - left)-(bottom - top))/2;
        QPainter imagePainter;
        imagePainter.begin(t_Image);
        imagePainter.drawImage(QPoint(0,from_height),temp_Image);
        imagePainter.end();
        *this->image = t_Image->scaled(40,40,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
        this->update();
    }
}
void showpic::set_image(QImage *image)
{
    this->image = image;
    this->update();
}

void showpic::save_file(int count,string typeName)
{
    //直接计算文件名

    string suffix(".png");
    string path("./pic_data/");
    string filepath,name;
    stringstream stream;
    stream<<count++;
    stream>>name;

    strstream ss;
    ss<<count;
    string countStr;
    ss>>countStr;

    //filepath =path + name + suffix;
    filepath=path+countStr+typeName+suffix;
    QString file(filepath.c_str());


    //文件名计算成功
    this->image->save(file);


    fstream log("./name.txt",ios_base::out | ios_base::app);
    log << countStr+typeName << endl;
}


QImage* showpic::get_image()
{
    return this->image;
}
