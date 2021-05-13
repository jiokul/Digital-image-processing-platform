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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SAVE
{
public:
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton_4;
    QLineEdit *lineEdit_4;
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QPushButton *pushButton_2;

    void setupUi(QWidget *SAVE)
    {
        if (SAVE->objectName().isEmpty())
            SAVE->setObjectName(QString::fromUtf8("SAVE"));
        SAVE->resize(394, 259);
        pushButton = new QPushButton(SAVE);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 30, 93, 28));
        lineEdit = new QLineEdit(SAVE);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(130, 30, 251, 28));
        lineEdit_2 = new QLineEdit(SAVE);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(130, 80, 251, 28));
        lineEdit_3 = new QLineEdit(SAVE);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(130, 130, 251, 28));
        pushButton_4 = new QPushButton(SAVE);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(10, 180, 93, 28));
        lineEdit_4 = new QLineEdit(SAVE);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(130, 180, 251, 28));
        comboBox = new QComboBox(SAVE);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(10, 80, 93, 28));
        comboBox_2 = new QComboBox(SAVE);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(10, 130, 93, 28));
        pushButton_2 = new QPushButton(SAVE);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(150, 220, 93, 28));

        retranslateUi(SAVE);

        QMetaObject::connectSlotsByName(SAVE);
    } // setupUi

    void retranslateUi(QWidget *SAVE)
    {
        SAVE->setWindowTitle(QCoreApplication::translate("SAVE", "SAVE", nullptr));
        pushButton->setText(QCoreApplication::translate("SAVE", "\351\200\211\346\213\251\350\267\257\345\276\204", nullptr));
        pushButton_4->setText(QCoreApplication::translate("SAVE", "\346\217\220\344\272\244\345\233\276\347\211\207\345\220\215\347\247\260", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("SAVE", "\347\201\260\345\272\246\345\233\276", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("SAVE", "\345\233\276\351\241\271\346\250\241\347\263\212", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("SAVE", "\351\253\230\346\226\257\345\271\263\346\273\221", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("SAVE", "\345\233\276\345\203\217\351\224\220\345\214\226", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("SAVE", "canny\350\276\271\347\274\230\346\243\200\346\265\213", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("SAVE", "otsu\345\233\276\345\203\217\345\210\206\345\211\262", nullptr));
        comboBox->setItemText(6, QCoreApplication::translate("SAVE", "\347\233\264\346\226\271\345\233\276\345\235\207\350\241\241\345\214\226\345\242\236\345\274\272", nullptr));
        comboBox->setItemText(7, QCoreApplication::translate("SAVE", "\345\275\251\350\211\262\347\233\264\346\226\271\345\233\276\345\235\207\350\241\241\345\214\226\345\242\236\345\274\272", nullptr));

        comboBox_2->setItemText(0, QCoreApplication::translate("SAVE", "JPG", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("SAVE", "PNG", nullptr));
        comboBox_2->setItemText(2, QCoreApplication::translate("SAVE", "BMP", nullptr));

        pushButton_2->setText(QCoreApplication::translate("SAVE", "\344\277\235\345\255\230", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SAVE: public Ui_SAVE {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAVE_H
