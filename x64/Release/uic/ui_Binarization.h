/********************************************************************************
** Form generated from reading UI file 'Binarization.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BINARIZATION_H
#define UI_BINARIZATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QWidget>
#include "QVTKWidget.h"

QT_BEGIN_NAMESPACE

class Ui_Binarization
{
public:
    QGridLayout *gridLayout;
    QVTKWidget *Bview;

    void setupUi(QWidget *Binarization)
    {
        if (Binarization->objectName().isEmpty())
            Binarization->setObjectName(QString::fromUtf8("Binarization"));
        Binarization->resize(716, 538);
        gridLayout = new QGridLayout(Binarization);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        Bview = new QVTKWidget(Binarization);
        Bview->setObjectName(QString::fromUtf8("Bview"));

        gridLayout->addWidget(Bview, 0, 0, 1, 1);


        retranslateUi(Binarization);

        QMetaObject::connectSlotsByName(Binarization);
    } // setupUi

    void retranslateUi(QWidget *Binarization)
    {
        Binarization->setWindowTitle(QCoreApplication::translate("Binarization", "Binarization", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Binarization: public Ui_Binarization {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BINARIZATION_H
