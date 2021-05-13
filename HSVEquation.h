#pragma once

#include <QWidget>
#include "ui_HSVEquation.h"
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
class HSVEquation : public QWidget
{
	Q_OBJECT

public:
	HSVEquation(QWidget *parent = Q_NULLPTR);
	~HSVEquation();
public:
	void changeimg();
	void changeimg2();
	QImage HSVEimg(QString fileName, int a);
	void OpenImg(QImage* img);
	QImage* _img;
	QImage* img_final;
	QImage* img_final1;
	void RGBtoHSV(float r, float g, float b, float* h, float* s, float* v);
	void HSVtoRGB(float h, float s, float v, float* r, float* g, float* b);
private:
	Ui::HSVEquation ui;
};
