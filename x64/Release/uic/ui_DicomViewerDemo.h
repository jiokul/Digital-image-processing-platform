/********************************************************************************
** Form generated from reading UI file 'DicomViewerDemo.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DICOMVIEWERDEMO_H
#define UI_DICOMVIEWERDEMO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DicomViewerDemoClass
{
public:
    QAction *actionOpenFile;
    QAction *actionOpenFolder;
    QAction *actionQuit;
    QAction *actionDefault;
    QAction *actionLungs;
    QAction *actionBrain;
    QAction *actionAbdomen;
    QAction *actionAngio;
    QAction *actionChest;
    QAction *actionBone;
    QAction *actionMediastinum;
    QAction *actionUserDefined;
    QAction *actionUser;
    QAction *actiontest;
    QAction *actionmpr;
    QAction *actionXY;
    QAction *actionXZ;
    QAction *actionYZ;
    QAction *actionDefined;
    QAction *actionBinarization;
    QAction *actionGray;
    QAction *actionSmoothGauss;
    QAction *actionGRAYPICTURE;
    QAction *actionsharpen;
    QAction *actionOTSU;
    QAction *actionPrewieet;
    QAction *actionCanny;
    QAction *actionopen;
    QAction *actionQuit_2;
    QAction *actionEgray;
    QAction *RGBEaction;
    QAction *actionSAVE;
    QAction *actionFANOTSU;
    QAction *actionblur;
    QAction *actionANTICHROMIC;
    QAction *actionHSI;
    QAction *actiondouble;
    QAction *actionHSV;
    QAction *actionmax;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QMenuBar *menuBar;
    QMenu *menufile;
    QMenu *menuedit;
    QMenu *menuview;
    QMenu *menuhelp;
    QMenu *menuWindowColor;
    QMenu *menuMPR;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *menu_4;
    QMenu *menu_5;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *DicomViewerDemoClass)
    {
        if (DicomViewerDemoClass->objectName().isEmpty())
            DicomViewerDemoClass->setObjectName(QString::fromUtf8("DicomViewerDemoClass"));
        DicomViewerDemoClass->resize(790, 67);
        DicomViewerDemoClass->setStyleSheet(QString::fromUtf8("/*\n"
"The MIT License\n"
"\n"
"Copyright (c) 2013-2018 Colin Duquesnoy https://github.com/ColinDuquesnoy/QDarkStyleSheet/blob/master/LICENSE.md\n"
"\n"
"Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated \n"
"documentation files (the \"Software\"), to deal in the Software without restriction, including without limitation the rights to \n"
"use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to \n"
"whom the Software is furnished to do so, subject to the following conditions:\n"
"\n"
"The above copyright notice and this permission notice shall be included in all copies or substantial portions of the \n"
"Software.\n"
"\n"
"THE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT \n"
"LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND \n"
"NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIA"
                        "BLE FOR ANY CLAIM, \n"
"DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT \n"
"OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.\n"
"*/\n"
"\n"
"\n"
"QToolTip {\n"
"    border: 1px solid #76797C;\n"
"    background-color: #5A7566;\n"
"    color: white;\n"
"    padding: 0px;                /*remove padding, for fix combobox tooltip.*/\n"
"    opacity: 200;\n"
"}\n"
"\n"
"QWidget {\n"
"    color: #eff0f1;\n"
"    background-color: #31363b;\n"
"    selection-background-color: #3daee9;\n"
"    selection-color: #eff0f1;\n"
"    background-clip: border;\n"
"    border-image: none;\n"
"    border: 0px transparent black;\n"
"    outline: 0;\n"
"}\n"
"\n"
"QWidget:item:hover {\n"
"    background-color: #18465d;\n"
"    color: #eff0f1;\n"
"}\n"
"\n"
"QWidget:item:selected {\n"
"    background-color: #18465d;\n"
"}\n"
"\n"
"QGroupBox::indicator {\n"
"    width: 18px;\n"
"    height: 18px;\n"
"}\n"
"\n"
"QGroupBox::indicator {\n"
"    margi"
                        "n-left: 2px;\n"
"}\n"
"\n"
"QGroupBox::indicator:unchecked {\n"
"    image: url(:/qss_icons/rc/checkbox_unchecked.png);\n"
"}\n"
"\n"
"QGroupBox::indicator:unchecked:hover,\n"
"QGroupBox::indicator:unchecked:focus,\n"
"QGroupBox::indicator:unchecked:pressed {\n"
"    border: none;\n"
"    image: url(:/qss_icons/rc/checkbox_unchecked_focus.png);\n"
"}\n"
"\n"
"QGroupBox::indicator:checked {\n"
"    image: url(:/qss_icons/rc/checkbox_checked.png);\n"
"}\n"
"\n"
"QGroupBox::indicator:checked:hover,\n"
"QGroupBox::indicator:checked:focus,\n"
"QGroupBox::indicator:checked:pressed {\n"
"    border: none;\n"
"    image: url(:/qss_icons/rc/checkbox_checked_focus.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:indeterminate {\n"
"    image: url(:/qss_icons/rc/checkbox_indeterminate.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:indeterminate:focus,\n"
"QCheckBox::indicator:indeterminate:hover,\n"
"QCheckBox::indicator:indeterminate:pressed {\n"
"    image: url(:/qss_icons/rc/checkbox_indeterminate_focus.png);\n"
"}\n"
"\n"
"QChec"
                        "kBox::indicator:checked:disabled,\n"
"QGroupBox::indicator:checked:disabled {\n"
"    image: url(:/qss_icons/rc/checkbox_checked_disabled.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:disabled,\n"
"QGroupBox::indicator:unchecked:disabled {\n"
"    image: url(:/qss_icons/rc/checkbox_unchecked_disabled.png);\n"
"}\n"
"\n"
"QRadioButton {\n"
"    spacing: 5px;\n"
"    outline: none;\n"
"    color: #eff0f1;\n"
"    margin-bottom: 2px;\n"
"}\n"
"\n"
"QRadioButton:disabled {\n"
"    color: #76797C;\n"
"}\n"
"\n"
"QRadioButton::indicator {\n"
"    width: 21px;\n"
"    height: 21px;\n"
"}\n"
"\n"
"QRadioButton::indicator:unchecked {\n"
"    image: url(:/qss_icons/rc/radio_unchecked.png);\n"
"}\n"
"\n"
"QRadioButton::indicator:unchecked:hover,\n"
"QRadioButton::indicator:unchecked:focus,\n"
"QRadioButton::indicator:unchecked:pressed {\n"
"    border: none;\n"
"    outline: none;\n"
"    image: url(:/qss_icons/rc/radio_unchecked_focus.png);\n"
"}\n"
"\n"
"QRadioButton::indicator:checked {\n"
"    border: none;\n"
""
                        "    outline: none;\n"
