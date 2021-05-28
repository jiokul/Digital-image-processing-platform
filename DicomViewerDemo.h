#pragma once

#include "QtWidgets/qmainwindow.h"
#include "ui_DicomViewerDemo.h"
#include <QProgressBar>
#include <vtkDICOMImageReader.h>
#include <vtkImageViewer2.h>
#include <vtkSmartPointer.h>
#include <QStandardItemModel>
#include "ImageRender.h"
#include "ShowAllTag.h"
#include "WindowColorDefined.h"
#include "screenShotClass.h"
using namespace std;

class DicomViewerDemo : public QMainWindow
{
Q_OBJECT

public:
	DicomViewerDemo(QWidget* parent = Q_NULLPTR);
	~DicomViewerDemo();

private:
	Ui::DicomViewerDemoClass ui;
protected:

/*
private slots:
	void on_actionOpenFile_triggered(); //打开单张DICOM文件
	void on_actionOpenFolder_triggered(); //打开DICOM文件夹
	void on_actionQuit_2_triggered(); //关闭
	
	void beginScreenShot();
	void saveImage(QString fileDir, QString fileName,QString styleStr);//保存图片

	void showTag();//查看Tag
	void on_actionXY_triggered();
	void on_actionXZ_triggered();
	void on_actionYZ_triggered();

	//窗宽窗位调节
	void on_actionDefault_triggered();//默认窗宽窗位
	void on_actionLungs_triggered();//肺
	void on_actionBrain_triggered();//头/脑
	void on_actionAbdomen_triggered();//腹部
	void on_actionAngio_triggered();//血管
	void on_actionChest_triggered();//胸
	void on_actionBone_triggered();//骨
	void on_actionMediastinum_triggered();//纵膈
	void on_actionDefined_triggered();//自定义
	void ChangeWindowColorByUserDefined(double WW,double WL);

	void onTreeViewDobuleClicked();//点击树视图子节点*/
public slots:
	void openB();
	void openBT();
	void open();
	void openG();
	void openS();
	void openC();
	void openE();
	void openRGBE();
	void openGP();
	void openSH();
	void open2();
	void on_actionQuit_2_triggered(); //关闭
	void save();
	void openI();
	void openblur();
	void openprewitt();
	void openHSIequation();
	void openHSVequation();
	void opendoubletchreshold();
	void openmax();
public:
	QString currentDir = "NULL";//当前显示的文件路径
	QString strDir[20];//存储文件路径
	QString openfile;
	int orderDir = 0;//第几个
};
