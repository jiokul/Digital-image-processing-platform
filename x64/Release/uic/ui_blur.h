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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "MyLabel.h"

QT_BEGIN_NAMESPACE

class Ui_blur
{
public:
    QGridLayout *gridLayout;
    MyLabel *label;
    QPushButton *pushButton;

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

        gridLayout->addWidget(label, 1, 0, 1, 1);

        pushButton = new QPushButton(blur);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 0, 0, 1, 1, Qt::AlignRight);


        retranslateUi(blur);

        QMetaObject::connectSlotsByName(blur);
    } // setupUi

    void retranslateUi(QWidget *blur)
    {
        blur->setWindowTitle(QCoreApplication::translate("blur", "blur", nullptr));
        label->setText(QString());
        pushButton->setText(QCoreApplication::translate("blur", "\344\277\235\345\255\230\345\233\276\347\211\207", nullptr));
    } // retranslateUi

};

namespace Ui {
    class blur: public Ui_blur {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BLUR_H
