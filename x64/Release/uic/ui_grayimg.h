/********************************************************************************
** Form generated from reading UI file 'grayimg.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAYIMG_H
#define UI_GRAYIMG_H

#include <MyLabel.h>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Binariza
{
public:
    QGridLayout *gridLayout;
    MyLabel *LBview;

    void setupUi(QWidget *Binariza)
    {
        if (Binariza->objectName().isEmpty())
            Binariza->setObjectName(QString::fromUtf8("Binariza"));
        Binariza->resize(640, 415);
        gridLayout = new QGridLayout(Binariza);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        LBview = new MyLabel(Binariza);
        LBview->setObjectName(QString::fromUtf8("LBview"));

        gridLayout->addWidget(LBview, 0, 0, 1, 1);


        retranslateUi(Binariza);

        QMetaObject::connectSlotsByName(Binariza);
    } // setupUi

    void retranslateUi(QWidget *Binariza)
    {
        Binariza->setWindowTitle(QCoreApplication::translate("Binariza", "Binariza", nullptr));
        LBview->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Binariza: public Ui_Binariza {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAYIMG_H
