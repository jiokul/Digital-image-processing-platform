/********************************************************************************
** Form generated from reading UI file 'Qsave.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QSAVE_H
#define UI_QSAVE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Qsave
{
public:
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QComboBox *comboBox_2;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton_4;
    QLineEdit *lineEdit_4;
    QPushButton *pushButton_2;

    void setupUi(QWidget *Qsave)
    {
        if (Qsave->objectName().isEmpty())
            Qsave->setObjectName(QString::fromUtf8("Qsave"));
        Qsave->resize(349, 326);
        gridLayout = new QGridLayout(Qsave);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton = new QPushButton(Qsave);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 0, 0, 1, 1);

        lineEdit = new QLineEdit(Qsave);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 0, 1, 1, 1);

        comboBox_2 = new QComboBox(Qsave);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));

        gridLayout->addWidget(comboBox_2, 1, 0, 1, 1);

        lineEdit_3 = new QLineEdit(Qsave);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        gridLayout->addWidget(lineEdit_3, 1, 1, 1, 1);

        pushButton_4 = new QPushButton(Qsave);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        gridLayout->addWidget(pushButton_4, 2, 0, 1, 1);

        lineEdit_4 = new QLineEdit(Qsave);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        gridLayout->addWidget(lineEdit_4, 2, 1, 1, 1);

        pushButton_2 = new QPushButton(Qsave);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 3, 1, 1, 1, Qt::AlignLeft);


        retranslateUi(Qsave);

        QMetaObject::connectSlotsByName(Qsave);
    } // setupUi

    void retranslateUi(QWidget *Qsave)
    {
        Qsave->setWindowTitle(QCoreApplication::translate("Qsave", "Qsave", nullptr));
        pushButton->setText(QCoreApplication::translate("Qsave", "\351\200\211\346\213\251\350\267\257\345\276\204", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("Qsave", "JPG", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("Qsave", "PNG", nullptr));
        comboBox_2->setItemText(2, QCoreApplication::translate("Qsave", "BMP", nullptr));

        pushButton_4->setText(QCoreApplication::translate("Qsave", "\346\217\220\344\272\244\345\233\276\347\211\207\345\220\215\347\247\260", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Qsave", "\344\277\235\345\255\230", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Qsave: public Ui_Qsave {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QSAVE_H
