/********************************************************************************
** Form generated from reading UI file 'Gpicture.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GPICTURE_H
#define UI_GPICTURE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QWidget>
#include "MyLabel.h"
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_Gpicture
{
public:
    QGridLayout *gridLayout;
    MyLabel *Glabel;
    QCustomPlot *Gwidget;

    void setupUi(QWidget *Gpicture)
    {
        if (Gpicture->objectName().isEmpty())
            Gpicture->setObjectName(QString::fromUtf8("Gpicture"));
        Gpicture->resize(800, 600);
        gridLayout = new QGridLayout(Gpicture);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        Glabel = new MyLabel(Gpicture);
        Glabel->setObjectName(QString::fromUtf8("Glabel"));

        gridLayout->addWidget(Glabel, 0, 0, 1, 1);

        Gwidget = new QCustomPlot(Gpicture);
        Gwidget->setObjectName(QString::fromUtf8("Gwidget"));

        gridLayout->addWidget(Gwidget, 0, 1, 1, 1);


        retranslateUi(Gpicture);

        QMetaObject::connectSlotsByName(Gpicture);
    } // setupUi

    void retranslateUi(QWidget *Gpicture)
    {
        Gpicture->setWindowTitle(QCoreApplication::translate("Gpicture", "Gpicture", nullptr));
        Glabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Gpicture: public Ui_Gpicture {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GPICTURE_H
