#ifndef MYNUMBER_H
#define MYNUMBER_H
#include <qpushbutton.h>
#include<qlineedit.h>
#include"CalculateHandle.h"


class MyButton : public QPushButton
{
    Q_OBJECT
public:

      QLineEdit* screen;
    static const int BUTTONWIDTH=50;
    static const int BUTTONHEIGHT=50;
    static const int INITHEIGHT=70;
    explicit MyButton(QWidget *parent,const QString &text,const int &x=0,const int &y=0);
    void setPosition(const int &x, const int &y);
    QString getContent() const;
    void setScreen(QLineEdit * screen);
    ~MyButton();
private:
    QString content;

signals:
    
public slots:
   void handleButton();

    
};

#endif // MYNUMBER_H
