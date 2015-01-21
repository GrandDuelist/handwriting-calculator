/********************************************************************************
** Form generated from reading UI file 'back.ui'
**
** Created: Fri Jun 28 13:41:34 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BACK_H
#define UI_BACK_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGraphicsView>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Back
{
public:
    QWidget *centralWidget;
    QPushButton *Okbutton;
    QPushButton *cancelbutton;
    QLabel *label;
    QLineEdit *lineEdit;
    QGraphicsView *graphicsView;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Back)
    {
        if (Back->objectName().isEmpty())
            Back->setObjectName(QString::fromUtf8("Back"));
        Back->resize(600, 400);
        centralWidget = new QWidget(Back);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        Okbutton = new QPushButton(centralWidget);
        Okbutton->setObjectName(QString::fromUtf8("Okbutton"));
        Okbutton->setGeometry(QRect(230, 180, 70, 28));
        cancelbutton = new QPushButton(centralWidget);
        cancelbutton->setObjectName(QString::fromUtf8("cancelbutton"));
        cancelbutton->setGeometry(QRect(310, 180, 70, 28));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 60, 91, 31));
        label->setTextFormat(Qt::PlainText);
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(10, 90, 113, 20));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(150, 180, 31, 31));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(130, 250, 40, 40));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(10, 130, 70, 35));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(10, 170, 70, 35));
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(220, 260, 75, 31));
        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(10, 210, 75, 31));
        Back->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Back);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 26));
        Back->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Back);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Back->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Back);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Back->setStatusBar(statusBar);

        retranslateUi(Back);

        QMetaObject::connectSlotsByName(Back);
    } // setupUi

    void retranslateUi(QMainWindow *Back)
    {
        Back->setWindowTitle(QApplication::translate("Back", "MainWindow", 0, QApplication::UnicodeUTF8));
        Okbutton->setText(QApplication::translate("Back", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        cancelbutton->setText(QApplication::translate("Back", "\347\241\256\350\256\244", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Back", "\350\276\223\345\207\272\346\241\206", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Back", "\350\256\260\351\224\231", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Back", "startlearn", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("Back", "save net", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("Back", "\350\257\206\345\210\253", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("Back", "readNet", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Back: public Ui_Back {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BACK_H
