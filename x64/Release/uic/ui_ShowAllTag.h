/********************************************************************************
** Form generated from reading UI file 'ShowAllTag.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWALLTAG_H
#define UI_SHOWALLTAG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ShowAllTag
{
public:
    QGridLayout *gridLayout;
    QSplitter *splitter;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QTableWidget *tableWidget;

    void setupUi(QWidget *ShowAllTag)
    {
        if (ShowAllTag->objectName().isEmpty())
            ShowAllTag->setObjectName(QString::fromUtf8("ShowAllTag"));
        ShowAllTag->resize(514, 600);
        gridLayout = new QGridLayout(ShowAllTag);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        splitter = new QSplitter(ShowAllTag);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Vertical);
        horizontalLayoutWidget = new QWidget(splitter);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit = new QLineEdit(horizontalLayoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        pushButton = new QPushButton(horizontalLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        splitter->addWidget(horizontalLayoutWidget);
        tableWidget = new QTableWidget(splitter);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        splitter->addWidget(tableWidget);

        gridLayout->addWidget(splitter, 0, 0, 1, 1);


        retranslateUi(ShowAllTag);

        QMetaObject::connectSlotsByName(ShowAllTag);
    } // setupUi

    void retranslateUi(QWidget *ShowAllTag)
    {
        ShowAllTag->setWindowTitle(QCoreApplication::translate("ShowAllTag", "ShowAllTag", nullptr));
        pushButton->setText(QCoreApplication::translate("ShowAllTag", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ShowAllTag: public Ui_ShowAllTag {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWALLTAG_H
