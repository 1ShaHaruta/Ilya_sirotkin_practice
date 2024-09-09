/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action;
    QAction *action_2;
    QAction *action_3;
    QAction *action_4;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTextBrowser *textBrowser;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton;
    QDateEdit *dateEdit;
    QPushButton *pushButton_2;
    QLabel *status;
    QLabel *label_2;
    QDateEdit *dateEdit_2;
    QLabel *name;
    QPushButton *pushButton_3;
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QPushButton *pushButton_4;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *menu_4;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(933, 600);
        MainWindow->setMaximumSize(QSize(1920, 1080));
        MainWindow->setMouseTracking(false);
        MainWindow->setAutoFillBackground(false);
        action = new QAction(MainWindow);
        action->setObjectName(QString::fromUtf8("action"));
        action_2 = new QAction(MainWindow);
        action_2->setObjectName(QString::fromUtf8("action_2"));
        action_3 = new QAction(MainWindow);
        action_3->setObjectName(QString::fromUtf8("action_3"));
        action_4 = new QAction(MainWindow);
        action_4->setObjectName(QString::fromUtf8("action_4"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setEnabled(true);
        centralwidget->setAutoFillBackground(false);
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setMaximumSize(QSize(900, 840));
        QFont font;
        font.setFamilies({QString::fromUtf8("URW Gothic [urw]")});
        font.setPointSize(13);
        font.setBold(true);
        textBrowser->setFont(font);

        gridLayout->addWidget(textBrowser, 9, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("URW Gothic [urw]")});
        font1.setPointSize(12);
        font1.setBold(false);
        pushButton->setFont(font1);

        gridLayout_2->addWidget(pushButton, 5, 0, 1, 1);

        dateEdit = new QDateEdit(centralwidget);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setDateTime(QDateTime(QDate(2024, 7, 5), QTime(0, 0, 0)));
        dateEdit->setMinimumDateTime(QDateTime(QDate(2024, 1, 1), QTime(0, 0, 0)));
        dateEdit->setMaximumDate(QDate(2024, 12, 31));

        gridLayout_2->addWidget(dateEdit, 4, 2, 1, 1);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("URW Gothic [urw]")});
        pushButton_2->setFont(font2);

        gridLayout_2->addWidget(pushButton_2, 6, 0, 1, 1);

        status = new QLabel(centralwidget);
        status->setObjectName(QString::fromUtf8("status"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(100);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(status->sizePolicy().hasHeightForWidth());
        status->setSizePolicy(sizePolicy);
        status->setFont(font);
        status->setFrameShape(QFrame::NoFrame);

        gridLayout_2->addWidget(status, 0, 1, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("URW Gothic [urw]")});
        font3.setBold(true);
        label_2->setFont(font3);

        gridLayout_2->addWidget(label_2, 4, 1, 1, 1);

        dateEdit_2 = new QDateEdit(centralwidget);
        dateEdit_2->setObjectName(QString::fromUtf8("dateEdit_2"));
        dateEdit_2->setDateTime(QDateTime(QDate(2024, 7, 5), QTime(0, 0, 0)));
        dateEdit_2->setMaximumDate(QDate(2024, 12, 31));
        dateEdit_2->setMinimumDate(QDate(2024, 1, 1));

        gridLayout_2->addWidget(dateEdit_2, 4, 0, 1, 1);

        name = new QLabel(centralwidget);
        name->setObjectName(QString::fromUtf8("name"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(name->sizePolicy().hasHeightForWidth());
        name->setSizePolicy(sizePolicy1);
        name->setMaximumSize(QSize(1920, 1080));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("URW Gothic [urw]")});
        font4.setPointSize(13);
        font4.setBold(true);
        font4.setUnderline(false);
        name->setFont(font4);
        name->setFrameShape(QFrame::NoFrame);

        gridLayout_2->addWidget(name, 0, 0, 1, 1);

        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setFont(font2);

        gridLayout_2->addWidget(pushButton_3, 7, 0, 1, 1);

        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setFont(font2);

        gridLayout_2->addWidget(comboBox, 5, 2, 1, 1);

        comboBox_2 = new QComboBox(centralwidget);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setFont(font2);

        gridLayout_2->addWidget(comboBox_2, 7, 2, 1, 1);

        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setFont(font2);

        gridLayout_2->addWidget(pushButton_4, 6, 2, 1, 1);


        gridLayout->addLayout(gridLayout_2, 9, 2, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 933, 29));
        menubar->setFont(font);
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        menu_3 = new QMenu(menubar);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        menu_4 = new QMenu(menubar);
        menu_4->setObjectName(QString::fromUtf8("menu_4"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menubar->addAction(menu_3->menuAction());
        menubar->addAction(menu_4->menuAction());
        menu->addAction(action);
        menu_2->addAction(action_2);
        menu_3->addAction(action_3);
        menu_4->addAction(action_4);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        action->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \321\206\320\262\320\265\321\202\321\213", nullptr));
        action_2->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \320\272\320\276\320\274\320\277\320\276\320\267\320\270\321\206\320\270\320\270", nullptr));
        action_3->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \320\262\321\201\320\265 \320\267\320\260\320\272\320\260\320\267\321\213", nullptr));
        action_4->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \320\274\320\276\320\270 \320\267\320\260\320\272\320\260\320\267\321\213", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\270\320\261\321\213\320\273\321\214 \320\267\320\260 \321\203\320\272\320\260\320\267\320\260\320\275\320\275\321\213\320\271 \320\277\320\265\321\200\320\270\320\276\320\264", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\277\321\203\320\273\321\217\321\200\320\275\320\276\321\201\321\202\321\214 \320\272\320\276\320\274\320\277\320\276\320\267\320\270\321\206\320\270\320\271", nullptr));
        status->setText(QCoreApplication::translate("MainWindow", "customer", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "       \320\264\320\276", nullptr));
        name->setText(QCoreApplication::translate("MainWindow", "Profile: ", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\273-\320\262\320\276 \320\270\321\201\320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\320\275\321\213\321\205 \321\206\320\262\320\265\321\202\320\276\320\262", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Insert", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "\320\235\320\276\320\262\321\213\320\271 \320\267\320\260\320\272\320\260\320\267", nullptr));

        comboBox_2->setItemText(0, QCoreApplication::translate("MainWindow", "Delete", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("MainWindow", "\320\227\320\260\320\272\320\260\320\267", nullptr));

        pushButton_4->setText(QCoreApplication::translate("MainWindow", "\320\222\321\201\320\265 \320\267\320\260\320\272\320\260\320\267\321\213 \320\275\320\260 \321\215\321\202\321\203 \320\264\320\260\321\202\321\203", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202\321\213", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\274\320\277\320\276\320\267\320\270\321\206\320\270\320\270", nullptr));
        menu_3->setTitle(QCoreApplication::translate("MainWindow", "\320\222\321\201\320\265 \320\267\320\260\320\272\320\260\320\267\321\213", nullptr));
        menu_4->setTitle(QCoreApplication::translate("MainWindow", "\320\234\320\276\320\270 \320\267\320\260\320\272\320\260\320\267\321\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
