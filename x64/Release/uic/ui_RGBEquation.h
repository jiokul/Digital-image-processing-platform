/********************************************************************************
** Form generated from reading UI file 'RGBEquation.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RGBEQUATION_H
#define UI_RGBEQUATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QWidget>
#include "MyLabel.h"

QT_BEGIN_NAMESPACE

class Ui_RGBEquation
{
public:
    QGridLayout *gridLayout;
    MyLabel *RGBlabel;

    void setupUi(QWidget *RGBEquation)
    {
        if (RGBEquation->objectName().isEmpty())
            RGBEquation->setObjectName(QString::fromUtf8("RGBEquation"));
        RGBEquation->resize(800, 600);
        gridLayout = new QGridLayout(RGBEquation);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        RGBlabel = new MyLabel(RGBEquation);
        RGBlabel->setObjectName(QString::fromUtf8("RGBlabel"));

        gridLayout->addWidget(RGBlabel, 0, 0, 1, 1);


        retranslateUi(RGBEquation);

        QMetaObject::connectSlotsByName(RGBEquation);
    } // setupUi

    void retranslateUi(QWidget *RGBEquation)
    {
        RGBEquation->setWindowTitle(QCoreApplication::translate("RGBEquation", "RGBEquation", nullptr));
        RGBlabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class RGBEquation: public Ui_RGBEquation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RGBEQUATION_H
