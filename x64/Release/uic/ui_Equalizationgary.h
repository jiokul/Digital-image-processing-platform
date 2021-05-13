/********************************************************************************
** Form generated from reading UI file 'Equalizationgary.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EQUALIZATIONGARY_H
#define UI_EQUALIZATIONGARY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QWidget>
#include "MyLabel.h"

QT_BEGIN_NAMESPACE

class Ui_Eview
{
public:
    QGridLayout *gridLayout;
    MyLabel *label;

    void setupUi(QWidget *Eview)
    {
        if (Eview->objectName().isEmpty())
            Eview->setObjectName(QString::fromUtf8("Eview"));
        Eview->resize(717, 552);
        gridLayout = new QGridLayout(Eview);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new MyLabel(Eview);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);


        retranslateUi(Eview);

        QMetaObject::connectSlotsByName(Eview);
    } // setupUi

    void retranslateUi(QWidget *Eview)
    {
        Eview->setWindowTitle(QCoreApplication::translate("Eview", "Equalizationgary", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Eview: public Ui_Eview {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EQUALIZATIONGARY_H
