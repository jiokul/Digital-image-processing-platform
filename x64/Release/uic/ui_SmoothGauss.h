/********************************************************************************
** Form generated from reading UI file 'SmoothGauss.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SMOOTHGAUSS_H
#define UI_SMOOTHGAUSS_H

#include "MyLabel.h"
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SmoothGauss
{
public:
    QGridLayout *gridLayout;
    MyLabel *Sview;

    void setupUi(QWidget *SmoothGauss)
    {
        if (SmoothGauss->objectName().isEmpty())
            SmoothGauss->setObjectName(QString::fromUtf8("SmoothGauss"));
        SmoothGauss->resize(800, 600);
        gridLayout = new QGridLayout(SmoothGauss);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        Sview = new MyLabel(SmoothGauss);
        Sview->setObjectName(QString::fromUtf8("Sview"));

        gridLayout->addWidget(Sview, 0, 0, 1, 1);


        retranslateUi(SmoothGauss);

        QMetaObject::connectSlotsByName(SmoothGauss);
    } // setupUi

    void retranslateUi(QWidget *SmoothGauss)
    {
        SmoothGauss->setWindowTitle(QCoreApplication::translate("SmoothGauss", "SmoothGauss", nullptr));
        Sview->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SmoothGauss: public Ui_SmoothGauss {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SMOOTHGAUSS_H
