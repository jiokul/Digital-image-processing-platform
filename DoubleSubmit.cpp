#include "DoubleSubmit.h"
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
#include "change.h"
#include "DoubleThreshold.h"
DoubleSubmit::DoubleSubmit(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	connect(ui.pushButton, SIGNAL(clicked(bool)), this, SLOT(getlow()));
	connect(ui.pushButton_2, SIGNAL(clicked(bool)), this, SLOT(gethigh()));
	connect(ui.pushButton_3, SIGNAL(clicked(bool)), this, SLOT(run()));
}

DoubleSubmit::~DoubleSubmit()
{
}

void DoubleSubmit::getlow()
{
	low = ui.lineEdit->text().toInt();
	qDebug() << low;
}
void DoubleSubmit::run()
{
	low = ui.lineEdit->text().toInt();
	high = ui.lineEdit_2->text().toInt();
	DoubleThreshold* Dimg = new DoubleThreshold();
	Dimg->high = high;
	Dimg->low = low;
	QPalette pal(Dimg->palette());
	//设置背景黑色
	pal.setColor(QPalette::Background, Qt::black);
	Dimg->setAutoFillBackground(true);
	Dimg->setPalette(pal);
	Dimg->setAttribute(Qt::WA_DeleteOnClose);
	Dimg->show();
	QImage img2 = Dimg->Doubleimg(fileName, type);
	Dimg->_img = &img2;
	Dimg->img_gray = Dimg->getcgray();
	Dimg->process(Dimg->img_gray);
	Dimg->OpenImg(Dimg->img_final);
}
void DoubleSubmit::gethigh()
{
	high = ui.lineEdit_2->text().toInt();
	qDebug() << high;
}