"    image: url(:/qss_icons/rc/radio_checked.png);\n"
"}\n"
"\n"
"QRadioButton::indicator:checked:hover,\n"
"QRadioButton::indicator:checked:focus,\n"
"QRadioButton::indicator:checked:pressed {\n"
"    border: none;\n"
"    outline: none;\n"
"    image: url(:/qss_icons/rc/radio_checked_focus.png);\n"
"}\n"
"\n"
"QRadioButton::indicator:checked:disabled {\n"
"    outline: none;\n"
"    image: url(:/qss_icons/rc/radio_checked_disabled.png);\n"
"}\n"
"\n"
"QRadioButton::indicator:unchecked:disabled {\n"
"    image: url(:/qss_icons/rc/radio_unchecked_disabled.png);\n"
"}\n"
"\n"
"QMenuBar {\n"
"    background-color: #31363b;\n"
"    color: #eff0f1;\n"
"}\n"
"\n"
"QMenuBar::item {\n"
"    background: transparent;\n"
"}\n"
"\n"
"QMenuBar::item:selected {\n"
"    background: transparent;\n"
"    border: 1px solid #76797C;\n"
"}\n"
"\n"
"QMenuBar::item:pressed {\n"
"    border: 1px solid #76797C;\n"
"    background-color: #3daee9;\n"
"    color: #eff0f1;\n"
"    margin-bottom: -1px;\n"
"    paddi"
                        "ng-bottom: 1px;\n"
"}\n"
"\n"
"QMenu {\n"
"    border: 1px solid #76797C;\n"
"    color: #eff0f1;\n"
"    margin: 2px;\n"
"}\n"
"\n"
"QMenu::icon {\n"
"    margin: 5px;\n"
"}\n"
"\n"
"QMenu::item {\n"
"    padding: 5px 30px 5px 30px;\n"
"    border: 1px solid transparent;\n"
"    /* reserve space for selection border */\n"
"}\n"
"\n"
"QMenu::item:selected {\n"
"    color: #eff0f1;\n"
"}\n"
"\n"
"QMenu::separator {\n"
"    height: 2px;\n"
"    background: lightblue;\n"
"    margin-left: 10px;\n"
"    margin-right: 5px;\n"
"}\n"
"\n"
"QMenu::indicator {\n"
"    width: 18px;\n"
"    height: 18px;\n"
"}\n"
"\n"
"\n"
"/* non-exclusive indicator = check box style indicator\n"
"   (see QActionGroup::setExclusive) */\n"
"\n"
"QMenu::indicator:non-exclusive:unchecked {\n"
"    image: url(:/qss_icons/rc/checkbox_unchecked.png);\n"
"}\n"
"\n"
"QMenu::indicator:non-exclusive:unchecked:selected {\n"
"    image: url(:/qss_icons/rc/checkbox_unchecked_disabled.png);\n"
"}\n"
"\n"
"QMenu::indicator:non-exclusive:checked {\n"
""
                        "    image: url(:/qss_icons/rc/checkbox_checked.png);\n"
"}\n"
"\n"
"QMenu::indicator:non-exclusive:checked:selected {\n"
"    image: url(:/qss_icons/rc/checkbox_checked_disabled.png);\n"
"}\n"
"\n"
"\n"
"/* exclusive indicator = radio button style indicator (see QActionGroup::setExclusive) */\n"
"\n"
"QMenu::indicator:exclusive:unchecked {\n"
"    image: url(:/qss_icons/rc/radio_unchecked.png);\n"
"}\n"
"\n"
"QMenu::indicator:exclusive:unchecked:selected {\n"
"    image: url(:/qss_icons/rc/radio_unchecked_disabled.png);\n"
"}\n"
"\n"
"QMenu::indicator:exclusive:checked {\n"
"    image: url(:/qss_icons/rc/radio_checked.png);\n"
"}\n"
"\n"
"QMenu::indicator:exclusive:checked:selected {\n"
"    image: url(:/qss_icons/rc/radio_checked_disabled.png);\n"
"}\n"
"\n"
"QMenu::right-arrow {\n"
"    margin: 5px;\n"
"    image: url(:/qss_icons/rc/right_arrow.png)\n"
"}\n"
"\n"
"QWidget:disabled {\n"
"    color: #454545;\n"
"    background-color: #31363b;\n"
"}\n"
"\n"
"QAbstractItemView {\n"
"    alternate-background-colo"
                        "r: #31363b;\n"
"    color: #eff0f1;\n"
"    border: 1px solid #3A3939;\n"
"    border-radius: 2px;\n"
"}\n"
"\n"
"QWidget:focus,\n"
"QMenuBar:focus {\n"
"    border: 1px solid #3daee9;\n"
"}\n"
"\n"
"QTabWidget:focus,\n"
"QCheckBox:focus,\n"
"QRadioButton:focus,\n"
"QSlider:focus {\n"
"    border: none;\n"
"}\n"
"\n"
"QLineEdit {\n"
"    background-color: #232629;\n"
"    padding: 5px;\n"
"    border-style: solid;\n"
"    border: 1px solid #76797C;\n"
"    border-radius: 2px;\n"
"    color: #eff0f1;\n"
"}\n"
"\n"
"QAbstractItemView QLineEdit {\n"
"    padding: 0;\n"
"}\n"
"\n"
"QGroupBox {\n"
"    border: 1px solid #76797C;\n"
"    border-radius: 2px;\n"
"    margin-top: 20px;\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top center;\n"
"    padding-left: 10px;\n"
"    padding-right: 10px;\n"
"    padding-top: 10px;\n"
"}\n"
"\n"
"QAbstractScrollArea {\n"
"    border-radius: 2px;\n"
"    border: 1px solid #76797C;\n"
"    background-color: transparent;\n"
"}\n"
""
                        "\n"
