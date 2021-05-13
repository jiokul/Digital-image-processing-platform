/********************************************************************************
** Form generated from reading UI file 'Egary.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EGARY_H
#define UI_EGARY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QWidget>
#include "MyLabel.h"

QT_BEGIN_NAMESPACE

class Ui_Egary
{
public:
    QGridLayout *gridLayout;
    MyLabel *label;

    void setupUi(QWidget *Egary)
    {
        if (Egary->objectName().isEmpty())
            Egary->setObjectName(QString::fromUtf8("Egary"));
        Egary->resize(800, 600);
        gridLayout = new QGridLayout(Egary);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new MyLabel(Egary);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);


        retranslateUi(Egary);

        QMetaObject::connectSlotsByName(Egary);
    } // setupUi

    void retranslateUi(QWidget *Egary)
    {
        Egary->setWindowTitle(QCoreApplication::translate("Egary", "Egary", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Egary: public Ui_Egary {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EGARY_H
