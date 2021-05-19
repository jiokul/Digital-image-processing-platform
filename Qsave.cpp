#include "Qsave.h"
#include <vtkSmartPointer.h>
#include <vtkImageViewer2.h>
#include <vtkDICOMImageReader.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <vtkTextProperty.h>
#include <vtkTextMapper.h>
#include <vtkCommand.h>
#include <vtkImageMapper.h>
#include <vtkInteractorStyleImage.h>
#include <QtWidgets/QFileDialog>
#include <QtCore/QSettings>
#include <QPushButton>
#include <QStandardItemModel>
#include <ui_DicomViewerDemo.h>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QMimeData>
#include <QMessageBox>
#include <QDebug>
#include <string>
#include <QScreen>
#include <QPixmap>
#include <QWidget>
#include <string.h>
#include <QDebug>
#include "vtkCallbackCommand.h"
#include "itkImage.h"
#include "itkImageFileReader.h"
#include "itkImageToVTKImageFilter.h"
#include "vtkImageViewer.h"
#include "vtkWin32RenderWindowInteractor.h"
#include "itkResampleImageFilter.h"//����
#include "itkBinaryThresholdImageFilter.h"//��ֵ��
#include "itkThresholdImageFilter.h"//��ֵ�ָ�
#include "itkBinaryBallStructuringElement.h"
#include "itkBinaryMorphologicalOpeningImageFilter.h"//������
#include "itkMultiplyImageFilter.h"//�˷�
#include "itkAndImageFilter.h"//��
#include "itkImageFileWriter.h"
#include "itkCastImageFilter.h"
#include <iostream>
#include <string>
#include "itkRescaleIntensityImageFilter.h"
#include "itkConnectedComponentImageFilter.h"//��ͨ��
#include "itkLabelToRGBImageFilter.h"//��ɫ
#include "itkConnectedThresholdImageFilter.h"
#include "vtkImageShiftScale.h"

#pragma execution_character_set("utf-8")//��ʾ����
Qsave::Qsave(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	connect(ui.comboBox_2, SIGNAL(activated(int)), this, SLOT(gettype2()));
	connect(ui.comboBox_2, SIGNAL(activated(int)), this, SLOT(settype2()));
	connect(ui.pushButton, SIGNAL(clicked(bool)), this, SLOT(getimgway()));
	connect(ui.pushButton, SIGNAL(clicked(bool)), this, SLOT(setimgway()));
	connect(ui.pushButton_4, SIGNAL(clicked(bool)), this, SLOT(getname()));
	connect(ui.pushButton_4, SIGNAL(clicked(bool)), this, SLOT(setname()));
	connect(ui.pushButton_2, SIGNAL(clicked(bool)), this, SLOT(saveimg()));
}

Qsave::~Qsave()
{
}

void Qsave::gettype2()
{
	type2 = ui.comboBox_2->currentIndex();
	qDebug() << type2;
}
void Qsave::getname()
{
	name = ui.lineEdit_4->text();
	qDebug() << name;
}
void Qsave::setimgway()
{
	ui.lineEdit->setText(svaefile);
}
void Qsave::settype2()
{
	switch (type2)
	{
	case 0:ui.lineEdit_3->setText("JPG��ʽ"); break;
	case 1:ui.lineEdit_3->setText("PNG��ʽ"); break;
	case 2:ui.lineEdit_3->setText("BMP��ʽ"); break;
	}
}
void Qsave::setname()
{
	ui.lineEdit_4->setText(name);
}
void Qsave::saveimg()
{
	switch (type2)
	{
	case 0:type = "jpg"; break;
	case 1:type = "png"; break;
	case 2:type = "bmp"; break;
	}
	name = ui.lineEdit_4->text();
	type2 = ui.comboBox_2->currentIndex();
	final->save(svaefile + "/" + name + "." + type);
	QMessageBox::information(NULL, "success", "����ɹ�");
	qDebug() << svaefile + "/" + name + "." + type;
	this->close();
}
void Qsave::getimgway()
{
	svaefile = QFileDialog::getExistingDirectory(this, "ѡ��Ŀ¼", "./", QFileDialog::ShowDirsOnly);
	qDebug() << svaefile;
}