"QScrollBar:horizontal {\n"
"    height: 15px;\n"
"    margin: 3px 15px 3px 15px;\n"
"    border: 1px transparent #2A2929;\n"
"    border-radius: 4px;\n"
"    background-color: #2A2929;\n"
"}\n"
"\n"
"QScrollBar::handle:horizontal {\n"
"    background-color: #605F5F;\n"
"    min-width: 5px;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"QScrollBar::add-line:horizontal {\n"
"    margin: 0px 3px 0px 3px;\n"
"    border-image: url(:/qss_icons/rc/right_arrow_disabled.png);\n"
"    width: 10px;\n"
"    height: 10px;\n"
"    subcontrol-position: right;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::sub-line:horizontal {\n"
"    margin: 0px 3px 0px 3px;\n"
"    border-image: url(:/qss_icons/rc/left_arrow_disabled.png);\n"
"    height: 10px;\n"
"    width: 10px;\n"
"    subcontrol-position: left;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::add-line:horizontal:hover,\n"
"QScrollBar::add-line:horizontal:on {\n"
"    border-image: url(:/qss_icons/rc/right_arrow.png);\n"
"    height: 10px;"
                        "\n"
"    width: 10px;\n"
"    subcontrol-position: right;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::sub-line:horizontal:hover,\n"
"QScrollBar::sub-line:horizontal:on {\n"
"    border-image: url(:/qss_icons/rc/left_arrow.png);\n"
"    height: 10px;\n"
"    width: 10px;\n"
"    subcontrol-position: left;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::up-arrow:horizontal,\n"
"QScrollBar::down-arrow:horizontal {\n"
"    background: none;\n"
"}\n"
"\n"
"QScrollBar::add-page:horizontal,\n"
"QScrollBar::sub-page:horizontal {\n"
"    background: none;\n"
"}\n"
"\n"
"QScrollBar:vertical {\n"
"    background-color: #2A2929;\n"
"    width: 15px;\n"
"    margin: 15px 3px 15px 3px;\n"
"    border: 1px transparent #2A2929;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical {\n"
"    background-color: #605F5F;\n"
"    min-height: 40px;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"QScrollBar::sub-line:vertical {\n"
"    margin: 3px 0px 3px 0px;\n"
"    border-image: url(:/q"
                        "ss_icons/rc/up_arrow_disabled.png);\n"
"    height: 10px;\n"
"    width: 10px;\n"
"    subcontrol-position: top;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical {\n"
"    margin: 3px 0px 3px 0px;\n"
"    border-image: url(:/qss_icons/rc/down_arrow_disabled.png);\n"
"    height: 10px;\n"
"    width: 10px;\n"
"    subcontrol-position: bottom;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::sub-line:vertical:hover,\n"
"QScrollBar::sub-line:vertical:on {\n"
"    border-image: url(:/qss_icons/rc/up_arrow.png);\n"
"    height: 10px;\n"
"    width: 10px;\n"
"    subcontrol-position: top;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical:hover,\n"
"QScrollBar::add-line:vertical:on {\n"
"    border-image: url(:/qss_icons/rc/down_arrow.png);\n"
"    height: 10px;\n"
"    width: 10px;\n"
"    subcontrol-position: bottom;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::up-arrow:vertical,\n"
"QScrollBar::down-arrow:vertical {\n"
"    "
                        "background: none;\n"
"}\n"
"\n"
"QScrollBar::add-page:vertical,\n"
"QScrollBar::sub-page:vertical {\n"
"    background: none;\n"
"}\n"
"\n"
"QTextEdit {\n"
"    background-color: #232629;\n"
"    color: #eff0f1;\n"
"    border: 1px solid #76797C;\n"
"}\n"
"\n"
"QPlainTextEdit {\n"
"    background-color: #232629;\n"
"    ;\n"
"    color: #eff0f1;\n"
"    border-radius: 2px;\n"
"    border: 1px solid #76797C;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: #76797C;\n"
"    color: #eff0f1;\n"
"    padding: 5px;\n"
"    border: 1px solid #76797C;\n"
"}\n"
"\n"
"QSizeGrip {\n"
"    image: url(:/qss_icons/rc/sizegrip.png);\n"
"    width: 12px;\n"
"    height: 12px;\n"
"}\n"
"\n"
"QMainWindow::separator {\n"
"    background-color: #31363b;\n"
"    color: white;\n"
"    padding-left: 4px;\n"
"    spacing: 2px;\n"
"    border: 1px dashed #76797C;\n"
"}\n"
"\n"
"QMainWindow::separator:hover {\n"
"    background-color: #787876;\n"
"    color: white;\n"
"    padding-left: 4px;\n"
"    border: 1px solid #76"
                        "797C;\n"
"    spacing: 2px;\n"
"}\n"
"\n"
"QMenu::separator {\n"
"    height: 1px;\n"
"    background-color: #76797C;\n"
"    color: white;\n"
"    padding-left: 4px;\n"
"    margin-left: 10px;\n"
"    margin-right: 5px;\n"
"}\n"
"\n"
"QFrame {\n"
"    border-radius: 2px;\n"
"    border: 1px solid #76797C;\n"
"}\n"
"\n"
"QFrame[frameShape=\"0\"] {\n"
"    border-radius: 2px;\n"
"    border: 1px transparent #76797C;\n"
"}\n"
"\n"
"QStackedWidget {\n"
"    border: 1px transparent black;\n"
"}\n"
"\n"
"QToolBar {\n"
"    border: 1px transparent #393838;\n"
"    background: 1px solid #31363b;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QToolBar::handle:horizontal {\n"
"    image: url(:/qss_icons/rc/Hmovetoolbar.png);\n"
"}\n"
"\n"
"QToolBar::handle:vertical {\n"
"    image: url(:/qss_icons/rc/Vmovetoolbar.png);\n"
"}\n"
"\n"
"QToolBar::separator:horizontal {\n"
"    image: url(:/qss_icons/rc/Hsepartoolbar.png);\n"
"}\n"
"\n"
"QToolBar::separator:vertical {\n"
"    image: url(:/qss_icons/rc/Vsepartoolbar.png);\n"
"}\n"
""
                        "\n"
"QToolButton#qt_toolbar_ext_button {\n"
"    background: #58595a\n"
"}\n"
"\n"
"QPushButton {\n"
"    color: #eff0f1;\n"
"    background-color: #31363b;\n"
"    border-width: 0px;\n"
"    border-color: #76797C;\n"
"    border-style: solid;\n"
"    padding: 5px;\n"
"    border-radius: 2px;\n"
"    outline: none;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: #31363b;\n"
"    border-width: 0px;\n"
"    border-color: #454545;\n"
"    border-style: solid;\n"
"    padding-top: 5px;\n"
"    padding-bottom: 5px;\n"
"    padding-left: 10px;\n"
"    padding-right: 10px;\n"
"    border-radius: 2px;\n"
"    color: #454545;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #3daee9;\n"
"    padding-top: -15px;\n"
"    padding-bottom: -17px;\n"
"}\n"
"\n"
"QComboBox {\n"
"    selection-background-color: #3daee9;\n"
"    border-style: solid;\n"
"    border: 1px solid #76797C;\n"
"    border-radius: 2px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"    background-color: #767"
                        "97C;\n"
"    border-color: #6A6969;\n"
"}\n"
"\n"
"QComboBox:hover,\n"
"QPushButton:hover,\n"
"QAbstractSpinBox:hover,\n"
"QLineEdit:hover,\n"
"QTextEdit:hover,\n"
"QPlainTextEdit:hover,\n"
"QAbstractView:hover,\n"
"QTreeView:hover {\n"
"    border: 1px solid #3daee9;\n"
"    color: #eff0f1;\n"
"}\n"
"\n"
"QComboBox:on {\n"
"    padding-top: 3px;\n"
"    padding-left: 4px;\n"
"    selection-background-color: #4a4a4a;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"    background-color: #232629;\n"
"    border-radius: 2px;\n"
"    border: 1px solid #76797C;\n"
"    selection-background-color: #18465d;\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 15px;\n"
"    border-left-width: 0px;\n"
"    border-left-color: darkgray;\n"
"    border-left-style: solid;\n"
"    border-top-right-radius: 3px;\n"
"    border-bottom-right-radius: 3px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(:/qss_icons/rc/down_arrow_disabled.png);\n"
""
                        "}\n"
"\n"
"QComboBox::down-arrow:on,\n"
"QComboBox::down-arrow:hover,\n"
"QComboBox::down-arrow:focus {\n"
"    image: url(:/qss_icons/rc/down_arrow.png);\n"
"}\n"
"\n"
"QAbstractSpinBox {\n"
"    padding: 5px;\n"
"    border: 1px solid #76797C;\n"
"    background-color: #232629;\n"
"    color: #eff0f1;\n"
"    border-radius: 2px;\n"
"    min-width: 75px;\n"
"}\n"
"\n"
"QAbstractSpinBox:up-button {\n"
"    background-color: transparent;\n"
"    subcontrol-origin: border;\n"
"    subcontrol-position: center right;\n"
"}\n"
"\n"
"QAbstractSpinBox:down-button {\n"
"    background-color: transparent;\n"
"    subcontrol-origin: border;\n"
"    subcontrol-position: center left;\n"
"}\n"
"\n"
"QAbstractSpinBox::up-arrow,\n"
"QAbstractSpinBox::up-arrow:disabled,\n"
"QAbstractSpinBox::up-arrow:off {\n"
"    image: url(:/qss_icons/rc/up_arrow_disabled.png);\n"
"    width: 10px;\n"
"    height: 10px;\n"
"}\n"
"\n"
"QAbstractSpinBox::up-arrow:hover {\n"
"    image: url(:/qss_icons/rc/up_arrow.png);\n"
"}\n"
"\n"
"QAbstrac"
                        "tSpinBox::down-arrow,\n"
"QAbstractSpinBox::down-arrow:disabled,\n"
"QAbstractSpinBox::down-arrow:off {\n"
"    image: url(:/qss_icons/rc/down_arrow_disabled.png);\n"
"    width: 10px;\n"
"    height: 10px;\n"
"}\n"
"\n"
"QAbstractSpinBox::down-arrow:hover {\n"
"    image: url(:/qss_icons/rc/down_arrow.png);\n"
"}\n"
"\n"
"QLabel {\n"
"    border: 0px solid black;\n"
"}\n"
"\n"
"QTabWidget {\n"
"    border: 0px transparent black;\n"
"}\n"
"\n"
"QTabWidget::pane {\n"
"    border: 1px solid #76797C;\n"
"    padding: 5px;\n"
"    margin: 0px;\n"
"}\n"
"\n"
"QTabWidget::tab-bar {\n"
"    /* left: 5px; move to the right by 5px */\n"
"}\n"
"\n"
"QTabBar {\n"
"    qproperty-drawBase: 0;\n"
"    border-radius: 3px;\n"
"}\n"
"\n"
"QTabBar:focus {\n"
"    border: 0px transparent black;\n"
"}\n"
"\n"
"QTabBar::close-button {\n"
"    image: url(:/qss_icons/rc/close.png);\n"
"    background: transparent;\n"
"}\n"
"\n"
"QTabBar::close-button:hover {\n"
"    image: url(:/qss_icons/rc/close-hover.png);\n"
"    background: tra"
                        "nsparent;\n"
"}\n"
"\n"
"QTabBar::close-button:pressed {\n"
"    image: url(:/qss_icons/rc/close-pressed.png);\n"
"    background: transparent;\n"
"}\n"
"\n"
"\n"
"/* TOP TABS */\n"
"\n"
"QTabBar::tab:top {\n"
"    color: #eff0f1;\n"
"    border: 1px solid #76797C;\n"
"    border-bottom: 1px transparent black;\n"
"    background-color: #31363b;\n"
"    padding: 5px;\n"
"    min-width: 50px;\n"
"    border-top-left-radius: 2px;\n"
"    border-top-right-radius: 2px;\n"
"}\n"
"\n"
"QTabBar::tab:top:selected {\n"
"    color: #eff0f1;\n"
"    background-color: #54575B;\n"
"    border: 1px solid #76797C;\n"
"    border-bottom: 2px solid #3daee9;\n"
"    border-top-left-radius: 2px;\n"
"    border-top-right-radius: 2px;\n"
"}\n"
"\n"
"QTabBar::tab:top:!selected:hover {\n"
"    background-color: #3daee9;\n"
"}\n"
"\n"
"\n"
"/* BOTTOM TABS */\n"
"\n"
"QTabBar::tab:bottom {\n"
"    color: #eff0f1;\n"
"    border: 1px solid #76797C;\n"
"    border-top: 1px transparent black;\n"
"    background-color: #31363b;\n"
"    pad"
                        "ding: 5px;\n"
"    border-bottom-left-radius: 2px;\n"
"    border-bottom-right-radius: 2px;\n"
"    min-width: 50px;\n"
"}\n"
"\n"
"QTabBar::tab:bottom:selected {\n"
"    color: #eff0f1;\n"
"    background-color: #54575B;\n"
"    border: 1px solid #76797C;\n"
"    border-top: 2px solid #3daee9;\n"
"    border-bottom-left-radius: 2px;\n"
"    border-bottom-right-radius: 2px;\n"
"}\n"
"\n"
"QTabBar::tab:bottom:!selected:hover {\n"
"    background-color: #3daee9;\n"
"}\n"
"\n"
"\n"
"/* LEFT TABS */\n"
"\n"
"QTabBar::tab:left {\n"
"    color: #eff0f1;\n"
"    border: 1px solid #76797C;\n"
"    border-left: 1px transparent black;\n"
"    background-color: #31363b;\n"
"    padding: 5px;\n"
"    border-top-right-radius: 2px;\n"
"    border-bottom-right-radius: 2px;\n"
"    min-height: 50px;\n"
"}\n"
"\n"
"QTabBar::tab:left:selected {\n"
"    color: #eff0f1;\n"
"    background-color: #54575B;\n"
"    border: 1px solid #76797C;\n"
"    border-left: 2px solid #3daee9;\n"
"    border-top-right-radius: 2px;\n"
"    border"
                        "-bottom-right-radius: 2px;\n"
"}\n"
"\n"
"QTabBar::tab:left:!selected:hover {\n"
"    background-color: #3daee9;\n"
"}\n"
"\n"
"\n"
"/* RIGHT TABS */\n"
"\n"
"QTabBar::tab:right {\n"
"    color: #eff0f1;\n"
"    border: 1px solid #76797C;\n"
"    border-right: 1px transparent black;\n"
"    background-color: #31363b;\n"
"    padding: 5px;\n"
"    border-top-left-radius: 2px;\n"
"    border-bottom-left-radius: 2px;\n"
"    min-height: 50px;\n"
"}\n"
"\n"
"QTabBar::tab:right:selected {\n"
"    color: #eff0f1;\n"
"    background-color: #54575B;\n"
"    border: 1px solid #76797C;\n"
"    border-right: 2px solid #3daee9;\n"
"    border-top-left-radius: 2px;\n"
"    border-bottom-left-radius: 2px;\n"
"}\n"
"\n"
"QTabBar::tab:right:!selected:hover {\n"
"    background-color: #3daee9;\n"
"}\n"
"\n"
"QTabBar QToolButton::right-arrow:enabled {\n"
"    image: url(:/qss_icons/rc/right_arrow.png);\n"
"}\n"
"\n"
"QTabBar QToolButton::left-arrow:enabled {\n"
"    image: url(:/qss_icons/rc/left_arrow.png);\n"
"}\n"
"\n"
"QTab"
                        "Bar QToolButton::right-arrow:disabled {\n"
"    image: url(:/qss_icons/rc/right_arrow_disabled.png);\n"
"}\n"
"\n"
"QTabBar QToolButton::left-arrow:disabled {\n"
"    image: url(:/qss_icons/rc/left_arrow_disabled.png);\n"
"}\n"
"\n"
"QDockWidget {\n"
"    background: #31363b;\n"
"    border: 1px solid #403F3F;\n"
"    titlebar-close-icon: url(:/qss_icons/rc/close.png);\n"
"    titlebar-normal-icon: url(:/qss_icons/rc/undock.png);\n"
"}\n"
"\n"
"QDockWidget::close-button,\n"
"QDockWidget::float-button {\n"
"    border: 1px solid transparent;\n"
"    border-radius: 2px;\n"
"    background: transparent;\n"
"}\n"
"\n"
"QDockWidget::close-button:hover,\n"
"QDockWidget::float-button:hover {\n"
"    background: rgba(255, 255, 255, 10);\n"
"}\n"
"\n"
"QDockWidget::close-button:pressed,\n"
"QDockWidget::float-button:pressed {\n"
"    padding: 1px -1px -1px 1px;\n"
"    background: rgba(255, 255, 255, 10);\n"
"}\n"
"\n"
"QTreeView,\n"
"QListView {\n"
"    border: 1px solid #76797C;\n"
"    background-color: #232629;\n"
""
                        "}\n"
"\n"
"QTreeView:branch:selected,\n"
"QTreeView:branch:hover {\n"
"    background: url(:/qss_icons/rc/transparent.png);\n"
"}\n"
"\n"
"QTreeView::branch:has-siblings:!adjoins-item {\n"
"    border-image: url(:/qss_icons/rc/transparent.png);\n"
"}\n"
"\n"
"QTreeView::branch:has-siblings:adjoins-item {\n"
"    border-image: url(:/qss_icons/rc/transparent.png);\n"
"}\n"
"\n"
"QTreeView::branch:!has-children:!has-siblings:adjoins-item {\n"
"    border-image: url(:/qss_icons/rc/transparent.png);\n"
"}\n"
"\n"
"QTreeView::branch:has-children:!has-siblings:closed,\n"
"QTreeView::branch:closed:has-children:has-siblings {\n"
"    image: url(:/qss_icons/rc/branch_closed.png);\n"
"}\n"
"\n"
"QTreeView::branch:open:has-children:!has-siblings,\n"
"QTreeView::branch:open:has-children:has-siblings {\n"
"    image: url(:/qss_icons/rc/branch_open.png);\n"
"}\n"
"\n"
"QTreeView::branch:has-children:!has-siblings:closed:hover,\n"
"QTreeView::branch:closed:has-children:has-siblings:hover {\n"
"    image: url(:/qss_icons/rc/br"
                        "anch_closed-on.png);\n"
"}\n"
"\n"
"QTreeView::branch:open:has-children:!has-siblings:hover,\n"
"QTreeView::branch:open:has-children:has-siblings:hover {\n"
"    image: url(:/qss_icons/rc/branch_open-on.png);\n"
"}\n"
"\n"
"QListView::item:!selected:hover,\n"
"QTreeView::item:!selected:hover {\n"
"    background: #18465d;\n"
"    outline: 0;\n"
"    color: #eff0f1\n"
"}\n"
"\n"
"QListView::item:selected:hover,\n"
"QTreeView::item:selected:hover {\n"
"    background: #287399;\n"
"    color: #eff0f1;\n"
"}\n"
"\n"
"QTreeView::indicator:checked,\n"
"QListView::indicator:checked {\n"
"    image: url(:/qss_icons/rc/checkbox_checked.png);\n"
"}\n"
"\n"
"QTreeView::indicator:unchecked,\n"
"QListView::indicator:unchecked {\n"
"    image: url(:/qss_icons/rc/checkbox_unchecked.png);\n"
"}\n"
"\n"
"QTreeView::indicator:indeterminate,\n"
"QListView::indicator:indeterminate {\n"
"    image: url(:/qss_icons/rc/checkbox_indeterminate.png);\n"
"}\n"
"\n"
"QTreeView::indicator:checked:hover,\n"
"QTreeView::indicator:checked:fo"
                        "cus,\n"
"QTreeView::indicator:checked:pressed,\n"
"QListView::indicator:checked:hover,\n"
"QListView::indicator:checked:focus,\n"
"QListView::indicator:checked:pressed {\n"
"    image: url(:/qss_icons/rc/checkbox_checked_focus.png);\n"
"}\n"
"\n"
"QTreeView::indicator:unchecked:hover,\n"
"QTreeView::indicator:unchecked:focus,\n"
"QTreeView::indicator:unchecked:pressed,\n"
"QListView::indicator:unchecked:hover,\n"
"QListView::indicator:unchecked:focus,\n"
"QListView::indicator:unchecked:pressed {\n"
"    image: url(:/qss_icons/rc/checkbox_unchecked_focus.png);\n"
"}\n"
"\n"
"QTreeView::indicator:indeterminate:hover,\n"
"QTreeView::indicator:indeterminate:focus,\n"
"QTreeView::indicator:indeterminate:pressed,\n"
"QListView::indicator:indeterminate:hover,\n"
"QListView::indicator:indeterminate:focus,\n"
"QListView::indicator:indeterminate:pressed {\n"
"    image: url(:/qss_icons/rc/checkbox_indeterminate_focus.png);\n"
"}\n"
"\n"
"QSlider::groove:horizontal {\n"
"    border: 1px solid #565a5e;\n"
"    height: 4px"
                        ";\n"
"    background: #565a5e;\n"
"    margin: 0px;\n"
"    border-radius: 2px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"    background: #232629;\n"
"    border: 1px solid #565a5e;\n"
"    width: 16px;\n"
"    height: 16px;\n"
"    margin: -8px 0;\n"
"    border-radius: 9px;\n"
"}\n"
"\n"
"QSlider::groove:vertical {\n"
"    border: 1px solid #565a5e;\n"
"    width: 4px;\n"
"    background: #565a5e;\n"
"    margin: 0px;\n"
"    border-radius: 3px;\n"
"}\n"
"\n"
"QSlider::handle:vertical {\n"
"    background: #232629;\n"
"    border: 1px solid #565a5e;\n"
"    width: 16px;\n"
"    height: 16px;\n"
"    margin: 0 -8px;\n"
"    border-radius: 9px;\n"
"}\n"
"\n"
"QToolButton {\n"
"    background-color: transparent;\n"
"    border: 1px transparent #76797C;\n"
"    border-radius: 2px;\n"
"    margin: 3px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QToolButton[popupMode=\"1\"] {\n"
"    /* only for MenuButtonPopup */\n"
"    padding-right: 20px;\n"
"    /* make way for the popup button */\n"
"    border: 1px #76797C;"
                        "\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QToolButton[popupMode=\"2\"] {\n"
"    /* only for InstantPopup */\n"
"    padding-right: 10px;\n"
"    /* make way for the popup button */\n"
"    border: 1px #76797C;\n"
"}\n"
"\n"
"QToolButton:hover,\n"
"QToolButton::menu-button:hover {\n"
"    background-color: transparent;\n"
"    border: 1px solid #3daee9;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QToolButton:checked,\n"
"QToolButton:pressed,\n"
"QToolButton::menu-button:pressed {\n"
"    background-color: #3daee9;\n"
"    border: 1px solid #3daee9;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"\n"
"/* the subcontrol below is used only in the InstantPopup or DelayedPopup mode */\n"
"\n"
"QToolButton::menu-indicator {\n"
"    image: url(:/qss_icons/rc/down_arrow.png);\n"
"    top: -7px;\n"
"    left: -2px;\n"
"    /* shift it a bit */\n"
"}\n"
"\n"
"\n"
"/* the subcontrols below are used only in the MenuButtonPopup mode */\n"
"\n"
"QToolButton::menu-button {\n"
"    border: 1px transparent #76797C;\n"
"    border-top-right-ra"
                        "dius: 6px;\n"
"    border-bottom-right-radius: 6px;\n"
"    /* 16px width + 4px for border = 20px allocated above */\n"
"    width: 16px;\n"
"    outline: none;\n"
"}\n"
"\n"
"QToolButton::menu-arrow {\n"
"    image: url(:/qss_icons/rc/down_arrow.png);\n"
"}\n"
"\n"
"QToolButton::menu-arrow:open {\n"
"    border: 1px solid #76797C;\n"
"}\n"
"\n"
"QPushButton::menu-indicator {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: bottom right;\n"
"    left: 8px;\n"
"}\n"
"\n"
"QTableView {\n"
"    border: 1px solid #76797C;\n"
"    gridline-color: #383f46;\n"
"    background-color: #232629;\n"
"}\n"
"\n"
"QTableView,\n"
"QHeaderView {\n"
"    border-radius: 0px;\n"
"}\n"
"\n"
"QTableView::item:pressed,\n"
"QListView::item:pressed,\n"
"QTreeView::item:pressed {\n"
"    background: #18465d;\n"
"    color: #eff0f1;\n"
"}\n"
"\n"
"QTableView::item:selected:active,\n"
"QTreeView::item:selected:active,\n"
"QListView::item:selected:active {\n"
"    background: #287399;\n"
"    color: #eff0f1;\n"
"}\n"
"\n"
""
                        "QHeaderView {\n"
"    background-color: #31363b;\n"
"    border: 1px transparent;\n"
"    border-radius: 0px;\n"
"    margin: 0px;\n"
"    padding: 0px;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: #31363b;\n"
"    color: #eff0f1;\n"
"    padding: 5px;\n"
"    border: 1px solid #76797C;\n"
"    border-radius: 0px;\n"
"    text-align: center;\n"
"}\n"
"\n"
"QHeaderView::section::vertical::first,\n"
"QHeaderView::section::vertical::only-one {\n"
"    border-top: 1px solid #76797C;\n"
"}\n"
"\n"
"QHeaderView::section::vertical {\n"
"    border-top: transparent;\n"
"}\n"
"\n"
"QHeaderView::section::horizontal::first,\n"
"QHeaderView::section::horizontal::only-one {\n"
"    border-left: 1px solid #76797C;\n"
"}\n"
"\n"
"QHeaderView::section::horizontal {\n"
"    border-left: transparent;\n"
"}\n"
"\n"
"QHeaderView::section:checked {\n"
"    color: white;\n"
"    background-color: #334e5e;\n"
"}\n"
"\n"
"\n"
"/* style the sort indicator */\n"
"\n"
"QHeaderView::down-arrow {\n"
"    image: url(:/qs"
                        "s_icons/rc/down_arrow.png);\n"
"}\n"
"\n"
"QHeaderView::up-arrow {\n"
"    image: url(:/qss_icons/rc/up_arrow.png);\n"
"}\n"
"\n"
"QTableCornerButton::section {\n"
"    background-color: #31363b;\n"
"    border: 1px transparent #76797C;\n"
"    border-radius: 0px;\n"
"}\n"
"\n"
"QToolBox {\n"
"    padding: 5px;\n"
"    border: 1px transparent black;\n"
"}\n"
"\n"
"QToolBox::tab {\n"
"    color: #eff0f1;\n"
"    background-color: #31363b;\n"
"    border: 1px solid #76797C;\n"
"    border-bottom: 1px transparent #31363b;\n"
"    border-top-left-radius: 5px;\n"
"    border-top-right-radius: 5px;\n"
"}\n"
"\n"
"QToolBox::tab:selected {\n"
"    /* italicize selected tabs */\n"
"    font: italic;\n"
"    background-color: #31363b;\n"
"    border-color: #3daee9;\n"
"}\n"
"\n"
"QStatusBar::item {\n"
"    border: 0px transparent dark;\n"
"}\n"
"\n"
"QFrame[height=\"3\"],\n"
"QFrame[width=\"3\"] {\n"
"    background-color: #76797C;\n"
"}\n"
"\n"
"QSplitter::handle {\n"
"    border: 1px dashed #76797C;\n"
"}\n"
"\n"
"QSp"
                        "litter::handle:hover {\n"
"    background-color: #787876;\n"
"    border: 1px solid #76797C;\n"
"}\n"
"\n"
"QSplitter::handle:horizontal {\n"
"    width: 1px;\n"
"}\n"
"\n"
"QSplitter::handle:vertical {\n"
"    height: 1px;\n"
"}\n"
"\n"
"QProgressBar {\n"
"    border: 1px solid #76797C;\n"
"    border-radius: 5px;\n"
"    text-align: center;\n"
"}\n"
"\n"
"QProgressBar::chunk {\n"
"    background-color: #05B8CC;\n"
"}\n"
"\n"
"QDateEdit {\n"
"    selection-background-color: #3daee9;\n"
"    border-style: solid;\n"
"    border: 1px solid #3375A3;\n"
"    border-radius: 2px;\n"
"    padding: 1px;\n"
"    min-width: 75px;\n"
"}\n"
"\n"
"QDateEdit:on {\n"
"    padding-top: 3px;\n"
"    padding-left: 4px;\n"
"    selection-background-color: #4a4a4a;\n"
"}\n"
"\n"
"QDateEdit QAbstractItemView {\n"
"    background-color: #232629;\n"
"    border-radius: 2px;\n"
"    border: 1px solid #3375A3;\n"
"    selection-background-color: #3daee9;\n"
"}\n"
"\n"
"QDateEdit::drop-down {\n"
"    subcontrol-origin: padding;\n"
"   "
                        " subcontrol-position: top right;\n"
"    width: 15px;\n"
"    border-left-width: 0px;\n"
"    border-left-color: darkgray;\n"
"    border-left-style: solid;\n"
"    border-top-right-radius: 3px;\n"
"    border-bottom-right-radius: 3px;\n"
"}\n"
"\n"
"QDateEdit::down-arrow {\n"
"    image: url(:/qss_icons/rc/down_arrow_disabled.png);\n"
"}\n"
"\n"
"QDateEdit::down-arrow:on,\n"
"QDateEdit::down-arrow:hover,\n"
"QDateEdit::down-arrow:focus {\n"
"    image: url(:/qss_icons/rc/down_arrow.png);\n"
"}"));
        actionOpenFile = new QAction(DicomViewerDemoClass);
        actionOpenFile->setObjectName(QString::fromUtf8("actionOpenFile"));
        actionOpenFolder = new QAction(DicomViewerDemoClass);
        actionOpenFolder->setObjectName(QString::fromUtf8("actionOpenFolder"));
        actionQuit = new QAction(DicomViewerDemoClass);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        actionDefault = new QAction(DicomViewerDemoClass);
        actionDefault->setObjectName(QString::fromUtf8("actionDefault"));
        actionLungs = new QAction(DicomViewerDemoClass);
        actionLungs->setObjectName(QString::fromUtf8("actionLungs"));
        actionBrain = new QAction(DicomViewerDemoClass);
        actionBrain->setObjectName(QString::fromUtf8("actionBrain"));
        actionAbdomen = new QAction(DicomViewerDemoClass);
        actionAbdomen->setObjectName(QString::fromUtf8("actionAbdomen"));
        actionAngio = new QAction(DicomViewerDemoClass);
        actionAngio->setObjectName(QString::fromUtf8("actionAngio"));
        actionChest = new QAction(DicomViewerDemoClass);
        actionChest->setObjectName(QString::fromUtf8("actionChest"));
        actionBone = new QAction(DicomViewerDemoClass);
        actionBone->setObjectName(QString::fromUtf8("actionBone"));
        actionMediastinum = new QAction(DicomViewerDemoClass);
        actionMediastinum->setObjectName(QString::fromUtf8("actionMediastinum"));
        actionUserDefined = new QAction(DicomViewerDemoClass);
        actionUserDefined->setObjectName(QString::fromUtf8("actionUserDefined"));
        actionUser = new QAction(DicomViewerDemoClass);
        actionUser->setObjectName(QString::fromUtf8("actionUser"));
        actiontest = new QAction(DicomViewerDemoClass);
        actiontest->setObjectName(QString::fromUtf8("actiontest"));
        actionmpr = new QAction(DicomViewerDemoClass);
        actionmpr->setObjectName(QString::fromUtf8("actionmpr"));
        actionXY = new QAction(DicomViewerDemoClass);
        actionXY->setObjectName(QString::fromUtf8("actionXY"));
        actionXZ = new QAction(DicomViewerDemoClass);
        actionXZ->setObjectName(QString::fromUtf8("actionXZ"));
        actionYZ = new QAction(DicomViewerDemoClass);
        actionYZ->setObjectName(QString::fromUtf8("actionYZ"));
        actionDefined = new QAction(DicomViewerDemoClass);
        actionDefined->setObjectName(QString::fromUtf8("actionDefined"));
        actionBinarization = new QAction(DicomViewerDemoClass);
        actionBinarization->setObjectName(QString::fromUtf8("actionBinarization"));
        actionGray = new QAction(DicomViewerDemoClass);
        actionGray->setObjectName(QString::fromUtf8("actionGray"));
        actionSmoothGauss = new QAction(DicomViewerDemoClass);
        actionSmoothGauss->setObjectName(QString::fromUtf8("actionSmoothGauss"));
        actionGRAYPICTURE = new QAction(DicomViewerDemoClass);
        actionGRAYPICTURE->setObjectName(QString::fromUtf8("actionGRAYPICTURE"));
        actionsharpen = new QAction(DicomViewerDemoClass);
        actionsharpen->setObjectName(QString::fromUtf8("actionsharpen"));
        actionOTSU = new QAction(DicomViewerDemoClass);
        actionOTSU->setObjectName(QString::fromUtf8("actionOTSU"));
        actionPrewieet = new QAction(DicomViewerDemoClass);
        actionPrewieet->setObjectName(QString::fromUtf8("actionPrewieet"));
        actionCanny = new QAction(DicomViewerDemoClass);
        actionCanny->setObjectName(QString::fromUtf8("actionCanny"));
        actionopen = new QAction(DicomViewerDemoClass);
        actionopen->setObjectName(QString::fromUtf8("actionopen"));
        actionQuit_2 = new QAction(DicomViewerDemoClass);
        actionQuit_2->setObjectName(QString::fromUtf8("actionQuit_2"));
        actionEgray = new QAction(DicomViewerDemoClass);
        actionEgray->setObjectName(QString::fromUtf8("actionEgray"));
        RGBEaction = new QAction(DicomViewerDemoClass);
        RGBEaction->setObjectName(QString::fromUtf8("RGBEaction"));
        actionSAVE = new QAction(DicomViewerDemoClass);
        actionSAVE->setObjectName(QString::fromUtf8("actionSAVE"));
        actionFANOTSU = new QAction(DicomViewerDemoClass);
        actionFANOTSU->setObjectName(QString::fromUtf8("actionFANOTSU"));
        actionblur = new QAction(DicomViewerDemoClass);
        actionblur->setObjectName(QString::fromUtf8("actionblur"));
        actionANTICHROMIC = new QAction(DicomViewerDemoClass);
        actionANTICHROMIC->setObjectName(QString::fromUtf8("actionANTICHROMIC"));
        actionHSI = new QAction(DicomViewerDemoClass);
        actionHSI->setObjectName(QString::fromUtf8("actionHSI"));
        actiondouble = new QAction(DicomViewerDemoClass);
        actiondouble->setObjectName(QString::fromUtf8("actiondouble"));
        actionHSV = new QAction(DicomViewerDemoClass);
        actionHSV->setObjectName(QString::fromUtf8("actionHSV"));
        actionmax = new QAction(DicomViewerDemoClass);
        actionmax->setObjectName(QString::fromUtf8("actionmax"));
        centralWidget = new QWidget(DicomViewerDemoClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        DicomViewerDemoClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(DicomViewerDemoClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 790, 26));
        menufile = new QMenu(menuBar);
        menufile->setObjectName(QString::fromUtf8("menufile"));
        menuedit = new QMenu(menuBar);
        menuedit->setObjectName(QString::fromUtf8("menuedit"));
        menuview = new QMenu(menuBar);
        menuview->setObjectName(QString::fromUtf8("menuview"));
        menuhelp = new QMenu(menuBar);
        menuhelp->setObjectName(QString::fromUtf8("menuhelp"));
        menuWindowColor = new QMenu(menuBar);
        menuWindowColor->setObjectName(QString::fromUtf8("menuWindowColor"));
        menuMPR = new QMenu(menuBar);
        menuMPR->setObjectName(QString::fromUtf8("menuMPR"));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menu);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        menu_3 = new QMenu(menu);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        menu_4 = new QMenu(menu);
        menu_4->setObjectName(QString::fromUtf8("menu_4"));
        menu_5 = new QMenu(menu);
        menu_5->setObjectName(QString::fromUtf8("menu_5"));
        DicomViewerDemoClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(DicomViewerDemoClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        DicomViewerDemoClass->setStatusBar(statusBar);

        menuBar->addAction(menufile->menuAction());
        menuBar->addAction(menuedit->menuAction());
        menuBar->addAction(menuview->menuAction());
        menuBar->addAction(menuhelp->menuAction());
        menuBar->addAction(menuWindowColor->menuAction());
        menuBar->addAction(menuMPR->menuAction());
        menuBar->addAction(menu->menuAction());
        menufile->addAction(actionOpenFile);
        menufile->addAction(actionopen);
        menufile->addAction(actionQuit_2);
        menufile->addAction(actionSAVE);
        menuWindowColor->addAction(actionDefault);
        menuWindowColor->addAction(actionLungs);
        menuWindowColor->addAction(actionBrain);
        menuWindowColor->addAction(actionAbdomen);
        menuWindowColor->addAction(actionAngio);
        menuWindowColor->addAction(actionChest);
        menuWindowColor->addAction(actionBone);
        menuWindowColor->addAction(actionMediastinum);
        menuWindowColor->addAction(actionDefined);
        menuMPR->addAction(actionXY);
        menuMPR->addAction(actionXZ);
        menuMPR->addAction(actionYZ);
        menu->addAction(actionGray);
        menu->addAction(actionSmoothGauss);
        menu->addAction(actionGRAYPICTURE);
        menu->addAction(actionsharpen);
        menu->addAction(menu_2->menuAction());
        menu->addAction(menu_4->menuAction());
        menu->addAction(menu_3->menuAction());
        menu->addAction(menu_5->menuAction());
        menu->addAction(actionblur);
        menu->addAction(actionANTICHROMIC);
        menu_2->addAction(actionOTSU);
        menu_2->addAction(actiondouble);
        menu_2->addAction(actionmax);
        menu_3->addAction(actionPrewieet);
        menu_3->addAction(actionCanny);
        menu_4->addAction(actionEgray);
        menu_4->addAction(RGBEaction);
        menu_4->addAction(actionHSI);
        menu_4->addAction(actionHSV);
        menu_5->addAction(actionFANOTSU);

        retranslateUi(DicomViewerDemoClass);

        QMetaObject::connectSlotsByName(DicomViewerDemoClass);
    } // setupUi

    void retranslateUi(QMainWindow *DicomViewerDemoClass)
    {
        DicomViewerDemoClass->setWindowTitle(QCoreApplication::translate("DicomViewerDemoClass", "DicomViewerDemo", nullptr));
        actionOpenFile->setText(QCoreApplication::translate("DicomViewerDemoClass", "\346\211\223\345\274\200DICOM\346\226\207\344\273\266", nullptr));
        actionOpenFolder->setText(QCoreApplication::translate("DicomViewerDemoClass", "\346\211\223\345\274\200DICOM\346\226\207\344\273\266\345\244\271", nullptr));
        actionQuit->setText(QCoreApplication::translate("DicomViewerDemoClass", "\351\200\200\345\207\272", nullptr));
        actionDefault->setText(QCoreApplication::translate("DicomViewerDemoClass", "\351\273\230\350\256\244", nullptr));
        actionLungs->setText(QCoreApplication::translate("DicomViewerDemoClass", "\350\202\272", nullptr));
        actionBrain->setText(QCoreApplication::translate("DicomViewerDemoClass", "\350\204\221", nullptr));
        actionAbdomen->setText(QCoreApplication::translate("DicomViewerDemoClass", "\350\205\271", nullptr));
        actionAngio->setText(QCoreApplication::translate("DicomViewerDemoClass", "\350\241\200\347\256\241", nullptr));
        actionChest->setText(QCoreApplication::translate("DicomViewerDemoClass", "\350\203\270", nullptr));
        actionBone->setText(QCoreApplication::translate("DicomViewerDemoClass", "\351\252\250", nullptr));
        actionMediastinum->setText(QCoreApplication::translate("DicomViewerDemoClass", "\347\272\265\350\206\210", nullptr));
        actionUserDefined->setText(QCoreApplication::translate("DicomViewerDemoClass", "\350\207\252\345\256\232\344\271\211", nullptr));
        actionUser->setText(QCoreApplication::translate("DicomViewerDemoClass", "User", nullptr));
        actiontest->setText(QCoreApplication::translate("DicomViewerDemoClass", "test", nullptr));
        actionmpr->setText(QCoreApplication::translate("DicomViewerDemoClass", "mpr", nullptr));
        actionXY->setText(QCoreApplication::translate("DicomViewerDemoClass", "Axial", nullptr));
        actionXZ->setText(QCoreApplication::translate("DicomViewerDemoClass", "Sagittal", nullptr));
        actionYZ->setText(QCoreApplication::translate("DicomViewerDemoClass", "Coronal", nullptr));
        actionDefined->setText(QCoreApplication::translate("DicomViewerDemoClass", "\350\207\252\345\256\232\344\271\211", nullptr));
        actionBinarization->setText(QCoreApplication::translate("DicomViewerDemoClass", "\344\272\214\345\200\274\345\214\226", nullptr));
        actionGray->setText(QCoreApplication::translate("DicomViewerDemoClass", "\347\201\260\345\272\246\345\233\276", nullptr));
        actionSmoothGauss->setText(QCoreApplication::translate("DicomViewerDemoClass", "\345\233\276\345\203\217\345\271\263\346\273\221", nullptr));
        actionGRAYPICTURE->setText(QCoreApplication::translate("DicomViewerDemoClass", "\347\201\260\345\272\246\347\233\264\346\226\271\345\233\276", nullptr));
        actionsharpen->setText(QCoreApplication::translate("DicomViewerDemoClass", "\345\233\276\345\203\217\351\224\220\345\214\226", nullptr));
        actionOTSU->setText(QCoreApplication::translate("DicomViewerDemoClass", "OTSU\345\210\206\345\211\262", nullptr));
        actionPrewieet->setText(QCoreApplication::translate("DicomViewerDemoClass", "Prewitt\347\256\227\346\263\225", nullptr));
        actionCanny->setText(QCoreApplication::translate("DicomViewerDemoClass", "Canny\347\256\227\346\263\225", nullptr));
        actionopen->setText(QCoreApplication::translate("DicomViewerDemoClass", "\346\211\223\345\274\200\346\226\207\344\273\266\345\233\276\347\211\207", nullptr));
        actionQuit_2->setText(QCoreApplication::translate("DicomViewerDemoClass", "\351\200\200\345\207\272", nullptr));
        actionEgray->setText(QCoreApplication::translate("DicomViewerDemoClass", "\347\233\264\346\226\271\345\233\276\345\235\207\350\241\241\345\214\226", nullptr));
        RGBEaction->setText(QCoreApplication::translate("DicomViewerDemoClass", "\345\275\251\350\211\262\347\233\264\346\226\271\345\233\276\345\235\207\350\241\241\345\214\226", nullptr));
        actionSAVE->setText(QCoreApplication::translate("DicomViewerDemoClass", "\345\202\250\345\255\230\345\233\276\347\211\207", nullptr));
        actionFANOTSU->setText(QCoreApplication::translate("DicomViewerDemoClass", "OTSU", nullptr));
        actionblur->setText(QCoreApplication::translate("DicomViewerDemoClass", "\345\233\276\345\203\217\346\250\241\347\263\212", nullptr));
        actionANTICHROMIC->setText(QCoreApplication::translate("DicomViewerDemoClass", "\345\233\276\345\203\217\345\217\215\350\211\262", nullptr));
        actionHSI->setText(QCoreApplication::translate("DicomViewerDemoClass", "HSI\347\251\272\351\227\264\347\233\264\346\226\271\345\233\276\345\235\207\350\241\241\345\214\226(I)", nullptr));
        actiondouble->setText(QCoreApplication::translate("DicomViewerDemoClass", "\345\217\214\351\230\210\345\200\274\345\210\206\345\211\262", nullptr));
        actionHSV->setText(QCoreApplication::translate("DicomViewerDemoClass", "HSV\347\233\264\346\226\271\345\233\276\345\235\207\350\241\241\345\214\226\357\274\210V\357\274\211", nullptr));
        actionmax->setText(QCoreApplication::translate("DicomViewerDemoClass", "\346\234\200\345\244\247\347\206\265\351\230\210\345\200\274\345\210\206\345\211\262", nullptr));
        menufile->setTitle(QCoreApplication::translate("DicomViewerDemoClass", "\346\226\207\344\273\266", nullptr));
        menuedit->setTitle(QCoreApplication::translate("DicomViewerDemoClass", "\347\274\226\350\276\221", nullptr));
        menuview->setTitle(QCoreApplication::translate("DicomViewerDemoClass", "\350\247\206\345\233\276", nullptr));
        menuhelp->setTitle(QCoreApplication::translate("DicomViewerDemoClass", "\345\270\256\345\212\251", nullptr));
        menuWindowColor->setTitle(QCoreApplication::translate("DicomViewerDemoClass", "\347\252\227\345\256\275\347\252\227\344\275\215", nullptr));
        menuMPR->setTitle(QCoreApplication::translate("DicomViewerDemoClass", "MPR", nullptr));
        menu->setTitle(QCoreApplication::translate("DicomViewerDemoClass", "\345\233\276\345\203\217\345\244\204\347\220\206", nullptr));
        menu_2->setTitle(QCoreApplication::translate("DicomViewerDemoClass", "\345\233\276\345\203\217\345\210\206\345\211\262", nullptr));
        menu_3->setTitle(QCoreApplication::translate("DicomViewerDemoClass", "\345\233\276\345\203\217\350\276\271\347\274\230\346\243\200\346\265\213", nullptr));
        menu_4->setTitle(QCoreApplication::translate("DicomViewerDemoClass", "\345\233\276\345\203\217\345\242\236\345\274\272", nullptr));
        menu_5->setTitle(QCoreApplication::translate("DicomViewerDemoClass", "\345\233\276\345\203\217\345\217\215\350\211\262\345\210\206\345\211\262", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DicomViewerDemoClass: public Ui_DicomViewerDemoClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DICOMVIEWERDEMO_H
