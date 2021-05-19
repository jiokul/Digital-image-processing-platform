/********************************************************************************
** Form generated from reading UI file 'Binariza.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BINARIZA_H
#define UI_BINARIZA_H

#include "MyLabel.h"
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Binariza
{
public:
    QGridLayout *gridLayout;
    MyLabel *LBview;
    QPushButton *pushButton;

    void setupUi(QWidget *Binariza)
    {
        if (Binariza->objectName().isEmpty())
            Binariza->setObjectName(QString::fromUtf8("Binariza"));
        Binariza->resize(800, 600);
        Binariza->setMinimumSize(QSize(0, 0));
        gridLayout = new QGridLayout(Binariza);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        LBview = new MyLabel(Binariza);
        LBview->setObjectName(QString::fromUtf8("LBview"));
        LBview->setBaseSize(QSize(800, 600));

        gridLayout->addWidget(LBview, 1, 0, 1, 1);

        pushButton = new QPushButton(Binariza);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 0, 0, 1, 1, Qt::AlignRight);


        retranslateUi(Binariza);

        QMetaObject::connectSlotsByName(Binariza);
    } // setupUi

    void retranslateUi(QWidget *Binariza)
    {
        Binariza->setWindowTitle(QCoreApplication::translate("Binariza", "Binariza", nullptr));
        LBview->setText(QString());
        pushButton->setText(QCoreApplication::translate("Binariza", "\344\277\235\345\255\230", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Binariza: public Ui_Binariza {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BINARIZA_H
