/********************************************************************************
** Form generated from reading UI file 'DoubleSubmit.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOUBLESUBMIT_H
#define UI_DOUBLESUBMIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DoubleSubmit
{
public:
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_3;

    void setupUi(QWidget *DoubleSubmit)
    {
        if (DoubleSubmit->objectName().isEmpty())
            DoubleSubmit->setObjectName(QString::fromUtf8("DoubleSubmit"));
        DoubleSubmit->resize(387, 276);
        gridLayout = new QGridLayout(DoubleSubmit);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton = new QPushButton(DoubleSubmit);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 0, 0, 1, 1);

        lineEdit = new QLineEdit(DoubleSubmit);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 0, 1, 1, 1);

        pushButton_2 = new QPushButton(DoubleSubmit);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 1, 0, 1, 1);

        lineEdit_2 = new QLineEdit(DoubleSubmit);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        gridLayout->addWidget(lineEdit_2, 1, 1, 1, 1);

        pushButton_3 = new QPushButton(DoubleSubmit);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 2, 0, 1, 2);


        retranslateUi(DoubleSubmit);

        QMetaObject::connectSlotsByName(DoubleSubmit);
    } // setupUi

    void retranslateUi(QWidget *DoubleSubmit)
    {
        DoubleSubmit->setWindowTitle(QCoreApplication::translate("DoubleSubmit", "DoubleSubmit", nullptr));
        pushButton->setText(QCoreApplication::translate("DoubleSubmit", "\346\217\220\344\272\244\344\275\216\351\230\210\345\200\274", nullptr));
        pushButton_2->setText(QCoreApplication::translate("DoubleSubmit", "\346\217\220\344\272\244\351\253\230\351\230\210\345\200\274", nullptr));
        lineEdit_2->setText(QString());
        pushButton_3->setText(QCoreApplication::translate("DoubleSubmit", "\344\277\256\346\224\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DoubleSubmit: public Ui_DoubleSubmit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOUBLESUBMIT_H
