/********************************************************************************
** Form generated from reading UI file 'Equalization.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EQUALIZATION_H
#define UI_EQUALIZATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QWidget>
#include "mylabel.h"

QT_BEGIN_NAMESPACE

class Ui_Equalization
{
public:
    QGridLayout *gridLayout;
    MyLabel *Eview;

    void setupUi(QWidget *Equalization)
    {
        if (Equalization->objectName().isEmpty())
            Equalization->setObjectName(QString::fromUtf8("Equalization"));
        Equalization->resize(800, 600);
        gridLayout = new QGridLayout(Equalization);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        Eview = new MyLabel(Equalization);
        Eview->setObjectName(QString::fromUtf8("Eview"));

        gridLayout->addWidget(Eview, 0, 0, 1, 1);


        retranslateUi(Equalization);

        QMetaObject::connectSlotsByName(Equalization);
    } // setupUi

    void retranslateUi(QWidget *Equalization)
    {
        Equalization->setWindowTitle(QCoreApplication::translate("Equalization", "Equalization", nullptr));
        Eview->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Equalization: public Ui_Equalization {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EQUALIZATION_H
