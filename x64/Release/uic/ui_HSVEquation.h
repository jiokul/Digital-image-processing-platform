/********************************************************************************
** Form generated from reading UI file 'HSVEquation.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HSVEQUATION_H
#define UI_HSVEQUATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QWidget>
#include "MyLabel.h"

QT_BEGIN_NAMESPACE

class Ui_HSVEquation
{
public:
    QGridLayout *gridLayout;
    MyLabel *label;

    void setupUi(QWidget *HSVEquation)
    {
        if (HSVEquation->objectName().isEmpty())
            HSVEquation->setObjectName(QString::fromUtf8("HSVEquation"));
        HSVEquation->resize(800, 600);
        gridLayout = new QGridLayout(HSVEquation);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new MyLabel(HSVEquation);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);


        retranslateUi(HSVEquation);

        QMetaObject::connectSlotsByName(HSVEquation);
    } // setupUi

    void retranslateUi(QWidget *HSVEquation)
    {
        HSVEquation->setWindowTitle(QCoreApplication::translate("HSVEquation", "HSVEquation", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class HSVEquation: public Ui_HSVEquation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HSVEQUATION_H
