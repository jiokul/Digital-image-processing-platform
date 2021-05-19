#pragma once

#include <QWidget>
#include "ui_Prewitt.h"
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
class Prewitt : public QWidget
{
	Q_OBJECT

public:
	Prewitt(QWidget *parent = Q_NULLPTR);
	~Prewitt();
public slots:
	void save();
public:
	QImage preimg(QString fileName, int a);
	void calculate();
	void grayScaleImg();
	QRgb edge;
	QRgb notedge;
	QImage* _img;
	QImage* img_gray;
	QImage* img_calulate;
	QImage* img_final;
	int three;
	vector<int> Histogram(QImage* img);
	int Otsu(QImage* img);
	void OpenImg(QImage* img);
private:
	Ui::Prewitt ui;
};
