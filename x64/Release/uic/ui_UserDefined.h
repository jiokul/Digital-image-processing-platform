/********************************************************************************
** Form generated from reading UI file 'UserDefined.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERDEFINED_H
#define UI_USERDEFINED_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserDefined
{
public:
    QLineEdit *myWW;
    QLineEdit *myWL;
    QPushButton *pushButton;

    void setupUi(QWidget *UserDefined)
    {
        if (UserDefined->objectName().isEmpty())
            UserDefined->setObjectName(QString::fromUtf8("UserDefined"));
        UserDefined->resize(352, 178);
        myWW = new QLineEdit(UserDefined);
        myWW->setObjectName(QString::fromUtf8("myWW"));
        myWW->setGeometry(QRect(40, 40, 113, 21));
        myWL = new QLineEdit(UserDefined);
        myWL->setObjectName(QString::fromUtf8("myWL"));
        myWL->setGeometry(QRect(190, 40, 113, 21));
        pushButton = new QPushButton(UserDefined);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(130, 110, 93, 28));

        retranslateUi(UserDefined);

        QMetaObject::connectSlotsByName(UserDefined);
    } // setupUi

    void retranslateUi(QWidget *UserDefined)
    {
        UserDefined->setWindowTitle(QCoreApplication::translate("UserDefined", "UserDefined", nullptr));
        pushButton->setText(QCoreApplication::translate("UserDefined", "\346\217\220\344\272\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserDefined: public Ui_UserDefined {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERDEFINED_H
