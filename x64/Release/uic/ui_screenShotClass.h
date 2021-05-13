/********************************************************************************
** Form generated from reading UI file 'screenShotClass.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCREENSHOTCLASS_H
#define UI_SCREENSHOTCLASS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_screenShotClass
{
public:
    QPushButton *pushButton;
    QLineEdit *lineEditFileName;
    QLineEdit *lineEditFileDir;
    QPushButton *getDirBtn;
    QComboBox *comboBox;

    void setupUi(QWidget *screenShotClass)
    {
        if (screenShotClass->objectName().isEmpty())
            screenShotClass->setObjectName(QString::fromUtf8("screenShotClass"));
        screenShotClass->resize(546, 336);
        pushButton = new QPushButton(screenShotClass);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(240, 270, 93, 28));
        lineEditFileName = new QLineEdit(screenShotClass);
        lineEditFileName->setObjectName(QString::fromUtf8("lineEditFileName"));
        lineEditFileName->setGeometry(QRect(52, 180, 291, 21));
        lineEditFileDir = new QLineEdit(screenShotClass);
        lineEditFileDir->setObjectName(QString::fromUtf8("lineEditFileDir"));
        lineEditFileDir->setGeometry(QRect(52, 40, 291, 21));
        getDirBtn = new QPushButton(screenShotClass);
        getDirBtn->setObjectName(QString::fromUtf8("getDirBtn"));
        getDirBtn->setGeometry(QRect(350, 40, 93, 28));
        comboBox = new QComboBox(screenShotClass);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(180, 120, 87, 22));

        retranslateUi(screenShotClass);

        QMetaObject::connectSlotsByName(screenShotClass);
    } // setupUi

    void retranslateUi(QWidget *screenShotClass)
    {
        screenShotClass->setWindowTitle(QCoreApplication::translate("screenShotClass", "screenShotClass", nullptr));
        pushButton->setText(QCoreApplication::translate("screenShotClass", "\347\241\256\345\256\232", nullptr));
        getDirBtn->setText(QCoreApplication::translate("screenShotClass", "\346\211\223\345\274\200\346\226\207\344\273\266\345\244\271", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("screenShotClass", "jpg", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("screenShotClass", "bmp", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("screenShotClass", "png", nullptr));

    } // retranslateUi

};

namespace Ui {
    class screenShotClass: public Ui_screenShotClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCREENSHOTCLASS_H
