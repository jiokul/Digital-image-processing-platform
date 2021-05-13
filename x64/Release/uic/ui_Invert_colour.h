/********************************************************************************
** Form generated from reading UI file 'Invert_colour.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INVERT_COLOUR_H
#define UI_INVERT_COLOUR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QWidget>
#include "MyLabel.h"

QT_BEGIN_NAMESPACE

class Ui_Invert_colour
{
public:
    QGridLayout *gridLayout;
    MyLabel *label;

    void setupUi(QWidget *Invert_colour)
    {
        if (Invert_colour->objectName().isEmpty())
            Invert_colour->setObjectName(QString::fromUtf8("Invert_colour"));
        Invert_colour->resize(800, 600);
        gridLayout = new QGridLayout(Invert_colour);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new MyLabel(Invert_colour);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);


        retranslateUi(Invert_colour);

        QMetaObject::connectSlotsByName(Invert_colour);
    } // setupUi

    void retranslateUi(QWidget *Invert_colour)
    {
        Invert_colour->setWindowTitle(QCoreApplication::translate("Invert_colour", "Invert_colour", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Invert_colour: public Ui_Invert_colour {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INVERT_COLOUR_H
