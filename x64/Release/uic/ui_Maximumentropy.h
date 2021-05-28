/********************************************************************************
** Form generated from reading UI file 'Maximumentropy.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAXIMUMENTROPY_H
#define UI_MAXIMUMENTROPY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "MyLabel.h"

QT_BEGIN_NAMESPACE

class Ui_Maximumentropy
{
public:
    QGridLayout *gridLayout;
    MyLabel *label;
    QPushButton *pushButton;

    void setupUi(QWidget *Maximumentropy)
    {
        if (Maximumentropy->objectName().isEmpty())
            Maximumentropy->setObjectName(QString::fromUtf8("Maximumentropy"));
        Maximumentropy->resize(800, 600);
        gridLayout = new QGridLayout(Maximumentropy);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new MyLabel(Maximumentropy);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        pushButton = new QPushButton(Maximumentropy);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 0, 0, 1, 1, Qt::AlignRight);


        retranslateUi(Maximumentropy);

        QMetaObject::connectSlotsByName(Maximumentropy);
    } // setupUi

    void retranslateUi(QWidget *Maximumentropy)
    {
        Maximumentropy->setWindowTitle(QCoreApplication::translate("Maximumentropy", "Maximumentropy", nullptr));
        label->setText(QString());
        pushButton->setText(QCoreApplication::translate("Maximumentropy", "\344\277\235\345\255\230", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Maximumentropy: public Ui_Maximumentropy {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAXIMUMENTROPY_H
