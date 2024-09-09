/********************************************************************************
** Form generated from reading UI file 'delete_form.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETE_FORM_H
#define UI_DELETE_FORM_H

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

class Ui_Delete_form
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLineEdit *comp;
    QLineEdit *count;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QDateEdit *dateEdit;
    QDateEdit *dateEdit_2;

    void setupUi(QDialog *Delete_form)
    {
        if (Delete_form->objectName().isEmpty())
            Delete_form->setObjectName(QString::fromUtf8("Delete_form"));
        Delete_form->resize(400, 265);
        buttonBox = new QDialogButtonBox(Delete_form);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 220, 341, 32));
        QFont font;
        font.setFamilies({QString::fromUtf8("URW Gothic [urw]")});
        font.setBold(true);
        buttonBox->setFont(font);
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        formLayoutWidget = new QWidget(Delete_form);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(29, 50, 341, 161));
        formLayoutWidget->setFont(font);
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        comp = new QLineEdit(formLayoutWidget);
        comp->setObjectName(QString::fromUtf8("comp"));
        comp->setFont(font);

        formLayout->setWidget(0, QFormLayout::FieldRole, comp);

        count = new QLineEdit(formLayoutWidget);
        count->setObjectName(QString::fromUtf8("count"));
        count->setFont(font);

        formLayout->setWidget(1, QFormLayout::FieldRole, count);

        label = new QLabel(formLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        dateEdit = new QDateEdit(formLayoutWidget);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setFont(font);
        dateEdit->setDateTime(QDateTime(QDate(2024, 7, 5), QTime(0, 0, 0)));
        dateEdit->setMaximumDateTime(QDateTime(QDate(2024, 12, 31), QTime(23, 59, 59)));
        dateEdit->setMinimumDateTime(QDateTime(QDate(2024, 1, 1), QTime(0, 0, 0)));

        formLayout->setWidget(2, QFormLayout::FieldRole, dateEdit);

        dateEdit_2 = new QDateEdit(formLayoutWidget);
        dateEdit_2->setObjectName(QString::fromUtf8("dateEdit_2"));
        dateEdit_2->setFont(font);
        dateEdit_2->setDateTime(QDateTime(QDate(2024, 7, 5), QTime(1, 0, 0)));
        dateEdit_2->setMaximumDateTime(QDateTime(QDate(2024, 12, 31), QTime(23, 59, 59)));
        dateEdit_2->setMinimumDateTime(QDateTime(QDate(2024, 7, 5), QTime(1, 0, 0)));

        formLayout->setWidget(3, QFormLayout::FieldRole, dateEdit_2);


        retranslateUi(Delete_form);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, Delete_form, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, Delete_form, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(Delete_form);
    } // setupUi

    void retranslateUi(QDialog *Delete_form)
    {
        Delete_form->setWindowTitle(QCoreApplication::translate("Delete_form", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Delete_form", "Composition", nullptr));
        label_2->setText(QCoreApplication::translate("Delete_form", "Count", nullptr));
        label_3->setText(QCoreApplication::translate("Delete_form", "Order_date", nullptr));
        label_4->setText(QCoreApplication::translate("Delete_form", "Date_of_completion", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Delete_form: public Ui_Delete_form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETE_FORM_H
