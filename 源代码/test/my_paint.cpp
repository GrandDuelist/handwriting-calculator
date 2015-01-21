#include "my_paint.h"
#include <QImage>
#include <QRgb>
#include <QTextEdit>
#include <QMouseEvent>
#include <QPainter>
#include <QPen>
#include <QColor>

My_paint::My_paint(QWidget *parent) :
    QWidget(parent)
{
    setAutoFillBackground(true);
    setPalette(QPalette(Qt::white));
    image = new QImage(150,150,QImage::Format_RGB32);
    image->fill(Qt::white);
    isLeftMouse = false;
    //paint = new QPainter(image);
    //paint->setPen(QPen(Qt::black,10,Qt::SolidLine,Qt::RoundCap));
}

void My_paint::mousePressEvent(QMouseEvent* event)
{
    if(event->button()==Qt::LeftButton)
    {
        isLeftMouse = true;
        startpos = event->pos();
    }
}
void My_paint::mouseMoveEvent(QMouseEvent * event)
{
    QPainter* painter = new QPainter;

    painter->begin(image);
    painter->setPen(QPen(Qt::black,5,Qt::SolidLine,Qt::RoundCap));
    painter->drawLine(startpos,event->pos());
    painter->end();
    startpos = event->pos();
    delete painter;
    update();
}
void My_paint::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawImage(QPoint(0,0),*image);
}
void My_paint::clear()
{
    delete image;
    image = new QImage(150,150,QImage::Format_RGB32);
    image->fill(Qt::white);
    update();
}
void My_paint::dispose_pic()
{
    //遍历image中的所有像素点，首先高度切分，然后左右切分，比较两者，取最大的
    //作为正方形的边长，然后将图像缩小到40*40大小
    /*QColor tempory_color;
    QColor standard(0,0,0);
    bool flag = false;
    int width = 0;
    int heigth = 0;
    int top,bottom,left,right;
    int vertical_length,cross_length;

    //先从上往下找
    for(;heigth < 100;heigth++)
    {
        for(width = 0;width < 100;width++)
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

    for(heigth = 99;heigth > -1;heigth--)
    {
        for(width = 0;width < 100;width++)
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
    for(;width < 100;width++)
    {
        for(heigth = 0;heigth < 100;heigth++)
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
    for(width = 99;width > -1;width--)
    {
        for(heigth = 0;heigth < 100;heigth++)
        {
            if(image->pixel(width,heigth) == standard.rgb())
            {
                flag = false;
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
    QImage temp_Image = image->copy(left,bottom,cross_length,vertical_length);

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
        //将图像缩小
        QImage final_Image = temp_Image.scaled(40,40);

    }
    else
    {

    }
    */
}
QImage* My_paint::get_Iamge()
{
    return this->image;
}
