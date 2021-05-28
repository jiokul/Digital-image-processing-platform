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
	void on_actionOpenFile_triggered(); //�򿪵���DICOM�ļ�
	void on_actionOpenFolder_triggered(); //��DICOM�ļ���
	void on_actionQuit_2_triggered(); //�ر�
	
	void beginScreenShot();
	void saveImage(QString fileDir, QString fileName,QString styleStr);//����ͼƬ

	void showTag();//�鿴Tag
	void on_actionXY_triggered();
	void on_actionXZ_triggered();
	void on_actionYZ_triggered();

	//����λ����
	void on_actionDefault_triggered();//Ĭ�ϴ���λ
	void on_actionLungs_triggered();//��
	void on_actionBrain_triggered();//ͷ/��
	void on_actionAbdomen_triggered();//����
	void on_actionAngio_triggered();//Ѫ��
	void on_actionChest_triggered();//��
	void on_actionBone_triggered();//��
	void on_actionMediastinum_triggered();//����
	void on_actionDefined_triggered();//�Զ���
	void ChangeWindowColorByUserDefined(double WW,double WL);

	void onTreeViewDobuleClicked();//�������ͼ�ӽڵ�*/
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
	void on_actionQuit_2_triggered(); //�ر�
	void save();
	void openI();
	void openblur();
	void openprewitt();
	void openHSIequation();
	void openHSVequation();
	void opendoubletchreshold();
	void openmax();
public:
	QString currentDir = "NULL";//��ǰ��ʾ���ļ�·��
	QString strDir[20];//�洢�ļ�·��
	QString openfile;
	int orderDir = 0;//�ڼ���
};
