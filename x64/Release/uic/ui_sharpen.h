/********************************************************************************
** Form generated from reading UI file 'sharpen.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHARPEN_H
#define UI_SHARPEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "MyLabel.h"

QT_BEGIN_NAMESPACE

class Ui_sharpen
{
public:
    QGridLayout *gridLayout;
    MyLabel *Sh_view;
    QPushButton *pushButton;

    void setupUi(QWidget *sharpen)
    {
        if (sharpen->objectName().isEmpty())
            sharpen->setObjectName(QString::fromUtf8("sharpen"));
        sharpen->resize(800, 600);
        gridLayout = new QGridLayout(sharpen);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        Sh_view = new MyLabel(sharpen);
        Sh_view->setObjectName(QString::fromUtf8("Sh_view"));

        gridLayout->addWidget(Sh_view, 1, 0, 1, 1);

        pushButton = new QPushButton(sharpen);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 0, 0, 1, 1, Qt::AlignRight);


        retranslateUi(sharpen);

        QMetaObject::connectSlotsByName(sharpen);
    } // setupUi

    void retranslateUi(QWidget *sharpen)
    {
        sharpen->setWindowTitle(QCoreApplication::translate("sharpen", "sharpen", nullptr));
        Sh_view->setText(QString());
        pushButton->setText(QCoreApplication::translate("sharpen", "\344\277\235\345\255\230\345\233\276\347\211\207", nullptr));
    } // retranslateUi

};

namespace Ui {
    class sharpen: public Ui_sharpen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHARPEN_H
