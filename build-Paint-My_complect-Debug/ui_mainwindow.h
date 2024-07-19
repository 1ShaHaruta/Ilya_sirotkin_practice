/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *pen_action;
    QAction *rect_action;
    QAction *triangle_action;
    QAction *circle_action;
    QAction *move_action;
    QAction *tie_action;
    QAction *remove_action;
    QWidget *centralwidget;
    QLabel *display;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        pen_action = new QAction(MainWindow);
        pen_action->setObjectName(QString::fromUtf8("pen_action"));
        rect_action = new QAction(MainWindow);
        rect_action->setObjectName(QString::fromUtf8("rect_action"));
        triangle_action = new QAction(MainWindow);
        triangle_action->setObjectName(QString::fromUtf8("triangle_action"));
        circle_action = new QAction(MainWindow);
        circle_action->setObjectName(QString::fromUtf8("circle_action"));
        move_action = new QAction(MainWindow);
        move_action->setObjectName(QString::fromUtf8("move_action"));
        tie_action = new QAction(MainWindow);
        tie_action->setObjectName(QString::fromUtf8("tie_action"));
        remove_action = new QAction(MainWindow);
        remove_action->setObjectName(QString::fromUtf8("remove_action"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setMinimumSize(QSize(800, 556));
        display = new QLabel(centralwidget);
        display->setObjectName(QString::fromUtf8("display"));
        display->setGeometry(QRect(0, 0, 1920, 1080));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menu->addAction(pen_action);
        menu->addAction(rect_action);
        menu->addAction(triangle_action);
        menu->addAction(circle_action);
        menu_2->addAction(move_action);
        menu_2->addAction(tie_action);
        menu_2->addAction(remove_action);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pen_action->setText(QCoreApplication::translate("MainWindow", "\320\232\320\260\321\200\320\260\320\275\320\264\320\260\321\210", nullptr));
        rect_action->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\321\217\320\274\320\276\321\203\320\263\320\276\320\273\321\214\320\275\320\270\320\272", nullptr));
        triangle_action->setText(QCoreApplication::translate("MainWindow", "\320\242\321\200\320\265\321\203\320\263\320\276\320\273\321\214\320\275\320\270\320\272", nullptr));
        circle_action->setText(QCoreApplication::translate("MainWindow", "\320\236\320\262\320\260\320\273", nullptr));
        move_action->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\274\320\265\321\211\320\265\320\275\320\270\320\265", nullptr));
        tie_action->setText(QCoreApplication::translate("MainWindow", "\320\241\320\262\321\217\320\267\321\213\320\262\320\260\320\275\320\270\320\265", nullptr));
        remove_action->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\265\320\275\320\270\320\265", nullptr));
        display->setText(QString());
        menu->setTitle(QCoreApplication::translate("MainWindow", "\320\230\320\275\321\201\321\202\321\200\321\203\320\274\320\265\320\275\321\202", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "\320\224\320\265\320\271\321\201\321\202\320\262\320\270\320\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
