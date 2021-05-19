/********************************************************************************
** Form generated from reading UI file 'Binariza_turn.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BINARIZA_TURN_H
#define UI_BINARIZA_TURN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "MyLabel.h"

QT_BEGIN_NAMESPACE

class Ui_Binariza_turn
{
public:
    QGridLayout *gridLayout;
    MyLabel *label;
    QPushButton *pushButton;

    void setupUi(QWidget *Binariza_turn)
    {
        if (Binariza_turn->objectName().isEmpty())
            Binariza_turn->setObjectName(QString::fromUtf8("Binariza_turn"));
        Binariza_turn->resize(800, 600);
        gridLayout = new QGridLayout(Binariza_turn);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new MyLabel(Binariza_turn);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        pushButton = new QPushButton(Binariza_turn);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 0, 0, 1, 1, Qt::AlignRight);


        retranslateUi(Binariza_turn);

        QMetaObject::connectSlotsByName(Binariza_turn);
    } // setupUi

    void retranslateUi(QWidget *Binariza_turn)
    {
        Binariza_turn->setWindowTitle(QCoreApplication::translate("Binariza_turn", "Binariza_turn", nullptr));
        label->setText(QString());
        pushButton->setText(QCoreApplication::translate("Binariza_turn", "\344\277\235\345\255\230\345\233\276\347\211\207", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Binariza_turn: public Ui_Binariza_turn {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BINARIZA_TURN_H
