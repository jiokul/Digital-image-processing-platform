/********************************************************************************
** Form generated from reading UI file 'grayview.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAYVIEW_H
#define UI_GRAYVIEW_H

#include "MyLabel.h"
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_grayview
{
public:
    QGridLayout *gridLayout;
    MyLabel *Gview;
    QPushButton *pushButton;

    void setupUi(QWidget *grayview)
    {
        if (grayview->objectName().isEmpty())
            grayview->setObjectName(QString::fromUtf8("grayview"));
        grayview->resize(800, 600);
        grayview->setSizeIncrement(QSize(800, 600));
        gridLayout = new QGridLayout(grayview);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        Gview = new MyLabel(grayview);
        Gview->setObjectName(QString::fromUtf8("Gview"));

        gridLayout->addWidget(Gview, 1, 0, 1, 1);

        pushButton = new QPushButton(grayview);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 0, 0, 1, 1, Qt::AlignRight);


        retranslateUi(grayview);

        QMetaObject::connectSlotsByName(grayview);
    } // setupUi

    void retranslateUi(QWidget *grayview)
    {
        grayview->setWindowTitle(QCoreApplication::translate("grayview", "grayview", nullptr));
        Gview->setText(QString());
        pushButton->setText(QCoreApplication::translate("grayview", "\344\277\235\345\255\230\345\233\276\347\211\207", nullptr));
    } // retranslateUi

};

namespace Ui {
    class grayview: public Ui_grayview {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAYVIEW_H
