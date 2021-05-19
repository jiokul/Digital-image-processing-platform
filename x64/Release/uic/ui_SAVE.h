/********************************************************************************
** Form generated from reading UI file 'SAVE.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAVE_H
#define UI_SAVE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SAVE
{
public:
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QLineEdit *lineEdit_4;
    QPushButton *pushButton_4;
    QComboBox *comboBox_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QComboBox *comboBox;
    QPushButton *pushButton_2;

    void setupUi(QWidget *SAVE)
    {
        if (SAVE->objectName().isEmpty())
            SAVE->setObjectName(QString::fromUtf8("SAVE"));
        SAVE->resize(573, 437);
        gridLayout = new QGridLayout(SAVE);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton = new QPushButton(SAVE);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 0, 0, 1, 1);

        lineEdit_4 = new QLineEdit(SAVE);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        gridLayout->addWidget(lineEdit_4, 3, 1, 1, 1);

        pushButton_4 = new QPushButton(SAVE);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        gridLayout->addWidget(pushButton_4, 3, 0, 1, 1);

        comboBox_2 = new QComboBox(SAVE);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));

        gridLayout->addWidget(comboBox_2, 2, 0, 1, 1);

        lineEdit = new QLineEdit(SAVE);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 0, 1, 1, 1);

        lineEdit_2 = new QLineEdit(SAVE);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        gridLayout->addWidget(lineEdit_2, 1, 1, 1, 1);

        lineEdit_3 = new QLineEdit(SAVE);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        gridLayout->addWidget(lineEdit_3, 2, 1, 1, 1);

        comboBox = new QComboBox(SAVE);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        gridLayout->addWidget(comboBox, 1, 0, 1, 1);

        pushButton_2 = new QPushButton(SAVE);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 4, 1, 1, 1, Qt::AlignLeft);


        retranslateUi(SAVE);

        QMetaObject::connectSlotsByName(SAVE);
    } // setupUi

    void retranslateUi(QWidget *SAVE)
    {
        SAVE->setWindowTitle(QCoreApplication::translate("SAVE", "SAVE", nullptr));
        pushButton->setText(QCoreApplication::translate("SAVE", "\351\200\211\346\213\251\350\267\257\345\276\204", nullptr));
        pushButton_4->setText(QCoreApplication::translate("SAVE", "\346\217\220\344\272\244\345\233\276\347\211\207\345\220\215\347\247\260", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("SAVE", "JPG", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("SAVE", "PNG", nullptr));
        comboBox_2->setItemText(2, QCoreApplication::translate("SAVE", "BMP", nullptr));

        comboBox->setItemText(0, QCoreApplication::translate("SAVE", "\347\201\260\345\272\246\345\233\276", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("SAVE", "\345\233\276\351\241\271\346\250\241\347\263\212", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("SAVE", "\351\253\230\346\226\257\345\271\263\346\273\221", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("SAVE", "\345\233\276\345\203\217\351\224\220\345\214\226", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("SAVE", "canny\350\276\271\347\274\230\346\243\200\346\265\213", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("SAVE", "prewitt\350\276\271\347\274\230\346\243\200\346\265\213", nullptr));
        comboBox->setItemText(6, QCoreApplication::translate("SAVE", "otsu\345\233\276\345\203\217\345\210\206\345\211\262", nullptr));
        comboBox->setItemText(7, QCoreApplication::translate("SAVE", "\345\217\214\351\230\210\345\200\274\345\210\206\345\211\262", nullptr));
        comboBox->setItemText(8, QCoreApplication::translate("SAVE", "\347\233\264\346\226\271\345\233\276\345\235\207\350\241\241\345\214\226\345\242\236\345\274\272", nullptr));
        comboBox->setItemText(9, QCoreApplication::translate("SAVE", "\345\275\251\350\211\262\347\233\264\346\226\271\345\233\276\345\235\207\350\241\241\345\214\226\345\242\236\345\274\272", nullptr));
        comboBox->setItemText(10, QCoreApplication::translate("SAVE", "HSI\347\233\264\346\226\271\345\233\276\345\235\207\350\241\241\345\214\226\345\242\236\345\274\272", nullptr));
        comboBox->setItemText(11, QCoreApplication::translate("SAVE", "HSV\347\233\264\346\226\271\345\233\276\345\235\207\350\241\241\345\214\226\345\242\236\345\274\272", nullptr));
        comboBox->setItemText(12, QCoreApplication::translate("SAVE", "\345\233\276\345\203\217\345\217\215\350\211\262", nullptr));

        pushButton_2->setText(QCoreApplication::translate("SAVE", "\344\277\235\345\255\230", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SAVE: public Ui_SAVE {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAVE_H
