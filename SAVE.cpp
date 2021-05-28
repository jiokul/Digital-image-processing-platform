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
#include "Prewitt.h"
#include "HSIEquation.h"
#include "DoubleThreshold.h"
#include "DoubleSubmit.h"
#include "HSVEquation.h"
#include "Invert_colour.h"
#pragma execution_character_set("utf-8")//显示中文
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
	flag1 = 1;
	switch (type1)
	{
	case 0:ui.lineEdit_2->setText("灰度图"); break;
	case 1:ui.lineEdit_2->setText("图像模糊"); break;
	case 2:ui.lineEdit_2->setText("高斯平滑"); break;
	case 3:ui.lineEdit_2->setText("图像锐化"); break;
	case 4:ui.lineEdit_2->setText("canny图像边缘检测"); break;
	case 5:ui.lineEdit_2->setText("prewitt图像边缘检测"); break;
	case 6:ui.lineEdit_2->setText("otsu图像分割"); break;
	case 7:ui.lineEdit_2->setText("双阈值图像分割"); break;
	case 8:ui.lineEdit_2->setText("直方图均衡化"); break;
	case 9:ui.lineEdit_2->setText("彩色直方图均衡化"); break;
	case 10:ui.lineEdit_2->setText("HSI直方图均衡化"); break;
	case 11:ui.lineEdit_2->setText("HSV直方图均衡化"); break;
	case 12:ui.lineEdit_2->setText("图像反色"); break;
	}
}

void SAVE::settype2()
{
	flag = 1;
	switch (type2)
	{
	case 0:ui.lineEdit_3->setText("JPG格式"); break;
	case 1:ui.lineEdit_3->setText("PNG格式"); break;
	case 2:ui.lineEdit_3->setText("BMP格式"); break;
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
		QMessageBox::information(NULL, "error", "请先打开图片");
		return;
	}
	if (svaefile.isEmpty())
	{
		QMessageBox::information(NULL, "error", "请先选择保存路径");
		return;
	}
	if (flag1 == 0)
	{
		QMessageBox::information(NULL, "error", "请先选择文件处理类型");
		return;
	}
	if (flag == 0)
	{
		QMessageBox::information(NULL, "error", "请先选择保存类型");
		return;
	}
	if (name.isEmpty())
	{
		QMessageBox::information(NULL, "error", "请先提交保存文件名");
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
	case 5:getprewitt(); break;
	case 6:getbinarize(); break;
	case 7:getdouble(); break;
	case 8:getEgary(); break;
	case 9:getrgbequantion(); break;
	case 10:getHSI(); break;
	case 11:getHSV(); break;
	case 12:gettrun(); break;
	}
	this->close();
	//qDebug() << svaefile + "/" + name + "." + type;
}

void SAVE::getgray()
{
	if (openfile.isEmpty())
	{
		QMessageBox::information(NULL, "error", "请先打开图片");
		return;
	}
	grayview* gimg = new grayview();
	QImage img2 = gimg->gary(openfile, type3);
	gimg->_img = &img2;
	QImage* grayImage = gimg->grayScaleImg();
	grayImage->save(svaefile+"/"+ name+"."+type);
	QMessageBox::information(NULL, "success", "保存成功");
}

