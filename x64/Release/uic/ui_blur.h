/********************************************************************************
** Form generated from reading UI file 'blur.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BLUR_H
#define UI_BLUR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QWidget>
#include "MyLabel.h"

QT_BEGIN_NAMESPACE

class Ui_blur
{
public:
    QGridLayout *gridLayout;
    MyLabel *label;

    void setupUi(QWidget *blur)
    {
        if (blur->objectName().isEmpty())
            blur->setObjectName(QString::fromUtf8("blur"));
        blur->resize(800, 600);
        gridLayout = new QGridLayout(blur);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new MyLabel(blur);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);


        retranslateUi(blur);

        QMetaObject::connectSlotsByName(blur);
    } // setupUi

    void retranslateUi(QWidget *blur)
    {
        blur->setWindowTitle(QCoreApplication::translate("blur", "blur", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class blur: public Ui_blur {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BLUR_H
