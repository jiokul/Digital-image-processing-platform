/********************************************************************************
** Form generated from reading UI file 'DoubleThreshold.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOUBLETHRESHOLD_H
#define UI_DOUBLETHRESHOLD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QWidget>
#include "MyLabel.h"

QT_BEGIN_NAMESPACE

class Ui_DoubleThreshold
{
public:
    QGridLayout *gridLayout;
    MyLabel *label;

    void setupUi(QWidget *DoubleThreshold)
    {
        if (DoubleThreshold->objectName().isEmpty())
            DoubleThreshold->setObjectName(QString::fromUtf8("DoubleThreshold"));
        DoubleThreshold->resize(800, 600);
        gridLayout = new QGridLayout(DoubleThreshold);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new MyLabel(DoubleThreshold);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);


        retranslateUi(DoubleThreshold);

        QMetaObject::connectSlotsByName(DoubleThreshold);
    } // setupUi

    void retranslateUi(QWidget *DoubleThreshold)
    {
        DoubleThreshold->setWindowTitle(QCoreApplication::translate("DoubleThreshold", "DoubleThreshold", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DoubleThreshold: public Ui_DoubleThreshold {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOUBLETHRESHOLD_H
