#include "SAVE.h"
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
#include "itkResampleImageFilter.h"//采样
#include "itkBinaryThresholdImageFilter.h"//二值化
#include "itkThresholdImageFilter.h"//阈值分割
#include "itkBinaryBallStructuringElement.h"
#include "itkBinaryMorphologicalOpeningImageFilter.h"//开运算
#include "itkMultiplyImageFilter.h"//乘法
#include "itkAndImageFilter.h"//与
#include "itkImageFileWriter.h"
#include "itkCastImageFilter.h"
#include <iostream>
#include <string>
#include "itkRescaleIntensityImageFilter.h"
#include "itkConnectedComponentImageFilter.h"//连通域
#include "itkLabelToRGBImageFilter.h"//彩色
#include "itkConnectedThresholdImageFilter.h"
#include "vtkImageShiftScale.h"
#include "Binarization.h"
#include "Binariza.h"
#include "grayview.h"
#include "start.h"
#include "SmoothGauss.h"
#include "canny.h"
#include "Egary.h"
#include "RGBEquation.h"
#include "Gpicture.h"
#include "start2.h"
#include "sharpen.h"
#include "change.h"
#include "blur.h"
SAVE::SAVE(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	connect(ui.comboBox, SIGNAL(activated(int)), this, SLOT(gettype1()));
	connect(ui.comboBox, SIGNAL(activated(int)), this, SLOT(settype1()));
	connect(ui.comboBox_2, SIGNAL(activated(int)), this, SLOT(gettype2()));
	connect(ui.comboBox_2, SIGNAL(activated(int)), this, SLOT(settype2()));
	connect(ui.pushButton, SIGNAL(clicked(bool)), this, SLOT(getimgway()));
	connect(ui.pushButton, SIGNAL(clicked(bool)), this, SLOT(setimgway()));
	connect(ui.pushButton_4, SIGNAL(clicked(bool)), this, SLOT(getname()));
	connect(ui.pushButton_4, SIGNAL(clicked(bool)), this, SLOT(setname()));
	connect(ui.pushButton_2, SIGNAL(clicked(bool)), this, SLOT(saveimg()));
}

SAVE::~SAVE()
{
	delete &ui;
}


void SAVE::getimgway()
{
	svaefile = QFileDialog::getExistingDirectory(this, "选择目录", "./", QFileDialog::ShowDirsOnly);
	qDebug() << svaefile;
}

void SAVE::gettype1()
{
	type1 = ui.comboBox->currentIndex();
	qDebug() << type1;
}

void SAVE::gettype2()
{
	type2 = ui.comboBox_2->currentIndex();
	qDebug() << type2;
}

void SAVE::getname()
{
	name = ui.lineEdit_4->text();
	qDebug() << name;
}

void SAVE::setimgway()
{
	ui.lineEdit->setText(svaefile);
}

void SAVE::settype1()
{
	switch (type1)
	{
	case 0:ui.lineEdit_2->setText(QString::fromLocal8Bit("灰度图")); break;
	case 1:ui.lineEdit_2->setText(QString::fromLocal8Bit("图像模糊")); break;
	case 2:ui.lineEdit_2->setText(QString::fromLocal8Bit("高斯平滑")); break;
	case 3:ui.lineEdit_2->setText(QString::fromLocal8Bit("图像锐化")); break;
	case 4:ui.lineEdit_2->setText(QString::fromLocal8Bit("canny图像边缘检测")); break;
	case 5:ui.lineEdit_2->setText(QString::fromLocal8Bit("otsu图像分割")); break;
	case 6:ui.lineEdit_2->setText(QString::fromLocal8Bit("直方图均衡化增强")); break;
	case 7:ui.lineEdit_2->setText(QString::fromLocal8Bit("彩色直方图均衡化增强")); break;
	}
}

void SAVE::settype2()
{
	switch (type2)
	{
	case 0:ui.lineEdit_3->setText(QString::fromLocal8Bit("JPG格式")); break;
	case 1:ui.lineEdit_3->setText(QString::fromLocal8Bit("PNG格式")); break;
	case 2:ui.lineEdit_3->setText(QString::fromLocal8Bit("BMP格式")); break;
	}
}

void SAVE::setname()
{
	ui.lineEdit_4->setText(name);
}

