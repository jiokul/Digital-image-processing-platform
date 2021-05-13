/********************************************************************************
** Form generated from reading UI file 'start.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_START_H
#define UI_START_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QWidget>
#include "MyLabel.h"

QT_BEGIN_NAMESPACE

class Ui_start
{
public:
    QGridLayout *gridLayout;
    MyLabel *Sview;

    void setupUi(QWidget *start)
    {
        if (start->objectName().isEmpty())
            start->setObjectName(QString::fromUtf8("start"));
        start->resize(800, 600);
        gridLayout = new QGridLayout(start);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        Sview = new MyLabel(start);
        Sview->setObjectName(QString::fromUtf8("Sview"));

        gridLayout->addWidget(Sview, 0, 0, 1, 1);


        retranslateUi(start);

        QMetaObject::connectSlotsByName(start);
    } // setupUi

    void retranslateUi(QWidget *start)
    {
        start->setWindowTitle(QCoreApplication::translate("start", "start", nullptr));
        Sview->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class start: public Ui_start {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_START_H
