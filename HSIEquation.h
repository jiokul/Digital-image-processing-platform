#pragma once

#include <QWidget>
#include "ui_HSIEquation.h"
#include <QVTKWidget.h>
#include <vtkDICOMImageReader.h>
#include <vtkImageViewer2.h>
#include <vtkSmartPointer.h>
#include <vtkTextMapper.h>
#include <vtkTextProperty.h>
#include <vtkRenderer.h>
#include <vtkActor2D.h>
#include <sstream>
#include <itkImage.h>
#include <itkImageFileReader.h>
#include <itkImageToVTKImageFilter.h>
#include <itkGDCMImageIO.h>
#include <itkMetaDataDictionary.h>
#include <itkMetaDataObject.h>
#include <itkImageSeriesReader.h>
#include <itkGDCMSeriesFileNames.h>
#include <vtkImageFlip.h>
using namespace std;
class HSIEquation : public QWidget
{
	Q_OBJECT

public:
	HSIEquation(QWidget *parent = Q_NULLPTR);
	~HSIEquation();
public slots:
	void save();
public:
	void changeimg();
	//void changeimg2();
	QImage HSIEimg(QString fileName, int a);
	void OpenImg(QImage* img);
	QImage* _img;
	QImage* img_final;
	void RGBtoHSI(float r, float g, float b, float* h, float* s, float* i);
	void HSItoRGB(float h, float s, float i, float* r, float* g, float* b);

private:
	Ui::HSIEquation ui;
};
