#include "DoubleSubmit.h"
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
	//���ñ�����ɫ
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