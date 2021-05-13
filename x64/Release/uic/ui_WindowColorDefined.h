/********************************************************************************
** Form generated from reading UI file 'WindowColorDefined.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOWCOLORDEFINED_H
#define UI_WINDOWCOLORDEFINED_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WindowColorDefined
{
public:
    QPushButton *pushButton;
    QLabel *label_WW;
    QLabel *label_WL;
    QLineEdit *lineEdit_WW;
    QLineEdit *lineEdit_WL;

    void setupUi(QWidget *WindowColorDefined)
    {
        if (WindowColorDefined->objectName().isEmpty())
            WindowColorDefined->setObjectName(QString::fromUtf8("WindowColorDefined"));
        WindowColorDefined->resize(389, 234);
        pushButton = new QPushButton(WindowColorDefined);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(150, 170, 93, 28));
        label_WW = new QLabel(WindowColorDefined);
        label_WW->setObjectName(QString::fromUtf8("label_WW"));
        label_WW->setGeometry(QRect(30, 90, 41, 20));
        label_WL = new QLabel(WindowColorDefined);
        label_WL->setObjectName(QString::fromUtf8("label_WL"));
        label_WL->setGeometry(QRect(200, 90, 41, 20));
        lineEdit_WW = new QLineEdit(WindowColorDefined);
        lineEdit_WW->setObjectName(QString::fromUtf8("lineEdit_WW"));
        lineEdit_WW->setGeometry(QRect(70, 90, 113, 21));
        lineEdit_WL = new QLineEdit(WindowColorDefined);
        lineEdit_WL->setObjectName(QString::fromUtf8("lineEdit_WL"));
        lineEdit_WL->setGeometry(QRect(240, 90, 113, 21));

        retranslateUi(WindowColorDefined);

        QMetaObject::connectSlotsByName(WindowColorDefined);
    } // setupUi

    void retranslateUi(QWidget *WindowColorDefined)
    {
        WindowColorDefined->setWindowTitle(QCoreApplication::translate("WindowColorDefined", "WindowColorDefined", nullptr));
        pushButton->setText(QCoreApplication::translate("WindowColorDefined", "\346\217\220\344\272\244", nullptr));
        label_WW->setText(QCoreApplication::translate("WindowColorDefined", "\347\252\227\345\256\275:", nullptr));
        label_WL->setText(QCoreApplication::translate("WindowColorDefined", "\347\252\227\344\275\215:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WindowColorDefined: public Ui_WindowColorDefined {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOWCOLORDEFINED_H
