/********************************************************************************
** Form generated from reading UI file 'HSIEquation.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HSIEQUATION_H
#define UI_HSIEQUATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QWidget>
#include "MyLabel.h"

QT_BEGIN_NAMESPACE

class Ui_HSIEquation
{
public:
    QGridLayout *gridLayout;
    MyLabel *HSIview;

    void setupUi(QWidget *HSIEquation)
    {
        if (HSIEquation->objectName().isEmpty())
            HSIEquation->setObjectName(QString::fromUtf8("HSIEquation"));
        HSIEquation->resize(800, 600);
        gridLayout = new QGridLayout(HSIEquation);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        HSIview = new MyLabel(HSIEquation);
        HSIview->setObjectName(QString::fromUtf8("HSIview"));

        gridLayout->addWidget(HSIview, 0, 0, 1, 1);


        retranslateUi(HSIEquation);

        QMetaObject::connectSlotsByName(HSIEquation);
    } // setupUi

    void retranslateUi(QWidget *HSIEquation)
    {
        HSIEquation->setWindowTitle(QCoreApplication::translate("HSIEquation", "HSIEquation", nullptr));
        HSIview->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class HSIEquation: public Ui_HSIEquation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HSIEQUATION_H
