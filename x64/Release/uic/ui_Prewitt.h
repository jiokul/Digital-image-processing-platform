/********************************************************************************
** Form generated from reading UI file 'Prewitt.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PREWITT_H
#define UI_PREWITT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "MyLabel.h"

QT_BEGIN_NAMESPACE

class Ui_Prewitt
{
public:
    QGridLayout *gridLayout;
    MyLabel *Pview;
    QPushButton *pushButton;

    void setupUi(QWidget *Prewitt)
    {
        if (Prewitt->objectName().isEmpty())
            Prewitt->setObjectName(QString::fromUtf8("Prewitt"));
        Prewitt->resize(800, 600);
        gridLayout = new QGridLayout(Prewitt);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        Pview = new MyLabel(Prewitt);
        Pview->setObjectName(QString::fromUtf8("Pview"));

        gridLayout->addWidget(Pview, 1, 0, 1, 1);

        pushButton = new QPushButton(Prewitt);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 0, 0, 1, 1, Qt::AlignRight);


        retranslateUi(Prewitt);

        QMetaObject::connectSlotsByName(Prewitt);
    } // setupUi

    void retranslateUi(QWidget *Prewitt)
    {
        Prewitt->setWindowTitle(QCoreApplication::translate("Prewitt", "Prewitt", nullptr));
        Pview->setText(QString());
        pushButton->setText(QCoreApplication::translate("Prewitt", "\344\277\235\345\255\230\345\233\276\347\211\207", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Prewitt: public Ui_Prewitt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PREWITT_H
