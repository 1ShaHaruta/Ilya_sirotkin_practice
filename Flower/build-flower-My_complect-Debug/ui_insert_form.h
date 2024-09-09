/********************************************************************************
** Form generated from reading UI file 'insert_form.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSERT_FORM_H
#define UI_INSERT_FORM_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Insert_form
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLineEdit *Composition;
    QLabel *label_3;
    QLineEdit *Count;
    QLabel *label_4;
    QDateEdit *dateEdit;
    QLabel *label_5;
    QDateEdit *dateEdit_2;

    void setupUi(QDialog *Insert_form)
    {
        if (Insert_form->objectName().isEmpty())
            Insert_form->setObjectName(QString::fromUtf8("Insert_form"));
        Insert_form->resize(400, 254);
        buttonBox = new QDialogButtonBox(Insert_form);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(50, 210, 301, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        formLayoutWidget = new QWidget(Insert_form);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 20, 371, 178));
        QFont font;
        font.setFamilies({QString::fromUtf8("URW Gothic [urw]")});
        font.setBold(true);
        formLayoutWidget->setFont(font);
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        Composition = new QLineEdit(formLayoutWidget);
        Composition->setObjectName(QString::fromUtf8("Composition"));
        Composition->setFont(font);

        formLayout->setWidget(0, QFormLayout::FieldRole, Composition);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        Count = new QLineEdit(formLayoutWidget);
        Count->setObjectName(QString::fromUtf8("Count"));
        Count->setFont(font);

        formLayout->setWidget(1, QFormLayout::FieldRole, Count);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_4);

        dateEdit = new QDateEdit(formLayoutWidget);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setFont(font);
        dateEdit->setDateTime(QDateTime(QDate(2024, 7, 5), QTime(0, 0, 0)));
        dateEdit->setMaximumDateTime(QDateTime(QDate(2024, 12, 31), QTime(23, 59, 59)));
        dateEdit->setMinimumDateTime(QDateTime(QDate(2024, 1, 1), QTime(0, 0, 0)));

        formLayout->setWidget(2, QFormLayout::FieldRole, dateEdit);

        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        formLayout->setWidget(3, QFormLayout::LabelRole, label_5);

        dateEdit_2 = new QDateEdit(formLayoutWidget);
        dateEdit_2->setObjectName(QString::fromUtf8("dateEdit_2"));
        dateEdit_2->setFont(font);
        dateEdit_2->setDateTime(QDateTime(QDate(2024, 7, 5), QTime(0, 0, 0)));
        dateEdit_2->setMaximumDate(QDate(2024, 12, 31));
        dateEdit_2->setMinimumDate(QDate(2024, 1, 1));

        formLayout->setWidget(3, QFormLayout::FieldRole, dateEdit_2);


        retranslateUi(Insert_form);
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, Insert_form, qOverload<>(&QDialog::reject));
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, Insert_form, qOverload<>(&QDialog::accept));

        QMetaObject::connectSlotsByName(Insert_form);
    } // setupUi

    void retranslateUi(QDialog *Insert_form)
    {
        Insert_form->setWindowTitle(QCoreApplication::translate("Insert_form", "Dialog", nullptr));
        label_2->setText(QCoreApplication::translate("Insert_form", "Composition:", nullptr));
        label_3->setText(QCoreApplication::translate("Insert_form", "Count:", nullptr));
        label_4->setText(QCoreApplication::translate("Insert_form", "Order_date", nullptr));
        label_5->setText(QCoreApplication::translate("Insert_form", "Date_of_completion", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Insert_form: public Ui_Insert_form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSERT_FORM_H
