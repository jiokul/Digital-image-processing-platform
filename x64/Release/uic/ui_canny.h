/********************************************************************************
** Form generated from reading UI file 'canny.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CANNY_H
#define UI_CANNY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "MyLabel.h"

QT_BEGIN_NAMESPACE

class Ui_canny
{
public:
    QGridLayout *gridLayout;
    MyLabel *Cview;
    QPushButton *pushButton;

    void setupUi(QWidget *canny)
    {
        if (canny->objectName().isEmpty())
            canny->setObjectName(QString::fromUtf8("canny"));
        canny->resize(800, 600);
        gridLayout = new QGridLayout(canny);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        Cview = new MyLabel(canny);
        Cview->setObjectName(QString::fromUtf8("Cview"));

        gridLayout->addWidget(Cview, 1, 0, 1, 1);

        pushButton = new QPushButton(canny);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 0, 0, 1, 1, Qt::AlignRight);


        retranslateUi(canny);

        QMetaObject::connectSlotsByName(canny);
    } // setupUi

    void retranslateUi(QWidget *canny)
    {
        canny->setWindowTitle(QCoreApplication::translate("canny", "canny", nullptr));
        Cview->setText(QString());
        pushButton->setText(QCoreApplication::translate("canny", "\344\277\235\345\255\230\345\233\276\347\211\207", nullptr));
    } // retranslateUi

};

namespace Ui {
    class canny: public Ui_canny {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CANNY_H
