#ifndef MY_PAINT_H
#define MY_PAINT_H

#include <QWidget>
#include <QImage>
#include <QRgb>
#include <QTextEdit>
#include <QPoint>
#include <QPainter>
#include <QPen>
#include <QMouseEvent>
class My_paint : public QWidget
{
    Q_OBJECT
public:
    explicit My_paint(QWidget *parent = 0);
    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent * event);
    void paintEvent(QPaintEvent*);
    void clear();
    void dispose_pic();
    QImage* get_Iamge();
signals:
    
public slots:
protected:
private:
    bool isLeftMouse;//用来表示是否是鼠标左键按下的标志位
    QImage* image;
    QPoint startpos;
    QPoint endpos;
    int width;

};

#endif // MY_PAINT_H
