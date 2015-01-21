#ifndef SHOWPIC_H
#define SHOWPIC_H

#include <QWidget>
#include <string>
using namespace std;

class showpic : public QWidget
{
    Q_OBJECT
public:
    explicit showpic(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);//处理绘图事件
    void dispose_pic(QImage* image);//处理图像的方法
    void set_image(QImage* image);
    void save_file(int count,string typeName);//保存文件
    QImage* get_image();//获取图像
    //QImage* add_noise();//把图像加噪声
    const static int WIDTH=150;
    const static int HEIGHT=150;
signals:
    
public slots:
private:
    QImage* image;
    bool is_Object;
};

#endif // SHOWPIC_H