void SAVE::saveimg()
{
	if (openfile.isEmpty())
	{
		return;
	}
	switch (type2)
	{
	case 0:type = "jpg"; break;
	case 1:type = "png"; break;
	case 2:type = "bmp"; break;
	}
	switch(type1)
	{
	case 0:getgray(); break;
	case 1:getblur(); break;
	case 2:getsmooth(); break;
	case 3:getsharpen(); break;
	case 4:gectcanny(); break;
	case 5:getbinarize(); break;
	case 6:getEgary(); break;
	case 7:getrgbequantion(); break;
	}
	this->close();
	qDebug() << svaefile + "/" + name + "." + type;
}

void SAVE::getgray()
{
	if (openfile.isEmpty())
	{
		return;
	}
	grayview* gimg = new grayview();
	QImage img2 = gimg->gary(openfile, type3);
	gimg->_img = &img2;
	QImage* grayImage = gimg->grayScaleImg();
	grayImage->save(svaefile+"/"+ name+"."+type);
}

void SAVE::getEgary()
{
	if(openfile.isEmpty())
	{
		return;
	}
	Egary* Eimg = new Egary();
	QImage img1 = Eimg->Egaryimg(openfile, type3);
	Eimg->_img = &img1;
	QImage* img2 = Eimg->grayScaleImg();
	Eimg->hist = Eimg->Histogram(img2);
	qDebug() << Eimg->hist;
	Eimg->Equaliation();
	Eimg->imgE->save(svaefile + "/" + name + "." + type);
}

void SAVE::getbinarize()
{
	if (openfile.isEmpty())
	{
		return;
	}
	Binariza* Bimg = new Binariza();
	QImage img = Bimg->binary(openfile, type3);
	Bimg->_img = &img;
	QImage* grayImage = Bimg->grayScaleImg();
	int threshold = Bimg->Otsu(grayImage);    // 计算出的阈值
	Bimg->threshold = threshold;
	qDebug() << Bimg->threshold;
	QImage* binaryImg = Bimg->process(grayImage);
	binaryImg->save(svaefile + "/" + name + "." + type);
}

void SAVE::gectcanny()
{
	if (openfile.isEmpty())
	{
		return;
	}
	canny* Cimg = new canny();
	QImage img1 = Cimg->cannyimg(openfile, type3);
	Cimg->_img = &img1;
	Cimg->grayScaleImg();
	Cimg->Smooth();
	Cimg->calculate();
	Cimg->nms();
	Cimg->bt();
	Cimg->st();
	Cimg->img_st->save(svaefile + "/" + name + "." + type);
}

void SAVE::getblur()
{
	if (openfile.isEmpty())
	{
		QMessageBox::information(NULL, "error", "请先打开文件");
		return;
	}
	blur* Simg = new blur();
	QImage img2 = Simg->blurimg(openfile, type3);
	Simg->_img = &img2;
	QImage* SmoothGaussImg1 = Simg->_img;
	QImage* SmoothGaussImg2 = Simg->getblurimg(SmoothGaussImg1);
	SmoothGaussImg2->save(svaefile + "/" + name + "." + type);
}

void SAVE::getrgbequantion()
{
	if (openfile.isEmpty())
	{
		return;
	}
	RGBEquation* RGBimg = new RGBEquation();
	QImage img1 = RGBimg->RGBEimg(openfile, type3);
	RGBimg->_img = &img1;
	RGBimg->Histogram();
	RGBimg->Equaliationr(RGBimg->rhist);
	RGBimg->Equaliationg(RGBimg->ghist);
	RGBimg->Equaliationb(RGBimg->bhist);
	RGBimg->final();
	qDebug() << RGBimg->newrhist[0];
	qDebug() << RGBimg->newghist[0];
	qDebug() << RGBimg->newbhist[0];
	RGBimg->imgE->save(svaefile + "/" + name + "." + type);
}

void SAVE::getsharpen()
{
	if (openfile.isEmpty())
	{
		return;
	}
	sharpen* Simg = new sharpen();
	QImage img2 = Simg->sharpenimg(openfile, type3);
	Simg->_img = &img2;
	QImage* SmoothGaussImg1 = Simg->_img;
	QImage* SmoothGaussImg2 = Simg->getsharpenimg(SmoothGaussImg1);
	SmoothGaussImg2->save(svaefile + "/" + name + "." + type);
}

void SAVE::getsmooth()
{
	if (openfile.isEmpty())
	{
		return;
	}
	SmoothGauss* Simg = new SmoothGauss();
	QImage img2 = Simg->Smooth(openfile, type3);
	Simg->_img = &img2;
	QImage* SmoothGaussImg1 = Simg->_img;
	QImage* SmoothGaussImg2 = Simg->getSmooth(SmoothGaussImg1);
	SmoothGaussImg2->save(svaefile + "/" + name + "." + type);
}