void SAVE::getEgary()
{
	if(openfile.isEmpty())
	{
		QMessageBox::information(NULL, "error", "请先打开图片");
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
	QMessageBox::information(NULL, "success", "保存成功");
}

void SAVE::getbinarize()
{
	if (openfile.isEmpty())
	{
		QMessageBox::information(NULL, "error", "请先打开图片");
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
	QMessageBox::information(NULL, "success", "保存成功");
}

void SAVE::gectcanny()
{
	if (openfile.isEmpty())
	{
		QMessageBox::information(NULL, "error", "请先打开图片");
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
	QMessageBox::information(NULL, "success", "保存成功");
}

void SAVE::getblur()
{
	if (openfile.isEmpty())
	{
		QMessageBox::information(NULL, "error", "请先打开图片");
		return;
	}
	blur* Simg = new blur();
	QImage img2 = Simg->blurimg(openfile, type3);
	Simg->_img = &img2;
	QImage* SmoothGaussImg1 = Simg->_img;
	QImage* SmoothGaussImg2 = Simg->getblurimg(SmoothGaussImg1);
	SmoothGaussImg2->save(svaefile + "/" + name + "." + type);
	QMessageBox::information(NULL, "success", "保存成功");
}

void SAVE::getrgbequantion()
{
	if (openfile.isEmpty())
	{
		QMessageBox::information(NULL, "error", "请先打开图片");
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
	QMessageBox::information(NULL, "success", "保存成功");
}

void SAVE::getsharpen()
{
	if (openfile.isEmpty())
	{
		QMessageBox::information(NULL, "error", "请先打开图片");
		return;
	}
	sharpen* Simg = new sharpen();
	QImage img2 = Simg->sharpenimg(openfile, type3);
	Simg->_img = &img2;
	QImage* SmoothGaussImg1 = Simg->_img;
	QImage* SmoothGaussImg2 = Simg->getsharpenimg(SmoothGaussImg1);
	SmoothGaussImg2->save(svaefile + "/" + name + "." + type);
	QMessageBox::information(NULL, "success", "保存成功");
}

void SAVE::getsmooth()
{
	if (openfile.isEmpty())
	{
		QMessageBox::information(NULL, "error", "请先打开图片");
		return;
	}
	SmoothGauss* Simg = new SmoothGauss();
	QImage img2 = Simg->Smooth(openfile, type3);
	Simg->_img = &img2;
	QImage* SmoothGaussImg1 = Simg->_img;
	QImage* SmoothGaussImg2 = Simg->getSmooth(SmoothGaussImg1);
	SmoothGaussImg2->save(svaefile + "/" + name + "." + type);
	QMessageBox::information(NULL, "success", "保存成功");
}

void SAVE::getprewitt()
{
	if (openfile.isEmpty())
	{
		QMessageBox::information(NULL, "error", "请先打开图片");
		return;
	}
	Prewitt* pimg = new Prewitt();
	QImage img2 = pimg->preimg(openfile, type3);
	pimg->_img = &img2;
	pimg->grayScaleImg();
	pimg->three = pimg->Otsu(pimg->img_gray);
	qDebug() << pimg->three;
	pimg->calculate();
	pimg->img_final->save(svaefile + "/" + name + "." + type);
	QMessageBox::information(NULL, "success", "保存成功");
}

void SAVE::getdouble()
{
	if (openfile.isEmpty())
	{
		QMessageBox::information(NULL, "error", "请先打开图片");
		return;
	}
	DoubleSubmit* Simg = new DoubleSubmit();
	Simg->move(150, 200);
	Simg->fileName = openfile;
	Simg->type = type3;
	Simg->show();
}

void SAVE::getHSI()
{
	if (openfile.isEmpty())
	{
		QMessageBox::information(NULL, "error", "请先打开图片");
		return;
	}
	HSIEquation* HSIimg = new HSIEquation();
	QImage img2 = HSIimg->HSIEimg(openfile, type3);
	HSIimg->_img = &img2;
	HSIimg->changeimg();
	HSIimg->img_final->save(svaefile + "/" + name + "." + type);
	QMessageBox::information(NULL, "success", "保存成功");
}

void SAVE::getHSV()
{
	if (openfile.isEmpty())
	{
		QMessageBox::information(NULL, "error", "请先打开图片");
		return;
	}
	HSVEquation* HSIimg = new HSVEquation();
	QImage img2 = HSIimg->HSVEimg(openfile, type3);
	HSIimg->_img = &img2;
	HSIimg->changeimg();
	HSIimg->changeimg2();
	HSIimg->img_final1->save(svaefile + "/" + name + "." + type);
	QMessageBox::information(NULL, "success", "保存成功");
}

void SAVE::gettrun()
{
	if (openfile.isEmpty())
	{
		QMessageBox::information(NULL, "error", "请先打开图片");
		return;
	}
	Invert_colour* Iimg = new Invert_colour();
	QPalette pal(Iimg->palette());
	QImage img2 = Iimg->colour(openfile, type3);
	Iimg->_img = &img2;
	Iimg->handling(Iimg->_img);
	Iimg->newimg->save(svaefile + "/" + name + "." + type);
	QMessageBox::information(NULL, "success", "保存成功");
}









