/********************************************************************************
** Form generated from reading UI file 'start2.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_START2_H
#define UI_START2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QWidget>
#include "MyLabel.h"

QT_BEGIN_NAMESPACE

class Ui_start2
{
public:
    QGridLayout *gridLayout;
    MyLabel *Sview;

    void setupUi(QWidget *start2)
    {
        if (start2->objectName().isEmpty())
            start2->setObjectName(QString::fromUtf8("start2"));
        start2->resize(800, 600);
        gridLayout = new QGridLayout(start2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        Sview = new MyLabel(start2);
        Sview->setObjectName(QString::fromUtf8("Sview"));

        gridLayout->addWidget(Sview, 0, 0, 1, 1);


        retranslateUi(start2);

        QMetaObject::connectSlotsByName(start2);
    } // setupUi

    void retranslateUi(QWidget *start2)
    {
        start2->setWindowTitle(QCoreApplication::translate("start2", "start2", nullptr));
        Sview->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class start2: public Ui_start2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_START2_H
