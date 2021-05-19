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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "MyLabel.h"

QT_BEGIN_NAMESPACE

class Ui_HSIEquation
{
public:
    QGridLayout *gridLayout;
    MyLabel *HSIview;
    QPushButton *pushButton;

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

        gridLayout->addWidget(HSIview, 1, 0, 1, 1);

        pushButton = new QPushButton(HSIEquation);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 0, 0, 1, 1, Qt::AlignRight);


        retranslateUi(HSIEquation);

        QMetaObject::connectSlotsByName(HSIEquation);
    } // setupUi

    void retranslateUi(QWidget *HSIEquation)
    {
        HSIEquation->setWindowTitle(QCoreApplication::translate("HSIEquation", "HSIEquation", nullptr));
        HSIview->setText(QString());
        pushButton->setText(QCoreApplication::translate("HSIEquation", "\344\277\235\345\255\230\345\233\276\347\211\207", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HSIEquation: public Ui_HSIEquation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HSIEQUATION_H
